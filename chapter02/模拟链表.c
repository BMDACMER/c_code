#include<stdio.h>
#include<stdlib.h>
#define N 101
 
int main()
{
   int data[N],right[N];
   int i,n,t,len;
   //�������е�����
   scanf("%d",&n);
   for(i=1;i<=n;i++)
    scanf("%d",&data[i]);
   len=n;
   //��ʼ������right
   for(i=1;i<=n;i++)
   {
       if(i!=n)
        right[i]=i+1;
       else
        right[i]=0;
   }
   //ֱ��������data��ĩβ����һ����
   len++;
   scanf("%d",&data[len]);
   //�������ͷ����ʼ����
   t=1;
   while(t!=0)
   {
       if(data[right[t]]>data[len])   //�ҵ�Ҫ����Ľڵ��λ��
       {
           right[len]=right[t];    //�²���ڵ����һ���ڵ㼴Ϊ��ǰ�ڵ����һ���ڵ�
           right[t]=len;            //��ǰ�ڵ����һ���ڵ�Ϊ�²���ڵ�
           break;
       }
       t=right[t];       //����ѭ�����൱�������е�p=p->next
   }
   //��������е����е���
   t=1;
   while(t!=0)
   {
      printf("%d  ",data[t]);
       t=right[t];           // �൱�������е�p=p->next    
   }
    printf("\n");
    return 0;
}
