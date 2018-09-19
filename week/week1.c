#include"head.h"

void week1(void){
        int menu=0, sub=0, total=0, sum=0;
		int price[3]={0};
		system("cls");
		while(1){
				if((menu=menu_display())==3)
					break;
				sub=sub_menu_display(menu);
				system("cls");
				sum+=output(price,menu,sub);
				if(menu==3)
					printf("ÃÑ °¡°Ý : %d",sum);
		}
}
