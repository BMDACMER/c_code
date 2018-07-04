#include <stdio.h>
#include <time.h>

int a[10]={0},i,total=0,book[10]={0};

void dfs(int step)   // step表示现在站在第几个盒子面前
{
	int i;
	if(step==10)  // 如果站在第10个盒子面前，则表示前9个盒子已经放好扑克牌
	{
		if(a[1]*100+a[2]*10+a[3] + a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9])
		{
			total++;
			printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
		}	
		return;         // 返回之前的一步（最近调用的地方） 
	} 
	
	// 此时站在第step个盒子面前，应该放哪张牌呢？
	// 按照1，2，3，。。。，n的顺序一一尝试
	for(i=1;i<=9;++i)
	{
		// 判断扑克牌i是否还在手上
		if(book[i]==0) // book[i]为0表示扑克牌还在手上
		{
			// 开始尝试使用扑克牌i
			a[step] = i;  // 将扑克牌i放入到第step个盒子中
			book[i] = 1;
			
			dfs(step+1);
			book[i]=0; 
		} 
	} 
	return;
} 

int main(int argc, char *argv[])
{
	double start,end;
	start = clock();
	dfs(1);    // 首先站在一个盒子面前 
	end = clock(); 
	printf("\ntotal=%d\n\n",total/2); 
	printf("total cost time:%lfs\n",(end-start)/1000);
	return 0;
}
