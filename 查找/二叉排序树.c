#include <stdio.h>
#include <stdlib.h>
#define N 50
typedef struct node
{
    int key;
    struct node *lchild,*rchild;
}BSTNode;
int InserBST(BSTNode *&p,int k);
BSTNode *CreateBST(int a[],int n)
{
    BSTNode *bt=NULL;
    int i=0;
    while(i<n)
    {
        InserBST(bt,a[i]);
        i++;
    }
    return bt;
}
int InserBST(BSTNode *&p,int k)
{
    if(p==NULL)
    {
        p=(BSTNode *)malloc(sizeof(BSTNode));
        p->key=k;
        p->lchild=p->rchild=NULL;
        return 1;
    }
    else if(k==p->key)
        return 0;
    else if(k<p->key)
        return InserBST(p->lchild,k);
    else
        return InserBST(p->rchild,k);
}
BSTNode *SearchBST(BSTNode *bt,int k)
{
    if(bt==NULL || bt->key==k)
        return bt;
    if(k<bt->key)
        return SearchBST(bt->lchild,k);
    else
        return SearchBST(bt->rchild,k);
}
int main()
{
    int ii,length;
    int num[N];
    int key;
    BSTNode *bt;
    printf("请输入原始数据，输入0结束\n");
    for(ii=0;ii<N;ii++)
    {
        scanf("%d",&num[ii]);
        if(num[ii] == 0)
            break;
    }
    length=ii;
    bt=CreateBST(num,length);
    printf("请输入要查找的数据\n");
    scanf("%d",&key);
    bt=SearchBST(bt,key);
    if(bt==NULL)
        printf("未找到\n");
    else
        printf("找到了");
}
