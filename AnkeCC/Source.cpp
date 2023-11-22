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
        strcpy(a, "車");
        break;
    case 2:
        strcpy(a, "馬");
        break;
    case 3:
        strcpy(a, "象");
        break;
    case 4:
        strcpy(a, "士");
        break;
    case 5:
        strcpy(a, "將");
        break;
    case 6:
        strcpy(a, "卒");
        break;
    case 7:
        strcpy(a, "鮑");
        break;

        //2p
    case 8:
        strcpy(a, "狙");
        break;
    case 9:
        strcpy(a, "傌");
        break;
    case 10:
        strcpy(a, "相");
        break;
    case 11:
        strcpy(a, "仕");
        break;
    case 12:
        strcpy(a, "帥");
        break;
    case 13:
        strcpy(a, "兵");
        break;
    case 14:
        strcpy(a, "炮");
        break;//1p
    default:
        strcpy(a, "無");
        break;
    }
    return a;
}

char* status(int n) {
    switch (n) {
    case 1:
        strcpy(statusarr, "請輸入你要移動的座標");
        break;
    case 2:
        strcpy(statusarr, "輸入的內容不符合格式，請檢查後再次輸入");
        break;
    case 3:
        strcpy(statusarr, "你所輸入的座標不存在");
        break;
    case 4:
        strcpy(statusarr, "你的棋子移動的不合規則");
        break;
    case 5:
        strcpy(statusarr, "阿姆阿姆 xP");
        break;
    case 6:
        strcpy(statusarr, "住手!!你在吃自己");
        break;
    case 7:
        strcpy(statusarr, "你正在動的並不是你的棋子");
        break;
    case 8:
        strcpy(statusarr, "你不能移動空氣");
        break;
    case 9:
        strcpy(statusarr, "王見王!");
        break;
    case 10:
        strcpy(statusarr, "自己移到自己?這樣有甚麼意義");
        break;
    case 100:
        strcpy(statusarr, "系統故障，請聯繫ANKE");
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
    printf("狀態:第%d局 輪到%dP \n     %s\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", round, player, statusarr);
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
                    printf("         遊戲玩法:");
                }
                if (i == 1) {
                    printf("          吃掉對方的將");
                }
                if (i == 2) {
                    printf("          上面為1P,");
                }
                if (i == 3) {
                    printf("          下面為2P");
                }
                printf("\n");
            }
            else if (i == 4) {
                printf("%s #%d\n         漢界         ", cheeseboard(4, 8), i);
            }

        }
        if (i == 5) {
            for (int k = 0; k < 1; k++) {
                printf("                                       楚河         ");
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

int rulecar(int first, int second, int col1, int row1, int col2, int row2) {  //車
    if (col1 == col2) {
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
            status(5);//吃掉了
        }
        else {
            status(4);
        }
    }
    else {
        status(4);
    }

    return 0;
}

int rulehorse(int first, int second, int col1, int row1, int col2, int row2) {//馬
    return 0;
}

int rulexian(int first, int second, int col1, int row1, int col2, int row2) { //象
    return 0;
}

int rulefour(int first, int second, int col1, int row1, int col2, int row2) { //士
    printf("%d %d %d %d %d %d", first, second, col1, row1, col2, row2);//測試

    if (row2 >= 3 && row2 <= 5 && ((first == 4 && col2 <= 2 && col2 >= 0) || (first == 11 && col2 <= 9 && col2 >= 7))) { // 在範圍內
        printf("!!!!");
        if ((col2 == col1 + 1 && row2 == row1 - 1) || (col2 == col1 - 1 && row2 == row1 + 1) || (col2 == col1 - 1 && row2 == row1 - 1) || (col2 == col1 ＋ 1 && row2 == row1 + 1)) {
            cheese[col2][row2] = first;//搬移
            cheese[col1][row1] = 0;
            if (second != 0) {
                status(5);//吃掉了
            }
        }
    }
    else {
        status(4);//不合規則
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
        }
    }
    else {
        status(4);//不合理
    }
    printf("%d %d", first, second);
    //王見王
    if (second == 5 || second == 12) {//吃掉將
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
            return 0;
        }
    }

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
    else if(first == 6 && col1 > 4 || first == 13 && col1 < 5){//玩家一 或 玩家二 在敵方內
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
    return 0;
}

int ruleTotal(int first,int second,int col1,int row1,int col2,int row2) {   //分配各自旗子的規則
    if (((first < 8 && second < 8) || (first > 7 && second > 7)) && (second != 0 && first != 0)) { //吃自己
        if (first == second) {//自己移到自己
            status(10);
            return(1);
        }
        status(6);
        return(1);
    }
    //吃自己 + 亂動別人旗子
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
    printf("你要移動的旗子");
    
    scanf("%s", commnd);
    commnd[0] = toupper(commnd[0]);
    //printf("in select1");
    if (commnd[0] >= 'A' && commnd[0] <= 'I' && commnd[1] >= '0' && commnd[1] <= '9' && commnd[2] <= 0) {//第一指令
        row1 = commnd[0] - 65;
        col1 = commnd[1] - 48;
        //printf("%d,", row);
        //printf("%d", col);
        first = cheese[col1][row1];
        if (first == 0) {
            status(8);
            return 1;
        }
        //printf("你選擇的是%s\n", cheeseboard(col, row));
    }
    else {
        status(3);
        printf("錯誤");
        return 1;
    }
    //printf("in select2");


    int row2, col2;
    /*if (row1 == NULL && col1 == NULL) {
        status(3);
        return 0;
    }*/
    printf("你要移動 %s 到哪裡", cheeseboard(col1, row1));
    scanf("%s", commnd);
    commnd[0] = toupper(commnd[0]);
    if (commnd[0] >= 'A' && commnd[0] <= 'I' && commnd[1] >= '0' && commnd[1] <= '9' && commnd[2] <= 0) {//第二指令
        row2 = commnd[0] - 65;
        col2 = commnd[1] - 48;
        //printf("%d,", row);
        //printf("%d", col);
        second = cheese[col2][row2];
        //printf("你選擇的是%s\n", cheeseboard(col2, row2));
        ruleTotal(first, second, col1, row1, col2, row2);
    }
    else {
        status(3);
        printf("錯誤");
        return 1;
    }
}


int main() {
    init();
    status(999);
    while (1) {
        printBoard();
        inputandselect();
        //clr();
    }
    system("pause");
}