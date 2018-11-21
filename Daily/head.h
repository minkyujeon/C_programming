#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

//week1
int menu_display(void);//주메뉴를 출력하고 입력값 전달
int sub_menu_display(int menu);//서브메뉴를 출력하고 입력값 전달
void coffee(void);//커피 부메뉴 출력
void juice(void);//쥬스 부메뉴 출력
void option(int price[3],int menu,int sub);//옵션 출력
int output(int price[3],int menu,int sub);


//week2
void gotoxy(int x, int y);
void show_board(char board[50][50],int m, int n); // 지뢰판 상태 출력
void show_board_mine(char board[50][50], int m, int n);//지뢰가 보이는 지뢰판 출력
void random_mine(char board[50][50],int m, int n, int mine); //지뢰 random으로 결정
int input_find(char board[50][50],int m,int n,int mine); //지뢰 찾기 입력



//week3
void show_seat(char the[10][10],int i, int j);
void reserve_seat(char the[10][10],int i,int j);
void cancel_seat(char the[10][10],int i, int j);
void menu(void);

//week4
int wash(char* shower[6],char *state[5]);
int eat(char* food[4],char *state[5]);
int do_study(char* subject[4],char *state[5]);
int drum(char* practice[4],char *state[5]);