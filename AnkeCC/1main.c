#include "head.h"
#include "global.h"


FILE* pFile;

char* getTime() {
    static char timeString[100];

    struct tm* localTime;
    time_t currentTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    strftime(timeString, sizeof(timeString), "%c", localTime);

    return timeString;
}

void ctrlc_handler(int signal) {
    printf("\n中斷遊戲QQ\n掰掰\n");
    fprintf(pFile, "%s control-c遊戲中斷\n", getTime());
    fclose(pFile);
    exit(EXIT_SUCCESS);
}

int clr() {
    printf("\x1b[H\x1b[J"); //clear display
    return 0;
}

int init() {
    if (signal(SIGINT, ctrlc_handler) == SIG_ERR) {
        perror("無法抓到sigint訊號");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            cheese[i][j] = cheesepreset[i][j];
        }
    }
    return 0;
}

void setColor(int n) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
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
        strcpy(name, "拘");
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
        strcpy(statusarr, "阿姆阿姆 Xp");
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

void printBoard() {
    printf("狀態:", round, player);
    setColor(highlightColor);
    printf("第%d步", round);
    setColor(textColor);
    printf(",輪到 ");
    setColor(highlightColor);
    printf("%dP \n", player);
    setColor(textColor);
    printf("狀態 %s\n", statusarr);
    setColor(poisColor);
    //printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n#A    #B    #C    #D    #E    #F    #G    #H    #I \n");
    setColor(textColor);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            if (i != 5) {
                if (i > 5) {
                    setColor(cheese[i - 1][j] > 7 ? twoPlayerColor : onePlayerColor);
                    printf("%s", cheeseboard(i - 1, j));  
                    setColor(otherBoardTextColor);
                    printf("----");

                }
                else {
                    setColor(cheese[i][j] > 7 ? twoPlayerColor : onePlayerColor);
                    printf("%s", cheeseboard(i, j));
                    setColor(otherBoardTextColor);
                    printf("----");
                }
            }
        }
        if (i != 5) {
            if (i > 5) {
                setColor(cheese[i - 1][8] > 7 ? twoPlayerColor : onePlayerColor);
                printf("%s", cheeseboard(i - 1, 8));
                setColor(poisColor);
                printf(" #%d", i - 1);
                setColor(otherBoardTextColor);
                if (i == 6 || i == 8) {
                    printf("          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                }
                if (i == 9) {
                    printf("            ");
                    setColor(onePlayerColor);
                    for (int n = 0; n < 18; n++) {
                        if (eated1[n] != 0) {
                            printf("%s ", cheesename(eated1[n]));
                        }
                    }
                    setColor(otherBoardTextColor);
                }
                
                printf("\n");
            }
            else if (i < 4) {
                setColor(cheese[i][8] > 7 ? twoPlayerColor : onePlayerColor);
                printf("%s", cheeseboard(i, 8));
                setColor(poisColor);
                printf(" #%d", i);
                setColor(textColor);
                if (i == 0) { 
                    printf("         遊戲玩法:");
                }
                if (i == 1) {
                    printf("          吃掉對方的將");
                }
                if (i == 2) {
                    printf("          上面為1P,下面為2P,輸入座標來移動旗子");
                }
                setColor(otherBoardTextColor);
                printf("\n");
            }
            else if (i == 4) {
                setColor(cheese[4][8] > 7 ? twoPlayerColor : onePlayerColor);
                printf("%s", cheeseboard(4, 8));
                setColor(poisColor);
                printf(" #%d\n",i);
                setColor(riverColor);
                printf("         漢界         ");
                setColor(textColor);
                printf("                                         上一步:");
                
            }

        }
        if (i == 5) {
            setColor(riverColor);
            printf("                                       楚河          ");
            setColor(textColor);
            if (lastMove1[0] != 0) {
                //這裡
                int row2 = lastMove2[0] - 65;
                int col2 = lastMove2[1] - 48;
                int first = cheese[col2][row2];
                first < 8 ? setColor(onePlayerColor) : setColor(twoPlayerColor);
                printf("          %s", lastMoveName1);
                setColor(textColor);
                printf("(%s) 移動到 (%s)", lastMove1 , lastMove2);
                if (lastMoveName2[0] != 0) {
                    int row2 = commnd2[0] - 65;
                    int col2 = commnd2[1] - 48;
                    int second = cheese[col2][row2];
                    printf(" 吃掉了");
                    lastMoveName2[9] < 8 ? setColor(onePlayerColor) : setColor(twoPlayerColor);
                    printf("%s",lastMoveName2);
                    setColor(textColor);
                }
            }
            
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
            setColor(textColor);
            printf("         1P:");
            setColor(onePlayerColor);
            for (int n = 1; n < 8; n++) {
                printf("%s, ", cheesename(n));
            }
            setColor(otherBoardTextColor);

        }
        if (i == 7) {
            setColor(textColor);
            printf("         2P:");
            setColor(twoPlayerColor);
            for (int n = 8; n < 15; n++) {
                printf("%s, ", cheesename(n));
            }
            setColor(otherBoardTextColor);
        }
        setColor(textColor);
        if(i == 8) {
            printf("         1P已被吃掉的棋子:");
        }
        if (i == 9) {
            printf("         2P已被吃掉的棋子:");
        }
        setColor(otherBoardTextColor);
        printf("\n");
    }
    for (int j = 0; j < 8; j++) {
        setColor(cheese[9][j] > 7 ? twoPlayerColor : onePlayerColor);
        printf("%s", cheeseboard(9, j)); 
        setColor(otherBoardTextColor);
        printf("----");
    }
    setColor(cheese[9][8] > 7 ? twoPlayerColor : onePlayerColor);
    printf("%s", cheeseboard(9, 8));
    setColor(poisColor);
    printf(" #%d", 9);
    printf("            ");
    setColor(twoPlayerColor);
    for (int n = 0; n < 17; n++) {
        if (eated2[n] != 0) {
            printf("%s ", cheesename(eated2[n]));
        }
    }
    setColor(poisColor);
    printf("\n#A    #B    #C    #D    #E    #F    #G    #H    #I \n");
    //printf("- - - - - - - - - - - - - - - - - - - - - - - - - - -");
    setColor(textColor);
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
    printf("你要移動");
    if (cheese[col1][row1] > 0) {
        if (cheese[col1][row1] < 8) {
            setColor(onePlayerColor);
        }
        if (cheese[col1][row1] > 7) {
            setColor(twoPlayerColor);
        }
    } else {
        setColor(textColor);
    }
    printf(" '%s' ", cheeseboard(col1, row1));
    setColor(textColor);
    printf("到哪裡:");

    scanf("%s", commnd2);
    commnd2[0] = toupper(commnd2[0]);
    if (commnd2[0] >= 'A' && commnd2[0] <= 'I' && commnd2[1] >= '0' && commnd2[1] <= '9' && commnd2[2] <= 0) {//第二指令
        row2 = commnd2[0] - 65;
        col2 = commnd2[1] - 48;
        second = cheese[col2][row2];

        lastMove1[0] = 0;
        lastMoveName2[0] = 0;
        if (ruleTotal(first, second, col1, row1, col2, row2) == 0) {
            strcpy(lastMove1, commnd1);
            strcpy(lastMove2, commnd2);
            strcpy(lastMoveName1, cheesename(first));
            if (second != 0) {
                strcpy(lastMoveName2, cheesename(second));
                lastMoveName2[9] = second;
            } else {
                lastMoveName2[0] = 0;
            }
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
    int winner = player == 1 ? 2 : 1;
    //clr();
    printf("\n%dP贏了\n恭喜!!!\n", winner);
    fprintf(pFile, "%s %dP贏了\n", getTime(), winner);
}

void fileInit() {
    pFile = fopen("..\\playCheeseLog.txt", "a");
    if (pFile == NULL) {
        printf("cannot not make File");
        return;
    }
    fprintf(pFile, "%s 遊戲開始\n",getTime());
}

int main() {
    init();
    fileInit();
    status(999);
    while (!win) {
        clr();
        printBoard();
        inputandselect();
    }
    if (win) {
        winfunc();
    }
    fprintf(pFile, "%s 遊戲正常結束\n", getTime());
    fclose(pFile);
    system("pause");
    return 0;
}