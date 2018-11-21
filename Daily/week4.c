#include"head.h"

void week4(void){
	int i=0, j=0;
	int n=0;
	char *shower[6]={"샴푸중","머리감기중","바디워시중","헹구기중","폼클렌징중","양치중"};
	char *food[4]={"밥","김치","고기","계란후라이"};
	char *subject[5]={"C프로그래밍","행렬대수학","응용수학","전산실습"};
	char *practice[3]={"오늘","눈이 마주쳤을 때","부르튼"};
	char *state[5]={"행복함","상쾌함","피곤함","배부름","성취감"};
	system("cls");

	printf("하루 일과를 시작합니다.\n");

	while(1){
		system("cls");
		printf("무엇을 하시겠습니까?\n");
		printf("================\n");
		printf("1.샤워\n");
		printf("2.밥먹기\n");
		printf("3.공부\n");
		printf("4.드럼 연습\n");
		printf("5.그만하고 자기\n");
		printf("================\n");

		scanf_s("%d",&n,sizeof(n));
		if(n==5){
			printf("오늘 하루도 수고했습니다. good night...\n");
			Sleep(2000);
			break;
		}
		switch(n){
		case 1:
			wash(shower,state);
			break;
		case 2:
			eat(food,state);
			break;
		case 3:
			do_study(subject,state);
			break;
		case 4:
			drum(practice,state);	
			break;
		}
	}
}
