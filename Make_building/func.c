#include"header.h"

int get_only_num(int limit)
{
	//숫자만 입력받도록 하는 함수
   char str[11] = "";
   char c = '0';
   int ok = 0;
   unsigned int num = 0;
   int i = 0, j = 0;

   while (!ok)
   {
      for (i = 0;; i++)
      {
         c = getchar();
         if (c == 10 || c == 13)
         {
            break;
         }

         if (c < '0' || c > '9')
         {
            printf("숫자가 아닌 값이 있습니다. 다시 입력하세요 \n");
            ok = 0;
            break;
         }

         if (i > limit)
         {
            printf("자리수 초과입니다. 다시 입력하세요 \n");
            ok = 0;
            break;
         }
         str[i] = c;
         ok = 1;
      }
      fflush(stdin);
   }

   //str에는 숫자만 저장되어 있으므로,  숫자로 변환. return 
   for (j = 0; j < i; j++)
   {
      num += str[j] - '0';
      num *= 10;
   }
   num = num / 10;

   return num;
}

int show_menu()
{
	//메뉴 출력
   int menu = 0;

   printf("##############################################\n");
   printf("1. 친구 리스트 생성　 　2. 친구 처음에 추가\n");
   printf("3. 친구 중간에 추가　   4. 친구 삭제\n");
   printf("5. 현재 상태 보이기     6. 종료\n");
   printf("##############################################\n");

   menu = get_only_num(1);
   return menu;
}

int mycompare(char*str,char*str2){
	int i=0,a=0;
	if(mystrlen(str)!=mystrlen(str2))
		a=0;
	else{
		for(i=0;i<mystrlen(str);i++)
			if(str[i]==str2[i])
				a=1;
			else
				a=2;
	}
	return a;//a가 1이면 두개가 같음
}

int mystrlen(char*str){//문자열 길이
	int i=0;
	while(str[i]!='\0')
		i++;
	return i;
}

void make_friend(Friend*Friends,Friend**head,Friend**tail){
	//list에 친구 추가
	Friends=(Friend*)malloc(sizeof(Friend));
	if(Friends==NULL){
		printf("에러!\n");
		exit(1);
	}
	printf("이름? ");
	fgets(Friends->name,20,stdin);
	printf("나이? ");
	Friends->age=get_only_num(1);
	printf("가진 돈?(만원 단위,999만원까지 가능) ");
	Friends->have_money=get_only_num(2);
	printf("성?(M,F둘 중 하나만 입력해주세요)");
	scanf_s("%c",&Friends->sex,sizeof(Friends->sex));
	getchar();//버퍼 지우기
	Friends->next=NULL;

	if(*head==NULL)
		(*head)=(*tail)=Friends;
	else{
		(*tail)->next=Friends;
		(*tail)=Friends;
	}
}

void add_friend_front(Friend**head){
	//친구를 list 앞부분에 추가하기
	Friend*new_Friend;
	new_Friend=(Friend*)malloc(sizeof(Friend));

	printf("이름? ");
	fgets(new_Friend->name,20,stdin);
	printf("나이? ");
	new_Friend->age=get_only_num(1);
	printf("가진 돈?(만원 단위,999만원까지 가능) ");
	new_Friend->have_money=get_only_num(2);
	printf("성?(M,F둘 중 하나만 입력해주세요)");
	scanf_s("%c",&new_Friend->sex,sizeof(new_Friend->sex));
	getchar();
	new_Friend->next=*head; //원래 head자리에 있던 것을 앞에 추가할 friend의 next가 가리키도록
	*head=new_Friend;
}

void add_friend_mid(Friend*pre){
	//친구를 list 중간에 추가하기
	Friend*new_Friend=(Friend*)malloc(sizeof(Friend));
	Friend*Friends_pre=(Friend*)malloc(sizeof(Friend));
	Friends_pre=NULL;

	printf("이름? ");
	fgets(new_Friend->name,20,stdin);
	printf("나이? ");
	new_Friend->age=get_only_num(1);
	printf("가진 돈?(만원 단위,999만원까지 가능) ");
	new_Friend->have_money=get_only_num(2);
	printf("성?(M,F둘 중 하나만 입력해주세요)");
	scanf_s("%c",&new_Friend->sex,sizeof(new_Friend->sex));
	getchar();

	new_Friend->next=Friends_pre->next;
	Friends_pre->next=new_Friend;
}

void delete_friend(Friend*Friends,Friend**head,Friend**tail){
	//친구 삭제
	Friend*Friends_pre=(Friend*)malloc(sizeof(Friend));
	char fname[20];//삭제할 친구 입력
	Friends_pre=NULL;

	printf("삭제 할 친구 이름은?");
	fgets(fname,20,stdin);
	Friends=*head;//처음부터 찾기 위함

	while(Friends!=NULL){
		//if(mycompare(fname,Friends->name)==1){
		if(strcmp(fname,Friends->name)==0){
			printf("%s\n",Friends->name);
			if(Friends==*head)//바로 처음 위치에 있는 친구 삭제
				*head=Friends->next; //다음 친구를 가리키게함
			else if(Friends==*tail){//마지막에 있는 친구 삭제
				Friends_pre->next=NULL;//맨 마지막 이전것의 next가 가리키는 것에 Null을 채우고
				*tail=Friends_pre;//tail의 위치를 바꿈
			}
			else//중간에 있는 친구 삭제
				Friends_pre->next=Friends->next;

			free(Friends);
			break;//조건 만족해서 찾으면 break
		}
		Friends_pre=Friends;
		Friends=Friends->next;//못찾으면 다음으로 넘어감
	}
}

void show_friend(Friend*Friends,Friend**head){
	//친구 list 출력
	Friends=*head;//처음으로 보냄
	if(*head==NULL)
		printf("리스트가 존재하지 않습니다.\n");
	else{
		while(Friends!=NULL){
			printf("~~~\n");
			printf("이름 : %s",Friends->name);
			printf("나이? : %d\n",Friends->age);
			printf("가진 돈? : %d\n",Friends->have_money);
			printf("성? : %c\n",Friends->sex);
			printf("\n");
			Friends=Friends->next;
		}
	}
}
