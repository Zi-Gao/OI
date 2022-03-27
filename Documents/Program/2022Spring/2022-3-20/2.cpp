/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
priority_queue <int> q;
pair<int,int> arr[1000];

inline int read();
int main(){
	int n=read();
	for(int i=0;i<n;i++){
		arr[i].first=read();
		arr[i].second=read();
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		if(!q.empty()&&-q.top()<=arr[i].first){
			q.pop();
			q.push(-arr[i].second);
		}else{
			q.push(-arr[i].second);
		}
	}
	printf("%d",q.size());
	
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
