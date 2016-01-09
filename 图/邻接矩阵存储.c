#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#define MaxVertexNum 100//��󶥵�������Ϊ100
int visited[100];//�洢��־����
typedef char VertexType;//������������Ϊ�ַ���
typedef int EdgeType;//�ߵ�Ȩֵ����Ϊ����
typedef struct
{
    VertexType vexs[MaxVertexNum];//�����
    EdgeType edges[MaxVertexNum][MaxVertexNum];//�ڽӾ��󣬼��߱�
    int n,e;//�������ͱ���
}MGraph;//MGraph�����ڽӾ���洢��ͼ����
#define MAXSIZE 1024
typedef int elemtype;
typedef struct SequenQueue
{
    elemtype data[MAXSIZE];
    int front1;//ͷָ��
    int rear;//βָ��
}SequenQueue;
void BFSM(MGraph *G,int k);
void BFSTraverseAL(MGraph *G);
//��ʼ��
SequenQueue* Init_SequenQueue()
{
    SequenQueue *Q;
    Q=(SequenQueue*)malloc(sizeof(SequenQueue));
    Q->front1=0;
    Q->rear=0;
    return Q;//����ѭ�����е��׵�ַ
}
//�����Ƿ�Ϊ��
int SequenQueue_Empty(SequenQueue* Q)
{
    if(Q->front1==Q->rear)
        return 1;//����Ϊ�գ�����1
    else
        return 0;
}
//�������е�Ԫ��

void Print_SequenQueue(SequenQueue *q)
{
	SequenQueue *temp;
	int front1;
	temp=q;
	front1=temp->front1;

	while((front1+1)%MAXSIZE!=temp->rear+1)
	{
		printf("����temp-��frontΪ%d��rearΪ%d",front1,temp->rear);
		printf("\n%d\n",temp->data[temp->front1]);
		front1++;
	}
}
//�ж϶����Ƿ�����
int SequenQueue_Full(SequenQueue *q)
{
    if((q->rear+1)%MAXSIZE==q->front1)
        return 1;//�����ȣ�������Ѿ�����
    else
        return 0;

}
//��ѭ�����еĳ���
int SequenQueue_Length(SequenQueue *q)
{
    return (q->rear-q->front1);
}
//���
int Enter_SequenQueue(SequenQueue*q,elemtype x)
{
    if(SequenQueue_Full(q))
    {
        printf("��������");
        return 0;//���ʧ�ܣ�����0
    }
    else{
        q->data[q->rear]=x;
        q->rear=(q->rear+1)%MAXSIZE;
        return 1;
    }


}
//����
int Delete_SequenQueue(SequenQueue *q,elemtype *x)
{
    if(q->front1==q->rear)
    {
        printf("����Ϊ��");
        return 0;
    }
    else
    {
        *x=q->data[q->front1];
        q->front1=(q->front1+1)%MAXSIZE;
        return 1;
    }
}
//ȡջ��Ԫ��
int GetFront_SequenQueue(SequenQueue *q,elemtype *x)
{
    if(q->front1==q->rear)
    {
        printf("����Ϊ��");
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
    printf("�����붥�����ͱ����������ʽΪ��������������\n");
    scanf("%d%d",&(G->n),&(G->e));//���붥�����ͱ���
    printf("�����붥����Ϣ\n");
    fflush(stdin);
    for(i=0;i<G->n;i++)
    {
        scanf("\n%c",&(G->vexs[i]));//���붥����Ϣ������������Ϣ��
    }
    printf("�������Ķ�����ϢΪ\n");
    for(i=0;i<G->n;i++)
        printf("%5c",G->vexs[i]);
    fflush(stdin);
    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
            G->edges[i][j]=0;//��ʼ���ڽӾ���
    printf("������ÿ���߶�Ӧ��������������(�����ʽΪ)\n");
    printf("����Ϊ%d\n",G->e);
    for(k=0;k<G->e;k++)
    {
        scanf("%d,%d",&i,&j);//����e���ߣ������ڽӾ���
        G->edges[i][j]=1;
    }
}
void BFSTraverseAL(MGraph *G)
{
    int i;
    for(i=0;i<G->n;i++)
        visited[i]=0;//��־������ʼ��
    for(i=0;i<G->n;i++)
        if(!visited[i])
            BFSM(G,i);//viΧ�Ƿ��ʣ�����bfs����
}
void BFSM(MGraph *G,int k)
{
    int i,j;
    SequenQueue *Q;
    Q=Init_SequenQueue();
    printf("����%c\n",G->vexs[k]);//����ԭ��vk
    visited[k]=1;
    Enter_SequenQueue(Q,k);//���
    while(!SequenQueue_Empty(Q))
    {
        Delete_SequenQueue(Q,&i);//����
        for(j=0;j<G->n;j++)
        {
            if(G->edges[i][j]==1 && !visited[j])//���vjΪ���ʣ�������
            {
                printf("����%c\n",G->vexs[j]);//����vj
                visited[j]=1;
                Enter_SequenQueue(Q,j);//���ʹ���vj���
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
    printf("���濪ʼ���й����������\n");
    BFSTraverseAL(&G);
    return 0;
}
