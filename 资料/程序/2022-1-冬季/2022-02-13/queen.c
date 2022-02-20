/*
 * @Author: Zi_Gao
 * @Date: 2022-02-13 17:13:51
 * @LastEditTime: 2022-02-13 17:13:51
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <stdio.h>
#include <stdlib.h>
#define max 5
//sum用于描述解的可能的个数，每当输出一次复合要求的位置
//sum的数量就会被+1
int queen[max], sum=0; /* max为棋盘最大坐标 */

void show() /* 输出所有皇后的坐标 */
{
    int i;
    printf("(");
    //i代表行数，queen[i]代表当前行元素所处的列数，
    //注意此处下标是从0开始的

    for(i = 0; i < max; i++)
    {
         printf(" %d", queen[i]+1);
    }
    printf(")\n");
    //每次输出一种解的时候，那么他的解的数量就会增加1
    sum++;
}

//此函数用于判断皇后当前皇后是否可以放在此位置
int PLACE(int n) /* 检查当前列能否放置皇后 */
{
    //queen[i] == queen[n]用于保证元素不能再同一列
    //abs(queen[i] - queen[n]) == abs(n - i)用于约束元素不能再同一行且不能再同一条斜线上
    int i;
    for(i = 0; i < n; i++) /* 检查横排和对角线上是否可以放置皇后 */
    {
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == abs(n - i))
        {
            return 0;
        }
    }
    return 1;
}

//核心函数，回溯法的思想
void NQUEENS(int n) /* 回溯尝试皇后位置,n为横坐标 */
{
    int i;
    for(i = 0; i < max; i++)
    {
        //首先将皇后放在第0列的位置，对于第一次来说是肯定成立的
        //所以第一次将皇后放在第0行0列的位置
        queen[n] = i; /* 将皇后摆到当前循环到的位置 */
        if(PLACE(n))
        {
            if(n == max - 1)
            {
                show(); /* 如果全部摆好，则输出所有皇后的坐标 */
            }
            else
            {
                NQUEENS(n + 1); /* 否则继续摆放下一个皇后 */
            }
        }
    }
}

int main()
{
    NQUEENS(0); /* 从横坐标为0开始依次尝试 */
    printf("\n");
    printf("总共的解法有%d种\n", sum);

    return 0;
}

