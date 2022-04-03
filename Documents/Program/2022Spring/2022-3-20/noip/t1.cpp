#include <cstdio>
#include <queue>
using namespace std;
inline int read();
priority_queue<int,vector<int>, greater<int> >q; 
int main(){
	freopen("t1.out","w",stdout);
	freopen("t1.in","r",stdin);
	int n=read();
	int sum=0;
	for(int i=0;i<n;i++){
		q.push(read());
	}
	while(!q.empty()){
		sum+=q.top()*q.size();
		q.pop();
	}
	printf("%d",sum);
	
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
