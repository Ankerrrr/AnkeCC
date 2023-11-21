#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
int player = 2, round = 1;
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
    //for (int i = 0; i < 10; i++) {
      //  for (int j = 0; j < 9; j++) {
        //    printf("%d, ", cheese[i][j]);
        //}
        //printf("\n");
    //}
}

int rulecar(int first, int second, int col1, int row1, int col2, int row2) {  //��
    if ((player == 1 && first == 1) || (player == 2 && first == 8)) { 
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
                        //status(6);//��� �A�b�Y�ۤv
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
            status(999);
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
                        //status(6);//��� �A�b�Y�ۤv
                        return 1;
                    }
                }
                else {//2p����
                    if (second <= 7) {
                        status(5);//�u�r�Q�Y���F
                    }
                    else {
                        //status(6);//��� �A�b�Y�ۤv
                        return 1;
                    }
                }
            }
            cheese[col2][row2] = first;//�h��
            cheese[col1][row1] = 0;
            status(999);
        }
    }
    else {
        if (first == 1 || first == 8) {
            status(7);//�ðʧO�H���X�l
        }
    }
    return 0;
}

int rulehorse(int first, int second, int col1, int row1, int col2, int row2) {//��
    return 0;
}

int rulexian(int first, int second, int col1, int row1, int col2, int row2) { //�H
    return 0;
}

int rulefour(int first, int second, int col1, int row1, int col2, int row2) { //�h
    return 0;
}

int ruleking(int first, int second, int col1, int row1, int col2, int row2) { //�N
    if (((col2 == col1 + 1 || col2 == col1 - 1) && row1 == row2) || ((row2 == row1 + 1 || row2 == row1 - 1) && col1 == col2)) { //�e�i ��h ���� �k�� �@��
        //printf("%d %d %d %d %d %d", first, second, col1, row1, col2, row1);//����
        if ((row2 >= 3 && row2 <= 5) && ((first == 5 && col2 <= 2 && col2 >= 0) || first == 12 && col2 <= 9 && col2 >= 7)) { //�b�d��
            cheese[col2][row2] = first;//�h��
            cheese[col1][row1] = 0;
            if (second != 0) {
                status(5);//�Y���F
            }
        }
        else {
            status(4);//���X�z
        }
    }
    else {
        status(4);//���X�z
    }
    printf("%d %d", first, second);
    //������
    if (second == 5 || second == 12) {//�Y���N
        int obstacle = 0;
        if (row1 == row2) { // �b�P�@��W
            int min_col = (col1 < col2) ? col1 : col2;
            int max_col = (col1 > col2) ? col1 : col2;

            for (int i = min_col + 1; i < max_col; i++) {
                if (cheese[i][row1] != 0) {
                    obstacle = 1; // ��������L�Ѥl
                    break;
                }
            }
        }
        // �p�G�����������󺡨��B�����S����L�Ѥl
        if (!obstacle) {
            cheese[col2][row2] = first;//�h��
            cheese[col1][row1] = 0;
            status(9); // �������I
            return 0;
        }
    }

}

//|col -row
int rulebin(int first, int second, int col1, int row1, int col2, int row2) {  //�L
    if ((first == 6 && (col2 == col1 + 1) && (row1 == row2)) || (first == 13 && (col2 == col1 - 1) && (row1 == row2))) { //�e�i�@�� �ŦX�W�h
        cheese[col2][row2] = first;
        cheese[col1][row1] = 0;
        if (second != 0) {
            status(5);//�Y��F��F
        }
    }
    else if(first == 6 && col1 > 4 || first == 13 && col1 < 5){//���a�@ �� ���a�G �b�Ĥ褺
        if ((row1 == row2 + 1 || row1 == row2 - 1) && col1 == col2) {//���k�ʤ@��
            cheese[col2][row2] = first;
            cheese[col1][row1] = 0;
            if (second != 0) {
                status(5);//�Y��F��F
            }
        }
        else {
            status(4);//���ʤ��X�z
            return(1);
        }  
    }
    else {
        status(4);//���ʤ��X�z
        return(1);
    }
    return 0;
}

int rulepow(int first, int second, int col1, int row1, int col2, int row2) { //��
    return 0;
}

int ruleTotal(int first,int second,int col1,int row1,int col2,int row2) {   //���t�U�ۺX�l���W�h
    if (((first < 8 && second < 8) || (first > 7 && second > 7)) && (second != 0 && first != 0)) { //�Y�ۤv
        status(6);
        return(1);
    }
    //�Y�ۤv + �ðʧO�H�X�l
    switch (first) {
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
    
    scanf("%s", commnd);
    commnd[0] = toupper(commnd[0]);
    if (commnd[0] >= 'A' && commnd[0] <= 'I' && commnd[1] >= '0' && commnd[1] <= '9' && commnd[2] <= 0) {//�Ĥ@���O
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
        return 1;
    }

    int row2, col2;
    if (row1 == NULL && col1 == NULL) {
        status(3);
        return 0;
    }
    printf("�A�n���� %s �����", cheeseboard(col1, row1));
    scanf("%s", commnd);
    commnd[0] = toupper(commnd[0]);
    if (commnd[0] >= 'A' && commnd[0] <= 'I' && commnd[1] >= '0' && commnd[1] <= '9' && commnd[2] <= 0) {//�ĤG���O
        row2 = commnd[0] - 65;
        col2 = commnd[1] - 48;
        //printf("%d,", row);
        //printf("%d", col);
        second = cheese[col2][row2];
        //printf("�A��ܪ��O%s\n", cheeseboard(col2, row2));
        ruleTotal(first, second, col1, row1, col2, row2);
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