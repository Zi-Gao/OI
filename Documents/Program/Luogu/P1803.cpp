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
inline int read();
struct race{
	int s,f;
};
inline bool cmp(race a,race b){
	if(a.f!=b.f){
		return a.f<b.f;
	}else{
		return a.s<b.s;
	}
	
}
race arr[1000005];
int main(){
	int n=read();
	
	for(int i=0;i<n;i++){
		arr[i].s=read();
		arr[i].f=read();
	}
	
	sort(arr,arr+n,cmp);
	
	int ft=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(arr[i].s>=ft){
			ft=arr[i].f;
			cnt++;
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
