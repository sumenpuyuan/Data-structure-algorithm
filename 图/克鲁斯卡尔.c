#include <stdio.h>
#include <stdlib.h>
#define MaxVertemNum 1024
typedef struct
{
    int vex1;//�ߵ���ʼ����
    int vex2;//�ߵ���ֹ����
    int weight;//�ߵ�Ȩֵ
}KEdge;
void kruskal(KEdge E[],int n,int e)
{
    int i,j,m1,m2,sn1,sn2,k;
    int vset[MaxVertemNum];//���ڼ�¼�����Ƿ�����ͬһ�����ϵĸ�������
    for(i=0;i<n;i++)
    {
        vset[i]=i;
    }
    k=0;//��ʾ��ǰ������С�������ĵ�k���ߣ���ֵΪ0
    j=0;//e�бߵ��±�
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
    printf("�����붥����\n");
    scanf("%d",&m);
    printf("������ߵ�����\n");
    scanf("%d",&n);
    printf("������ߵ���Ϣ����ʽΪ ��ʼ����<�ո�>��ֹ����<�ո�>Ȩֵ\n");
    for(ii=0;ii<n;ii++)
    {
        scanf("\n%d %d %d",&E[ii].vex1,&E[ii].vex2,&E[ii].weight);
    }
    length=ii;
    printf("ԭʼ����λ\n");
    for(ii=0;ii<length;ii++)
    {
         printf("%5d%5d%5d\n",E[ii].vex1,E[ii].vex2,E[ii].weight);
    }
    QuickSort(E,0,length-1);
    printf("����������Ϊ\n");
    for(ii=0;ii<length;ii++)
    {
        printf("%5d%5d%5d\n",E[ii].vex1,E[ii].vex2,E[ii].weight);
    }
    kruskal(E,m,n);

    return 0;
}
