#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#define MaxVertexNum 100//最大顶点数设置为100
int visited[100];//存储标志向量
typedef char VertexType;//顶点类型设置为字符型
typedef int EdgeType;//边的权值设置为整形
typedef struct
{
    VertexType vexs[MaxVertexNum];//顶点表
    EdgeType edges[MaxVertexNum][MaxVertexNum];//邻接矩阵，即边表
    int n,e;//顶点数和边数
}MGraph;//MGraph是以邻接矩阵存储的图类型
#define MAXSIZE 1024
typedef int elemtype;
typedef struct SequenQueue
{
    elemtype data[MAXSIZE];
    int front1;//头指针
    int rear;//尾指真
}SequenQueue;
void BFSM(MGraph *G,int k);
void BFSTraverseAL(MGraph *G);
//初始化
SequenQueue* Init_SequenQueue()
{
    SequenQueue *Q;
    Q=(SequenQueue*)malloc(sizeof(SequenQueue));
    Q->front1=0;
    Q->rear=0;
    return Q;//返回循环队列的首地址
}
//队列是否为空
int SequenQueue_Empty(SequenQueue* Q)
{
    if(Q->front1==Q->rear)
        return 1;//队列为空，返回1
    else
        return 0;
}
//遍历所有的元素

void Print_SequenQueue(SequenQueue *q)
{
	SequenQueue *temp;
	int front1;
	temp=q;
	front1=temp->front1;

	while((front1+1)%MAXSIZE!=temp->rear+1)
	{
		printf("现在temp-》front为%d，rear为%d",front1,temp->rear);
		printf("\n%d\n",temp->data[temp->front1]);
		front1++;
	}
}
//判断队列是否满了
int SequenQueue_Full(SequenQueue *q)
{
    if((q->rear+1)%MAXSIZE==q->front1)
        return 1;//如果相等，则队列已经满了
    else
        return 0;

}
//球循环队列的长度
int SequenQueue_Length(SequenQueue *q)
{
    return (q->rear-q->front1);
}
//入队
int Enter_SequenQueue(SequenQueue*q,elemtype x)
{
    if(SequenQueue_Full(q))
    {
        printf("队列已满");
        return 0;//入队失败，返回0
    }
    else{
        q->data[q->rear]=x;
        q->rear=(q->rear+1)%MAXSIZE;
        return 1;
    }


}
//出兑
int Delete_SequenQueue(SequenQueue *q,elemtype *x)
{
    if(q->front1==q->rear)
    {
        printf("队列为空");
        return 0;
    }
    else
    {
        *x=q->data[q->front1];
        q->front1=(q->front1+1)%MAXSIZE;
        return 1;
    }
}
//取栈顶元素
int GetFront_SequenQueue(SequenQueue *q,elemtype *x)
{
    if(q->front1==q->rear)
    {
        printf("队列为空");
        return 0;
    }
    else
    {
        *x=q->data[q->front1];
        return 1;

    }
}
void CreateMGraph(MGraph *G)
{
    int i,j,k;
    printf("请输入顶点数和边数（输入格式为顶点数，边数）\n");
    scanf("%d%d",&(G->n),&(G->e));//输入顶点数和边数
    printf("请输入顶点信息\n");
    fflush(stdin);
    for(i=0;i<G->n;i++)
    {
        scanf("\n%c",&(G->vexs[i]));//输入顶点信息，建立顶点信息表
    }
    printf("您简历的顶点信息为\n");
    for(i=0;i<G->n;i++)
        printf("%5c",G->vexs[i]);
    fflush(stdin);
    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
            G->edges[i][j]=0;//初始化邻接矩阵
    printf("请输入每条边对应的两个顶点的序号(输入格式为)\n");
    printf("边数为%d\n",G->e);
    for(k=0;k<G->e;k++)
    {
        scanf("%d,%d",&i,&j);//输入e条边，建立邻接矩阵
        G->edges[i][j]=1;
    }
}
void BFSTraverseAL(MGraph *G)
{
    int i;
    for(i=0;i<G->n;i++)
        visited[i]=0;//标志变量初始化
    for(i=0;i<G->n;i++)
        if(!visited[i])
            BFSM(G,i);//vi围城访问，进行bfs搜索
}
void BFSM(MGraph *G,int k)
{
    int i,j;
    SequenQueue *Q;
    Q=Init_SequenQueue();
    printf("访问%c\n",G->vexs[k]);//访问原点vk
    visited[k]=1;
    Enter_SequenQueue(Q,k);//入队
    while(!SequenQueue_Empty(Q))
    {
        Delete_SequenQueue(Q,&i);//出兑
        for(j=0;j<G->n;j++)
        {
            if(G->edges[i][j]==1 && !visited[j])//如果vj为访问，并且有
            {
                printf("访问%c\n",G->vexs[j]);//访问vj
                visited[j]=1;
                Enter_SequenQueue(Q,j);//访问过的vj入队
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
    printf("下面开始进行广度优先搜索\n");
    BFSTraverseAL(&G);
    return 0;
}
