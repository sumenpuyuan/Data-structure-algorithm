#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
int num[N];
int b[N];
void Merge(int a[],int s1,int e1,int s2,int e2,int b[])
{
    int k=s1;
    int i=s1;
    while(s1<=e1  && s2<=e2)
    {
        if(a[s1]<=a[s2])
            b[k++]=a[s1++];
        else
            b[k++]=a[s2++];
    }
    while(s1<=e1)
        b[k++]=a[s1++];
    while(s2<=e2)
        b[k++]=a[s2++];
    k--;
    while(k>=i)
    {
        a[k]=b[k];
        k--;
    }
}
void MergeSort(int a[],int i,int j,int b[])
{
    int k;
    if(i<j)
    {
        k=(i+j)/2;
        MergeSort(a,i,k,b);
        MergeSort(a,k+1,j,b);
        Merge(a,i,k,k+1,j,b);
    }


}
int main()
{
    int ii,length;
    printf("请输入数据，输入0结束\n");
    for(ii=0;ii<N;ii++)
    {
        scanf("%d",&num[ii]);
        if(num[ii]==0)
            break;
    }
    length=ii;
    MergeSort(num,0,length-1,b);
    printf("排序后的数据为\n");
    for(ii=0;ii<length;ii++)
    {
        printf("%5d",num[ii]);
    }

}
