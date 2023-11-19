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
    static char statusarr[20];
    switch (n) {
    case 1:
        strcpy(statusarr, "請輸入你要移動的座標");
        break;
    case 2:
        strcpy(statusarr, "請輸入你要移動的座標");
        break;
    default:
        strcpy(statusarr, "發生系統錯誤，請聯絡Anke");
    }

    return statusarr;
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
    printf("狀態:第%d局 輪到%dP \n     %s\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", round, player, status(9));
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

int main() {
    init();
    printBoard();
    //clr();
    system("pause");
}
