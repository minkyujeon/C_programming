#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

#define MINX 1
#define MINY 1
#define MAXX 25
#define MAXY 80
#define ESC 27
#define ENTER 13
#define SPACE 32

void gotoxy(int x, int y);//커서 이동
int print_box(void);//테두리 그리기
void print_dot(int x, int y, char*c);//공 출력
void bar(int x, char c);//bar 출력
void delete_bar(int bar_x);//bar 지우기(이동하는 것처럼 보이기 위해)
void Color(int x);//text색 바꾸기
void brick(int x, int y);//벽돌 출력
int random(void);
void cursor(void);//커서 깜빡임 없애기