/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <queue>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
multiset<pair<int,int> > s;
pair<int,int>arr[200000];
inline int read();
int main(){
//	freopen("water.in","r",stdin);
//	freopen("water.out","w",stdout);
	int n=read();


	for(int i=0;i<n;i++){
		scanf("%d %d",&arr[i].first,&arr[i].second);
	}
	
	pair<int,int> t;
	for(int i=0;i<n;i++){
		scanf("%d %d",&t.first,&t.second);
		s.insert(t);
	}


	
	sort(arr,arr+n);

	int cnt=0;
	for(int i=0;i<n;i++){//pair<int,int> a=

		pair<int,int> a=*--s.upper_bound(arr[i]);
		
		printf("\n%d %d\n%d %d\n",arr[i].first,arr[i].second,a.first,a.second);
		if(arr[i].first>=a.first&&arr[i].second>=a.second){
			s.erase(s.lower_bound(arr[i]));
			cnt++;
//			printf("YYY\n");	
//			printf("%d",cnt);
		}
		
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
