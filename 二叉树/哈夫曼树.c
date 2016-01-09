#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define N 100
typedef struct
{
    char cd[N];//��ŵ�ǰ�ڵ�Ĺ���������
    int start;//��Ź���������
}HCode;
typedef struct node
{
    double weight;//Ȩ��
    int parent;//˫�׽ڵ�
    int lchild;//���ӽڵ�
    int rchild;//�Һ��ӽڵ�
}HTNode;
void CreateHT(HTNode ht[],int n)//�����������
{
    int i,j,k,lnode,rnode;
    double min1,min2;
    for(i=0;i<2*n-1;i++)
    {
        //ht[i].parent=ht[i].lchild=ht[i].rchild[i]=-1;//���нڵ����ֵ��Ϊ-1
        ht[i].parent=-1;
        ht[i].lchild=-1;
        ht[i].rchild=-1;
    }
    for(i=n;i<2*n-1;i++)
    {
        min1=min2=300;
        lnode=rnode=-1;
        for(k=0;k<=i-1;k++)
            if(ht[k].parent==-1)
            {
                if(ht[k].weight<min1)
                {
                    min2=min1;rnode=lnode;
                    min1=ht[k].weight;lnode=k;
                }
                else if(ht[k].weight<min2)
                {
                    min2=ht[k].weight;rnode=k;
                }
            }
            ht[i].weight=ht[lnode].weight+ht[rnode].weight;
            ht[i].lchild=lnode;ht[i].rchild=rnode;
            ht[lnode].parent=i;ht[rnode].parent=i;
    }
}
void CreateHCode(HTNode ht[],HCode hcd[],int n)
{
    int i,f,c;
    int ii;
    HCode hc;
    for(i=0;i<n;i++)
    {
        hc.start=n;c=i;
        f=ht[i].parent;
		for(ii=0;ii<n;ii++)
			hc.cd[ii]=9;
        while(f!=-1)
        {
            printf("c=%d,ht[f].lchild=%d\n",c,ht[f].lchild);
            if(ht[f].lchild==c)
            {
                hc.cd[hc.start--]='0';
                printf("�����%dλ��%c\n",hc.start+1,hc.cd[hc.start+1]);
            }
            else
            {
                hc.cd[hc.start--]='1';
                printf("�����%dλ��%c\n",hc.start+1,hc.cd[hc.start+1]);
            }
            c=f;f=ht[f].parent;

        }
          for(ii=n;ii>0;ii--)
                printf("%c",hc.cd[ii]);
        printf("\n\n\n\n\n");
        printf("\n");
        hcd[i]=hc;
    }

}
int main()
{
    int ii,ij;
    HTNode ht[20];
	 HCode hcd[N];
        ht[0].weight=5;
        ht[1].weight=29;
        ht[2].weight=7;
        ht[3].weight=8;
        ht[4].weight=14;
        ht[5].weight=23;
        ht[6].weight=3;
        ht[7].weight=11;
    for(ii=0;ii<7;ii++)
        printf("%lf\n",ht[ii].weight);

    system("pause");
    CreateHT(ht,8);
   for(ii=0;ii<15;ii++)
        printf("%10lf%5d%5d%5d\n",ht[ii].weight,ht[ii].parent,ht[ii].lchild,ht[ii].rchild);
    system("pause");
   
    CreateHCode(ht,hcd,8);
    for(ii=0;ii<8;ii++)
    {
        for(ij=8;ij>0;ij--)
            printf("%c",hcd[ii].cd[ij]);
        printf("\n");
    }
}
