#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

void gotoxy(int x, int y);
void show_board(char board[50][50],int m, int n); // 지뢰판 상태 출력
void show_board_mine(char board[50][50], int m, int n);//지뢰가 보이는 지뢰판 출력
void random_mine(char board[50][50],int m, int n, int mine); //지뢰 random으로 결정
int input_find(char board[50][50],int m,int n,int mine); //지뢰 찾기 입력

