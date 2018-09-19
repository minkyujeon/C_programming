#include <stdio.h>
#include <time.h>

int aker(int m, int n)
{
    int rst = 0;

    if (m == 0) //basecase
        rst = n + 1;
    else if (m > 0 & n == 0)
    {
        rst = aker(m - 1, 1);
    }
    else if (m > 0 & n > 0)
    {
        rst = aker(m - 1, aker(m, n - 1));
    }
    return rst;
}

int aker_2(int m, int n)
{
    int stack[100000] = {0}; //m값을 넣기(깊이를 표현)
    int state = 0;           //현재 깊이의 상태

    while (1)
    {
        if (m == 0)
        {
            n++;
            if (state == 0) //현재 깊이가 제일 밖!
                break;
            state = state - 1; //m이 0에 도달했을때 깊이를 하나 빠져 나가야함
            m = stack[state];  //m값에 깊이 1개 줄인 값을 넣음
        }
        else if (m > 0 && n == 0)
        {
            m--;
            n = 1;
        }
        else if (m > 0 & n > 0)
        {
            stack[state] = m - 1; //현재 상태의 m을 m-1로
            state = state + 1;    // 다음상태로 넘어가고
            stack[state] = m;     //넘어온 상태에 원래 m값을 넣어주기
            n--;                  //그 다음상태의 n=n-1로
        }
    }
    return n;
}

int main(void)
{
    int m = 0, n = 0;
    int num = 0, num_2 = 0;
    clock_t start, end;
    clock_t start1, end1;

    printf("m을 입력하시오 : ");
    scanf("%d", &m);
    printf("n을 입력하시오 : ");
    scanf("%d", &n);

    start = clock();
    num = aker(m, n);
    end = clock();

    start1 = clock();
    num_2 = aker_2(m, n);
    end1 = clock();

    printf("aker(재귀) : %d, 시간 : %f\n", num, (double)(end - start) / CLOCKS_PER_SEC);
    printf("aker_2(반복문) : %d, 시간 : %lf\n", num_2, (double)(end1 - start1) / CLOCKS_PER_SEC);
    return 0;
}
