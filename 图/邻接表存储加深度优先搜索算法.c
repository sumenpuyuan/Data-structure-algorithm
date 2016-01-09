#include<stdio.h>
#define MaxVertexNum 100//最大顶点数设置为100
typedef char VertexType;//顶点类型设置为字符型
typedef struct node
{
    int adjvex;//邻接点域
    struct node *next;//指向下一个邻接点的指针域
}EdgeNode;
int visited[100];
typedef struct vnode
{
    VertexType vertex;//顶点雨
    EdgeNode *firstedge;//边表头指针
}VertexNode;
typedef struct
{
    VertexNode adjlist[MaxVertexNum];//邻接表
    int n,e;//顶点数和边数
}ALGraph;//是以邻接表存储的图类型
void CreateALGraph(ALGraph *G)
{
    int i,k,j;
    EdgeNode *s;
    printf("请输入顶点数和边数\n");
    scanf("%d%d",&(G->n),&(G->e));//读入顶点数和边数
    printf("顶点数为%d，边数为R%d\n",G->n,G->e);
    printf("请输入顶点信息\n");
    for(i=0;i<G->n;i++)
    {

        scanf("\n%c",&G->adjlist[i].vertex);//读入顶点信息

        G->adjlist[i].firstedge=NULL;//顶点的边表头指针设为空
    }
    printf("建立的顶点表信息为\n");
    for(i=0;i<G->n;i++)
        printf("%5c",G->adjlist[i]);
    printf("请输入边的信息\n");
    for(k=0;k<G->e;k++)
    {
        fflush(stdin);
        scanf("%d,%d",&i,&j);//读入边的顶点序列号
        fflush(stdin);
        s=(EdgeNode *)malloc(sizeof(EdgeNode));
        s->adjvex=j;//邻接点序号为j
        s->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=s;
    }

}
void DFSAL(ALGraph *G,int i)
{
    EdgeNode *p;
    printf("访问%c\n",G->adjlist[i].vertex);//访问顶点
    visited[i]=1;//标记vi已经访问
    p=G->adjlist[i].firstedge;//去vi变标的头指针
    while(p!=NULL)
    {
        if(!visited[p->adjvex]);//若vj尚未访问，进行纵向搜索
            DFSAL(G,p->adjvex);
        p=p->next;//找vi的下一个邻接点
    }
}
void DFSTraverseAL(ALGraph *G)
{
    int i;
    for(i=0;i<G->n;i++)
        visited[i]=0;//标志向量初始化
    for(i=0;i<G->n;i++)
        if(!visited[i])
            DFSAL(G,i);
}

int main()
{
    ALGraph G;
    EdgeNode *temp;
    int ii,ij;
    CreateALGraph(&G);
    printf("建立的顶点信息为\n");
    for(ii=0;ii<G.n;ii++)
    {
        printf("%c   ",G.adjlist[ii].vertex);
        if(G.adjlist[ii].firstedge==NULL)
            printf("NULL\n");
        else
        {
            temp=G.adjlist[ii].firstedge;
            while(temp!=NULL)
            {
                printf("%5d",temp->adjvex);
                temp=temp->next;
            }
            printf("\n");
        }
    }
    printf("下面开始进行深度优先搜索\n");
    DFSTraverseAL(&G);

}
