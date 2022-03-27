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
int main(){
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	int arr[40000]={0};
	int w=read();
	int n=read();
	for(int i=0;i<n;i++){
		arr[i]=read();
	}
	sort(arr,arr+n);

	int cnt=0;
	int l=0,r=n-1;
	while(l<=r){
		if(arr[r]+arr[l]<=w){
			cnt++;
			l++;
			r--;
		}else{
			cnt++;
			r--;
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
