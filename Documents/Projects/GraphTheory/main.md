# 图论之最短路径

## 0000.什么是图

### 00.图的简介

**图论 (Graph theory)** 是数学的一个分支，图是图论的主要研究对象。**图 (Graph)** 是由若干给定的顶点及连接两顶点的边所构成的图形，这种图形通常用来描述某些事物之间的某种特定关系。顶点用于代表事物，连接两顶点的边则用于表示两个事物间具有这种关系。

在OI中，图的顶点只是抽象的一个点，连接两个点的“线”。一个图大概长这样：

### 01.图的概念

1.  **顶点**：就是下**图中的圆圈**。上面的数字就是他的编号，用来描述不同的点。

2.  **边**：下图中**连接两个圆圈的线**就是边了。

3.  **边权**：下图中边上面的数字就是边权。大概可以理解为**边的长度**，也就是两个点的距离。但实际上边**权是可以为负数**的，所以不能完全理解为边的长度。

以上是介绍图的基本组成部分。图还分种类，我只介绍简单的两种\~\~，因为其他的我不会\~\~。

1.  **无向图**：顾名思义，就是没有方向。具体来说就是 **A点到B点有边，那么B点到A点就有边，A点到B点的边权=B点到A点的边权**。

2.  **有向图**：与无向图相对，**A点到B点有边，但B点到A点不一定有边，A点到B点的边权不一定等于B点到A点的边权**。

## 0010.图的储存

我们已经了解了什么是图，但要离实现有关图的程序还要解决一个问题：**数据结构**。

我们再来观察一下这个图，里面有两个东西：点和边权。那么我们可以用一个数组储`e`来存储，其中`e[i][j]`表示**i点到j点的边权**。不连接的点用正无穷表示，至于为啥是因为方便算法设计，i=j时储存为0。

这个图存下来大概是这样：

![e](C:\Users\Administrator\Desktop\OI\Documents\Projects\GraphTheory\photo\10\e.png)

## 0011.图的遍历

之前大家学习过**深度优先搜索(Depth First Search)**，也许也有人听说过**宽度优先搜索(Breadth First Search)**。其中的“深度”和“宽度”，其实就是指在图的遍历中的访问顺序。

### 00.DFS

**深度优先搜索**顾名思义就是先遍历深度。具体说就是**一直往下走，走到底，再往上退后一层，继续往下走，直到把每一个点都遍历了****。

伪代码:

```
dfs(cur)
	print cur
	cnt+1
	if cnt=n stop
	for i:1->n
		if cur-j连接 j未遍历
			dfs(i)
```

模板代码:

```c++
/*
 *cur: 当前的点
 *cnt:遍历的点个数
 *INF:正无穷
 *e:邻接矩阵
 *dfs_book:标记数组
 */
void depthFirstSearch(int cur){
	printf("%d ",cur);
	++cnt;
	if(cnt==n) return;
	for(int i=1;i<=n;i++)
		if(e[cur][i]<INF&&dfs_book[i]==0){
			dfs_book[i]=1;
			depthFirstSearch(i);
		}
}
```

### 01.BFS

**宽度优先搜索**顾名思义就是先遍历宽度。具体就是**从一个出发，把与之相邻的每一点遍历之后，又以与之相邻的第一个点为出发点，遍历与之相邻的没遍历过的点**。

具体实现起来我们可以使用一个**队列**，是一个**先进先出(FIFO—first in first out)**的数据结构，与**栈**的数据结构相对。**我们从一个起始的顶点开始，将与之相邻的所以点入队，之后出队一个元素，这个元素就是当前所在的点。又继续将此时队列顶端的点所相邻的点入**队……重复操作，就实现了宽搜。

伪代码:

```
while head<tail and tail
	cur=que.head
	for i:1->n
		if cur-i连接 i未遍历
			que.push i
		if tail==n 
			stop
	que.pop
```

模板代码:

```c++
/*
 *cur: 当前的点
 *bfs_book:标记数组
 *INF:正无穷
 *e:邻接矩阵
 *que:队列
 *head:队头
 *tail:队尾
 */
void breadthFirstSearch(){
	bool bfs_book[MAX_SIZE]={0};
	int que[MAX_SIZE]={0},head=0,tail=0,cur=1;

	que[tail++]=cur;
	bfs_book[cur]=1;

	while(head<tail && tail<n){
		cur=que[head];
		for(int i=1;i<=n;i++){
			if(e[cur][i]!=INF && !bfs_book[i]){
				que[tail++]=i;
				bfs_book[i]=1;
			}
			if(tail==n) break;
		}
		head++;
	}

	for(int i=1;i<=n;i++)
		if(bfs_book[i]) printf("%d ",i);
}
```

