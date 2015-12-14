//blog��http://sumenpuyuan.com/2015/11/23/%E8%BF%B7%E5%AE%AB%E9%97%AE%E9%A2%98%E6%9C%80%E4%BC%98%E8%A7%A3-%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0/
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
#include<windef.h>
#include<stdbool.h>
#include<wtypes.h>
# define MAX 64
# define M 8
# define N 8
int mg[M+2][N+2]=
{
    {1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,0,1},
	{1,0,1,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,1,1,1,1,1},
	{1,0,1,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};
typedef struct box
{
	int i;//��ǰ������к�
	int j;//��ǰ������к�
	int pre;//��·����һ�����ڶ����е��±�
}Box;
typedef struct
{
    Box data[MAX];
    int front,rear;//��ͷָ��Ͷ�βָ��
}QuType;
bool mgpath(int xi,int yi,int xe,int ye)//����·����xi��yi������xe��ye��
{
    int i,j,find=0,di;
    QuType qu;
    qu.front=qu.rear=-1;
    qu.rear++;
    qu.data[qu.rear].i=xi;
    qu.data[qu.rear].j=yi;//��xi����yi�����
    qu.data[qu.rear].pre=-1;
    mg[xi][yi]=-1;//���丳ֵ-1�������ظ�����
    while(qu.front!=qu.rear && !find)
    {
        qu.front++;//����
        i=qu.data[qu.front].i;
        j=qu.data[qu.front].j;
        if(i==xe && j==ye)
        {
            find=1;
            print(qu,qu.front);
            return true;
        }
        for(di=0;di<4;di++)
        {
            switch(di)
            {
                case 0:i=qu.data[qu.front].i-1;j=qu.data[qu.front].j;break;
                case 1:i=qu.data[qu.front].i;j=qu.data[qu.front].j+1;break;
                case 2:i=qu.data[qu.front].i+1;j=qu.data[qu.front].j;break;
                case 4:i=qu.data[qu.front].i;j=qu.data[qu.front].j-1;break;
            }
            if(mg[i][j]==0)
            {
                qu.rear++;//�������ڷ�����뵽������ȥ
                qu.data[qu.rear].i=i;
                qu.data[qu.rear].j=j;
                qu.data[qu.rear].pre=qu.front;//ָ����һ��������±�
                mg[i][j]=-1;
            }
        }

    }
    return false;//δ�ҵ�·��ʱ
}
void print(QuType qu,int front)
{
    int k=front,i,j,ns=0;
    printf("\n");
    do
    {
        j=k;
        k=qu.data[k].pre;
        qu.data[j].pre=-1;
    }
    while(k!=0);
    printf("�Թ�·������\n");

		      // printf("��");

            //printf("��");

    k=0;
    while(k<MAX)
    {
        if(qu.data[k].pre==-1 && qu.data[k].i<M+2 && qu.data[k].j<N+2)
        {

            mg[qu.data[k].i][qu.data[k].j]=2;
        }
        k++;
    }

    for(i=0;i<10;i++)
	{
	  for(j=0;j<10;j++)
	  {
		if(mg[i][j]==1)
		       printf("��");
		else if(mg[i][j]==2)
		       printf("��");
		else
		       printf("  ");
	  }
	 printf("\n");
	}
    printf("\n");
    k=0;
    while(k<MAX)
    {
        if(qu.data[k].pre==-1)
        {
            ns++;
            printf("\t(%d %d)",qu.data[k].i,qu.data[k].j);
            if(qu.data[k].i==8 && qu.data[k].j==8)
                break;
            if(ns%5==0)
                printf("\n");
        }
        k++;
    }
    printf("\n");


}
int main()
{
    if(!mgpath(1,1,M,N))
        printf("û�г�·");
}
