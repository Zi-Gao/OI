/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 09:46:12
 * @LastEditTime: 2022-02-14 14:24:35
 * @LastEditors: Zi_Gao
 * @Description: 
 */
/*
6
400
300
500
300
250
600
*/
#include <cstdio>
using namespace std;
inline int read();
int main(){
	freopen("dollars.in","r",stdin);
	freopen("dollars.out","w",stdout);
	int arr[1000]={0};
	int N=read();
	
	for(int i=0;i<N;i++){
		arr[i]=read();
	}
	double dollar=100;
	for(int i=0;i<N-1;i++){
		if(arr[i]>arr[i+1]){
			dollar*=1.0*arr[i]/arr[i+1];
		}
	}

	printf("%.2lf",dollar);

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