## 0100.最短路径

### 00.Floyd-Warshall

Floyd-Warshall弗洛伊德算法，是处理图上**任意两点间的最短路径的算法**。

首先我们简化一下模型，缩短`e[i][j]`我们可以引入k点，使`e[i][k]+e[k][j]<e[i][j]`这样就可以缩短成功。

值得一提的是Floyd-Warshall**可以处理带负权**和**带负环**的图，但不能判别是否有**负环**的图。具体负权是指权重为负的边，负环是指总长的为负的**回路**，为什么要判别？因为如果图中出现可负环，那么就不存在短路这一说法了，只要一直转圈就可以一直缩短长度。

示意图:

![3](C:\Users\Administrator\Desktop\OI\Documents\Projects\GraphTheory\photo\100.0\3.png)

伪代码:

```
for k:1->n
	for i:1->n
		for j:1->n
			e[i][j]=min(e[i][k]+e_floyd[k][j],e[i][j])
```

模板代码:

```c++
/*
 *k:中专点
 *i:起始点
 *j:终止点
 *INF:正无穷
 *e_floyd:邻接矩阵
 */
void Floyd_Warshall(){
	memcpy(e_floyd,e,sizeof(e));

	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e_floyd[i][j]=min(e_floyd[i][k]+e_floyd[k][j],e_floyd[i][j]);

	write(e_floyd);
}
```

明显看出，其时间复杂度为O(N^3)

### 01.Dijkstra

#### 朴素版

Dijkstra/ˈdaɪkstrə/迪杰斯特拉算法是处理**一点到其余个点的短路**，也叫做"**单源最短路径**"。以下简称dij算法。

dij算法基于一个**没有负权**的图之上的一个**贪心**或者说**动归**算法。其具体原理是：**在一个没有负权的图上，我们找到一个与1号点最相近的点k，那么`e[1][k]`不可能缩短，毕竟在图上没有负权。然后我们就拿着这个点k将寻找与其相邻的点p，使得`e[1][k]+e[k][p]<e[i][p]`,并缩短`e[i][p]`为`e[1][k]+e[k][p]`这一步叫做“松弛”。松弛一轮以后，我们就可以得到一各新的点，与点1最近，继续松弛。重复操作就求到了短路**。

伪代码:

```
for i:1->n
	dis[i]=e[1][i]

for i:1->n-1
	min,u=find(dis)
	book_dij[u]=1;
	book u
	for j:1->n
		if !book j
			dis[j]=min(dis[u]+e[u][j],dis[j])
```

模板代码:

```c++
/*
 *e_floyd:邻接矩阵
 *book_dij:记录是否访问过
 *dij_dis:记录距离
 *min:记录最小距离
 *u:记录最小距离的点
 *INF:正无穷
 */
void Dijkstra(){
	bool book_dij[MAX_SIZE]={0};
	int dis[MAX_SIZE]={0},_min,u;
	book_dij[1]=1;

	for(int i=1;i<=n;i++)
		dis[i]=e[1][i];

	for(int i=1;i<n;i++){
		_min=INF;
		for(int j=1;j<=n;j++)
			if(!book_dij[j]&&dis[j]<_min){
				_min=dis[j];
				u=j;
			}
		book_dij[u]=1;
		for(int j=1;j<=n;j++)
			if(!book_dij[j])
				dis[j]=min(dis[u]+e[u][j],dis[j]);
	}

	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
}
```

可以看到dij时间复杂度是O(N^3)

#### 邻接表

这个地方我们需要一种新的存储方式**邻接表**，本质上这是一种链表，但是我们使用数组来实现，使其使用起来更简单。

邻接表是按边的方式进行的存储，我们需要把边进行编号从1->m。存储边的这一部分我们使用三个数组：`u` `v` `w`，其中`u[i]`表示**第i条边的起始点**，`v[i]`表示**第i条边的终止点**，`w[i]`表示**第i条边的边权**。然后我们还需要让边与顶点、边与边联系起来，我们使用`first[i]`表示**第i个点的第一条边**，`next[i]`表示第i条边的下一条边。

以这个图为例**(没有画图，懒了)**

```
4 5
1 4 9
4 3 8
1 2 5
2 4 6
1 3 7
```

示意图:

![邻接表](C:\Users\Administrator\Desktop\OI\Documents\Projects\GraphTheory\photo\100.1\1\邻接表.png)

遍历点1的边:

![邻接表-遍历](C:\Users\Administrator\Desktop\OI\Documents\Projects\GraphTheory\photo\100.1\1\邻接表-遍历.png)
