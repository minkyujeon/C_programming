void gotoxy(int x, int y){//커서이동
        COORD Pos;//(1,1)~(80,25)로 사용
		Pos.X=x-1;
		Pos.Y=y-1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

int print_box(void){//테두리
        int i=0, j=0;//i:행, j;열
                for(i=MINY;i<=MAXY;i+=2){
                        for(j=MINX;j<=MAXX;j+=1){
                                if(i==MINY || j==MINX || j==MAXX || i==MAXY-1){//양끝쪽만 ■
                                        gotoxy(i,j);
										Color(6);//테두리를 노란색으로
										printf("■");
                                }
                        }
                printf("\n");
        }
        return 0;
}

void print_dot(int x, int y,char*c){//해당 위치에 공 출력하기
	gotoxy(x,y);
	printf("%s",c);
}

void bar(int x, char c){//바 그리기
	int i=0;
		gotoxy(x,23);
		for(i=0;i<15;i++)//크기 15인 바
			printf("%c",c);
}

void delete_bar(int bar_x){//바 이동을 위한 바 삭제
	int i=0;
	//print_dot(x,y," ");
	
	for(i=bar_x; i<bar_x+15;i++){
		print_dot(i,23," "); 
	}	
}


void Color(int x){//text색깔 바꾸는 함수
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}
void brick(int x, int y){ // 벽돌 추가
	int i=0, j=0;
	int block[4][4]={
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
	};
	
	for(i=0;i<4;i++){
		gotoxy(x,y+i);//y에 i만큼 더해줘야 네모가 4*4형식으로 출력됨(줄바꿈)
		for(j=0;j<4;j++){
			if(block[i][j]==1)
				printf("■");
		}
		printf("\n");
	}
}

int random(void){
	int rand_num=0;
	srand((unsigned)time(NULL));
	rand_num=rand()%45+15;
	return rand_num;
}



void cursor(void){ // 커서 숨기기
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
 
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
 
    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}