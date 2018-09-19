#include"header.h"

int main(void){
	Friend*head=(Friend*)malloc(sizeof(Friend));
	Friend*tail=(Friend*)malloc(sizeof(Friend));
	int menu=0;
	Friend*Friends=NULL;
	FILE*fp;
	head=tail=NULL;
	
	if((fp=fopen("Friend.txt","w"))==NULL){
		printf("error!\n");
		exit(1);
	}
	while(1){
		menu=show_menu();
		if(menu==6){
			printf("종료합니다.\n");
			break;
		}
		switch(menu){
		case 1:
			make_friend(Friends,&head,&tail);
			break;
		case 2:
			add_friend_front(&head);
			break;
		case 3:
			//add_friend_mid();
			break;
		case 4:
			delete_friend(Friends,&head,&tail);
			break;
		case 5:
			show_friend(Friends,&head);
			break;
		}
	}
}

