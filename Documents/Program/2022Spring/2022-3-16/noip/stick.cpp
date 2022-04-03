/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 09:46:12
 * @LastEditTime: 2022-02-14 14:24:35
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include<algorithm>
using namespace std;
struct stick{
	int l;
	int w;
}arr[2000];
int g[2000];
int k=1;
inline bool cmp(stick a,stick b){
	if(a.l!=b.l){
		return a.l<b.l;
	}else{
		return a.w<b.w;
	}
}
inline int read();
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int n=read();

	for(int i=0;i<n;i++){
		arr[i].l=read();
		arr[i].w=read();
	}

	sort(arr,arr+n,cmp);
	
//	for(int i=0;i<n;i++){
//		printf("%d %d\n",arr[i].l,arr[i].w);
//	}

	g[0]=arr[0].w;
	for(int i=1;i<n;i++){
		int _max=0x80000000;
		int temp=0;
		for(int j=0;j<k;j++){
			if(g[j]>_max&&g[j]<=arr[i].w){
				_max=g[j];
				temp=j;
			}
		}
		if(_max==0x80000000){
			g[k]=arr[i].w;
			k++;
		}else{
			g[temp]=arr[i].w;
		}
		
	}

	printf("%d",k);
	
	
	

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
