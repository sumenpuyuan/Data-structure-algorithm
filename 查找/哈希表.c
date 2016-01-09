#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100
#define NULLKEY -1//����չؼ���
typedef struct
{
    int key;
    int count;//̽�������
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
    //m�ǹ�ϣ���С
    //n��ʵ�������С
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
    printf("������Ҫ�����Ĺ�ϣ���С\n");
    scanf("%d",&haValue);
    printf("������ԭʼ����(����С��%d),����0����\n",haValue);
    for(ii=0;ii<haValue;ii++)
    {
        scanf("%d",&num[ii]);
        if(num[ii]==0)
            break;
    }
    length=ii;
    CreateHT(ha,num,length,haValue);
    printf("�ɹ�������ϣ��\n");
    for(ii=0;ii<haValue;ii++)
        printf("%5d",ha[ii].key);
    printf("������Ҫ���ҵ�����\n");
    scanf("%d",&cha);
    cha=SearchHT(ha,haValue,cha);
    if(cha==-1)
        printf("δ�ҵ�");
    else
        printf("�ҵ��ˣ��±�Ϊ%d",cha);

}
