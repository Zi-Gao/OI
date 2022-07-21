/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
#define file
using namespace std;
inline int read();

#define MAX_SIZE 1000+10
struct fa{
	int arr[MAX_SIZE];
	
	fa(){
		for(int i=1;i<MAX_SIZE;i++){
			arr[i]=i;
		}
		return;
	}
	
	inline int find(int x){
		return x==arr[x]?x:(arr[x]=find(arr[x]));
	}
	
	inline int find_b(int x){
		while(arr[x]!=x){
			x=arr[x];
		}
		return x;
	}
	
	inline void merge(int i,int j){
		arr[find(i)]=find(j);
		return;
	}
	
	void clear(){
		for(int i=1;i<MAX_SIZE;i++){
			arr[i]=i;
		}
		return;
	}
}f;

struct node{
	int x,y,l;
}arr[10000+10];

bool cmp(node a,node b){
	if(a.l!=b.l){
		return a.l<b.l;
	}
	if(a.x!=b.x){
		return a.x<b.x;
	}
	return a.y<b.y;
}

int main(){
	#ifdef file
	freopen("cloud.in", "r", stdin);
	freopen("cloud.out", "w", stdout);
	#endif
	
	int n=read();
	int m=read();
	int k=read();
	int cnt=n;
	int p=0;
	
	if(k>n){
		printf("No Answer");
		return 0;
	}
	
	for(int i=0;i<m;i++){
		arr[i].x=read();
		arr[i].y=read();
		arr[i].l=read();
	}

	sort(arr,arr+m,cmp);
	
	for(int i=0;i<m;i++){
		if(cnt==k)break;
		if(f.find(arr[i].x)!=f.find(arr[i].y)){
			cnt--;
			p+=arr[i].l;
			f.merge(arr[i].x,arr[i].y);
		}
	}
	
	printf("%d",p);

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
