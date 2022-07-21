/*
这个题要求某一段的区间最大值 
要想O(1)求区间和
只能用前缀和 
*/
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
deque<int> q;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n,m;//题目中的n,m 
	cin >> n >> m;
	int a[300001]={0};
	
	for(int i=1;i<=n;i++){
		cin >> a[i];//输入 
		a[i]=a[i]+a[i-1];//求前缀和 
	}
	
	int Max=a[1];//求最大值Max 
	//主代码 
	for(int i=1;i<=n;i++){
		//维持单调队列 
		while(!q.empty() && a[q.back()]>=a[i]) q.pop_back();//维持单调性 
		q.push_back(i);//进入队列

		//如何保持从i到i-m这段区间某个区间的值最大 
		//这个区间的右端点越大，左端点越小
		//区间最值越大 
		//即前缀和最大减去前缀和最小（头减尾）
		Max=max(Max,a[q.back()]-a[q.front()]);
		if(i-m>0){
			//维护滑动窗口 
			if(q.front()==i-m){
				q.pop_front();
			}
			if(q.back()==i-m){
				q.pop_back();
			}
		}
	}
	cout << Max;	
	return 0;
}
/*
样例 
1,-3,5,1,-2,3
6 4 
1 -3 5 1 -2 3
*/
