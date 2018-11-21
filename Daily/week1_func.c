#include"head.h"

int menu_display(void){
        int num=0;
        char*main_menu[3]={"Coffee","Juice","종료"};
		printf("============메인 메뉴===========\n");
        for(num=0;num<3;num++){
                printf("%d. %s\n",num+1,main_menu[num]);
        }

        printf("메뉴를 고르시오: ");
        scanf_s("%d",&num,sizeof(num));

        return num;
}

int sub_menu_display(int menu){
        int num=0;
        system("cls");
        printf("============서브 메뉴============\n");
        if(menu==1)
                coffee();
        else if(menu==2)
                juice();
        printf("어느것을 주문하시겠습니까?(종료-1)");
		scanf_s("%d",&num,sizeof(num));
        return num;
}

void coffee(void){
        int i=0;
        char*coffee_1[4]={"아메리카노(3000)","카페라떼(3500)","카페모카(3500)","메인메뉴로 이동"};

        for(i=0;i<4;i++){
                printf("%d. %s\n",i+1,coffee_1[i]);
        }

}
void juice(void){
        int i=0;
        char*juice_1[4]={"오렌지쥬스(3000)","사과쥬스(2500)","키위쥬스(3500)","메인메뉴료 이동"};
        for(i=0;i<4;i++){
                printf("%d. %s\n",i+1,juice_1[i]);
        }
}

void option(int price[3],int menu,int sub){//메뉴에 따라
	int i=0,n=0,num=0;
	int coffee_price[3]={3000,3500,3500};
	int juice_price[3]={3000,2500,3500};
	int hot_price[3]={0,0,0};
	int ice_price[3]={500,500,500};
	int dc_card[3]={500,500,500};

	printf("옵션을 선택하시오 : ");
	printf("===============\n");
	printf("0.옵션 필요없음\n");
	printf("1.hot\n");
	printf("2.ice\n");
	printf("3.coupon\n");
	printf("4.D/C card\n");
	printf("===============\n");
	scanf("%d",&num);
	system("cls");
	switch(num){
		case 0 :
			if(menu==1)
						price[sub-1]=coffee_price[sub-1];
					else if(menu==2)
						price[sub-1]=juice_price[sub-1];
			break;
		case 1 :
				if(menu==1)
					price[sub-1]=coffee_price[sub-1]+hot_price[sub-1];
				else if(menu==2)
					price[sub-1]=juice_price[sub-1]+hot_price[sub-1];
			break;
		case 2:
				if(menu==1)
					price[sub-1]=coffee_price[sub-1]+ice_price[sub-1];
				else if(menu==2)
					price[sub-1]=juice_price[sub-1]+ice_price[sub-1];
			break;
		case 3:
			printf("쿠폰을 10장 모으셨습니까?");
			printf("1. yes, 2.no\n");
			scanf_s("%d",&n,sizeof(n));
			if(n==1){
				printf("무료입니다.\n");
					price[sub-1]=0;
			}
			else if(n==2){
				printf("쿠폰은 10장부터 사용 가능합니다.\n");
					if(menu==1)
						price[sub-1]=coffee_price[sub-1];
					else if(menu==2)
						price[sub-1]=juice_price[sub-1];
			}
			break;

		case 4:
			for(i=0;i<3;i++){
				if(menu==1)
					price[sub-1]=(coffee_price[sub-1]-dc_card[sub-1]);
				else if(menu==2)
					price[sub-1]=(juice_price[sub-1]-dc_card[sub-1]);
			}
			break;
	}
}

int output(int price[3],int menu,int sub){
	int total=0;
		if(menu==1){
			if(sub==1){
				option(price,menu,sub);
		        printf("아메리카노 주문하셨습니다.\n");
				printf("가격 : %d\n",price[sub-1]);
				total=price[sub-1];
			}
			else if (sub==2){
				option(price,menu,sub);
				printf("카페라떼 주문하셨습니다.\n");
				printf("가격 : %d\n",price[sub-1]);
				total=price[sub-1];
			}
			else if(sub==3){
				option(price,menu,sub);
				printf("카페모카 주문하셨습니다.\n");
				printf("가격 : %d\n",price[sub-1]);
				total=price[sub-1];
			}
			else if(sub==4)
				menu_display();
		}
		else if(menu==2){
			if(sub==1){
				option(price,menu,sub);
				printf("오렌지쥬스 주문하셨습니다.\n");
				printf("가격 : %d\n",price[sub-1]);
				total=price[sub-1];
			}
			else if(sub==2){
				option(price,menu,sub);
				printf("사과쥬스 주문하셨습니다.\n");
				printf("가격 : %d\n",price[sub-1]);
				total=price[sub-1];
			}
			else if(sub==3){
				option(price,menu,sub);
				printf("키위쥬스 주문하셨습니다.\n");
				printf("가격 : %d\n",price[sub-1]);
				total=price[sub-1];
			}
			else if(sub==4)
				menu_display();
		}return total;
}