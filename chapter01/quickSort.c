#include<stdio.h> 
#include<string.h>
#define N 100
 
void quickSort(int array[],int left,int right)
{ 
	int i = left;
	int j = right;
	int value = array[left],temp;    // 得到哨兵元素
	// 异常处理，保证right >= left 
	if(left>right)
		return;
	
	while(i < j)
	{
		// 从右向左找一个比基准数小的 
		while(value<=array[j] && i<j) j--;
		// 从左到右找一个比基数大的
		while(value>=array[i] && i<j)  i++;
		// 当i，j没相遇时  交换两者位置
		if(i < j)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
		
	}	
	// 最终基准归位 
	if(i == j)
	{
		array[left] = array[i];
		array[i] = value;
	} 
	
	// 递归调用基准数划分的左右两组序列
	quickSort(array,left,i-1);
	quickSort(array,i+1,right); 
	
}

void print(int array[],int len)
{
	int i;
	for(i=0;i<len;++i)
		printf("%d\t",array[i]);
}
int main()
{
	int n,i,array[N]; // n表示要输入排序元素的个数
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&array[i]);
	} 
	
	// 调用排序函数
	quickSort(array,0,n-1);
	//打印函数 
	print(array,n);
	printf("\n");
	return 0;
}

