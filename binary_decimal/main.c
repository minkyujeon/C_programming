#include<stdio.h>

void trans_to_binary(int num);
void trans_to_decimal(char binary_num[32]);

int main(void){
	int num=0;
	int i=0,j=0;
	char binary_num[32]={'1','1','1','0','0','0'};

	printf("10진수를 입력하시오 : ");
	scanf_s("%d",&num,sizeof(num));
	trans_to_binary(num);
	printf("\n");
	
	printf("2진수를 입력하시오 : ");
	trans_to_decimal(binary_num);

}