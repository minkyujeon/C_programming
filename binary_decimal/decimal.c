//10진수 입력, 2진수로 변환
#include<stdio.h>

void trans_to_binary(int num){
	int i=0,j=0,n=0;
	char bin[32]={0};
	int a=0;
	
	while(1){
		if(num<1)
			break;
		else
			bin[n]=num%2+'0';
		num=(num/2);//입력받은 10진수를 2로 나눈 몫
		n++;
		//printf("num : %d\n",num);
	}
	for(i=n;i>=0;i--)
		printf("%c ",bin[i]);
}
