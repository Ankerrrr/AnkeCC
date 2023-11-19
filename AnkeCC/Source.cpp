#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cheesepreset[10][9] = {
    {1, 2, 3, 4, 5, 4, 3, 2, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 7, 0, 0, 0, 0, 0, 7, 0},
    {6, 0, 6, 0, 6, 0, 6, 0, 6},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {13, 0, 13, 0, 13, 0, 13, 0, 13},
    {0, 14, 0, 0, 0, 0, 0, 14, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {8, 9, 10, 11, 12, 11, 10, 9, 8}
};
int cheese[10][9] = { 0 };
int player = 1, round = 1;
char commnd[10];
static char statusarr[20];

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
        strcpy(statusarr, "���i���i");
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
                    printf("%s----", cheeseboard(i - 1, j));
                }
                else {
                    printf("%s----", cheeseboard(i, j));
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
                    printf("         �Y����誺�N");
                }
                if (i == 2) {
                    printf("         �W����1P �U����2P");
                }
                printf("\n");
            }
            else if (i == 4) {
                printf("%s #%d\n                       �~��         ", cheeseboard(4, 8), i);
            }

        }
        if (i == 5) {
            for (int k = 0; k < 1; k++) {
                printf("                       ���e         ");
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
    //for (int i = 0; i < 10; i++) {
      //  for (int j = 0; j < 9; j++) {
        //    printf("%d, ", cheese[i][j]);
        //}
        //printf("\n");
    //}
}
//col -  row |
int movecheese(int first,int second,int col1,int row1,int col2,int row2) {
    //��
    if ( (player == 1 && first == 1) || (player == 2 && first == 8) ) { //���l 
        printf("CAR");
        if (col1 == col2) {  //���ʪ��O�X�z�� ��V����
            for (int i = col1; i < col2; i++) {//�ˬd���ʹL�{���L�I��
                if (cheese[row1][i] != 0) { //�p�G���I��
                    status(4); //���A ���ʤ��X�z
                    return 1;
                }
            }
            if (second != 0) {//���ʨ쪺�a�観�F��
                if (player == 1) {//1p����
                    if (second >= 8) {
                        status(5);//���i
                    }
                    else {
                        status(6);//��� �A�b�Y�ۤv
                        return 1;
                    }
                }
                else {//2p����
                    if (second <= 7) {
                        status(5);//�u�r�Q�Y���F
                    }
                    else {
                        status(6);//��� �A�b�Y�ۤv
                        return 1;
                    }
                }
            }
            cheese[col2][row2] = first;//�h��
            cheese[col1][row1] = 0;


        }
        else if (row1 == row2) {//���ʪ��O�X�z�� ���V����
            for (int i = row1; i < row2; i++) {//�ˬd���ʹL�{���L�I��
                if (cheese[i][col1] != 0) { //�p�G���I��
                    status(4); //���A ���ʤ��X�z
                    return 1;
                }
            }
            if (second != 0) {//���ʨ쪺�a�観�F��
                if (player == 1) {//1p����
                    if (second >= 8) {
                        status(5);//�u�r�Q�Y���F
                    }
                    else {
                        status(6);//��� �A�b�Y�ۤv
                        return 1;
                    }
                }
                else {//2p����
                    if (second <= 7) {
                        status(5);//�u�r�Q�Y���F
                    }
                    else {
                        status(6);//��� �A�b�Y�ۤv
                        return 1;
                    }
                }
            }
            cheese[col2][row2] = first;//�h��
            cheese[col1][row1] = 0;
        }
    }
    else {
        if (first == 1 || first == 8) {
            status(7);//�ðʧO�H���X�l
        }
    }
    
}

int inputandselect() {
    int first, second;
    int row1, col1;
    printf("�A�n���ʪ��X�l");
    
    scanf("%s", commnd);
    if (commnd[0] >= 'A' && commnd[0] <= 'I' && commnd[1] >= '0' && commnd[1] <= '9' && commnd[2] <= 0) {
        row1 = commnd[0] - 65;
        col1 = commnd[1] - 48;
        //printf("%d,", row);
        //printf("%d", col);
        first = cheese[col1][row1];
        if (first == 0) {
            status(8);
            return 1;
        }
        //printf("�A��ܪ��O%s\n", cheeseboard(col, row));
    }
    else {
        status(3);
        printf("���~");      
    }

    int row2, col2;
    printf("�A�n���� %s �����", cheeseboard(col1, row1));
    scanf("%s", commnd);
    if (commnd[0] >= 'A' && commnd[0] <= 'I' && commnd[1] >= '0' && commnd[1] <= '9' && commnd[2] <= 0) {
        row2 = commnd[0] - 65;
        col2 = commnd[1] - 48;
        //printf("%d,", row);
        //printf("%d", col);
        second = cheese[col2][row2];
        //printf("�A��ܪ��O%s\n", cheeseboard(col2, row2));
        movecheese(first,second,col1,row1,col2,row2);
    }
    else {
        status(3);
        printf("���~");
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