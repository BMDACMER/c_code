#include <stdio.h>

int count = 0;        // ����ȫ�ֱ��� ������¼�ƶ��Ĳ��� 

void hanoi(int n,char x,char y,char z)
{
	if(n==0)
	{
		/* ʲôҲ���� */
	}else{
		hanoi(n-1,x,z,y);
		printf("%c->%c\t",x,y);
		count++; 
		hanoi(n-1,z,y,x);
	}
}

int main()
{
	hanoi(3,'A','B','C');
	printf("\n\n");
	printf("�ܹ��ƶ���%d��\n\n",count);
	return 0;
}
