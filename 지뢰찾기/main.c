#include"head.h"

int main(void){
	int i=0,j=0;
	int a=0;
	int m=0,n=0;//m행 n열
	int num=0;
	int mine=0;
	char board[50][50]={""};
	srand((unsigned)time(NULL));
	system("cls");
    printf("★★★★★★★★★★★★★\n");
	printf("★★지 뢰 찾 기 시 작!★★\n");
	printf("★★★★★★★★★★★★★\n");
	Sleep(2000);
	system("cls");
	while(1){
		gotoxy(1,n+1);//그림 아래에 입력을 받기 위해 커서를 옮김
		printf("크기를 결정하시오(종료 : -2)\n");
		printf("가로 : ");
		scanf_s("%d",&m,sizeof(m));
		if(m==-2){
			printf("종료합니다.\n");
			break;
		}
		printf("세로 : ");
		scanf_s("%d",&n,sizeof(n));

		for(i=0;i<m;i++){//m*n배열
			for(j=0;j<n;j++){
				board[i][j]='0';
			}
		}
		printf("지뢰의 개수를 결정하시오 : ");
		scanf_s("%d",&mine,sizeof(mine));
		system("cls");

		show_board(board,m,n);//처음 판 출력
		random_mine(board,m, n, mine);//지뢰 mine개 만큼 랜덤 배치
		show_board_mine(board,m,n);//지뢰가 포함된 판 출력(main판 오른쪽에)
		
		a=input_find(board,m,n,mine);
		system("cls");

		show_board(board,m,n);
		show_board_mine(board,m,n);
		
		//gotoxy(1,50);
		//printf("찾은 지뢰 개수 : %d\n",num);
	}
}
