/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstdio>
#include <queue>

//#define file
using namespace std;
priority_queue<int> q;
inline int read();
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif
	
	int n=read();
	for(int i=0;i<n;i++){
		q.push(-read());
	}
	
	int cnt=0;
	while(!q.empty()){
		int t=q.top();
		q.pop();
		if(q.empty()){
			break;
		}
		t+=q.top();
		q.pop();
		q.push(t);
		cnt-=t;
	}
	
	printf("%d",cnt);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
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
