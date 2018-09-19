#include<stdio.h>
#include<Windows.h>
#include<conio.h>

void getString(char *msg, char*str, int mode);
int mystrlen(char*str);
int compare(char * id, char *id_input);

int main(void){
	int i=0;
	char*id_input=NULL;
	char*pass_input=NULL;
	char * id="NULLNULL";
	char * password="123456789*";
	int result=0;


	getString("ID",id_input,0);
	printf("!!!\n");
	getString("Password",pass_input,1);
	result=compare(id,id_input);
	if(result==1)printf("맞습니다.\n");
	else printf("틀립니다.\n");
}

void getString(char *msg, char*str, int mode){
	//mode 1:일반 , 0 ==pw
	int i=0;
	printf("%s를 입력하시오 : \n",msg);
	if(mode==0) scanf_s("%s",str);
	else if(mode==1){
		for(i=0;str[i]==13;i++){
			str[i]=getch();
			printf("*");
			if(str[i]==13)	break;
			i++;
		}
	}
}

int mystrlen(char*str){
	int i=0;
	while(str[i]!='\0')
		i++;

	return i;
}
int compare(char * id, char *id_input){
	int i=0;

	if(mystrlen(id)!=mystrlen(id_input)) return 0; //틀리다

	for(i=0;id[i]!='\0';i++){
		if(id[i]==id_input[i])
			printf("%c == %c\n",id[i],id_input[i]);
	}

	if(i==mystrlen(id)) return 1;
	else return 0;
}


