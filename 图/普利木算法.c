#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#define MaxVertexNum 100//��󶥵�������Ϊ100
#define N 4000 //�涨����ĸߴ�Ϊ40000
struct close
{
	int adjvex;
	int lowcost;
};
struct close closedge[MaxVertexNum];
typedef char VertexType;//������������Ϊ�ַ���
typedef int EdgeType;//�ߵ�Ȩֵ����Ϊ����
typedef struct
{
    VertexType vexs[MaxVertexNum];//�����
    EdgeType edges[MaxVertexNum][MaxVertexNum];//�ڽӾ��󣬼��߱�
    int n,e;//�������ͱ���
}MGraph;//MGraph�����ڽӾ���洢��ͼ����
void CreateMGraph(MGraph *G)
{
    int i,j,k,quan;
    printf("�����붥�����ͱ����������ʽΪ������<�ո�>������\n");
    scanf("%d%d",&(G->n),&(G->e));//���붥�����ͱ���
    printf("�����붥����Ϣ�������ʽΪ�����<�س�>\n");
    fflush(stdin);
    for(i=0;i<G->n;i++)
    {
        scanf("\n%c",&(G->vexs[i]));//���붥����Ϣ������������Ϣ��
    }
    printf("�������Ķ�����ϢΪ\n");
    for(i=0;i<G->n;i++)
        printf("%5c",G->vexs[i]);
    printf("\n");
    fflush(stdin);
    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
        {
            if(i==j)
                G->edges[i][j]=0;
            else
                G->edges[i][j]=N;//��ʼ���ڽӾ���
        }

    printf("������ÿ���߶�Ӧ��������������(�����ʽΪ)��ʼ�����,��ֹ�����,Ȩֵ\n");

    for(k=0;k<G->e;k++)
    {
        scanf("%d,%d,%d",&i,&j,&quan);//����e���ߣ������ڽӾ���
        G->edges[i][j]=quan;
        G->edges[j][i]=quan;
    }
}
void Prim02(MGraph g,int v)
{
    int lowcost[N];
    int closest[N],i,j,k;
    int min;
    for(i=0;i<g.n;i++)
    {
        lowcost[i]=g.edges[v][i];
        closest[i]=v;
    }
    for(i=0;i<g.n;i++)
        printf("%5d",lowcost[i]);
    printf("\n");
    for(i=1;i<g.n;i++)
    {
        min=N;
        for(j=0;j<g.n;j++)
        {
            if(lowcost[j] != 0 && lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
        }
            printf("�ߣ�%d����%d��ȨֵΪ%d\n",closest[k],k,min);
            lowcost[k]=0;
            for(j=0;j<g.n;j++)
            {
                if(g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j])
                {
                    lowcost[j]=g.edges[k][j];
                    closest[j]=k;
                }
            }

    }
}
int main()
{
	MGraph G;
    int ii,ij;
    CreateMGraph(&G);
    printf("�����Ķ����Ϊ\n");
    for(ii=0;ii<G.n;ii++)
    {
        printf("%c\n",G.vexs[ii]);
    }
    printf("\n�������ڽӾ���Ϊ\n");
    for(ii=0;ii<G.n;ii++)
    {
        for(ij=0;ij<G.n;ij++)
            printf("%5d",G.edges[ii][ij]);
        printf("\n");
    }
    Prim02(G,0);
}
