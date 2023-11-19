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
        strcpy(statusarr, "阿姆阿姆");
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
                    printf("         遊戲玩法:");
                }
                if (i == 1) {
                    printf("         吃掉對方的將");
                }
                if (i == 2) {
                    printf("         上面為1P 下面為2P");
                }
                printf("\n");
            }
            else if (i == 4) {
                printf("%s #%d\n                       漢界         ", cheeseboard(4, 8), i);
            }

        }
        if (i == 5) {
            for (int k = 0; k < 1; k++) {
                printf("                       楚河         ");
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
    //車
    if ( (player == 1 && first == 1) || (player == 2 && first == 8) ) { //車子 
        printf("CAR");
        if (col1 == col2) {  //移動的是合理的 橫向移動
            for (int i = col1; i < col2; i++) {//檢查移動過程有無碰撞
                if (cheese[row1][i] != 0) { //如果有碰撞
                    status(4); //狀態 移動不合理
                    return 1;
                }
            }
            if (second != 0) {//移動到的地方有東西
                if (player == 1) {//1p移動
                    if (second >= 8) {
                        status(5);//阿姆
                    }
                    else {
                        status(6);//住手 你在吃自己
                        return 1;
                    }
                }
                else {//2p移動
                    if (second <= 7) {
                        status(5);//哎呀被吃掉了
                    }
                    else {
                        status(6);//住手 你在吃自己
                        return 1;
                    }
                }
            }
            cheese[col2][row2] = first;//搬移
            cheese[col1][row1] = 0;


        }
        else if (row1 == row2) {//移動的是合理的 直向移動
            for (int i = row1; i < row2; i++) {//檢查移動過程有無碰撞
                if (cheese[i][col1] != 0) { //如果有碰撞
                    status(4); //狀態 移動不合理
                    return 1;
                }
            }
            if (second != 0) {//移動到的地方有東西
                if (player == 1) {//1p移動
                    if (second >= 8) {
                        status(5);//哎呀被吃掉了
                    }
                    else {
                        status(6);//住手 你在吃自己
                        return 1;
                    }
                }
                else {//2p移動
                    if (second <= 7) {
                        status(5);//哎呀被吃掉了
                    }
                    else {
                        status(6);//住手 你在吃自己
                        return 1;
                    }
                }
            }
            cheese[col2][row2] = first;//搬移
            cheese[col1][row1] = 0;
        }
    }
    else {
        if (first == 1 || first == 8) {
            status(7);//亂動別人的旗子
        }
    }
    
}

int inputandselect() {
    int first, second;
    int row1, col1;
    printf("你要移動的旗子");
    
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
        //printf("你選擇的是%s\n", cheeseboard(col, row));
    }
    else {
        status(3);
        printf("錯誤");      
    }

    int row2, col2;
    printf("你要移動 %s 到哪裡", cheeseboard(col1, row1));
    scanf("%s", commnd);
    if (commnd[0] >= 'A' && commnd[0] <= 'I' && commnd[1] >= '0' && commnd[1] <= '9' && commnd[2] <= 0) {
        row2 = commnd[0] - 65;
        col2 = commnd[1] - 48;
        //printf("%d,", row);
        //printf("%d", col);
        second = cheese[col2][row2];
        //printf("你選擇的是%s\n", cheeseboard(col2, row2));
        movecheese(first,second,col1,row1,col2,row2);
    }
    else {
        status(3);
        printf("錯誤");
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