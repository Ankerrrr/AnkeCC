#include "head.h"
#include "global.h"

int clr() {
    printf("\x1b[H\x1b[J"); //clear display
    return 0;
}

int init() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            cheese[i][j] = cheesepreset[i][j];
        }
    }
    return 0;
}

char* cheeseboard(int i, int j) {
    static char a[20];

    switch (cheese[i][j]) {
    case 0:
        strcpy(a, "  ");
        break;
        //1p
    case 1:
        strcpy(a, "��");
        break;
    case 2:
        strcpy(a, "��");
        break;
    case 3:
        strcpy(a, "�H");
        break;
    case 4:
        strcpy(a, "�h");
        break;
    case 5:
        strcpy(a, "�N");
        break;
    case 6:
        strcpy(a, "��");
        break;
    case 7:
        strcpy(a, "�j");
        break;
        //2p
    case 8:
        strcpy(a, "��");
        break;
    case 9:
        strcpy(a, "�X");
        break;
    case 10:
        strcpy(a, "��");
        break;
    case 11:
        strcpy(a, "�K");
        break;
    case 12:
        strcpy(a, "��");
        break;
    case 13:
        strcpy(a, "�L");
        break;
    case 14:
        strcpy(a, "��");
        break;//1p
    default:
        strcpy(a, "�L");
        break;
    }
    return a;
}

char* status(int n) {
    switch (n) {
    case 1:
        strcpy(statusarr, "�п�J�A�n���ʪ��y��");
        break;
    case 2:
        strcpy(statusarr, "��J�����e���ŦX�榡�A���ˬd��A����J");
        break;
    case 3:
        strcpy(statusarr, "�A�ҿ�J���y�Ф��s�b");
        break;
    case 4:
        strcpy(statusarr, "�A���Ѥl���ʪ����X�W�h");
        break;
    case 5:
        strcpy(statusarr, "���i���i xP");
        break;
    case 6:
        strcpy(statusarr, "���!!�A�b�Y�ۤv");
        break;
    case 7:
        strcpy(statusarr, "�A���b�ʪ��ä��O�A���Ѥl");
        break;
    case 8:
        strcpy(statusarr, "�A���ಾ�ʪŮ�");
        break;
    case 9:
        strcpy(statusarr, "������!");
        break;
    case 10:
        strcpy(statusarr, "�ۤv����ۤv?�o�˦��ƻ�N�q");
        break;
    case 100:
        strcpy(statusarr, "�t�άG�١A���pôANKE");
        break;
    default:
        strcpy(statusarr, ":)");
    }

    return 0;
}

int roundstatus() {
    if (player == 1) {
        player = 2;
    }
    else {
        player = 1;
    }
    return 0;
}

void printBoard() {
    printf("���A:��%d�� ����%dP \n     %s\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", round, player, statusarr);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            if (i != 5) {
                if (i > 5) {
                    if (i == 6) {
                        printf("%s~~~~", cheeseboard(i - 1, j));
                    }
                    else {
                        printf("%s----", cheeseboard(i - 1, j));
                    }
                }
                else {
                    if (i == 4) {
                        printf("%s~~~~", cheeseboard(i, j));
                    }
                    else {
                        printf("%s----", cheeseboard(i, j));
                    }
                }
            }
        }
        if (i != 5) {
            if (i > 5) {
                printf("%s", cheeseboard(i - 1, 8));
                printf(" #%d", i - 1);
                printf("\n");
            }
            else if (i < 4) {
                printf("%s", cheeseboard(i, 8));
                printf(" #%d", i);
                if (i == 0) {
                    printf("         �C�����k:");
                }
                if (i == 1) {
                    printf("          �Y����誺�N");
                }
                if (i == 2) {
                    printf("          �W����1P,");
                }
                if (i == 3) {
                    printf("          �U����2P");
                }
                if (i == 4) {
                    printf("          ��J�y�ШӲ��ʺX�l");
                }
                
                printf("\n");
            }
            else if (i == 4) {
                printf("%s #%d\n         �~��         ", cheeseboard(4, 8), i);
            }

        }
        if (i == 5) {
            for (int k = 0; k < 1; k++) {
                printf("                                       ���e         ");
            }
            printf("");
        }
        for (int k = 0; k < 9; k++) {
            if (i == 4 || i == 5) {
                printf("");
            }
            else {
                printf(" |    ");
            }
        }
        printf("\n");
    }
    for (int j = 0; j < 8; j++) {
        printf("%s----", cheeseboard(9, j));
    }
    printf("%s", cheeseboard(9, 8));
    printf(" #%d", 9);
    printf("\n#A    #B    #C    #D    #E    #F    #G    #H    #I \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    printf("\n");
}

int ruleTotal(int first,int second,int col1,int row1,int col2,int row2) {  
    if (((first < 8 && second < 8) || (first > 7 && second > 7)) && (second != 0 && first != 0)) { //�Y�ۤv
        if ((col1 == col2) && (row1 == row2)) {//�ۤv����ۤv
            status(10);
            return(1);
        }
        status(6);
        return(1);
    }
    
    //�ðʧO�H�X�l
    //if (player == 1 && first > 7 || player == 2 && first < 8) {
      //  status(7);
    //    return(1);
  // }

    switch (first) {//���t�U�ۺX�l�����
    case 1:
    case 8:
        rulecar(first, second, col1, row1, col2, row2);
        break;

    case 2:
    case 9:
        rulehorse(first, second, col1, row1, col2, row2);
        break;

    case 3:
    case 10:
        rulexian(first, second, col1, row1, col2, row2);
        break;

    case 4:
    case 11:
        rulefour(first, second, col1, row1, col2, row2);
        break;

    case 5:
    case 12:
        ruleking(first, second, col1, row1, col2, row2);
        break;

    case 6:
    case 13:
        rulebin(first,second,col1,row1,col2,row2);
        break;

    case 7:
    case 14:
        rulepow(first, second, col1, row1, col2, row2);
        break;

    default:
        status(100);
        return 1;
    }
    return 0;
}

int inputandselect() {
    int first, second;
    int row1, col1;
    printf("�A�n���ʪ��X�l");
    
    scanf("%s", commnd1);
    commnd1[0] = toupper(commnd1[0]);
    if (commnd1[0] >= 'A' && commnd1[0] <= 'I' && commnd1[1] >= '0' && commnd1[1] <= '9' && commnd1[2] <= 0) {//�Ĥ@���O
        row1 = commnd1[0] - 65;
        col1 = commnd1[1] - 48;

        first = cheese[col1][row1];
        if (first == 0) {
            status(8);
            return 1;
        }
    }
    else {
        status(3);
        printf("���~");
        return 1;
    }

    int row2, col2;
    printf("�A�n���� '%s' �����", cheeseboard(col1, row1));
    scanf("%s", commnd2);
    commnd2[0] = toupper(commnd2[0]);
    if (commnd2[0] >= 'A' && commnd2[0] <= 'I' && commnd2[1] >= '0' && commnd2[1] <= '9' && commnd2[2] <= 0) {//�ĤG���O
        row2 = commnd2[0] - 65;
        col2 = commnd2[1] - 48;
        second = cheese[col2][row2];
        if (ruleTotal(first, second, col1, row1, col2, row2) == 0) {
            round == 1 ? 2 : 1;
        }
    }
    else {
        status(3);
        printf("���~");
        return 1;
    }
}

int main() {
    init();
    status(999);
    while (1) {
        printBoard();
        inputandselect();
        clr();
    }
    system("pause");
}