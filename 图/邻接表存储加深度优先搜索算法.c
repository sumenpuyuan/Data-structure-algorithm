#include<stdio.h>
#define MaxVertexNum 100//��󶥵�������Ϊ100
typedef char VertexType;//������������Ϊ�ַ���
typedef struct node
{
    int adjvex;//�ڽӵ���
    struct node *next;//ָ����һ���ڽӵ��ָ����
}EdgeNode;
int visited[100];
typedef struct vnode
{
    VertexType vertex;//������
    EdgeNode *firstedge;//�߱�ͷָ��
}VertexNode;
typedef struct
{
    VertexNode adjlist[MaxVertexNum];//�ڽӱ�
    int n,e;//�������ͱ���
}ALGraph;//�����ڽӱ�洢��ͼ����
void CreateALGraph(ALGraph *G)
{
    int i,k,j;
    EdgeNode *s;
    printf("�����붥�����ͱ���\n");
    scanf("%d%d",&(G->n),&(G->e));//���붥�����ͱ���
    printf("������Ϊ%d������ΪR%d\n",G->n,G->e);
    printf("�����붥����Ϣ\n");
    for(i=0;i<G->n;i++)
    {

        scanf("\n%c",&G->adjlist[i].vertex);//���붥����Ϣ

        G->adjlist[i].firstedge=NULL;//����ı߱�ͷָ����Ϊ��
    }
    printf("�����Ķ������ϢΪ\n");
    for(i=0;i<G->n;i++)
        printf("%5c",G->adjlist[i]);
    printf("������ߵ���Ϣ\n");
    for(k=0;k<G->e;k++)
    {
        fflush(stdin);
        scanf("%d,%d",&i,&j);//����ߵĶ������к�
        fflush(stdin);
        s=(EdgeNode *)malloc(sizeof(EdgeNode));
        s->adjvex=j;//�ڽӵ����Ϊj
        s->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=s;
    }

}
void DFSAL(ALGraph *G,int i)
{
    EdgeNode *p;
    printf("����%c\n",G->adjlist[i].vertex);//���ʶ���
    visited[i]=1;//���vi�Ѿ�����
    p=G->adjlist[i].firstedge;//ȥvi����ͷָ��
    while(p!=NULL)
    {
        if(!visited[p->adjvex]);//��vj��δ���ʣ�������������
            DFSAL(G,p->adjvex);
        p=p->next;//��vi����һ���ڽӵ�
    }
}
void DFSTraverseAL(ALGraph *G)
{
    int i;
    for(i=0;i<G->n;i++)
        visited[i]=0;//��־������ʼ��
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
    printf("�����Ķ�����ϢΪ\n");
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
    printf("���濪ʼ���������������\n");
    DFSTraverseAL(&G);

}
