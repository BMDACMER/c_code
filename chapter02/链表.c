#include <stdio.h>
#include <stdlib.h>

//���ﴴ��һ���ṹ��������ʾ����Ľ������
typedef struct node
{
	int data;
	struct node *next;
}List;
int main()
{
	List *head,*p,*q,*t;
	int i,n,a;
	scanf("%d",&n);
	head = NULL;//ͷָ���ʼΪ��
	for(i=1;i<=n;i++)//ѭ������n����
	{
		scanf("%d",&a);
		//��̬����һ���ռ䣬�������һ����㣬������ʱָ��pָ��������
		p=(List *)malloc(sizeof(List));
		p->data=a;//�����ݴ洢����ǰ����data����
		p->next=NULL;//���õ�ǰ���ĺ��ָ��ָ��գ�Ҳ���ǵ�ǰ������һ�����Ϊ��
		if(head==NULL)
			head=p;//������ǵ�һ�������Ľ�㣬��ͷָ��ָ��������
		else
			q->next=p;//������ǵ�һ�������Ľ�㣬����һ�����ĺ��ָ��ָ��ǰ���
			q=p;//ָ��qҲָ��ǰ���
	}
	printf("���������������֣�");
	scanf("%d",&a);//������������
	t=head;//������ͷ����ʼ����
	while(t!=NULL)//��û�е�������β����ʱ��ѭ��
	{
		if(t->next->data > a)//�����ǰ�����һ������ֵ���ڴ����������������뵽�м�
		{
			p=(List *)malloc(sizeof(List));//��̬����һ���ռ䣬��������������	
			p->data=a;
			p->next=t->next;//�������ĺ��ָ��ָ��ǰ���ĺ��ָ����ָ��Ľ��
			t->next=p;//��ǰ���ĺ��ָ��ָ���������
			break;//��������˳�ѭ��
		}
		t=t->next;//������һ�����
	}
	//��������е�������
	t=head;
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;//������һ�����
	}
	printf("\n\n"); 
	// �ͷ�ָ�루free�ͷŵ�ָ������ָ��ָ����ڴ棬������void�� 
	free(head);
	free(p);
	free(q);
	free(t);
	
	return 0;
}
