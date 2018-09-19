#include"head.h"

void gotoxy(int x, int y){//커서이동
        COORD Pos;//(1,1)~(80,25)로 사용
		Pos.X=x-1;
		Pos.Y=y-1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

void show_board(char board[50][50],int m, int n){ // 지뢰판 상태 출력
	int i=0,j=0;		
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(board[i][j]=='1') printf("■");
			else if(board[i][j]=='3') printf("◎");
			else printf("□");
		}printf("\n");
	}
}



void show_board_mine(char board[50][50],int m, int n){ // 지뢰 위치 보임
	int i=0,j=0;		
	for(i=0;i<m;i++){
			gotoxy(30,i+1);
				for(j=0;j<n;j++){
					if(board[i][j]=='2'||board[i][j]=='3')printf("▲");
					else printf("□");
				}printf("\n");
		}
}

void random_mine(char board[50][50],int m, int n, int mine){ //지뢰 random으로 결정 (지뢰판, 지뢰 개수)
	int i=0,j=0;
	int a=0,b=0;
	int count=0;

	for(i=0;i<mine;i++){
		while(1){
			a=rand()%m;
			b=rand()%n;
			if(board[a][b]=='2')
				a;//조건문을 넘어가기 위해 그냥 적어줌
			else{
				board[a][b]='2';
				break;
			}
		}
		board[a][b]='2';
	}
}

int input_find(char board[50][50],int m,int n,int mine){ //지뢰 찾기 입력

	int i=0, j=0;
	int x=0,y=0;
	int num=0;

	while(1){
		//system("cls");
		printf("입력(종료하려면 -1) : \n");
		printf("행 : "); scanf_s("%d",&x,sizeof(x));
			if(x==-1){
				printf("입력을 종료합니다.\n");
				break;
			}
		printf("열 : "); scanf_s("%d",&y,sizeof(y));
		if(x>m || y>n)
			printf("영역을 벗어났습니다. 다시 입력해 주세요\n");
		if(board[x-1][y-1]=='2'){
			printf("지뢰를 밟았습니다 (3초 뒤 종료)");
			Sleep(3000);
			//system("cls");
			break;
		}
		
		//지뢰 인근을 입력했을 때 지뢰를 ◎로 나타내줌
		if(board[x-2][y-2]=='2'){//입력[x-1][y-1]
			board[x-2][y-2]='3';
			num++;
		}
		if(board[x-2][y-1]=='2'){ 
			board[x-2][y-1]='3';
			num++;
		}
		if(board[x-2][y]=='2'){
			board[x-2][y]='3';
			num++;
		}
		if(board[x-1][y-2]=='2'){
			board[x-1][y-2]='3';
			num++;
		}
		if(board[x-1][y]=='2'){
			board[x-1][y]='3';
			num++;
		}
		if(board[x][y-2]=='2'){
			board[x][y-2]='3';
			num++;
		}
		if(board[x][y-1]=='3'){
			board[x][y-1]='3';
			num++;
		}
		if(board[x][y]=='2'){
			board[x][y]='3';
			num++;
		}
		
		for(i=0;i<m;i++){ //입력한 곳에 1을 넣음
			for(j=0;j<n;j++){
				if(i==(x-1) && j==(y-1))
					board[i][j]='1';
			}
		}
		printf("찾은 지뢰 개수 : %d\n",num);
		if(num==mine){
			printf("you win!!!\n");
			Sleep(2000);
			break;
		}
	}
}