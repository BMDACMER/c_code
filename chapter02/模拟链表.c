#include<stdio.h>
#include<stdlib.h>
#define N 101
 
int main()
{
   int data[N],right[N];
   int i,n,t,len;
   //读入已有的数据
   scanf("%d",&n);
   for(i=1;i<=n;i++)
    scanf("%d",&data[i]);
   len=n;
   //初始化数组right
   for(i=1;i<=n;i++)
   {
       if(i!=n)
        right[i]=i+1;
       else
        right[i]=0;
   }
   //直接在数组data的末尾增加一个数
   len++;
   scanf("%d",&data[len]);
   //从链表的头部开始遍历
   t=1;
   while(t!=0)
   {
       if(data[right[t]]>data[len])   //找到要插入的节点的位置
       {
           right[len]=right[t];    //新插入节点的下一个节点即为当前节点的下一个节点
           right[t]=len;            //当前节点的下一个节点为新插入节点
           break;
       }
       t=right[t];       //构成循环，相当于链表中的p=p->next
   }
   //输出链表中的所有的数
   t=1;
   while(t!=0)
   {
      printf("%d  ",data[t]);
       t=right[t];           // 相当于链表中的p=p->next    
   }
    printf("\n");
    return 0;
}
