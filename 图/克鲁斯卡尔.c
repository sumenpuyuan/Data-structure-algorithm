#include <stdio.h>
#include <stdlib.h>
#define MaxVertemNum 1024
typedef struct
{
    int vex1;//边的起始顶点
    int vex2;//边的终止顶点
    int weight;//边的权值
}KEdge;
void kruskal(KEdge E[],int n,int e)
{
    int i,j,m1,m2,sn1,sn2,k;
    int vset[MaxVertemNum];//用于记录定点是否属于同一个集合的辅助数组
    for(i=0;i<n;i++)
    {
        vset[i]=i;
    }
    k=0;//表示当前构造最小生成树的第k条边，初值为0
    j=0;//e中边的下标
    for(j=0;j<e;j++)
    {
        m1=E[j].vex1;
        m2=E[j].vex2;
        sn1=vset[m1];
        sn2=vset[m2];
        if(sn1 != sn2)
        {
            printf("<%d %d> :%d\n",m1,m2,E[j].weight);
            k++;
            if(k==n-1)
                break;
            for(i=0;i<n;i++)
                if(vset[i] == sn1)
                    vset[i]=sn2;
        }
    }
}
int partition(KEdge E[],int i,int j)
{
    int temp=E[i].weight;
    KEdge atemp=E[i];
    while(i<j)
    {
        while (E[j].weight>=temp && i<j)
            j--;
        if(i<j)
            E[i++]=E[j];
        while( E[i].weight<=temp && i<j)
            i++;
        if(i<j)
            E[j--]=E[i];
    }
    E[i]=atemp;
    return i;
}
int QuickSort(KEdge E[],int i,int j)
{
    int k;
    if(i<j)
    {
        k=partition(E,i,j);
        QuickSort(E,i,k-1);
        QuickSort(E,k+1,j);
    }
}
int main()
{
    KEdge E[100];
    int n,ii,m,length;
    printf("请输入顶点数\n");
    scanf("%d",&m);
    printf("请输入边的条数\n");
    scanf("%d",&n);
    printf("请输入边的信息，格式为 起始顶点<空格>终止定点<空格>权值\n");
    for(ii=0;ii<n;ii++)
    {
        scanf("\n%d %d %d",&E[ii].vex1,&E[ii].vex2,&E[ii].weight);
    }
    length=ii;
    printf("原始数据位\n");
    for(ii=0;ii<length;ii++)
    {
         printf("%5d%5d%5d\n",E[ii].vex1,E[ii].vex2,E[ii].weight);
    }
    QuickSort(E,0,length-1);
    printf("调整后数据为\n");
    for(ii=0;ii<length;ii++)
    {
        printf("%5d%5d%5d\n",E[ii].vex1,E[ii].vex2,E[ii].weight);
    }
    kruskal(E,m,n);

    return 0;
}
