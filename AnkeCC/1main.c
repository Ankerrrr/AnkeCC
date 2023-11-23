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
                if (i == 4) {
                    printf("          輸入座標來移動旗子");
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
}

int ruleTotal(int first,int second,int col1,int row1,int col2,int row2) {  
    if (((first < 8 && second < 8) || (first > 7 && second > 7)) && (second != 0 && first != 0)) { //吃自己
        if ((col1 == col2) && (row1 == row2)) {//自己移到自己
            status(10);
            return(1);
        }
        status(6);
        return(1);
    }
    
    //亂動別人旗子
    //if (player == 1 && first > 7 || player == 2 && first < 8) {
      //  status(7);
    //    return(1);
  // }

    switch (first) {//分配各自旗子的函數
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
    
    scanf("%s", commnd1);
    commnd1[0] = toupper(commnd1[0]);
    if (commnd1[0] >= 'A' && commnd1[0] <= 'I' && commnd1[1] >= '0' && commnd1[1] <= '9' && commnd1[2] <= 0) {//第一指令
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
        printf("錯誤");
        return 1;
    }

    int row2, col2;
    printf("你要移動 '%s' 到哪裡", cheeseboard(col1, row1));
    scanf("%s", commnd2);
    commnd2[0] = toupper(commnd2[0]);
    if (commnd2[0] >= 'A' && commnd2[0] <= 'I' && commnd2[1] >= '0' && commnd2[1] <= '9' && commnd2[2] <= 0) {//第二指令
        row2 = commnd2[0] - 65;
        col2 = commnd2[1] - 48;
        second = cheese[col2][row2];
        if (ruleTotal(first, second, col1, row1, col2, row2) == 0) {
            round == 1 ? 2 : 1;
        }
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
        clr();
    }
    system("pause");
}