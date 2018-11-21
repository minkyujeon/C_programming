#include<stdio.h>

void input(char*str);
void output(char*str);
int mystrlen(char*str);
int check_str(char*str,char*pattern);
int my_strcmp(char*str,char*pattern);

int main(void){
	int i=0;
	int count=0;
	char*str={"0"};
	char*pattern={"0"};

	printf("문자열을 입력하시오 : ");
	input(str);
	printf("패턴을 입력하시오 : ");
	input(pattern);

	for(i=0;i<mystrlen(str)-mystrlen(pattern)+1;i++){
		if(check_str(&str[i],pattern)==1){	
			i+=mystrlen(pattern);
			count++;
		}
	}
	printf("패턴은 무엇입니까??");
	output(pattern);
	printf("\n");
	printf("몇 개의 패턴을 발견했습니까?");
	printf(" %d 개 \n",count);
}

void input(char*str){
	int i=0;
	while(1){
		str[i]=getchar();
		if(str[i]==10 || str[i]==13)
			break;
		i++;
	}
}

void output(char*str){
	int i=0;
	for(i=0;i<mystrlen(str);i++){
		printf("%c",str[i]);
	}
}

int mystrlen(char*str){ //문자열 길이
	int i=0;
	while(str[i]!='\0')
		i++;
	return i;
}

int check_str(char*str,char*pattern){
	int i=0;
	int a=0;
	if(str[0]!=pattern[0]) //우선 첫 글자가 다르면 볼것도 없음
		a=0;
	else{ //비교 시작
		a=my_strcmp(str,pattern);
	}
	return a;
}

int my_strcmp(char*str,char*pattern){
	int i=0;
	int a=0;
	for(i=0;i<mystrlen(pattern);i++){
		if(str[i]==pattern[i])
			a=1;
		else a=0;
	}
	return a;			
}