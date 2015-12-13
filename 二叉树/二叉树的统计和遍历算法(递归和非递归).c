//blog��http://sumenpuyuan.com/2015/12/08/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%81%8D%E5%8E%86%E5%92%8C%E7%BB%9F%E8%AE%A1%E7%AE%97%E6%B3%95/2/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#define N 100
typedef char elemtype;
typedef struct BiTreeNode
{
	elemtype data;
	struct BiTreeNode *lchild,*rchild;
	char flag;

}BiTreeNode,*BiTree;
int  InOrderNo(BiTree bt);
void visit(char data);
//�����չ�����������
void CreateBiTree(BiTree *bt,char str[])
{
	char ch;
	static int i=0;
	ch=str[i++];
	if(ch=='.')
		*bt=NULL;
	else
	{
		*bt=(BiTree)malloc(sizeof(BiTreeNode));
		(*bt)->data=ch;
		CreateBiTree(&((*bt)->lchild),str);
		CreateBiTree(&((*bt)->rchild),str);

	}

}
//�������
void ProOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		visit(bt->data);
		ProOrder(bt->lchild);
		ProOrder(bt->rchild);
	}
}
//�������
void InOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->lchild);
		visit(bt->data);
		InOrder(bt->rchild);
	}
}
void visit(char data)
{
	printf("%c\t",data);
}
void PostOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		visit(bt->data);
	}
}
int BitreeLeaf(BiTree bt)
{
	if(bt==NULL)
		return 0;
	if(bt->lchild==NULL && bt->rchild==NULL)
		return 1;
	return (BitreeLeaf(bt->lchild)+BitreeLeaf(bt->rchild));
}
void BitreeLeaf02( BiTree T, int *k ) {     //�����ʱk��Ӧ��ʵ�γ�ʼ��Ϊ0
              if ( T != NULL ) {
                 (*k)++;
			BitreeLeaf02(T->lchild,k);
			BitreeLeaf02(T->rchild,k);
          }
       }
int  InOrderNo(BiTree bt)
{
	BiTree s[N],p=bt;
	int top=-1;//top��ʾջ��ָ��
	p=bt;
	if(p==NULL) return 0;//ջΪ�գ���������
	do
	{
		while(p!=NULL)
		{
			if(top>=N-1)
			{
				printf("ջ���");
				return 0;
			}
			s[++top]=p;
			p=p->lchild;//ָ��ָ��������ӽڵ�

		};
		if(top==-1) return 0;//ջ��ʱ����
		else
		{
			p=s[top--];
			//visit(p->data);
			if(p->rchild==NULL && p->lchild==NULL)
				visit(p->data);
			p=p->rchild;//ָ��ָ���ӵ��Һ��ӽڵ�

		}

	}
	while(p!=NULL || top!=-1);
	return 0;

}
int  InOrderNo03(BiTree bt)
{
	BiTree s[N],p=bt;
	int top=-1;//top��ʾջ��ָ��
	p=bt;
	if(p==NULL) return 0;//ջΪ�գ���������
	do
	{
		while(p!=NULL)
		{
			if(top>=N-1)
			{
				printf("ջ���");
				return 0;
			}
			s[++top]=p;
			visit(p->data);
			p=p->lchild;//ָ��ָ��������ӽڵ�

		};
		if(top==-1) return 0;//ջ��ʱ����
		else
		{
			p=s[top--];
			p=p->rchild;//ָ��ָ���ӵ��Һ��ӽڵ�

		}

	}
	while(p!=NULL || top!=-1);
	return 0;

}
int max(int x,int y)
{
    return x>y?x:y;
}
int BitreeDepth(BiTree bt)
{
    int d=0,depthL,depthR;
    if(bt==NULL)
        return 0;
    //if(bt->lchild==NULL && bt->rchild==NULL)
    if(bt->lchild==NULL && bt->rchild==NULL)
        return 1;
    depthL=BitreeDepth(bt->lchild);
    depthR=BitreeDepth(bt->rchild);
    d=max(depthL,depthR);
    return d+1;
}
int  InOrderNo04(BiTree bt)
{
	BiTree s[N],p=bt;
	int top=-1;//top��ʾջ��ָ��
	p=bt;
	if(p==NULL) return 0;//ջΪ�գ���������
	do
	{
		while(p!=NULL)
		{
			if(top>=N-1)
			{
				printf("ջ���");
				return 0;
			}
			s[++top]=p;
			//visit(p->data);
			p=p->lchild;//ָ��ָ��������ӽڵ�

		};
		if(top==-1) return 0;//ջ��ʱ����
		else
		{
			p=s[top--];
			visit(p->data);
			p=p->rchild;//ָ��ָ���ӵ��Һ��ӽڵ�

		}

	}
	while(p!=NULL || top!=-1);
	return 0;

}

