#include <stdio.h>

// �׳� 

void prove(int n)
{
	if(n == 0)
	{
		printf("���ݲ���1���ó�P(%d)������\n",n);
	}else{
		prove(n - 1);
		printf("���ݲ���2������˵����P(%d)��������P(%d)Ҳ��������\n",n -1,n);
		printf("��ˣ�����˵��P(%d)�ǳ����ġ���\n",n);
	}
} 
int main(int argc, char *argv[])
{
	prove(2);
	return 0;
}
