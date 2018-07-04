#include <stdio.h>
 
int a[10]={0},book[10]={0},n;

void dfs(int step)   // step表示现在站在第几个盒子面前
{
	int i;
	if(step==n+1)   // 如果站在第n+1个盒子面前，则表示前n个盒子已经放好扑克牌
	{
		// 输出一种排序（1~n号盒子的扑克牌编号）
		for(i=1;i<=n;++i)
			printf("%d",a[i]);
		printf("\n");	 
	} 
	
	// 此时站在第step个盒子面前，应该放哪张牌呢？
	// 按照1，2，3，。。。，n的顺序一一尝试
	for(i=1;i<=n;++i)
	{
		// 判断扑克牌i是否还在手上
		if(book[i]==0)    // book[i]等于0表示i号扑克牌在手上
		{
			// 开始尝试使用扑克牌
			a[step] = i;    // 将i号扑克牌放入到第step个盒子中
			book[i] = 1;    // 将book[i]设为1，表示i号扑克牌已经不再手上
			
			// 第step个盒子已经放好扑克牌没接下来需要走到下一个盒子面前
			dfs(step+1);   // 这里通过函数的递归调用来实现（自己调用自己）
			book[i] = 0;    // 这是非常关键的一步，一定要将刚才尝试的扑克牌收回，才能进行下一次尝试 
		} 
	} 
	return; 
} 

/*
	深度优先搜索的基本模型
	void dfs(int step)
	{
		判断边界
		尝试每一种可能  
		for(i=1;i<=n;++i)
		{
			继续下一步 dfs(step+1); 
		} 
		返回  return ;
	} 
*/

int main()
{
	printf("请输入1~9之间的整数\t");
	scanf("%d",&n);   // 输入的时候需要主要n为1~9之间的整数 
	dfs(1);     // 首先站在1号小盒子面前 
	printf("\n"); 
	return 0;
}
