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
        strcpy(name, "車");
        break;
    case 2:
        strcpy(name, "馬");
        break;
    case 3:
        strcpy(name, "象");
        break;
    case 4:
        strcpy(name, "士");
        break;
    case 5:
        strcpy(name, "將");
        break;
    case 6:
        strcpy(name, "卒");
        break;
    case 7:
        strcpy(name, "鮑");
        break;
        //2p
    case 8:
        strcpy(name, "狙");
        break;
    case 9:
        strcpy(name, "傌");
        break;
    case 10:
        strcpy(name, "相");
        break;
    case 11:
        strcpy(name, "仕");
        break;
    case 12:
        strcpy(name, "帥");
        break;
    case 13:
        strcpy(name, "兵");
        break;
    case 14:
        strcpy(name, "炮");
        break;//1p
    default:
        strcpy(name, "無");
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
        if (player == 1) {
            strcpy(statusarr, "現在輪到1P 你正在動不是你的棋子");
        }
        else {
            strcpy(statusarr, "現在輪到2P 你正在動不是你的棋子");
        }
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
                    printf("         遊戲玩法:");
                }
                if (i == 1) {
                    printf("          吃掉對方的將");
                }
                if (i == 2) {
                    printf("          上面為1P,下面為2P,輸入座標來移動旗子");
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
            printf("         1P已被吃掉的棋子:");
        }
        if (i == 9) {
            printf("         2P已被吃掉的棋子:");
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
    if (((first < 8 && second < 8) || (first > 7 && second > 7)) && (second != 0 && first != 0)) { //吃自己
        if ((col1 == col2) && (row1 == row2)) {//自己移到自己
            status(10);
            return(1);
        }
        status(6);
        return(1);
    }
    
    //亂動別人旗子
    if (player == 1 && first > 7 || player == 2 && first < 8) {
        status(7);
        return(1);
   }

    switch (first) {//分配各自旗子的函數
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
    printf("你要移動的旗子:");
    
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
    printf("你要移動 '%s' 到哪裡:", cheeseboard(col1, row1));
    scanf("%s", commnd2);
    commnd2[0] = toupper(commnd2[0]);
    if (commnd2[0] >= 'A' && commnd2[0] <= 'I' && commnd2[1] >= '0' && commnd2[1] <= '9' && commnd2[2] <= 0) {//第二指令
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
        printf("錯誤");
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