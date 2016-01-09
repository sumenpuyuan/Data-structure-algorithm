#include<stdio.h>
#include<stdlib.h>
#define LH 1               //ltree  high 1         //���ڵ������������������
#define EH 0				//balance 0			//���ڵ����������������һ���
#define RH -1				//rtree high -1      //���ڵ������������������
typedef struct bitnode{
		int data;
		int bf;           //ƽ������  �ж��������Ժ��ж��Ƿ�ƽ��   ��ÿ����һ����Ҫ�鵱ǰ�����Ƿ�ƽ��
		struct bitnode *lchild,*rchild;     //�ҵ���С��ƽ������������ת
}bitnode,* bitree;

void r_rotate(bitree *p)
{
	bitree l;
	l=(*p)->lchild;
	(*p)->lchild=l->rchild;
	l->rchild=(*p);
	(*p)=l;
}
void l_rotate(bitree *p)       //(*T->lchild)                //����ת
{
	bitree l;            //Ŀ��Ҫ�Ѹ��ڵ���Һ��ӱ�Ϊ�����
	l=(*p)->rchild;              // l Ϊ���ڵ�����������Һ���
	(*p)->rchild=l->lchild;      //���ڵ���Һ���Ϊ���������Һ���
	l->lchild=(*p);
	(*p)=l;
}
void leftbalance(bitree *T)
{
	bitree l,lr;
	l=(*T)->lchild;                   //  Ҫ��ת������*t�� ���� Ҫ�ж��������Ƿ�Ҫ��ת
	switch(l->bf)
		{
			case LH:                 //��������Ҳ��lh
				(*T)->bf=l->bf=EH;
				r_rotate(T);            //ֱ������
				break;
			case RH:                  //���������������ҽ��
				lr=l->rchild;           //lrΪ��������������
				switch(lr->bf)
				{
					case LH:          //lrΪ��������������(����һ�����)
						(*T)->bf=RH;        //��ת�Ժ� rh
						l->bf=EH;
						break;
					case EH:
						(*T)->bf=l->bf=EH;     //û�н��
						break;
					case RH:
						(*T)->bf=EH;
						l->bf=LH;
						break;
				}
			lr->bf=EH;
			l_rotate(&(*T)->lchild);       //����ת������
			r_rotate(T);          //����ת�����
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
int insertavl(bitree *T,int e,int *taller)   //����ָ��   *taller�ж�����û�г���  true������  false:����ԭ�߶�
{
	if(!*T)        //      *T==NULL;                               //tΪ��   ֱ��Ϊ�ý�㴴��
		{
			*T=(bitree)malloc(sizeof(bitnode));
			(*T)->data=e;
			(*T)->lchild=(*T)->rchild=NULL;
			(*T)->bf=EH;                  //ƽ�����Ӳ�δ�ı�
			*taller=1;
		}
	else
		{
			if(e==(*T)->data)        //�����ظ�,ֱ�ӷ���false
				{
					 *taller=0;
					 return 0;
				}
			if(e<(*T)->data)          //С�ڸ��ڵ��ֵ�������ڵ���������ĵ�ַ�����ж�Ȼ�����
				{
				if(!insertavl(&(*T)->lchild,e,taller))
					return 0;
				if(*taller)              //����Ԫ�غ�������
					{
					switch((*T)->bf)       //����bf��״̬���ж� �²������Ժ��Ƿ���Ҫ��ת
						{
							case LH:          //�������������������������� ��Ҫ������ת ����Lƽ���ж���ת�Ĵ���
							leftbalance(T);      //��ƽ��
							*taller=0;    //��ת�Ժ�����û�г���
							break;
							case EH:          //ԭ�������������ƽ���
							(*T)->bf=LH;         //ƽ�����Ӹı�  ��ΪLH
							*taller=1;		//���ĸ߶�����
							break;
							case RH:          //ԭ���ĸ���������������Ǹߵ�
							(*T)->bf=EH;      //���뵽�������Ժ�  ƽ������ΪEH
							*taller=0;    //���ĸ߶�û�иı�
							break;
						}
					}
				}
			else
				{
				if(!insertavl(&(*T)->rchild,e,taller))
						return 0;
				if(*taller)                      //ͬ������������������жϸ߶��Ƿ�����
					{
					switch((*T)->bf)              //�����Ժ� �ж���������ƽ������
						{
							case LH:               //���ڵ��������ԭ����һ���ڵ�  ����������������
							(*T)->bf=EH;			//ƽ�������ٴ�ƽ��
							*taller=0;
							break;
							case EH:              //���������ԭ��û������
							(*T)->bf=RH;			//ƽ�����Ӹ�Ϊ rh
							*taller=1;         //���ĸ߶�����
							break;
							case RH:
							rightbalance(T);      //���ж������Ƿ���Ҫ�ƶ�
							*taller=0;      //��ת�Ժ�����û���Ӹ߶�
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
