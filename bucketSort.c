#include<stdio.h>
#include<string.h>
#define N 100
#define M 26

// 统计字符串中字母出现的个次数 (忽略大小写)
int main()
{
	char str[N];
	int count[M];
	int i,j=0;
//	scanf("%s",str);
	gets(str);
	for(i=0;i<M;++i)
		count[i]=0;
	
	for(i=0;i<strlen(str);++i)
	{
		if(str[i]>='a' && str[i]<='z')
			count[str[i]-97]++;
		else if(str[i]>='A' && str[i]<='Z')
			count[str[i]-65]++;	
	}	
	
	for(i=0;i<M;++i)
		if(count[i]!=0)
		{
			printf("%3c:%2d\t",i+65,count[i]);
			j++;
			if (j%5==0)
			{
				printf("\n");
				j = 0;
			}
		}
	return 0;
} 
