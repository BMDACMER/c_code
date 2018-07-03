#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	// 对5个数 进行全排列 
	int a,b,c,d,e;
	float start,finish;
	start = clock();
	for(a=1;a<=5;++a)
		for(b=1;b<=5;++b)
			for(c=1;c<=5;++c)
				for(d=1;d<=5;++d)
					for(e=1;e<=5;++e)
						if(a!=b && a!=c && a!=d && a!=e
		                        && b!=c && b!=d && b!=e
	     								&& c!=d && c!=e
										        && d!=e)
							printf("%d%d%d%d%d\n",a,b,c,d,e);
	finish = clock();
	printf("总耗时：%.5fs\n",(finish-start)/1000);
	return 0;
}
