#include <stdio.h>
void int_pointer(void)
{
    int i = 100;
    int ar[3] = {1, 2, 3};
    int ar_2[5][3] = {{1, 2, 3}, {10, 20, 30}, {100, 200, 300}, {1000, 2000, 3000}, {10000, 20000, 30000}};

    printf("i의 주소값은 %p, i의 값은 : %d \n", &i, i);
    printf("ar의 주소값 : %x \n", &ar);
    printf("ar[0]의 주소값 : %x \n", &ar[0]);
    printf("ar[0]의 값 : %x \n", ar[0]);
    printf("ar[1]의 주소값 : %x \n", &ar[1]);
    printf("ar[1]의 값 : %x \n", ar[1]);
    printf("ar[2]의 주소값 : %x \n", &ar[2]);
    printf("ar[2]의 값 : %x \n", ar[2]);

    printf("-------------------------------\n");
}
int main(void)
{
    //1차원 정수배열
    int ar[3] = {10, 20, 30};
    //위와 유사하게 사용되는 1차원 정수포인터
    int *p_ar[3] = {10, 20, 30};
    int *p;

    //1차원 문자배열
    char str[5] = "abcd";

    //문자배열과 유사하게 사용되는 1차포인터
    char *pstr = "ABCD";

    //2차원 문자배열
    char *suit[4] = {"Flowers!!", "Diamond!!", "Money!!", NULL};
    char *q = suit; //q도 출력해보세요!

    // ar이 저장된 메모리 주소.
    // ar[0] 이 저장된 주소 : %p
    // ar[0] 에 들어있는 값 : %d

    int_pointer();

    // str의 실제 메모리 주소
    // str에 저장된 값 : 주소
    // str에 들어있는 값 전체 : %s 문자열
    // str[0]이 저장된 실제 메모리 주소 ,
    // str[0]에 들어있는 값 : %c

    printf("##### char str[5]=\"abcd\"; 일 때 \n");
    printf(" str의 주소 : %p \n", &str);
    printf(" str의 값: %p \n", str);
    printf(" str[0]의 주소 : %p \n", &str[0]);
    printf(" str[0]의 값 : %c \n", str[0]);

    printf("\n ##### char *pstr=\"ABCD\"; 일 때 \n");
    printf(" pstr의 주소 : %p \n", &pstr);
    printf(" pstr의 값: %p \n", pstr);
    printf(" &(*pstr) == pstr[0]의 주소 : %p %p \n", &(*pstr), &pstr[0]);
    printf(" *pstr == pstr[0]의 값 : %c %c \n", *pstr, pstr[0]);
    printf(" &(*(pstr+1)) == pstr[1]의 주소 : %p %p \n", &(*(pstr + 1)), &pstr[1]);
    printf(" *(pstr+1) == pstr[1]의 값 : %c %c \n", *(pstr + 1), pstr[1]);
    printf("\n ##### char *suit[4]={\"Flowers!!\",\"Diamond!!\",\"Money!!\", NULL}; 일 때 \n");
    printf(" suit의 주소 : %p \n", &suit);
    printf(" suit[0]의 주소 : %p \n", &suit[0]);
    printf("----------------------------------------------------------------\n");

    printf("# 변수이름/표현 | 변수값의 type | 값 | 퍼센트c 또는, s 로 찍으면 \n");
    printf(" suit[0] 주소 %p %s \n", suit[0], suit[0]);
    printf(" suit[1] 주소 %p %s \n", suit[1], suit[1]);
    printf(" suit[2] 주소 %p %s \n", suit[2], suit[2]);
    printf(" *suit[0] char ---- %c \n", *suit[0]);
    printf(" *suit[1] char ---- %c \n", *suit[1]);
    printf(" *suit[2] char ---- %c \n", *suit[2]);
    printf(" *(suit+0) 주소 %p %s \n", *(suit + 0), *(suit + 0));
    printf(" *(suit+1) 주소 %p %s \n", *(suit + 1), *(suit + 1));
    printf(" *(suit+2) 주소 %p %s \n", *(suit + 2), *(suit + 2));
    printf(" suit[1][3] char ---- %c \n", suit[1][3]);
    printf(" &suit[1][3] 주소 %p %s \n", &suit[1][3], &suit[1][3]);
    printf(" *(suit+1)+3 주소 %p %s \n", (*(suit + 1) + 3), (*(suit + 1) + 3));
    printf(" *(*(suit+1)+3) char ---- %c \n", *(*(suit + 1) + 3), *(*(suit + 1) + 3));

    return 0;
}
