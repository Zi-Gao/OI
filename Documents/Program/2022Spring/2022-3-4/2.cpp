/***
 * @Author: Zi_Gao
 * @LastEditors: Zi_Gao
 * @Description: 优先队列 
 */
#include<cstdio>
//#include<queue>
#include <queue>
using namespace std;
//priority_queue <node> q;
priority_queue <int,vector<int>,greater<int> > q;
int main(){
	q.push(122314);
	q.push(100);
	q.push(156000);
	q.push(1024350);
	q.push(10040);

	printf("%d\n",q.top());
	q.pop();	
}
