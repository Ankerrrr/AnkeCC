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

char* cheesename(int nub) {
    static char name[20];
    switch (nub) {
    case 0:
        strcpy(name, "  ");
        break;
        //1p
    case 1:
        strcpy(name, "��");
        break;
    case 2:
        strcpy(name, "��");
        break;
    case 3:
        strcpy(name, "�H");
        break;
    case 4:
        strcpy(name, "�h");
        break;
    case 5:
        strcpy(name, "�N");
        break;
    case 6:
        strcpy(name, "��");
        break;
    case 7:
        strcpy(name, "�j");
        break;
        //2p
    case 8:
        strcpy(name, "��");
        break;
    case 9:
        strcpy(name, "�X");
        break;
    case 10:
        strcpy(name, "��");
        break;
    case 11:
        strcpy(name, "�K");
        break;
    case 12:
        strcpy(name, "��");
        break;
    case 13:
        strcpy(name, "�L");
        break;
    case 14:
        strcpy(name, "��");
        break;//1p
    default:
        strcpy(name, "�L");
        break;
    }
    return name;
}

char* cheeseboard(int i, int j) {
    return cheesename(cheese[i][j]);
}

void status(int n) {
    strcpy(statusarr, " ");
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
        if (player == 1) {
            strcpy(statusarr, "�{�b����1P �A���b�ʤ��O�A���Ѥl");
        }
        else {
            strcpy(statusarr, "�{�b����2P �A���b�ʤ��O�A���Ѥl");
        }
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
                
                if (i == 6) {
                    printf("          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                }
                if (i == 8) {
                    printf("          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                }
                if (i == 9) {
                    printf("            ");
                    for (int n = 0; n < 18; n++) {
                        printf("%s ", cheesename(eated1[n]));
                    }
                }
                
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
                    printf("          �W����1P,�U����2P,��J�y�ШӲ��ʺX�l");
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
        if (i == 6) {
            printf("         1P:");
            for (int n = 1; n < 8; n++) {
                printf("%s, ", cheesename(n));
            }
        }
        if (i == 7) {
            printf("         2P:");
            for (int n = 8; n < 15; n++) {
                printf("%s, ", cheesename(n));
            }
        }
        if(i == 8) {
            printf("         1P�w�Q�Y�����Ѥl:");
        }
        if (i == 9) {
            printf("         2P�w�Q�Y�����Ѥl:");
        }
        printf("\n");
    }
    for (int j = 0; j < 8; j++) {
        printf("%s----", cheeseboard(9, j));
    }
    printf("%s", cheeseboard(9, 8));
    printf(" #%d", 9);
    printf("            ");
    for (int n = 0; n < 20; n++) {
        printf("%s ", cheesename(eated2[n]));
    }
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
    if (player == 1 && first > 7 || player == 2 && first < 8) {
        status(7);
        return(1);
   }

    switch (first) {//���t�U�ۺX�l�����
    case 1:
    case 8:
        if (rulecar(first, second, col1, row1, col2, row2) != 0) { 
            return 1; 
        };
        break;

    case 2:
    case 9:
        if (rulehorse(first, second, col1, row1, col2, row2) != 0) { 
            return 1; 
        };
        break;

    case 3:
    case 10:
        if (rulexian(first, second, col1, row1, col2, row2) != 0) { 
            return 1; 
        };
        break;

    case 4:
    case 11:
        if (rulefour(first, second, col1, row1, col2, row2) != 0) {
            return 1; 
        };
        break;

    case 5:
    case 12:
        if (ruleking(first, second, col1, row1, col2, row2) != 0) { 
            return 1;
        };
        break;

    case 6:
    case 13:
        if (rulebin(first, second, col1, row1, col2, row2) != 0) { 
            return 1; 
        };
        break;

    case 7:
    case 14:
        if (rulepow(first, second, col1, row1, col2, row2) != 0) {
            return 1; 
        };
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
    int eat1num = 0, eat2num = 0;
    printf("�A�n���ʪ��X�l:");
    
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
    printf("�A�n���� '%s' �����:", cheeseboard(col1, row1));
    scanf("%s", commnd2);
    commnd2[0] = toupper(commnd2[0]);
    if (commnd2[0] >= 'A' && commnd2[0] <= 'I' && commnd2[1] >= '0' && commnd2[1] <= '9' && commnd2[2] <= 0) {//�ĤG���O
        row2 = commnd2[0] - 65;
        col2 = commnd2[1] - 48;
        second = cheese[col2][row2];

        if (ruleTotal(first, second, col1, row1, col2, row2) == 0) {
            player = player == 1 ? 2 : 1;
            round++;
            if (second < 8 && second != 0) { // 1p been eat
                eated1[eat1num] = second;
                eat1num++;
            }
            else if (second > 7) {//2p been eat
                eated2[eat2num] = second;
                eat2num++;
            }
            if (second == 0) {
                status(999);
            }
            if (second == 5 || second == 12) {
                win = 1; //win
            }
        }
        rewind(stdin);
        rewind(stdout);
    }
    else {
        status(3);
        printf("���~");
        return 1;
    }
}

void winfunc() {
    for (int i = 0; i < 10; i++) {
    }
}

int main() {
    init();
    status(999);
    //while (!win) {
    //    printboard();
    //    inputandselect();
    //    clr();
    //}
    //if (win) {
    //    clr();
    //    winfunc();
    //}
    winfunc();
    system("pause");
}