/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <queue>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
priority_queue <int> q;
pair<int,int> arr[1000];

inline int read();
int main(){
	int n=read();
	for(int i=0;i<n;i++){
		arr[i].second=read();
		arr[i].first=read();
	}
	sort(arr,arr+n);
	multiset<int> s;
	for(int i=0;i<n;i++){
		if(s.size()>0&&*s.begin()<=arr[i].second){
			s.erase(--s.upper_bound(arr[i].second));
			s.insert(arr[i].first);
		}else{
			s.insert(arr[i].first);
		}
	}
	printf("%d",s.size());
	
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
