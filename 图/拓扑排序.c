#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100//��󶥵�������Ϊ100
typedef int VertexType;//������������Ϊ�ַ���
int indegree[100];
#define N 100
typedef struct node
{
    int adjvex;//�ڽӵ���
    int adjvexb;//���
    struct node *next;//ָ����һ���ڽӵ��ָ����
    struct node *nextb;//ָ�������һ��ָ��
}EdgeNode;
int visited[100];
typedef struct vnode
{
    VertexType vertex;//������
    EdgeNode *firstedge;//�߱�ͷָ��
    EdgeNode *firstedgeb;//ָ����ı߱�ͷָ��
}VertexNode;
typedef struct
{
    VertexNode adjlist[MaxVertexNum];//�ڽӱ�
    VertexNode adjlistb[MaxVertexNum];//��
    int n,e;//�������ͱ���
}ALGraph;//�����ڽӱ�洢��ͼ����
//���ɣ���ʼдջ����Ϣ
typedef struct SequenStack
{
    int data[N];
    int top;//ջ��ָ��
}SequenStack;
//��ʼ��ջ
SequenStack * Init_SequenStack()
{
    SequenStack *s;
    s=(SequenStack *)malloc(sizeof(SequenStack));
    s->top=-1;
    return s;
}
//�ж�ջ��
int SequenStack_Empty(SequenStack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
//�ж�ջ��
int SequenStack_Full(SequenStack *s)
{
    if(s->top+1 == N)
        return 1;
    else
        return 0;
}
//��ջ
int Push_SequenStack(SequenStack *s,int x)
{
    if(SequenStack_Full(s))
    {
        printf("ջ����\n");
        return 0;
    }
    else
    {
        s->data[++(s->top)]=x;
        return 1;
    }
}
//��ջ
int Pop_SequenStack(SequenStack *s,int *x)
{
    if(SequenStack_Empty(s))
    {
        printf("ջ�ǿյ�\n");
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
        printf("��\n");
        return 0;
    }
    else
    {
        *x=s->data[s->top];
        return 1;
    }
}
//��������
void topsort(ALGraph *G,int indegree[])
{
    int i,j;
    SequenStack *s=Init_SequenStack();//��ʼ��һ��ջ
    EdgeNode *p;
   // for(i=)
   for(i=0;i<G->n;i++)
   {
        if(indegree[i]==0)
        {
            Push_SequenStack(s,i);
       //     printf("һ��վ%d\n",i);
        }
   }
    /*printf("������������������\n");
    for(i=0;i<G->n;i++)
    {
        printf("%5d",indegree[i]);
    }*/
   /* printf("����ջ����\n");
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
    printf("�����붥�����ͱ����������ʽΪ ������<�ո�>����\n");
    scanf("%d%d",&(G->n),&(G->e));//���붥�����ͱ���
    printf("������Ϊ%d������ΪR%d\n",G->n,G->e);
    printf("�����붥����Ϣ,�����ʽΪ �����<�س�>\n");
    for(i=0;i<G->n;i++)
    {

        scanf("\n%d",&G->adjlist[i].vertex);//���붥����Ϣ
        G->adjlistb[i].vertex=G->adjlist[i].vertex;

        G->adjlist[i].firstedge=NULL;//����ı߱�ͷָ����Ϊ��
        G->adjlistb[i].firstedgeb=NULL;
    }
    printf("�����Ķ������ϢΪ\n");
    for(i=0;i<G->n;i++)
        printf("%5d",G->adjlist[i]);
    printf("������ߵ���Ϣ,�����ʽΪ i,j<�س�>\n");
    for(k=0;k<G->e;k++)
    {
        fflush(stdin);
        scanf("%d,%d",&i,&j);//����ߵĶ������к�
        fflush(stdin);
        s=(EdgeNode *)malloc(sizeof(EdgeNode));
        s->adjvex=j;//�ڽӵ����Ϊj
        s->adjvexb=i;

        s->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=s;

        s->nextb=G->adjlistb[j].firstedgeb;
        G->adjlistb[j].firstedgeb=s;
    }
    printf("����Ϊ\n");
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
    printf("\n���Ϊ\n");
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
    printf("�����Ķ�����ϢΪ\n");
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
    printf("���濪ʼ��������\n");
    topsort(&G,indegree);
   // DFSTraverseAL(&G);

}
