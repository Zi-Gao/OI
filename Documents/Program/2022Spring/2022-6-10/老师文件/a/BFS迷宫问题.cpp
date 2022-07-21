#include <cstdio>
#include <iostream>
using namespace std;

struct node {
	int x;   //横坐标 
	int y;   //纵坐标 
	int s;   //步数 
};

int main() {
	int n, m, startx, starty, p, q, tx, ty;
	struct node que[2501];
	int head, tail;
	int nxt[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};   //向右走、向下走、向左走、向上走
	int a[51][51] = {0}, book[51][51 ] ={0};
	
	//读入 n和 m,n为行，m为列 
	cin >> n >> m;
	//读入迷宫
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		} 
	}		
	//读入起点和终点坐标
	cin >> startx >> starty >> p >> q;	
	//队列初始化
	head = tail = 1;
	//起点入队列
	que[tail].x = startx;
	que[tail].y = starty;	
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	int flag = 0;   //用来标记是否到达目标点，0表示暂时还没有到达，1表示到达
	while(head < tail) {  //当队列非空时循环
		//顺时针枚举四个方向的走法
		for(int k = 0; k < 4; k++) {
			//计算下一个点的坐标
			tx = que[head].x + nxt[k][0];
			ty = que[head].y + nxt[k][1];
			//判断是否越界
			if(tx < 1 || tx > n || ty < 1 || ty > m)
				continue;
			//判断该点是否为障碍物或者已经在路径中
			if(a[tx][ty] == 0 && book[tx][ty] == 0)	{
				book[tx][ty] = 1;        //标记这个点已经走过
			    //插入新的点到队列中
				que[tail].x = tx;
				que[tail].y = ty;			
				que[tail].s = que[head].s + 1;   //步数是上一节点的步数+1 
				tail++; 
			} 
			//如果到目标点了，停止扩展，任务结束，退出循环
			if(tx == p && ty == q) {
				flag = 1;
				break;
			} 
		} 
		if(flag == 1) break;
	    head++;    //扩展完当前点之后，把这个点出队，即head++，这样才能继续扩展后面的点		
	} 	
	//打印队列中末尾（目标点）的步数
	cout << que[tail-1].s;
	
	return 0;
}


