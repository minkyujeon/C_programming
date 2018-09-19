#include<stdio.h>
#include<memory.h>
#include<malloc.h>
#include <Windows.h>
#include<string.h>

typedef struct friends{
	char name[20];
	int age;
	int ???;
	char sex;
	struct friends*next;
}Friend;

int get_only_num(int limit);
int show_menu();
int mycompare(char*str,char*str2);
int mystrlen(char*str);
void make_friend(Friend*Friends,Friend**head,Friend**tail);
void add_friend_front(Friend**head);
void delete_friend(Friend*Friends,Friend**head,Friend**tail);
void show_friend(Friend*Friends,Friend**head);
