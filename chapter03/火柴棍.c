#include <stdio.h>
#include <time.h>
 
// 本算法用来解决 火柴棒  枚举问题
// 问题描述  详见《啊哈！算法》 P67

// 该函数用来计数 每个数字需要的火柴根数 
int func(int x) 
{
	int num = 0;
	int f[10] = {
		6,2,5,5,4,5,6,3,7,6
	};                             // 用一个数组来记录0~9每个数字需要用到多少根火柴棍 
	
	while(x/10!=0)                // 如果x/10的商不等于0的话，说明这个数至少有两位 
	{
		// 获得x的末尾数字并将此数所需要用到的火柴棍根数累加到num中 
		num += f[x%10];
		x = x/10;
	}
	// 最后加上此时x所需要用到的火柴棍的根数（此时x一定是一位数）
	num += f[x];	
	return num;  // 返回需要火柴棍的总根数 
} 
 
int main(int argc, char *argv[])
{
	int a,b,c,m,i,sum=0;      // sum用来计数的，一次一定要初始化为0
	float start,finish;
	scanf("%d",&m);    // 读入火柴棍的个数
	start = clock();
	// 开始枚举a和b
	for(a=0;a<=1111;++a)
	{
		for(b=0;b<=1111;++b)
		{
			c = a+b;
			// func函数用来计算每一个数需要用到的火柴棍的总数
			// 当a使用的火柴根数 + b使用的火柴根数 + c使用的火柴根数之和恰好等于m-4时，则成功地找出了一组解
			if(func(a)+func(b)+func(c) == m-4)
			{
				printf("%d+%d=%d\n",a,b,c);
				sum++;
			} 
		}
		
	} 
	finish = clock();
	printf("\n一共可以拼出%d个不同的等式\n\n",sum);
	printf("总共用时%.3f秒\n\n",(finish-start)/1000);
	return 0;
}

