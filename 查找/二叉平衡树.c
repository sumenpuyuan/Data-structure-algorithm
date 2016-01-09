#include<stdio.h>
#include<stdlib.h>
#define LH 1               //ltree  high 1         //根节点的左子树比右子树高
#define EH 0				//balance 0			//根节点的左子树和右子树一般高
#define RH -1				//rtree high -1      //根节点的右子树比左子树高
typedef struct bitnode{
		int data;
		int bf;           //平衡因子  判断输入结点以后判断是否平衡   是每插入一个都要查当前的树是否平衡
		struct bitnode *lchild,*rchild;     //找到最小不平衡子树进行旋转
}bitnode,* bitree;

void r_rotate(bitree *p)
{
	bitree l;
	l=(*p)->lchild;
	(*p)->lchild=l->rchild;
	l->rchild=(*p);
	(*p)=l;
}
void l_rotate(bitree *p)       //(*T->lchild)                //左旋转
{
	bitree l;            //目的要把根节点的右孩子变为根结点
	l=(*p)->rchild;              // l 为根节点的左子树的右孩子
	(*p)->rchild=l->lchild;      //根节点的右孩子为左子树的右孩子
	l->lchild=(*p);
	(*p)=l;
}
void leftbalance(bitree *T)
{
	bitree l,lr;
	l=(*T)->lchild;                   //  要旋转右旋（*t） 首先 要判断左子树是否要旋转
	switch(l->bf)
		{
			case LH:                 //左子树的也是lh
				(*T)->bf=l->bf=EH;
				r_rotate(T);            //直接右旋
				break;
			case RH:                  //根结点的左子树的右结点
				lr=l->rchild;           //lr为左子树的右子树
				switch(lr->bf)
				{
					case LH:          //lr为左子树的右子树(还有一个结点)
						(*T)->bf=RH;        //旋转以后 rh
						l->bf=EH;
						break;
					case EH:
						(*T)->bf=l->bf=EH;     //没有结点
						break;
					case RH:
						(*T)->bf=EH;
						l->bf=LH;
						break;
				}
			lr->bf=EH;
			l_rotate(&(*T)->lchild);       //先旋转左子树
			r_rotate(T);          //再旋转根结点
			break;
		}
}
void rightbalance(bitree *T)
{
	bitree r,rl;
	r=(*T)->rchild;
	switch(r->bf)
		{
			case RH:
				(*T)->bf=r->bf=EH;
				l_rotate(T);
				break;
			case LH:
				rl=r->lchild;
				switch(rl->bf)
				{
					case RH:
						(*T)->bf=LH;
						r->bf=EH;
						break;
					case EH:
						(*T)->bf=r->bf=EH;
						break;
					case LH:
						(*T)->bf=EH;
						r->bf=RH;
						break;
				}
			rl->bf=EH;
			r_rotate(&(*T)->rchild);
			l_rotate(T);
			break;
		}
}
int insertavl(bitree *T,int e,int *taller)   //二级指针   *taller判断树有没有长高  true：长高  false:保持原高度
{
	if(!*T)        //      *T==NULL;                               //t为空   直接为该结点创建
		{
			*T=(bitree)malloc(sizeof(bitnode));
			(*T)->data=e;
			(*T)->lchild=(*T)->rchild=NULL;
			(*T)->bf=EH;                  //平衡因子并未改变
			*taller=1;
		}
	else
		{
			if(e==(*T)->data)        //数据重复,直接返回false
				{
					 *taller=0;
					 return 0;
				}
			if(e<(*T)->data)          //小于根节点的值，传根节点的左子树的地址进行判断然后插入
				{
				if(!insertavl(&(*T)->lchild,e,taller))
					return 0;
				if(*taller)              //插入元素后树长高
					{
					switch((*T)->bf)       //根据bf的状态来判断 新插入结点以后是否需要旋转
						{
							case LH:          //根结点的左子树的左子树插入结点 需要进行旋转 进入L平衡判断旋转的次数
							leftbalance(T);      //左平衡
							*taller=0;    //旋转以后树并没有长高
							break;
							case EH:          //原来根结点以下是平衡的
							(*T)->bf=LH;         //平衡因子改变  改为LH
							*taller=1;		//树的高度增加
							break;
							case RH:          //原来的根结点以下右子树是高的
							(*T)->bf=EH;      //插入到左子树以后  平衡因子为EH
							*taller=0;    //树的高度没有改变
							break;
						}
					}
				}
			else
				{
				if(!insertavl(&(*T)->rchild,e,taller))
						return 0;
				if(*taller)                      //同样插入根结点的右子树判断高度是否增加
					{
					switch((*T)->bf)              //增加以后 判断树的树的平衡因子
						{
							case LH:               //根节点的左字树原先有一个节点  现在在右子树插入
							(*T)->bf=EH;			//平衡因子再次平衡
							*taller=0;
							break;
							case EH:              //该树根结点原先没有子树
							(*T)->bf=RH;			//平衡因子改为 rh
							*taller=1;         //树的高度增加
							break;
							case RH:
							rightbalance(T);      //先判断子树是否需要移动
							*taller=0;      //旋转以后树并没增加高度
							break;

						}
					}
				}
		}
	return 1;
}
void intraver(bitree p)
{
	bitree in=p;
	if(in)
		{
		if(in->lchild!=NULL)
			intraver(in->lchild);
		printf("%3d",in->data);
		if(in->rchild!=NULL)
			intraver(in->rchild);
		}
	return ;
}
int main(void)
{
	int taller=0;
	bitree root;
	root=NULL;
	int i;
	int a[10]={3,2,1,4,5,6,7,10,9,8};
	for(i=0;i<10;i++)
		{
		insertavl(&root,a[i],&taller);
		}
	intraver(root);
	return 0;
}
