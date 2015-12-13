//blog：http://sumenpuyuan.com/2015/12/08/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%81%8D%E5%8E%86%E5%92%8C%E7%BB%9F%E8%AE%A1%E7%AE%97%E6%B3%95/2/
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
//结合扩展先序遍历序列
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
//先序遍历
void ProOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		visit(bt->data);
		ProOrder(bt->lchild);
		ProOrder(bt->rchild);
	}
}
//中序遍历
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
void BitreeLeaf02( BiTree T, int *k ) {     //设调用时k对应的实参初始化为0
              if ( T != NULL ) {
                 (*k)++;
			BitreeLeaf02(T->lchild,k);
			BitreeLeaf02(T->rchild,k);
          }
       }
int  InOrderNo(BiTree bt)
{
	BiTree s[N],p=bt;
	int top=-1;//top表示栈顶指针
	p=bt;
	if(p==NULL) return 0;//栈为空，便利结束
	do
	{
		while(p!=NULL)
		{
			if(top>=N-1)
			{
				printf("栈溢出");
				return 0;
			}
			s[++top]=p;
			p=p->lchild;//指针指向他的最孩子节点

		};
		if(top==-1) return 0;//栈空时结束
		else
		{
			p=s[top--];
			//visit(p->data);
			if(p->rchild==NULL && p->lchild==NULL)
				visit(p->data);
			p=p->rchild;//指针指向孩子的右孩子节点

		}

	}
	while(p!=NULL || top!=-1);
	return 0;

}
int  InOrderNo03(BiTree bt)
{
	BiTree s[N],p=bt;
	int top=-1;//top表示栈顶指针
	p=bt;
	if(p==NULL) return 0;//栈为空，便利结束
	do
	{
		while(p!=NULL)
		{
			if(top>=N-1)
			{
				printf("栈溢出");
				return 0;
			}
			s[++top]=p;
			visit(p->data);
			p=p->lchild;//指针指向他的最孩子节点

		};
		if(top==-1) return 0;//栈空时结束
		else
		{
			p=s[top--];
			p=p->rchild;//指针指向孩子的右孩子节点

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
	int top=-1;//top表示栈顶指针
	p=bt;
	if(p==NULL) return 0;//栈为空，便利结束
	do
	{
		while(p!=NULL)
		{
			if(top>=N-1)
			{
				printf("栈溢出");
				return 0;
			}
			s[++top]=p;
			//visit(p->data);
			p=p->lchild;//指针指向他的最孩子节点

		};
		if(top==-1) return 0;//栈空时结束
		else
		{
			p=s[top--];
			visit(p->data);
			p=p->rchild;//指针指向孩子的右孩子节点

		}

	}
	while(p!=NULL || top!=-1);
	return 0;

}

int  InOrderNo02(BiTree bt)
{
	BiTree s[N],p=bt,temp;//s[]是个指针数组
	int top=-1;//top表示栈顶指针
	p=bt;
	if(p==NULL) return 0;//栈为空，便利结束
	do
	{
		while(p!=NULL)
		{
			if(top>=N-1)
			{
				printf("栈溢出");
				return 0;
			}
			p->flag='L';
			s[++top]=p;
			p=p->lchild;//指针指向他的最孩子节点

		};
		//现在左海子为空
		if(top!=-1 && s[top]->flag=='R')//栈空时结束
		{
			temp=s[top--];
			visit(temp->data);
		//	printf("进入了if语句,现在top=%d\n",top);
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
				  p=p->rchild;//指针指向孩子的右孩子节点
			else
				printf("p为空\n");
		//	printf("进入到了else语句,现在top=%d\n",top);
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
		puts("1创建树");
		puts("2递归先序遍历");
		puts("3递归中序遍历");
		puts("4递归后序遍历");
		puts("5递归叶子节点");
		puts("6递归节点个数");
		puts("7非递归输出树的叶子节点");
		puts("8后序非递归输出节点数据");
		puts("9中序非递归输出节点数据");
		puts("10先序非递归输出节点数据");
		puts("11二叉树深度");
		//puts("9先序非递归输出节点数据");
		scanf("%d",&key);
		switch(key)
		{
		case 1:	CreateBiTree(&bt,str);getch();break;
		case 2: ProOrder(bt);getch();break;
		case 3: InOrder(bt);getch();break;
		case 4:PostOrder(bt);getch();break;
		case 5:res=BitreeLeaf(bt);printf("叶子节点共有%d个\n",res);getch();break;
		case 6:BitreeLeaf02(bt,&k);
			printf("树的节点个数为%d",k);
			getch();
			break;
		case 7:InOrderNo(bt);getch();break;
		case 8:InOrderNo02(bt);getch();break;
		case 9:InOrderNo04(bt);getch();break;
		case 10:InOrderNo03(bt);getch();break;
		case 11:depth=BitreeDepth(bt);
            printf("深度为%d\n",depth);
		getch();break;
		default:break;
		}
	}
}
int main()
{
	menu();
}
