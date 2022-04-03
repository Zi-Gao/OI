/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 09:46:12
 * @LastEditTime: 2022-02-14 14:24:35
 * @LastEditors: Zi_Gao
 * @Description: 
3 6
-50 -47 36 -30 -23
17 -19 -34 -13 -8
-42 -3 -43 34 -45
 */
#include <cstdio>
using namespace std;
inline int read();
int in[200][30000]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m=read(),n=read(),t;
	int arr[30000]={0};
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n-1;j++){
			if(i==0){
				arr[j]=read();
			}else{
				t=read();
				if(t>arr[j]){
					arr[j]=t;
				}
			}
		}
	}
	
//	for(int i=0;i<n-1;i++){
//		printf("%d ",arr[i]);
//	}
//	putchar('\n');
	
	int sum[30000]={0};
	
	for(int i=0;i<n-1;i++){
		sum[i+1]=arr[i]+sum[i];
	}
//	
//	for(int i=0;i<n;i++){
//		printf("%d ",sum[i]);
//	}
	
	int _max=0x80000000;
	
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n-1;j++){
			if(_max<sum[j]-sum[i]){
				_max=sum[j]-sum[i];
			}
			
		}
	}
	
	printf("%d",_max);
	
	
	
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
