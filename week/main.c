#include"head.h"

int main(void){
	char menu=0;

	while(menu!='q'){
		system("cls");
		printf("##########################################\n");
		printf("     2017-2 학기 수업내용\n");
		printf("##########################################\n");

		printf("Week1. Ordering System\n");
		printf("Week2. 지뢰찾기\n");
		printf("Week3. Ticket Reservation\n");
		printf("Week4. In My Home \n");
		printf("종료(q) \n");
		printf("select menu : ");
		scanf_s("%c",&menu,sizeof(menu));

		switch(menu){

		case'1' : week1();break;
		case'2' : week2();break;
		case'3' : week3();break;
		case'4' : week4();break;
		case'q' : break;
		
		}
	}return 0;
}