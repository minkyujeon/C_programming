#include "head.h"
#include "fun.h"

#define MINX 1
#define MINY 1
#define MAXX 25
#define MAXY 80
#define ESC 27
#define ENTER 13
#define SPACE 32

int main(void)
{
	int x = 0, y = 0, xt = 1, yt = 1, a = 30, b = 23; //a,b?? ???? ???
	print_box();									  //??еш? ???
	Color(15);
	printf("????????? esc?? ???????? \n"); //??еш? ????? ???????
	printf("?? ??? : space bar ");
	cursor();	//ии?? ?????
	bar(a, '-'); //bar ???
	brick(random(), 5);

	while (1)
	{

		if (GetAsyncKeyState(ESC) < 0)
		{
			printf("????????.");
			break;
		}
		if (GetAsyncKeyState(SPACE) < 0)
		{
			gotoxy(a, b);
			x = a + 7;
			y = b - 1;

			while (1)
			{
				delete_bar(a);
				if (GetAsyncKeyState(ESC) < 0)
					break;

				if (GetAsyncKeyState(VK_LEFT) < 0)
				{
					if (a == MINY + 2)
						a = MINY + 2;
					else
						a--;
				}
				if (GetAsyncKeyState(VK_RIGHT) < 0)
				{
					if (a + 15 == MAXY - 1)
						a = MAXY - 16;
					else
						a++;
				}
				bar(a, '-');
				print_dot(x, y, " ");
				x += xt;
				y -= yt;
				if (y == MINX + 1 || y == MAXX - 1)
				{
					if (y == MAXX - 1)
					{
						system("cls");
						Color(13);
						printf("???????? ! ");
						break;
					}
					else
						yt *= -1;
				}
				if (x == MINY + 2 || x == MAXY - 3)
				{
					xt *= -1;
				}
				if ((x > a - 2 && x < a + 17) && (y > b - 2 && y < b + 2))
				{
					yt *= -1;
				}
				Color(15);
				print_dot(x, y, "??");
				Sleep(30);
			}
		}
	}
	return 0;
}