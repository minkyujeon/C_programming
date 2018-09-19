#include"header.h"

int main(void){
	char**room=NULL;//room안에 사람도 넣어줘야

	int i=0,size=0,num=0,menu=0;
	int size_after=0;

	while(1){
		menu=menu_list();

		if(menu==7){
			printf("종료합니다.\n");
			break;
		}
		else{
			switch(menu){
				case 1://myroom만들기(초기)
					size=input();
					make_room_p(&room,size);
					break;
				case 2://my_room크기 변경
					size_after=input();
					size_trans(&room,size_after);
					break;
				case 3://room_mate추가
					show_room(room);
					printf("몇 번 방에 추가하시겠습니까?");
					scanf_s("%d",&i,sizeof(i));
					if(room[i]==NULL)
						room[i]=make_friend();
					else
						printf("입주하실 수 없습니다. 다시 입력해주세요.\n");
					break;
				case 4://room_mate이사
					move_mate(&room);
					break;
				case 5:
					move_room(room);
					break;
				case 6:
					show_room(room);
					Sleep(2000);
					break;
			}
		}
	}
	free(room);
}
