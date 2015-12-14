#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define N 50
#define LeftChild(i)(2*(i)+1)//����һ���꣬ȡ�������±�
void BuildDown(int a[],int n,int rootIndex)
{
    int root=a[rootIndex];//ȡ�ø��ڵ�����
    int childIndex=LeftChild(rootIndex);//ȡ�������±�
    while(childIndex<n)
    {
        if(childIndex!=n-1 && a[childIndex+1]>a[childIndex])
            childIndex++;
        if(root<a[childIndex])
        {
            a[rootIndex]=a[childIndex];//�ϴ����������ƶ�
            rootIndex=childIndex;//�����µĸ��ڵ�С��
            childIndex=LeftChild(rootIndex);//�趨�µ������±�
        }
        else
            break;
    }
    a[rootIndex]=root;//���ڵ�����Ŀ��λ��
}
int num[N];
void QuickSelectSort(int a[],int n)
{
    int min;//min�����СԪ���±�
    int temp,ii,ij;
    for(ii=0;ii<n;ii++)
    {
        min=ii;
        for(ij=ii+1;ij<n;ij++)
        {
            if(a[min]>a[ij])
                min=ij;
        }
        temp=a[min];
        a[min]=a[ii];
        a[ii]=temp;
    }
}
void HeapSort(int a[],int n)
{
    int temp,i;
    int rootIndex;
    for(rootIndex=(n-2)/2;rootIndex>=0;rootIndex--)
    {
        BuildDown(a,n,rootIndex);
    }
    for(i=n-1;i>=0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;//������½�����������ĩβ
        BuildDown(a,i,0);//���µ����������Խṹ
    }

}
int main()
{
    int ii,length,key;
    printf("�������������У�����0����\n");
    for(ii=0;ii<N;ii++)
    {
        scanf("%d",&num[ii]);
        if(num[ii]==0)
            break;
    }
    length=ii;
    printf("1��ѡ������\n2������\n");
    scanf("%d",&key);
    if(key==1)
        QuickSelectSort(num,length);
    else if(key==2)
    {
        HeapSort(num,length);
    }
    printf("����������Ϊ\n");
    for(ii=0;ii<length;ii++)
    {
        printf("%5d",num[ii]);
    }
    return 0;
}
