#include"head.h"

int wash(char* shower[6],char *state[5]){
	int i=0;
	printf("샤워를 시작합니다.\n");
	for(i=0;i<6;i++){
		printf("%s... \n",*(shower+i));		
		Sleep(1000);
	}
	printf("%s!!\n",*(state+1));
	printf("다 씻었습니다. 몸을 닦고 나갑니다.\n");
	Sleep(2000);

}

int eat(char* food[4],char *state[5]){
	int i=0;
	int num=0;
	printf("식사를 시작합니다.\n");
	while(1){
	printf("무엇을 드시겠습니까?\n");
	printf("================\n");
	printf("1.밥\n");
	printf("2.김치\n");
	printf("3.고기\n");
	printf("4.계란후라이\n");
	printf("5.종료\n");
	printf("================\n");

	scanf_s("%d",&num,sizeof(num));
	
	if(num==5){
		printf("다 먹었습니다.\n");
		break;
	}
		switch(num){
		case 1:
			printf("%s을 먹는중입니다. \n",*(food+(num-1)));
			Sleep(1000);
			break;
		case 2:
			printf("%s을 먹는 중입니다.\n",*(food+(num-1)));
			Sleep(1000);
			break;
		case 3:
		printf("%s을 먹는 중입니다.\n",*(food+(num-1)));
			Sleep(1000);
			break;
		case 4:
			printf("%s을 먹는 중입니다.\n",*(food+(num-1)));
			Sleep(1000);
			break;
		}
	}
	printf("%s!!\n",*(state+3));
	printf("%s!!\n",*(state));
	Sleep(2000);
}
int do_study(char* subject[4],char *state[5]){
	int i=0, num=0;
	printf("공부를 시작합니다.\n");
	while(1){
		printf("어떤 과목을 공부하겠습니까?\n");
		printf("======================\n");
		printf("1.C프로그래밍\n");
		printf("2.행렬대수학\n");
		printf("3.응용수학\n");
		printf("4.전산실습\n");
		printf("5.그만\n");
		printf("======================\n");

		scanf_s("%d",&num,sizeof(num));
		if(num==5){
			printf("너무 피곤합니다. 좀 쉬는게 나을 것 같습니다.\n");
			break;
		}
	switch(num){
		case 1:
			printf("%s 과제를 시작합니다 \n",*(subject+(num-1)));
			printf("노트북 부팅중...\n");
			Sleep(1000);
			printf("visual C++을 켭니다\n");
			printf("지뢰찾기 과제를 수행하기 위해 고민합니다.\n");
			Sleep(1000);
			printf("코딩을 시작합니다.\n");
			Sleep(2000);
			printf("과제를 완료하였습니다.\n");
			printf("%s!!\n",*(state+2));
			printf("%s!!\n",*(state+4));
			Sleep(2000);
			break;
		case 2:
			printf("%s 공부를 시작합니다.\n",*(subject+(num-1)));
			printf("선형대수학책을 폅니다.\n");
			printf("linearly independent에 대한 개념을 공부합니다.\n");
			Sleep(1000);
			printf("%s!!\n",*(state+2));
			printf("%s!!\n",*(state+4));
			Sleep(2000);
			break;
		case 3:
			printf("%s을 공부합니다.\n",*(subject+(num-1)));
			printf("미적분학 책을 폅니다.\n");
			printf("필기 내용과 함께 공부 중\n");
			Sleep(1000);
			printf("연습문제 풀이로 넘어갑니다.\n");
			Sleep(1000);
			printf("%s!!\n",*(state+2));
			printf("%s!!\n",*(state+4));
			Sleep(2000);
			break;
		case 4:
			printf("%s을 공부합니다.\n",*(subject+(num-1)));
			printf("노트북을 부팅합니다.\n");
			Sleep(1000);
			printf("r studio 프로그램을 켭니다.\n");
			Sleep(1000);
			printf("책에 있는 연습문제들을 코딩해봅니다.\n");
			Sleep(1000);
			printf("%s!!\n",*(state+2));
			printf("%s!!\n",*(state+4));
			Sleep(2000);
			break;
		}
	}
}


int drum(char* practice[4],char *state[5]){
	int num=0;
	printf("드럼 연습을 시작합니다.\n");
	printf("동아리방 가는중...\n");
	Sleep(1000);
	printf("동아리방에 도착했습니다.\n");
	while(1){
		printf("어떤 곡을 연습 하겠습니까?\n");
		printf("===================\n");
		printf("1.오늘\n");
		printf("2.눈이 마주쳤을 때\n");
		printf("3.부르튼\n");
		printf("4.그만\n");
		printf("===================\n");
	
		scanf_s("%d",&num,sizeof(num));
		printf("드럼 스틱을 꺼냅니다.\n");
		Sleep(1000);
		if(num==4){
			printf("충분히 연습했습니다. 동방을 나갑니다.\n");
			printf("%s!!\n",*(state+0));
			printf("%s!!\n",*(state+4));
			Sleep(2000);
			break;
		}
			switch(num){
			case 1:
				printf("%s을 연습합니다. \n",*(practice+(num-1)));
				printf("악보를 꺼냅니다.\n");
				Sleep(1000);
				printf("노래를 틉니다.\n");
				printf("%s라는 노래에 맞추어 드럼을 칩니다.\n",*(practice+(num-1)));
				Sleep(1000);
				break;
			case 2:
				printf("%s을 연습합니다. \n",*(practice+(num-1)));
				printf("악보를 꺼냅니다.\n");
				Sleep(1000);
				printf("노래를 틉니다.\n");
				printf("%s라는 노래에 맞추어 드럼을 칩니다.\n",*(practice+(num-1)));
				Sleep(1000);
				break;
			case 3:
				printf("%s을 연습합니다. \n",*(practice+(num-1)));
				printf("악보를 꺼냅니다.\n");
				Sleep(1000);
				printf("노래를 틉니다.\n");
				printf("%s라는 노래에 맞추어 드럼을 칩니다.\n",*(practice+(num-1)));
				Sleep(1000);
				break;
			}
	}
}
