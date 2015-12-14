//
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int InsertSort(int arr[],int length)
{
    int ii,ij,n=length;
    int target;
    for(ii=1;ii<n;ii++)
    {
        ij=ii;
        target=arr[ii];
        while(ij>0 && target<arr[ij-1])
        {
            arr[ij]=arr[ij-1];
            ij--;
        }
        arr[ij]=target;
    }
}
void ShellSort(int arr[],int length)
{
    int n=length;
    int ii,ij,gap;
    int temp;
    gap=n/2;
    while(gap>0)
    {
        for(ii=gap;ii<n;ii++)//对所有相隔gap位置的元素进行直接插入·排序
        {
            temp=arr[ii];
            ij=ii-gap;
            while(ij>=0 && temp<arr[ij])
            {
                arr[ij+gap]=arr[ij];
                ij=ij-gap;
            }
            arr[ij+gap]=temp;
        }
        gap=gap/2;
    }

}
int main()
{
    int arr[MAX];
    int ii,length;
    int key;
    printf("请输入要插入的数据，本算法将使用插入排序排序（输入0结束）\n");
    for(ii=0;ii<MAX;ii++)
    {
        scanf("%d",&arr[ii]);
        if(arr[ii]==0)
            break;
        else;
    }
    length=ii;
    printf("1直接插入排序\n2希尔排序\n");
    scanf("%d",&key);
    if(key==1)
        InsertSort(arr,length);
    else if(key==2)
        ShellSort(arr,length);
    else
        printf("你的输入有误\n");
    for(ii=0;ii<length;ii++)
    {
        printf("%5d",arr[ii]);
    }
}
