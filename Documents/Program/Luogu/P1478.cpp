/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include<queue>

using namespace std;
struct node
{
	int x,y;
	bool operator < (const node & a) const
	{
		return y>a.y;
	}
};
priority_queue <node> q;
int len=0;
int s;
inline int read();
int main(){
	int n=read();
	s=read();
	len=read()+read();
	node t;
	for(int i=0;i<n;i++){
		t.x=read();
		t.y=read();
		q.push(t);
	}
	int cnt=0;
	while(q.size()!=0){
		
		if(q.top().x<=len){
			s-=q.top().y;
			if(s<0){
				break;
			}
			cnt++;
		}
		q.pop();
	}
	printf("%d",cnt);
	
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
