/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 09:46:12
 * @LastEditTime: 2022-02-14 14:24:35
 * @LastEditors: Zi_Gao
 * @Description: 
4
7 9 3 6 4 2 5 3
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
inline int read();
int qpow(int a, int b) {
    int ans = 1;
    if(b==0){
        return 1;
    }
    if(b%2==0){
        ans=qpow(a,b/2);
        ans=ans*ans;
    }else{
        ans=qpow(a,b-1);
        ans=ans*a;
    }
    return ans;
}
int main(){
	int N=read();
	int arr[1000]={0};
	int x[1000]={0};
	int y[1000]={0};
	
	for(int i=1;i<=N;i++){
		arr[i]=read();
	}

	sort(arr+1,arr+N+1);
	bool flag[1000]={0};
	if(N%2==1){
		int intY=0,intX=0;
		for(int j=N;j>N/2+1;j--){
			intY+=qpow(10,j-N/2-2)*arr[j];
			flag[j]=true;
		}
		int i=1;
		for(int j=1;i<=N/2+1;j--){
			if(i==1){
				int temp=1;
				for(temp=1;arr[temp]==0;temp++){
				}
				intX+=qpow(10,N/2-i+1)*arr[temp];
				flag[temp]=true;
				i++;
			}
			if(flag[j]==true){
				continue;
			}
			intX+=qpow(10,N/2-i+1)*arr[j];
			flag[j]=true;
			i++;
		}
		printf("%d %d",intY,intX);
	}else{
		
	}

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
