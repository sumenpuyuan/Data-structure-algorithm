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
    printf("������ԭʼ����,����0��������\n");
    for(ii=0;ii<N;ii++)
    {
        scanf("%d",&num[ii]);
        if(num[ii]==0)
            break;
    }
    length=ii;
    while(1)
    {

        printf("������Ҫ���ҵ�����\n");
        scanf("%d",&key);
        puts("1˳�����");
        puts("2�۰����");
        puts("���������к�");
        scanf("%d",&index);
        switch(index)
        {
            case 1:res=orderSee(num,length,key);break;
            case 2:res=BinarySearch(num,length,key);break;
            default:break;
        }
        if(res==-1)
            printf("δ�ҵ�\n");
        else
            printf("�ҵ��ˣ�λ����%d\n",res+1);
        getch();
        system("cls");

    }

    //printf("Hello world!\n");
    return 0;
}
