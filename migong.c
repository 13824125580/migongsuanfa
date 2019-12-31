#include<stdio.h>
#define R 7  //行；
#define C 8  //列；
int M[R+2][C+2]=   //迷宫'1'表示墙，'0'表示路；
{
    /*   0  1 2 3 4 5 6 7 8  9*/
    /*0*/1, 1,1,1,1,1,1,1,1, 1,
     
    /*1*/1, 0,0,0,1,1,1,1,1, 1,
    /*2*/1, 0,1,0,1,1,1,1,1, 1,
    /*3*/1, 0,0,0,1,1,1,1,1, 1,
    /*4*/1, 1,1,1,0,0,0,0,1, 1,
    /*5*/1, 1,1,1,0,1,1,0,1, 1,
    /*6*/1, 1,1,1,0,0,0,0,1, 1,
    /*7*/1, 1,1,1,1,1,0,0,0, 1,
      
    /*8*/1, 1,1,1,1,1,1,1,1, 1
};
int t[R+2][C+2]={0};  //与迷宫相同的二维数组，用来表示该条路有没有走；
int Move[4][2]=      //记录走的方向；
{
    {1,0},    //向南走；
    {0,1},    //向东走；
    {-1,0},   //向北走；
    {0,-1}    //向西走；
};
int stack[100][2];   //用来存放路径的栈；
int top;
int sum=0;
 
//输出；
void Print(int sum)
{
    int i;
    printf("迷宫的第%d条路径如下:\n",sum);
    for(i=0;i<=top;i++)
        printf("(%d,%d)->",stack[i][0],stack[i][1]);
    printf("出口");
    printf("\n");
}
 
//调用迷宫函数；
void Maze(int x,int y)
{
    if(x==7&&y==8)
    {
        sum++;
        Print(sum);
    }
    else
    {
        int i; 
        for(i=0;i<4;i++)       //遍历四个方向；
        {
            int a=x+Move[i][0];    //找到下一个要走位置的x；
            int b=y+Move[i][1];    //找到下一个要走位置的y；
            if(!M[a][b]&&!t[a][b]) //判断这个位置可不可以走；
            {
                t[a][b]=1; //用数组t,M记录这个位置已经走过了；
                top++;             //将top++用来存储下一个位置坐标；
                stack[top][0]=a;   //将横坐标x存入stack数组中；
                stack[top][1]=b;   //将纵坐标y存入stack数组中；
                Maze(a,b);         //继续寻找下一个位置；
                t[a][b]=0; //回溯之后需要将这个位置清空，表示这条路没有走过；
                top--;             //并且将这个位置从栈中去除；
            }
        }
    }
}
 
int main(void)
{
    //迷宫初始化；
    stack[0][0]=1;     //存放起点的x，y的坐标；
    stack[0][1]=1;
    top=0;             //top++表示已经存放了开始坐标；
    t[1][1]=M[1][1]=1; //表示第一个位置已经走过了；
    Maze(1,1);
    return 0;
}
