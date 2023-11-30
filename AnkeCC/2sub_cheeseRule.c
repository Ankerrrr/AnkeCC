#include "head.h"
#include "global.h"

int rulecar(int first, int second, int col1, int row1, int col2, int row2) {  //��
    if (col1 == col2 ) {
        int obstacle = 0;
        int min = row1 > row2 ? row2 : row1;
        int max = row1 < row2 ? row2 : row1;
        for (int i = min + 1; i < max; i++) {
            if (cheese[col1][i] != 0) {
                obstacle = 1;
            }
        }
        if (!obstacle) { //�S���I��
            cheese[col2][row2] = first;
            cheese[col1][row1] = 0;
            if (second != 0) {
                status(5);//�Y���F
            }
        }
        else {
            status(4);
            return 1;
        }
    }
    else if (row1 == row2) {
        int obstacle = 0;
        int min = col1 > col2 ? col2 : col1;
        int max = col1 < col2 ? col2 : col1;
        for (int i = min + 1; i < max; i++) {
            if (cheese[i][row1] != 0) {
                obstacle = 1;
            }
        }

        if (!obstacle) {
            cheese[col2][row2] = first;
            cheese[col1][row1] = 0;
            if (second != 0) {
                status(5);//�Y���F
            }
        }
        else {
            status(4);
            return 1;
        }
    }
    else {
        status(4);
        return 1;
    }

    return 0;
}

int rulehorse(int first, int second, int col1, int row1, int col2, int row2) {//��
    //2 9
    //printf("%d %d %d %d %d %d", first, second, col1, row1, col2, row2);//����
    //printf("!!!!");
    if ((col2 == col1 + 1 && row2 == row1 + 2 && !cheese[col1][row1 + 1]) || //�� �� 
        (col2 == col1 - 1 && row2 == row1 + 2 && !cheese[col1][row1 + 1]) ||
        (col2 == col1 - 1 && row2 == row1 - 2 && !cheese[col1][row1 - 1]) ||
        (col2 == col1 + 1 && row2 == row1 - 2 && !cheese[col1][row1 - 1]) ||
        (col2 == col1 + 2 && row2 == row1 + 1 && !cheese[col1 + 1][row1]) || //��
        (col2 == col1 - 2 && row2 == row1 + 1 && !cheese[col1 - 1][row1]) ||
        (col2 == col1 - 2 && row2 == row1 - 1 && !cheese[col1 - 1][row1]) ||
        (col2 == col1 + 2 && row2 == row1 - 1 && !cheese[col1 + 1][row1])) {

        if (second != 0) {
            status(5);//�Y���F
        }
        cheese[col2][row2] = first;//�h��
        cheese[col1][row1] = 0;
    }
    else {
        status(4);//���X�W�h
        return 1;
    }
    return 0;
}

int rulexian(int first, int second, int col1, int row1, int col2, int row2) { //�H
    //3 10
    //printf("%d %d %d %d %d %d", first, second, col1, row1, col2, row2);//����
    if ((first == 3 && col2 <= 4 && col2 >= 0) || (first == 10 && col2 <= 9 && col2 >= 5)) { // �b�d��
        printf("!!!!");
        if ((col2 == col1 + 2 && row2 == row1 - 2 && !cheese[col1 + 1][row1 - 1]) ||  //�Цr�� + �d�H�}
            (col2 == col1 - 2 && row2 == row1 + 2 && !cheese[col1 - 1][row1 + 1]) ||
            (col2 == col1 - 2 && row2 == row1 - 2 && !cheese[col1 - 1][row1 - 1]) ||
            (col2 == col1 + 2 && row2 == row1 + 2 && !cheese[col1 + 1][row1 + 1])) {
            if (second != 0) {
                status(5);//�Y���F
            }
            cheese[col2][row2] = first;//�h��
            cheese[col1][row1] = 0;
        }
        else {
            status(4);//���X�W�h
            return 1;
        }
    }
    else {
        status(4);//���X�W�h
        return 1;
    }
    return 0;
}

int rulefour(int first, int second, int col1, int row1, int col2, int row2) { //�h
    //printf("%d %d %d %d %d %d", first, second, col1, row1, col2, row2);//����
    if (row2 >= 3 && row2 <= 5 && ((first == 4 && col2 <= 2 && col2 >= 0) || (first == 11 && col2 <= 9 && col2 >= 7))) { // �b�d��
        printf("!!!!");
        if ((col2 == col1 + 1 && row2 == row1 - 1) || (col2 == col1 - 1 && row2 == row1 + 1) || (col2 == col1 - 1 && row2 == row1 - 1) || (col2 == col1 + 1 && row2 == row1 + 1)) {
            if (second != 0) {
                status(5);//�Y���F
            }
            cheese[col2][row2] = first;//�h��
            cheese[col1][row1] = 0;
        }
        else {
            status(4);//���X�W�h
            return 1;
        }
    }
    else {
        status(4);//���X�W�h
        return 1;
    }
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
            return 1;
        }
    } else if ((second == 5 || second == 12) && row1 == row2) {//������//�Y���N
        printf("123");
        int obstacle = 0;
        if (row1 == row2) { // �b�P�@��W
            printf("456");
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
            printf("789");
        } else {
            status(4);//���X�z
            printf("afs");
            return 1;
        }
    }else {
        status(4);//���X�z
        printf("bbb");
        return 1;
    }
    return 0;
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
    else if (first == 6 && col1 > 4 || first == 13 && col1 < 5) {//���a�@ �� ���a�G �b�Ĥ褺
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
    // 7 14
    if ((col1 == col2 && row1 != row2) || (row1 == row2 && col1 != col2)) {//����
        if (col1 == col2) {
            int min = row1 > row2 ? row2 : row1;
            int max = row1 < row2 ? row2 : row1;
            int obstacle = 0;
            for (int i = min + 1; i < max; i++) {
                if (cheese[col1][i] != 0) {
                    obstacle++;
                }
            }
            int player = first == 7 ? 1 : 2;
            if (obstacle == 0 && second == 0) { //�����S���F�� �B �쪺�a��O�Ū�
                cheese[col2][row2] = first;
                cheese[col1][row1] = 0;
                return 0;
            }
            if (obstacle == 1 && ((player == 1 && second > 7) || (player == 2 && second < 8)) && second != 0) { //�������@�ӪF�� �B �Y���X�z
                cheese[col2][row2] = first;
                cheese[col1][row1] = 0;
                if (second != 0) {
                    status(5);//�Y��F��F
                }
            } else {
                status(4);//���ʤ��X�z
                return(1);
            }
        }
        else if (row1 == row2) {
            int min = col1 > col2 ? col2 : col1;
            int max = col1 < col2 ? col2 : col1;
            int obstacle = 0;
            for (int i = min + 1; i < max; i++) {
                if (cheese[i][row1] != 0) {
                    obstacle++;
                }
            }
            int player = first == 7 ? 1 : 2;
            if (obstacle == 0 && second == 0) {//�����S���F�� �B �쪺�a��O�Ū�
                cheese[col2][row2] = first;
                cheese[col1][row1] = 0;
                return 0;
            }
            if (obstacle == 1 && ((player == 1 && second > 7) || (player == 2 && second < 8)) && second != 0) {//�������@�ӪF�� �B �Y���X�z
                cheese[col2][row2] = first;
                cheese[col1][row1] = 0;
                if (second != 0) {
                    status(5);//�Y��F��F
                    return 0;
                }
            } else {
                status(4);//���ʤ��X�z
                return(1);
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