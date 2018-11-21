#include"head.h"

void menu(void){
	printf("=======메뉴=======\n");
		printf("1.좌석 보이기\n");
		printf("2.좌석 예약하기\n");
		printf("3.좌석 취소하기\n");
		printf("4.종료\n");
		printf("==================\n");
}		
		
void show_seat(char the[10][10]){
	int i=0,j=0;		
	for(i=0;i<10;i++){
				for(j=0;j<10;j++){
					if(the[i][j]=='1')printf("■");
					else printf("□");
				}printf("\n");
			}
}

void reserve_seat(char the[10][10],int m,int n){
	int i=0, j=0;
	while(1){
		printf("좌석을 입력해주세요(종료하려면 -1)\n");
		printf("행 : "); scanf_s("%d",&m,sizeof(m));
			if(m==-1){
				printf("종료합니다.\n");
				break;
			}
		printf("열 : "); scanf_s("%d",&n,sizeof(n));
		if(m>10 || n>10)
			printf("자리가 존재하지 않습니다. 다시 입력해 주세요\n");
		if(the[m-1][n-1]=='1'){
			printf("이미 차있습니다.\n");
		}		
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				if(i==m && j==n)
					the[i-1][j-1]='1';
			}
		}
	}
}

void cancel_seat(char the[10][10],int m, int n){
	int i=0,j=0;
	printf("어느 자리를 취소하시겠습니까\n");
			printf("행:");scanf_s("%d",&m,sizeof(m));
			printf("열:");scanf_s("%d",&n,sizeof(n));
			for(i=0;i<10;i++){
				for(j=0;j<10;j++){
					if(i==m && j==n)
						the[i-1][j-1]='0';
				}
		}
}