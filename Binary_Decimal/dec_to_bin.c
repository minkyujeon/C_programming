#include <stdio.h>

void trans_to_binary(int num);

int main(void){
	int num=0;
	int i=0,j=0;

	printf("10진수를 입력하시오 : ");
	scanf("%d",&num,sizeof(num));
	trans_to_binary(num);
}

//10진수를 2진수로 변경하는 함수
void trans_to_binary(int num){
	int i=0,j=0,n=0;
	char bin[32]={0};
	int a=0;
	
	while(1){
		if(num<1)
			break;
		else
			bin[n]=num%2+'0';
		num=(num/2);
		n++;
		//printf("num : %d\n",num);
	}
	for(i=n;i>=0;i--)
		printf("%c ",bin[i]);
}