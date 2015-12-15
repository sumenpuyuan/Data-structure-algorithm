#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100//最大顶点数设置为100
typedef int VertexType;//顶点类型设置为字符型
int indegree[100];
#define N 100
typedef struct node
{
    int adjvex;//邻接点域
    int adjvexb;//逆的
    struct node *next;//指向下一个邻接点的指针域
    struct node *nextb;//指向逆的下一个指针
}EdgeNode;
int visited[100];
typedef struct vnode
{
    VertexType vertex;//顶点雨
    EdgeNode *firstedge;//边表头指针
    EdgeNode *firstedgeb;//指向逆的边表头指针
}VertexNode;
typedef struct
{
    VertexNode adjlist[MaxVertexNum];//邻接表
    VertexNode adjlistb[MaxVertexNum];//逆
    int n,e;//顶点数和边数
}ALGraph;//是以邻接表存储的图类型
//来吧，开始写栈的信息
typedef struct SequenStack
{
    int data[N];
    int top;//栈顶指针
}SequenStack;
//初始化栈
SequenStack * Init_SequenStack()
{
    SequenStack *s;
    s=(SequenStack *)malloc(sizeof(SequenStack));
    s->top=-1;
    return s;
}
//判断栈空
int SequenStack_Empty(SequenStack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
//判断栈满
int SequenStack_Full(SequenStack *s)
{
    if(s->top+1 == N)
        return 1;
    else
        return 0;
}
//入栈
int Push_SequenStack(SequenStack *s,int x)
{
    if(SequenStack_Full(s))
    {
        printf("栈已满\n");
        return 0;
    }
    else
    {
        s->data[++(s->top)]=x;
        return 1;
    }
}
//出栈
int Pop_SequenStack(SequenStack *s,int *x)
{
    if(SequenStack_Empty(s))
    {
        printf("栈是空的\n");
        return 0;
    }
    else
    {
        *x=s->data[(s->top--)];
        return 1;
    }
}
int GetTop_SequenStack(SequenStack *s,int *x)
{
    if(SequenStack_Empty(s))
    {
        printf("空\n");
        return 0;
    }
    else
    {
        *x=s->data[s->top];
        return 1;
    }
}
//拓扑排序
void topsort(ALGraph *G,int indegree[])
{
    int i,j;
    SequenStack *s=Init_SequenStack();//初始化一个栈
    EdgeNode *p;
   // for(i=)
   for(i=0;i<G->n;i++)
   {
        if(indegree[i]==0)
        {
            Push_SequenStack(s,i);
       //     printf("一如站%d\n",i);
        }
   }
    /*printf("我们来看看度数数组\n");
    for(i=0;i<G->n;i++)
    {
        printf("%5d",indegree[i]);
    }*/
   /* printf("现在栈里有\n");
    for(i=0;i<=s->top;i++)
        printf("%5d",s->data[i]);
    printf("\n");
    system("pause");
*/
	while(s->top >= 0)
    {
        Pop_SequenStack(s,&i);
        printf("%5d",i);
        p=G->adjlist[i].firstedge;
        while(p!=NULL)
        {
            j=p->adjvex;
            indegree[j]--;
            if(indegree[j]==0)
                Push_SequenStack(s,j);
            p=p->next;
        }
    }


}
void CreateALGraph(ALGraph *G)
{
    int i,k,j,record;
    EdgeNode *s,*temp;
    printf("请输入顶点数和边数，输入格式为 顶点数<空格>边数\n");
    scanf("%d%d",&(G->n),&(G->e));//读入顶点数和边数
    printf("顶点数为%d，边数为R%d\n",G->n,G->e);
    printf("请输入顶点信息,输入格式为 顶点号<回车>\n");
    for(i=0;i<G->n;i++)
    {

        scanf("\n%d",&G->adjlist[i].vertex);//读入顶点信息
        G->adjlistb[i].vertex=G->adjlist[i].vertex;

        G->adjlist[i].firstedge=NULL;//顶点的边表头指针设为空
        G->adjlistb[i].firstedgeb=NULL;
    }
    printf("建立的顶点表信息为\n");
    for(i=0;i<G->n;i++)
        printf("%5d",G->adjlist[i]);
    printf("请输入边的信息,输入格式为 i,j<回车>\n");
    for(k=0;k<G->e;k++)
    {
        fflush(stdin);
        scanf("%d,%d",&i,&j);//读入边的顶点序列号
        fflush(stdin);
        s=(EdgeNode *)malloc(sizeof(EdgeNode));
        s->adjvex=j;//邻接点序号为j
        s->adjvexb=i;

        s->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=s;

        s->nextb=G->adjlistb[j].firstedgeb;
        G->adjlistb[j].firstedgeb=s;
    }
    printf("正的为\n");
    for(i=0;i<G->n;i++)
    {
        temp=G->adjlist[i].firstedge;
        while(temp!=NULL)
        {
            printf("%5d",temp->adjvex);
            temp=temp->next;
        }
        printf("\n");
    }
    printf("\n逆的为\n");
    for(i=0;i<G->n;i++)
    {
        record=0;
        temp=G->adjlistb[i].firstedgeb;
        while(temp!=NULL)
        {
            record++;
            printf("%5d",temp->adjvexb);
            temp=temp->nextb;
        }
        indegree[i]=record;
        printf("\n");
    }
    system("pause");
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
        printf("%d   ",G.adjlist[ii].vertex);
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
    printf("下面开始拓扑排序\n");
    topsort(&G,indegree);
   // DFSTraverseAL(&G);

}
