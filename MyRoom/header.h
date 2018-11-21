#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<Windows.h>

typedef struct friends{
	char*name;
	int age;
}Friend;

typedef struct floor{
	Friend*proom;
	struct floor*pnext;
}Floor;

int menu_list(void);//메뉴 보이기
void make_room_p(char ***room, int size);//룸 만들기(초기)
char *make_friend(void);//친구 방에 넣기
void size_trans(char***room,int size_after);//룸 크기 바꾸기
void move_mate(char***room);//친구 이사(삭제하기)
void move_room(char**room);//방 이사(바꾸기)
void show_room(char**room);//룸 보이기
int input(void);//이름 글자 수 입력
int mystrlen(char*str);//문자열 길이
int mycompare(char*str,char*str2);//문자열 비교
void mystring(char**str);