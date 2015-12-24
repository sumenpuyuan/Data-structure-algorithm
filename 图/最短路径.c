#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#define INF 1000
#define MaxVertexNum 100//��󶥵�������Ϊ100
int visited[100];//�洢��־����
typedef char VertexType;//������������Ϊ�ַ���
typedef int EdgeType;//�ߵ�Ȩֵ����Ϊ����
typedef struct
{
    VertexType vexs[MaxVertexNum];//�����
    int edges[MaxVertexNum][MaxVertexNum];//�ڽӾ��󣬼��߱�
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
void dispath(int dist[],int path[],int s[],int n,int v);
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
	int quan;
    printf("�����붥�����ͱ����������ʽΪ��������������\n");
    scanf("%d,%d",&(G->n),&(G->e));//���붥�����ͱ���
    printf("�����붥����Ϣ,�����ʽΪ �����<�س�>\n");
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
            G->edges[i][j]=INF;//��ʼ���ڽӾ���
    printf("������ÿ���߶�Ӧ��������������(�����ʽΪ)����ʼ����<�ո�>��ֹ����<�ո�>Ȩֵ<�س�>\n");
    printf("����Ϊ%d\n",G->e);
    for(k=0;k<G->e;k++)
    {
        scanf("%d,%d,%d",&i,&j,&quan);//����e���ߣ������ڽӾ���
        G->edges[i][j]=quan;
		//G->edges[j][i]=quan;
    }
}
void dijkstra(MGraph *G,int v)
{
	int dist[MaxVertexNum],path[MaxVertexNum];
	int s[MaxVertexNum];
	int mindis;
	int i,j,k;
//	printf("�������\n");
//	system("pause");
//	printf("����Ϊ%d\n",G->n);
	for(i=0;i<G->n;i++)
	{
		dist[i]=G->edges[v][i];
		//printf("dist[%d]=%d\n",i,dist[i]);
		s[i]=0;
		if(G->edges[v][i]<INF)
			path[i]=v;
		else
			path[i]=-1;
	}
	s[v]=1;
/*	printf("��һ��forѭ������\n");
	system("pause");
	printf("���㷨�У�dist����\n");
	for(i=0;i<G->n;i++)
	{
		printf("%5d",dist[i]);
	}*/
	for(i=0;i<G->n;i++)
	{
		mindis=INF;
		k=v;
		for(j=0;j<G->n;j++)
		{
			if(s[j]==0 && dist[j]<mindis)
			{
				k=j;
				mindis=dist[j];
			}
		}
		s[k]=1;
		for(j=0;j<G->n;j++)
		{
			if(s[j]==0 && G->edges[k][j]<INF && dist[k]+G->edges[k][j]<dist[j])
			{
				dist[j]=dist[k]+G->edges[k][j];
				//printf("k=%d\n",k);
				//printf("%d+%d\n",dist[k],G->edges[k][j]);
			//	printf("��ؼ��Ĳ������ˣ�����dist[%d]=%d\n",j,dist[j]);
				path[j]=k;
			}
		}
	}
/*	system("pause");
	printf("���㷨�У�dist����\n");
	for(i=0;i<G->n;i++)
	{
		printf("%5d",dist[i]);
	}
	printf("\n");*/
	dispath(dist,path,s,G->n,v);
}
void dispath(int dist[],int path[],int s[],int n,int v)
{
	int i,k;
	for(i=0;i<n;i++)
	{
		if(s[i]==1)
		{
			k=i;
			printf("v%d��v%d�����·��Ϊ",v,i);
			while(k!=v)
			{
				printf("v%d<-",k);
				k=path[k];
			}
			printf("v%d ·������Ϊ%d\n",v,dist[i]);
		}
		else
			printf("v%d<-v%d������·��\n");
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
    dijkstra(&G,0);
    return 0;
}
