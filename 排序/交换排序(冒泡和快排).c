#include <stdio.h>
#include <stdlib.h>
#define N 100
int num[N];
void bubble(int num[],int length)
{
    int n=length;
    int ii,ij,iflag=0,temp;
    for(ii=1;ii<n;ii++)
    {
        iflag=0;
        for(ij=0;ij<n-ii;ij++)
        {
            if(num[ij]>num[ij+1])
            {
                temp=num[ij];
                num[ij]=num[ij+1];
                num[ij+1]=temp;
                iflag=1;
            }
        }
        if(iflag==0)
            break;
    }
}
int parition(int a[],int i,int j)
{
    int temp=a[i];//选择首元素为划分元素
    while(i<j)
    {
        while(a[j]>=temp && i<j)//当while1里面有两个条件时，下方一定要跟上if条件语句判断
            j--;
        if(i<j)
            a[i++]=a[j];//若找到移动元素。把小标i+1
        while(a[i]<=temp && i<j)
            i++;
        if(i<j)
            a[j--]=a[i];
    }
    a[i]=temp;//划分完毕，把划分元素至于目标
    return i;
}
void QuickSort(int a[],int i,int j)
{
    int k;//程序采用递归实现，这里是递归的结束条件
    if(i<j)
    {
        k=parition(a,i,j);
        QuickSort(a,i,k-1);
        QuickSort(a,k+1,j);
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
    printf("1冒泡排序\n2快速排序\n");
    scanf("%d",&key);
    if(key==1)
        bubble(num,length);
    else if(key==2)
        QuickSort(num,0,length-1);
    printf("排序后的数据为\n");
    for(ii=0;ii<length;ii++)
    {
        printf("%5d",num[ii]);
    }
    return 0;
}
