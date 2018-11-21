#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(void){
        int a;
        printf("wordfinder_201411802 전민규\n");
        for(a=1;a<=5;a++){

                int wordcount=0;
                int wordcount1=0;
                int h,i,j,k,b,d,e,f,g;
                int c=0;
                FILE*fp=NULL;
                fp=fopen("sample.txt","r");
                char word[30];//입력한 문자열 중에 단어
                char strTemp[255];//한줄
                char*token;//한 문장에서 단어단위로 나눈 단어
                int linecount=0;//라인 수
                int front=0;//앞글자
                char front1[10]={0};
                char back1[10]={0};
                int back=0;//뒷글자
                char str[20];//맨 처음에 입력하는 문자열
                printf("%d번째 검색 단어를 입력하세요 : ",a);

                //input 받는거 코딩해보기
                gets(str);//입력받아서
                for(b=0;;b++){//{front}word{back}
                        if(isalpha(str[0]))//첫글자가 알파벳
                                break;
                        else if(isdigit(str[b])){//b번째로 숫자가 나옴
                                front1[c]=str[b];
                                c++;
                        }
                        else if(str[b]=='}'){
                                front1[c]='\0';//숫자 찾기
                                b++;
                                c=0;
                                break;
                        }
                }
                for(;;b++){
                        if(str[b]=='{' || str[b]=='\0'){
                                word[c]='\0';
                                c=0;
                                break;
                        }
                        else{
							 word[c]=str[b];
                                c++;
                        }
                }
                for(;;b++){
                        if(str[b]=='\0')
                                break;
                        if(str[b]!='{' && isdigit(str[b])){
                                back1[c]=str[b];
                                c++;
                        }
                        else if(str[b]=='}'){
                                back1[c]='\0';
                                break;
                        }
                }
                front=atoi(front1);
                back=atoi(back1);

                printf("\nfront : %d       back : %d ",front,back);

                while(!feof(fp)){//파일의 끝까지 반복적으로 읽어들임
                        linecount++;//라인 수를 셈
                        wordcount1=0;
                        fgets(strTemp,sizeof(strTemp),fp);//파일에서 fgets로 한줄씩 받아오기
                        char*token=strtok(strTemp," ");//한줄을 단어단위로 나누기
                        while(token!=NULL){//한줄 단어가 끝날때 까지

                                //if(token[strlen(token)]=='\0'){
                                //
                                //}

                                int flag=0;//일치 여부를 저장하기 위한 변수
                                int tm=0;
                                for(k=0;k<strlen(word);k++){
                                        if(word[k]==token[front+k]){//token 첫번째에서 front만큼 뒤에있는게 word / flag가 마지막에만 0을 인정하게됨, 모두 0을 저장해야함..     
                                        }//일치할 경우

                                        else{
                                                flag=1;
                                               break;   //일치하지 않을 경우 (한번이라도 일치하지 않는다면 flag값이 0에서 1로 변경됨
                                        }
                                }

                                if(flag==0){
                                        if(strlen(token)==(front+back+strlen(word))){
                                                for(int t=0;t<strlen(token);t++){
                                                        if(token[t]=='\n'){
															     tm=1;
                                                        }
                                                        else{
                                                        }
                                                }
                                                        if(tm!=1){
                                                        if(wordcount1==0){
                                                                printf("\nline#%d: %s",linecount, token);
                                                                wordcount1++;
                                                        }
                                                        else{
                                                                printf(", %s",token);
                                                                wordcount1++;
                                                        }
                                                        wordcount++;
                                                }
                                        }

                                }
                                token=strtok(NULL," ");
                        }
                }

                fclose(fp);
                printf("\n\n총 %d개의 %s를 찾았습니다.\n",wordcount,str);
        }

        return 0;
}
                                                                  