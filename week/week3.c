#include"head.h"
//1.좌석 보이기
//2.좌석 예약하기  -> 메뉴만들어서 만들기
//3.좌석 취소하기
void week3(void){
	int i=0,j=0;
	int m=0,n=0;//m행 n열
	int num=0;
	char the[10][10]={""};
	for(i=0;i<10;i++){//10*10배열
		for(j=0;j<10;j++){
			the[i][j]='0';
		}
	}
	system("cls");
	while(1){
		menu();

		printf("메뉴를 입력하시오 : ");
		scanf_s("%d",&num,sizeof(num));
		if(num==4)
			break;
		system("cls");
		switch(num){
		case 1:
			printf("1.좌석 보이기\n");
			show_seat(the,m,n);
			break;
	
		case 2:
			printf("2.좌석 예약하기\n");
			reserve_seat(the,m,n);
			
			break;
		case 3:
			printf("3.좌석 취소하기\n");
			cancel_seat(the,m,n);
			break;		
		}
	}	
}