#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100
#define NULLKEY -1//定义空关键字
typedef struct
{
    int key;
    int count;//探查次数域
}HashTable[MAX];
int SearchHT(HashTable ha,int m,int k)
{
    int i=0,adr;
    adr=k%m;
    while(ha[adr].key!=NULLKEY && ha[adr].key!=k)
    {
        i++;
        adr=(adr+1)%m;
    }
    if(ha[adr].key==k)
        return adr;
    else
        return -1;
}
void InsertHT(HashTable ha,int k,int m)
{
    int i,adr;
    adr=k%m;
    if(ha[adr].key == NULLKEY)
    {
        ha[adr].key=k;
        ha[adr].count=1;
    }
    else
    {
        i=1;
        do{
            adr=(adr+1)%m;
            i++;
        }while(ha[adr].key!=NULLKEY);
        ha[adr].key=k;
        ha[adr].count=i;
    }
}
void CreateHT(HashTable ha,int x[],int n,int m)
{
    //m是哈希表大小
    //n是实际数组大小
    int i;
    for(i=0;i<m;i++)
    {
        ha[i].key=NULLKEY;
        ha[i].count=0;
    }
    for(i=0;i<n;i++)
    {
        InsertHT(ha,x[i],m);
    }
}
int main()
{
    int haValue,length,ii;
    int num[MAX];
    int cha;
    HashTable ha;
    printf("请输入要创建的哈希表大小\n");
    scanf("%d",&haValue);
    printf("请输入原始数据(个数小于%d),输入0结束\n",haValue);
    for(ii=0;ii<haValue;ii++)
    {
        scanf("%d",&num[ii]);
        if(num[ii]==0)
            break;
    }
    length=ii;
    CreateHT(ha,num,length,haValue);
    printf("成功建立哈希表\n");
    for(ii=0;ii<haValue;ii++)
        printf("%5d",ha[ii].key);
    printf("请输入要查找的数据\n");
    scanf("%d",&cha);
    cha=SearchHT(ha,haValue,cha);
    if(cha==-1)
        printf("未找到");
    else
        printf("找到了，下标为%d",cha);

}
