/***
 * @Author: Zi_Gao
 * @LastEditors: Zi_Gao
 * @Description: 优先队列 
 */
#include<cstdio>
#include <queue>
using namespace std;
priority_queue <int,vector<int>,less<int> > q;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	
	int n=read();
	int k=read();
	int arr[1100]={0};
	for(int i=0;i<n;i++){
		q.push(read());
	}
	
	int cnt=0;
	while(!q.empty()){
		int t=q.top();
		q.pop();
		if(q.empty()){
			cnt=t;
			break;
		}
		t+=q.top();
		q.pop();
		q.push(t/k);
		cnt=t;
	}
	
	printf("%d",cnt);
}
