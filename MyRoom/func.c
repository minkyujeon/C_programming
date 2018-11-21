#include"header.h"

int menu_list(void){
	int menu=0;
	printf("=======MY_Room_mate======\n");
	printf("1.my_room만들기 \n");
	printf("2.my_room크기 변경하기 \n");
	printf("3.room mate 추가하기\n");
	printf("4.room mate 이사하기\n");
	printf("5.my room 이사하기\n");
	printf("6.현재 room 상황 출력\n");
	printf("7.종료\n");
	printf("=========================\n");
	printf("메뉴를 선택하시오 : ");
	scanf_s("%d",&menu,sizeof(menu));
	return menu;
}


void make_room_p(char ***room,int size){//처음 방 만들기(방 주소를 인자로)
	int i=0;
	*room=(char**)malloc(sizeof(char*)*size);// room을 이중포인터형으로 선언해줬기에 (char**)malloc도 이중포인터로!
	memset(*room,0x0,sizeof(char*)*size);//0으로 초기화
	for(i=0;i<size;i++){
		(*room)[i]=make_friend();//*(*(room)+i)=make_friend()와 같은표현
	}
	show_room(*room);
}

char *make_friend(void){
	int size=0,i=0;
	char*name=NULL;
	//printf("친구 이름이 몇 글자 인가요?");
	//scanf_s("%d",&size,sizeof(size));
	//name=(char*)malloc(sizeof(char)*size*2+1);//한글이기 때문+널문자
	printf("친구이름을 입력하시오 : ");
	printf("!!\n");
	fseek(stdin,0,SEEK_END);
	//scanf_s("%s",name,(sizeof(char)*size*2)+1);//크기만큼 입력받기 주의!!!
	mystring(&name);
	return name;
}

void size_trans(char***room,int size_after){//더블포인터의 주소를 받아야!(크기를 바꾸기위해)  (나의 위치를 보내야함) 디버그
	int i=0,j=0;
	int size=0;
	size=_msize(*room)/4;//원래 층 크기
	printf("msize 원래 : %d \n",size);
	*room=(char**)realloc(*room,sizeof(char*)*size_after);
	size_after=_msize(*room)/4;//결국 입력받은 size_after와 같음
	printf("msize 나중: %d \n",size_after);
	if(size<size_after){
		for(i=size;i<size_after;i++){
			*((*room)+i)=NULL;//room[0][i], (*room)[i]=NULL과 같은표현
			printf("%p\n",**room);
		}
	}
}

void move_mate(char***room){
	int i=0,length=0;
	char*friend_name=NULL;
	show_room(*room);
	printf("친구 이름이 몇글자인가요?");
	scanf_s("%d",&length,sizeof(length));
	friend_name=(char*)malloc(sizeof(char)*length*2+1);//한글이기 때문+널문자 입력할 때 곱하기2*"글씨 길이"+1 해줘야함!!
	printf("이사 갈 친구이름 : ");
	scanf_s("%s",friend_name,(sizeof(char)*length*2+1));//크기만큼 입력받기 주의!!!
	for(i=0;i<_msize(*room)/4;i++){
		if(mycompare(*(*(room)+i),friend_name)==1){
			*(*(room)+i)=NULL;
			printf("이사갑니다.\n");
		}
	}
	Sleep(2000);
}

void move_room(char**room){
	int i=0,j=0;
	char*temp=NULL;
	show_room(room);
	printf("몇 번 방에있는 사람을 내보내겠습니까?");
	scanf_s("%d",&i,sizeof(i));
	printf("몇 번 방으로 보내겠습니까?");
	scanf_s("%d",&j,sizeof(j));
	if(room[j]!=NULL)
		printf("그 방은 불가합니다. 다시 골라주세요\n");
	else{
		temp=room[i];//room의 i번째 방이 가리키고 있는 주소의 값을 변경
		room[i]=room[i];
		room[j]=temp;
		room[i]=NULL;
	}
}

void show_room(char**room){
	int i;
	for(i=0;i<_msize(room)/sizeof(char*);i++)
		printf("Room[%d] : %p %s\n",i,*(room+i),*(room+i));
}

int input(void){
	int num=0;
	printf("방 몇개로? : ");
	scanf_s("%d",&num,sizeof(num));
	return num;
}

int mystrlen(char*str){//문자열 길이
	int i=0;
	while(str[i]!='\0')
		i++;
	return i;
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

void mystring(char**str){
	char ch;
	int count=0;
	*str=(char*)malloc(sizeof(char*)*30);
	memset(*str,0x0,sizeof(char*)*30);
	while(1){
		if(count==30){
				printf("더 이상 입력받을 수 없습니다.\n");
				break;
		}
		ch=getche();
		if(ch==13 || ch==10){
			printf("\n");
			break;
		}
		(*str)[count]=ch;
		count++;
		if(kbhit()){
			ch=getche();
			(*str)[count]=ch;
			count++;
		}
	}
	str[count]='\0';
	//printf("문자열 길이 : %d\n",mystrlen(*str));
}