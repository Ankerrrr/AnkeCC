#ifndef GLOBALS_H
#define GLOBALS_H

#define onePlayerColor 12
#define twoPlayerColor 14
#define otherBoardTextColor 8
#define textColor 7
#define poisColor 2
#define riverColor 9

extern int cheesepreset[10][9];
extern int cheese[10][9];
extern int eated1[20];
extern int eated2[20];
extern short win;
extern int player;
extern int round;
extern char commnd1[10];
extern char commnd2[10];
extern char statusarr[30];

extern rulecar(int, int, int, int, int, int);
extern rulehorse(int, int, int, int, int, int);
extern rulexian(int, int, int, int, int, int);
extern rulefour(int, int, int, int, int, int);
extern ruleking(int, int, int, int, int, int);
extern rulebin(int, int, int, int, int, int);
extern rulepow(int, int, int, int, int, int);

#endif
