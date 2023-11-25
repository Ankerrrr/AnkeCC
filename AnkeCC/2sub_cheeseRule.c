#include "head.h"
#include "global.h"

int rulecar(int first, int second, int col1, int row1, int col2, int row2) {  //車
    if (col1 == col2 ) {
        int obstacle = 0;
        int min = row1 > row2 ? row2 : row1;
        int max = row1 < row2 ? row2 : row1;
        for (int i = min + 1; i < max; i++) {
            if (cheese[col1][i] != 0) {
                obstacle = 1;
            }
        }
        if (!obstacle) { //沒有碰撞
            cheese[col2][row2] = first;
            cheese[col1][row1] = 0;
            if (second != 0) {
                status(5);//吃掉了
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
                status(5);//吃掉了
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

int rulehorse(int first, int second, int col1, int row1, int col2, int row2) {//馬
    //2 9
    //printf("%d %d %d %d %d %d", first, second, col1, row1, col2, row2);//測試
    //printf("!!!!");
    if ((col2 == col1 + 1 && row2 == row1 + 2 && !cheese[col1][row1 + 1]) || //馬 直 
        (col2 == col1 - 1 && row2 == row1 + 2 && !cheese[col1][row1 + 1]) ||
        (col2 == col1 - 1 && row2 == row1 - 2 && !cheese[col1][row1 - 1]) ||
        (col2 == col1 + 1 && row2 == row1 - 2 && !cheese[col1][row1 - 1]) ||
        (col2 == col1 + 2 && row2 == row1 + 1 && !cheese[col1 + 1][row1]) || //橫
        (col2 == col1 - 2 && row2 == row1 + 1 && !cheese[col1 - 1][row1]) ||
        (col2 == col1 - 2 && row2 == row1 - 1 && !cheese[col1 - 1][row1]) ||
        (col2 == col1 + 2 && row2 == row1 - 1 && !cheese[col1 + 1][row1])) {

        if (second != 0) {
            status(5);//吃掉了
        }
        cheese[col2][row2] = first;//搬移
        cheese[col1][row1] = 0;
    }
    else {
        status(4);//不合規則
        return 1;
    }
    return 0;
}

int rulexian(int first, int second, int col1, int row1, int col2, int row2) { //象
    //3 10
    //printf("%d %d %d %d %d %d", first, second, col1, row1, col2, row2);//測試
    if ((first == 3 && col2 <= 4 && col2 >= 0) || (first == 10 && col2 <= 9 && col2 >= 5)) { // 在範圍內
        printf("!!!!");
        if ((col2 == col1 + 2 && row2 == row1 - 2 && !cheese[col1 + 1][row1 - 1]) ||  //田字型 + 卡象腳
            (col2 == col1 - 2 && row2 == row1 + 2 && !cheese[col1 - 1][row1 + 1]) ||
            (col2 == col1 - 2 && row2 == row1 - 2 && !cheese[col1 - 1][row1 - 1]) ||
            (col2 == col1 + 2 && row2 == row1 + 2 && !cheese[col1 + 1][row1 + 1])) {
            if (second != 0) {
                status(5);//吃掉了
            }
            cheese[col2][row2] = first;//搬移
            cheese[col1][row1] = 0;
        }
        else {
            status(4);//不合規則
            return 1;
        }
    }
    else {
        status(4);//不合規則
        return 1;
    }
    return 0;
}

int rulefour(int first, int second, int col1, int row1, int col2, int row2) { //士
    //printf("%d %d %d %d %d %d", first, second, col1, row1, col2, row2);//測試
    if (row2 >= 3 && row2 <= 5 && ((first == 4 && col2 <= 2 && col2 >= 0) || (first == 11 && col2 <= 9 && col2 >= 7))) { // 在範圍內
        printf("!!!!");
        if ((col2 == col1 + 1 && row2 == row1 - 1) || (col2 == col1 - 1 && row2 == row1 + 1) || (col2 == col1 - 1 && row2 == row1 - 1) || (col2 == col1 + 1 && row2 == row1 + 1)) {
            if (second != 0) {
                status(5);//吃掉了
            }
            cheese[col2][row2] = first;//搬移
            cheese[col1][row1] = 0;
        }
        else {
            status(4);//不合規則
            return 1;
        }
    }
    else {
        status(4);//不合規則
        return 1;
    }
    return 0;
}

int ruleking(int first, int second, int col1, int row1, int col2, int row2) { //將
    if (((col2 == col1 + 1 || col2 == col1 - 1) && row1 == row2) || ((row2 == row1 + 1 || row2 == row1 - 1) && col1 == col2)) { //前進 後退 左邊 右邊 一格
        //printf("%d %d %d %d %d %d", first, second, col1, row1, col2, row1);//測試
        if ((row2 >= 3 && row2 <= 5) && ((first == 5 && col2 <= 2 && col2 >= 0) || first == 12 && col2 <= 9 && col2 >= 7)) { //在範圍內
            cheese[col2][row2] = first;//搬移
            cheese[col1][row1] = 0;
            if (second != 0) {
                status(5);//吃掉了
            }
        }
        else {
            status(4);//不合理
            return 1;
        }
    }else if (second == 5 || second == 12) {//王見王//吃掉將
        int obstacle = 0;
        if (row1 == row2) { // 在同一行上
            int min_col = (col1 < col2) ? col1 : col2;
            int max_col = (col1 > col2) ? col1 : col2;

            for (int i = min_col + 1; i < max_col; i++) {
                if (cheese[i][row1] != 0) {
                    obstacle = 1; // 中間有其他棋子
                    break;
                }
            }
        }
        // 如果王見王的條件滿足且中間沒有其他棋子
        if (!obstacle) {
            cheese[col2][row2] = first;//搬移
            cheese[col1][row1] = 0;
            status(9); // 王見王！
        } else {
            status(4);//不合理
            return 1;
        }
    }else {
        status(4);//不合理
        return 1;
    }
    return 0;
}

//|col -row
int rulebin(int first, int second, int col1, int row1, int col2, int row2) {  //兵
    if ((first == 6 && (col2 == col1 + 1) && (row1 == row2)) || (first == 13 && (col2 == col1 - 1) && (row1 == row2))) { //前進一格 符合規則
        cheese[col2][row2] = first;
        cheese[col1][row1] = 0;
        if (second != 0) {
            status(5);//吃到東西了
        }
    }
    else if (first == 6 && col1 > 4 || first == 13 && col1 < 5) {//玩家一 或 玩家二 在敵方內
        if ((row1 == row2 + 1 || row1 == row2 - 1) && col1 == col2) {//左右動一格
            cheese[col2][row2] = first;
            cheese[col1][row1] = 0;
            if (second != 0) {
                status(5);//吃到東西了
            }
        }
        else {
            status(4);//移動不合理
            return(1);
        }
    }
    else {
        status(4);//移動不合理
        return(1);
    }
    return 0;
}

int rulepow(int first, int second, int col1, int row1, int col2, int row2) { //炮
    // 7 14
    if ((col1 == col2 && row1 != row2) || (row1 == row2 && col1 != col2)) {//直走
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
            if (obstacle == 0 && second == 0) {
                cheese[col2][row2] = first;
                cheese[col1][row1] = 0;
            }
            if (obstacle == 1 && (player == 1 && second > 7) || (player == 2 && second < 8) && second != 0) {
                printf("BBB");
                cheese[col2][row2] = first;
                cheese[col1][row1] = 0;
                if (second != 0) {
                    status(5);//吃到東西了
                }
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
            if (obstacle == 0 && second == 0) {
                cheese[col2][row2] = first;
                cheese[col1][row1] = 0;
            }
            if (obstacle == 1 && ((player == 1 && second > 7) || (player == 2 && second < 8)) && second != 0) {
                printf("AAA");
                cheese[col2][row2] = first;
                cheese[col1][row1] = 0;
                if (second != 0) {
                    status(5);//吃到東西了
                }
            }
        }
        else {
            status(4);//移動不合理
            return(1);
        }
    }
    else {
        status(4);//移動不合理
        return(1);
    }
    return 0;
}