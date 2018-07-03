#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	// 对5个数 进行全排列 
	int a[6];  // 存放5位数 
	int sum,flag[6],i;
	float start,finish;
	start = clock();
	for(a[1]=1;a[1]<=5;++a[1])
		for(a[2]=1;a[2]<=5;++a[2])
			for(a[3]=1;a[3]<=5;++a[3])
				for(a[4]=1;a[4]<=5;++a[4])
					for(a[5]=1;a[5]<=5;++a[5])
					{
						for(i=1;i<=5;++i)  // 初始化flag数组 
							flag[i] = 0; 
						for(i=1;i<=5;++i)    // 如果某个数出现过就标记一下
							flag[a[i]]=1;
						sum = 0;	
						for(i=1;i<=5;++i)     
							sum += flag[i];    
						// 如果恰好出现了5个不同的数，并且满足条件，则输出
						if(sum==5)
						{
							printf("%d%d%d%d%d\n",a[1],a[2],a[3],a[4],a[5]);
						}		
					}
						
	finish = clock();
	printf("总耗时：%.5fs\n",(finish-start)/1000);
	return 0;
}
