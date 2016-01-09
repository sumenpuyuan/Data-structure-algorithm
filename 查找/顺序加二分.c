#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define N 50
int orderSee(int num[],int n,int key)
{
    int ii;
    for(ii=0;ii<n;ii++)
    {
        if(num[ii] == key)
            return ii;
    }
    return -1;
}
int BinarySearch(int a[],int n,int key)
{
    int l=0;
    int h=n-1;
    int m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(key == a[m])
            return m;
        if(key<a[m])
            h=m-1;
        else
            l=m+1;
    }
    return -1;
}
int main()
{
    int num[N];
    int length;
    int ii,key,index;
    int res;
    printf("请输入原始数据,输入0结束输入\n");
    for(ii=0;ii<N;ii++)
    {
        scanf("%d",&num[ii]);
        if(num[ii]==0)
            break;
    }
    length=ii;
    while(1)
    {

        printf("请输入要查找的数据\n");
        scanf("%d",&key);
        puts("1顺序查找");
        puts("2折半查找");
        puts("请输入序列号");
        scanf("%d",&index);
        switch(index)
        {
            case 1:res=orderSee(num,length,key);break;
            case 2:res=BinarySearch(num,length,key);break;
            default:break;
        }
        if(res==-1)
            printf("未找到\n");
        else
            printf("找到了，位置是%d\n",res+1);
        getch();
        system("cls");

    }

    //printf("Hello world!\n");
    return 0;
}
