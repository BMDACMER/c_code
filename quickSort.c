#include<stdio.h> 
#include<string.h>
#define N 100
 
void quickSort(int array[],int left,int right)
{ 
	int i = left;
	int j = right;
	int value = array[left],temp;    // �õ��ڱ�Ԫ��
	// �쳣������֤right >= left 
	if(left>right)
		return;
	
	while(i < j)
	{
		// ����������һ���Ȼ�׼��С�� 
		while(value<=array[j] && i<j) j--;
		// ��������һ���Ȼ������
		while(value>=array[i] && i<j)  i++;
		// ��i��jû����ʱ  ��������λ��
		if(i < j)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
		
	}	
	// ���ջ�׼��λ 
	if(i == j)
	{
		array[left] = array[i];
		array[i] = value;
	} 
	
	// �ݹ���û�׼�����ֵ�������������
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
	int n,i,array[N]; // n��ʾҪ��������Ԫ�صĸ���
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&array[i]);
	} 
	
	// ����������
	quickSort(array,0,n-1);
	//��ӡ���� 
	print(array,n);
	printf("\n");
	return 0;
}

