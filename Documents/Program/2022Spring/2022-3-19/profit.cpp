/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 09:46:12
 * @LastEditTime: 2022-02-14 14:24:35
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#pragma GCC optimze(2)
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
inline int read();
priority_queue<int> q;
int main(){
	freopen("profit.out","w",stdout);
	freopen("profit.in","r",stdin);
	int n=read(),x;
	long long z=0;
	for(int i=0;i<n;i++){
		x=read();
		q.push(-x);
		q.push(-x);
		z+=x+q.top();
		q.pop();
	}
	printf("%lld",z);
    return 0;
}
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
