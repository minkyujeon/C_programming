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
	int x = 0, y = 0, xt = 1, yt = 1, a = 30, b = 23; //a,b : the point of bar
	print_box(); //print edge
	Color(15);
	printf("Stop if you push esc \n"); 
	printf("Shot the ball : space bar ");
	cursor(); //Remove cursor
	bar(a, '-'); //print bar
	brick(random(), 5);

	while (1)
	{

		if (GetAsyncKeyState(ESC) < 0) // Stop if you push ESC
		{
			printf("Quit.");
			break;
		}
		if (GetAsyncKeyState(SPACE) < 0)
		//Space bar to shot the ball
		{
			gotoxy(a, b);
			x = a + 7; //middle of bar
			y = b - 1;

			while (1)
			{
				delete_bar(a);//remove bar
				if (GetAsyncKeyState(ESC) < 0) //stop if  you push ESC
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
				bar(a, '-');//print bar
				print_dot(x, y, " ");
				x += xt;
				y -= yt;
				if (y == MINX + 1 || y == MAXX - 1)
				//reach ceiling or bottom - edge, ball are 2byte -> tuning size
				{
					if (y == MAXX - 1)
					{
						system("cls");
						Color(13);
						printf("game over ! ");
						break;
					}
					else
						yt *= -1; //y direction is change, x direction is same
				}
				if (x == MINY + 2 || x == MAXY - 3)//reach left edge or right edge
				{
					xt *= -1;//x direction is change, y direction is same
				}
				if ((x > a - 2 && x < a + 17) && (y > b - 2 && y < b + 2))//ball shape is 2byte
				//cannot get down the bar
				{
					yt *= -1;
				}
				Color(15);//white color
				print_dot(x, y, "?");
				Sleep(30);
			}
		}
	}
	return 0;
}
