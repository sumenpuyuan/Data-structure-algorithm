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
    int temp=a[i];//ѡ����Ԫ��Ϊ����Ԫ��
    while(i<j)
    {
        while(a[j]>=temp && i<j)//��while1��������������ʱ���·�һ��Ҫ����if��������ж�
            j--;
        if(i<j)
            a[i++]=a[j];//���ҵ��ƶ�Ԫ�ء���С��i+1
        while(a[i]<=temp && i<j)
            i++;
        if(i<j)
            a[j--]=a[i];
    }
    a[i]=temp;//������ϣ��ѻ���Ԫ������Ŀ��
    return i;
}
void QuickSort(int a[],int i,int j)
{
    int k;//������õݹ�ʵ�֣������ǵݹ�Ľ�������
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
    printf("�������������У�����0����\n");
    for(ii=0;ii<N;ii++)
    {
        scanf("%d",&num[ii]);
        if(num[ii]==0)
            break;
    }
    length=ii;
    printf("1ð������\n2��������\n");
    scanf("%d",&key);
    if(key==1)
        bubble(num,length);
    else if(key==2)
        QuickSort(num,0,length-1);
    printf("����������Ϊ\n");
    for(ii=0;ii<length;ii++)
    {
        printf("%5d",num[ii]);
    }
    return 0;
}
