#include <stdio.h>
#include <windows.h>
#define N 50

// (x,y)---小球的位置    （p,q）-------迷宫出口 

int main(int argc, char *argv[])
{
	char a[N][N]={
		"######",
		"#o #  ",
		"# ## #",
		"#  # #",
		"##   #",
		"######",
	};
	int i,x,y,p,q;
	char ch;
	
	x=1;y=1;p=1;q=5;
	for(i=0;i<=5;++i)
		puts(a[i]);
	
	while(x!=p || y!=q)
	{
		ch=getch();
		
		if(ch=='s' || ch=='S')
		{
			if(a[x+1][y]!='#')
			{
				a[x][y]=' ';
				x++;
				a[x][y]='o';
			}
		}
		
		if(ch=='w' || ch=='W')
		{
			if(a[x-1][y]!='#')
			{
				a[x][y]=' ';
				x--;
				a[x][y]='o';
			}
		}
		
		if(ch=='a' || ch=='A')
		{
			if(a[x][y-1]!='#')
			{
				a[x][y]=' ';
				y--;
				a[x][y]='o';
			}
		}
		
		if(ch=='d' || ch=='D')
		{
			if(a[x][y+1]!='#')
			{
				a[x][y]=' ';
				y++;
				a[x][y]='o';
			}
		}
		
		system("cls");
		for(i=0;i<=5;i++)
			puts(a[i]);
	}
	
	system("cls");
	printf("You win!\n");	
	Sleep(4000);	
	return 0;
}
