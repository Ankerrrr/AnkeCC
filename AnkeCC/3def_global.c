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

int cheese[10][9];
int eated1[20] = { 0 };
int eated2[20] = { 0 };
int eat1num = 0, eat2num = 0;
int player = 1;
int round = 1;
short win = 0;

char statusarr[30];
char lastMove1[10];
char lastMove2[10];
char commnd1[20] = { 0 };
char commnd2[20] = { 0 };
char lastMoveName1[10] = { 0 };
char lastMoveName2[10] = { 0 };

