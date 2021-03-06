#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	//  算法改进  用book来标记互不相等的数
	int a[10],i,total=0,book[10],sum;
	double start,end;
	start = clock();
	for(a[1]=1;a[1]<=9;++a[1])  // 第一个数的百位
	for(a[2]=1;a[2]<=9;++a[2])  // 第一个数的十位 
	for(a[3]=1;a[3]<=9;++a[3])  // 第一个数的个位
	for(a[4]=1;a[4]<=9;++a[4])  // 第二个数的百位
	for(a[5]=1;a[5]<=9;++a[5])  // 第二个数的十位
	for(a[6]=1;a[6]<=9;++a[6])  // 第二个数的个位
	for(a[7]=1;a[7]<=9;++a[7])  // 第三个数的百位
	for(a[8]=1;a[8]<=9;++a[8])  // 第三个数的十位
	for(a[9]=1;a[9]<=9;++a[9])  // 第三个数的个位
	{
		for(i=1;i<10;++i)   // 初始化book数组
			book[i]=0;
		for(i=1;i<10;++i)   // 如果某个数出现过就标记一下 
			book[a[i]]=1;	 
			
		// 统计共出现了多少个不同的数
		sum = 0;
		for(i=1;i<10;++i)
			sum+=book[i];
		// 如果正好出现了9个不同的数，并且满足等式条件，则输出
		if(sum == 9 &&  a[1]*100+a[2]*10+a[3] + a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9])
		{
			total++;
			printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
		}		
	} 
	end = clock(); 
	printf("\ntotal=%d\n\n",total/2); 
	printf("total cost time:%lfs\n",(end-start)/1000);
	return 0;
}
