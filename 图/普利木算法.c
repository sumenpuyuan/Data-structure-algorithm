#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#define MaxVertexNum 100//最大顶点数设置为100
#define N 4000 //规定无穷的高达为40000
struct close
{
	int adjvex;
	int lowcost;
};
struct close closedge[MaxVertexNum];
typedef char VertexType;//顶点类型设置为字符型
typedef int EdgeType;//边的权值设置为整形
typedef struct
{
    VertexType vexs[MaxVertexNum];//顶点表
    EdgeType edges[MaxVertexNum][MaxVertexNum];//邻接矩阵，即边表
    int n,e;//顶点数和边数
}MGraph;//MGraph是以邻接矩阵存储的图类型
void CreateMGraph(MGraph *G)
{
    int i,j,k,quan;
    printf("请输入顶点数和边数（输入格式为顶点数<空格>边数）\n");
    scanf("%d%d",&(G->n),&(G->e));//输入顶点数和边数
    printf("请输入顶点信息，输入格式为顶点号<回车>\n");
    fflush(stdin);
    for(i=0;i<G->n;i++)
    {
        scanf("\n%c",&(G->vexs[i]));//输入顶点信息，建立顶点信息表
    }
    printf("您简历的顶点信息为\n");
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
                G->edges[i][j]=N;//初始化邻接矩阵
        }

    printf("请输入每条边对应的两个顶点的序号(输入格式为)起始顶点号,终止顶点号,权值\n");

    for(k=0;k<G->e;k++)
    {
        scanf("%d,%d,%d",&i,&j,&quan);//输入e条边，建立邻接矩阵
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
            printf("边（%d——%d）权值为%d\n",closest[k],k,min);
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
    printf("建立的顶点表为\n");
    for(ii=0;ii<G.n;ii++)
    {
        printf("%c\n",G.vexs[ii]);
    }
    printf("\n建立的邻接矩阵为\n");
    for(ii=0;ii<G.n;ii++)
    {
        for(ij=0;ij<G.n;ij++)
            printf("%5d",G.edges[ii][ij]);
        printf("\n");
    }
    Prim02(G,0);
}
