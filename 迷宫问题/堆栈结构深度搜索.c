//blog：http://sumenpuyuan.com/2015/11/23/%E8%BF%B7%E5%AE%AB%E9%97%AE%E9%A2%98%E6%9C%80%E4%BC%98%E8%A7%A3-%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0/
#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <conio.h>
#define MAXSIZE 1024
typedef int elemtype;
typedef struct
{
    int row;//横坐标方向
    int column;//纵坐标方向
    int direction;//从当前路径查找下一个方块的方向

}SElemType;
typedef struct SequenStack
{
    SElemType data[MAXSIZE];
    int top;//top为栈顶指针
}SequenStack;
//栈的初始化

SequenStack* Init_SequenStack()
{
    SequenStack *s;
    s=(SequenStack *)malloc(sizeof(SequenStack));
    s->top=-1;
    return s;

}
//判断栈是否为空
int SequenStack_Empty(SequenStack *s)
{
    if(s->top==-1)
        return 1;//栈为空，。返回1
    else
        return 0;

}
//入栈
int Push_SequenStack(SequenStack *s,SElemType x)
{
        s->top++;
        s->data[s->top].row=x.row;
        s->data[s->top].direction=x.direction;
        s->data[s->top].column=x.column;
        return 1;
}
//出栈
int Pop_SequenStack(SequenStack *s,SElemType *x)
{
    if(s->top==-1)
    {
        puts("栈为空");
        return 0;
    }
    else{

        x->column=s->data[s->top].column;
        x->direction=s->data[s->top].direction;
        x->row=s->data[s->top].row;
         s->top--;
        return 1;
    }
}
//区栈顶元素
int GetTop_SequenStack(SequenStack *s,SElemType *x)
{
    if(s->top==-1)
    {
        puts("栈为空");
        return 0;
    }
    else{
        x->column=s->data[s->top].column;
        x->direction=s->data[s->top].direction;
        x->row=s->data[s->top].row;
        return 1;
    }



}


#define SIZE 7

int Maze[SIZE][SIZE]={
    {1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1},
    {1,0,1,1,1,0,1},
    {1,0,0,0,0,0,1},
    {1,0,1,1,1,1,1},
    {1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1}

   /* {1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1},
    {1,0,1,1,1,1,1},
    {1,0,0,0,0,0,1},
    {1,0,1,1,1,1,1},
    {1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1}

*/
};
typedef struct
{
    int x;
    int y;
}Direction;
Direction Move[5]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};//存储东南西北方向

//typedef SElemType elemtype;
int path(SequenStack *s,int Maze[SIZE][SIZE],Direction Move[5]);
int main()
{
    int ii,ij,key;
    SequenStack *s;
     for(ii=0;ii<SIZE;ii++)
    {
        for(ij=0;ij<SIZE;ij++)
        {
            if(Maze[ii][ij]==1)
                printf("▉");
            else
                printf("  ");

        }
        printf("\n");
    }
    printf("\n\n\n");
    s=Init_SequenStack();
    key=path(s,Maze,Move);
    if(key==1)
    {
        for(ii=0;ii<SIZE;ii++)
        {
            for(ij=0;ij<SIZE;ij++)
            {
                if(Maze[ii][ij]==1)
                    printf("▉");
                else if(Maze[ii][ij]==-1)
                    printf("☆");
                else
                    printf("  ");

            }
            printf("\n");
        }
    }
    else
    {
          for(ii=0;ii<SIZE;ii++)
        {
            for(ij=0;ij<SIZE;ij++)
            {
                if(Maze[ii][ij]==1)
                    printf("▉");
                else if(Maze[ii][ij]==-1)
                    printf("☆");
                else
                    printf("  ");

            }
            printf("\n");
        }
         printf("没有出路");
    }

}
int path(SequenStack *s,int Maze[SIZE][SIZE],Direction Move[5])
{

    SElemType temp;//声明临时变量
    SElemType tryPath;
    int x,y,d,i,j,trytime;
    temp.row=1;
    temp.column=1;
    temp.direction=0;
    Maze[1][1]=-1;
    Push_SequenStack(s,temp);
    while(!SequenStack_Empty(s))
    {
        GetTop_SequenStack(s,&temp);
        x=temp.row;
        y=temp.column;
        d=temp.direction+1;//设置当前路径
        trytime=0;
        while(d<=4)
        {
            i=x+Move[d].x;
            j=y+Move[d].y;
            if(Maze[i][j]==0)
            {
                if(trytime==0)
                {
                    Pop_SequenStack(s,&tryPath);
                    tryPath.direction=d;

                    Push_SequenStack(s,tryPath);
                    trytime++;
                }
                temp.row=i;
                temp.column=j;
                temp.direction=1;
                Push_SequenStack(s,temp);//将新的路径方块入栈
                x=i;y=j;
                Maze[x][y]=-1;//在迷宫中留下足迹
                if(x==SIZE-2 && y==SIZE-2)
                {
                    return 1;//如果到达出口，则完成查找，返回调用函数
                }
                else{
                    d=1;//重置方向，继续查找
                }
            }
            else
            {
                d++;
                trytime=0;
            }
        }
        if(d==5 && !SequenStack_Empty(s))
        {
            Pop_SequenStack(s,&temp);
            Maze[x][y]='X';//在迷宫中标记次方块不可通过

        }
    }
    return 0;
}