int  InOrderNo02(BiTree bt)
{
	BiTree s[N],p=bt,temp;//s[]�Ǹ�ָ������
	int top=-1;//top��ʾջ��ָ��
	p=bt;
	if(p==NULL) return 0;//ջΪ�գ���������
	do
	{
		while(p!=NULL)
		{
			if(top>=N-1)
			{
				printf("ջ���");
				return 0;
			}
			p->flag='L';
			s[++top]=p;
			p=p->lchild;//ָ��ָ��������ӽڵ�

		};
		//��������Ϊ��
		if(top!=-1 && s[top]->flag=='R')//ջ��ʱ����
		{
			temp=s[top--];
			visit(temp->data);
		//	printf("������if���,����top=%d\n",top);
		//	printf("\n\n\n");
		//	system("pause");
		}
		else if(top==-1)
            return  0;
		else
		{
			p=s[top];
			top--;
			p->flag='R';
			s[++top]=p;
		//	s[top]->flag='R';0
			if(p!=NULL)
				  p=p->rchild;//ָ��ָ���ӵ��Һ��ӽڵ�
			else
				printf("pΪ��\n");
		//	printf("���뵽��else���,����top=%d\n",top);
		//	printf("\n\n\n\n");
		//	system("pause");
		}
	}
	while(p!=NULL || top!=-1);

}

void menu()
{
	int key;
	int res;
	int k=0;
	int depth;
	BiTree bt;
		char str[]={'A','B','C',
						'.','.',
						'D','.','.',
						'E','.','F','G'
						,'.','.','.'};
	while(1)
	{
		system("cls");
		puts("1������");
		puts("2�ݹ��������");
		puts("3�ݹ��������");
		puts("4�ݹ�������");
		puts("5�ݹ�Ҷ�ӽڵ�");
		puts("6�ݹ�ڵ����");
		puts("7�ǵݹ��������Ҷ�ӽڵ�");
		puts("8����ǵݹ�����ڵ�����");
		puts("9����ǵݹ�����ڵ�����");
		puts("10����ǵݹ�����ڵ�����");
		puts("11���������");
		//puts("9����ǵݹ�����ڵ�����");
		scanf("%d",&key);
		switch(key)
		{
		case 1:	CreateBiTree(&bt,str);getch();break;
		case 2: ProOrder(bt);getch();break;
		case 3: InOrder(bt);getch();break;
		case 4:PostOrder(bt);getch();break;
		case 5:res=BitreeLeaf(bt);printf("Ҷ�ӽڵ㹲��%d��\n",res);getch();break;
		case 6:BitreeLeaf02(bt,&k);
			printf("���Ľڵ����Ϊ%d",k);
			getch();
			break;
		case 7:InOrderNo(bt);getch();break;
		case 8:InOrderNo02(bt);getch();break;
		case 9:InOrderNo04(bt);getch();break;
		case 10:InOrderNo03(bt);getch();break;
		case 11:depth=BitreeDepth(bt);
            printf("���Ϊ%d\n",depth);
		getch();break;
		default:break;
		}
	}
}
int main()
{
	menu();
}
