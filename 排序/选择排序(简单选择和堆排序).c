#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define N 50
#define LeftChild(i)(2*(i)+1)//定义一个宏，取得左孩子下标
void BuildDown(int a[],int n,int rootIndex)
{
    int root=a[rootIndex];//取得根节点数据
    int childIndex=LeftChild(rootIndex);//取得左孩子下标
    while(childIndex<n)
    {
        if(childIndex!=n-1 && a[childIndex+1]>a[childIndex])
            childIndex++;
        if(root<a[childIndex])
        {
            a[rootIndex]=a[childIndex];//较大数据网上移动
            rootIndex=childIndex;//设置新的根节点小标
            childIndex=LeftChild(rootIndex);//设定新的左孩子下标
        }
        else
            break;
    }
    a[rootIndex]=root;//根节点至于目标位置
}
int num[N];
void QuickSelectSort(int a[],int n)
{
    int min;//min存放最小元素下标
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
        a[i]=temp;//把组大致交换到子序列末尾
        BuildDown(a,i,0);//重新调整，构建对结构
    }

}
int main()
{
    int ii,length,key;
    printf("请输入数组序列，输入0结束\n");
    for(ii=0;ii<N;ii++)
    {
        scanf("%d",&num[ii]);
        if(num[ii]==0)
            break;
    }
    length=ii;
    printf("1简单选择排序\n2堆排序\n");
    scanf("%d",&key);
    if(key==1)
        QuickSelectSort(num,length);
    else if(key==2)
    {
        HeapSort(num,length);
    }
    printf("排序后的数据为\n");
    for(ii=0;ii<length;ii++)
    {
        printf("%5d",num[ii]);
    }
    return 0;
}
