/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 09:46:12
 * @LastEditTime: 2022-02-14 14:24:35
 * @LastEditors: Zi_Gao
 * @Description: 
 */
/*
1
10000000
01000000
2
01000000
00100000
3
11000000
10100000
4
00100000
00010000
78
01110010
11001010
0

2
01000000
4
00100000
5
10100000
8
00010000
83
11001010
0

*/
#include <cstdio>
#include <cstring>
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
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	
	int temp=read();
	int arr[100];
	int i,j,k,out;
	int cnt;
	while(temp){
		i=0;
		cnt=0;
		memset(arr,0,sizeof(arr));
		
		while(temp){
			arr[i]=temp&1;
			temp=temp>>1;
			i++;
		}

		for(j=0;j<40;j++){
			if(arr[j]==1&&arr[j+1]==0){
				arr[j+1]=1;
				arr[j]=0;
				break;
			}
			cnt+=arr[j];
		}
		
		for(k=0;k<=j;k++){
			if(cnt>0){
				arr[k]=1;
			}else{
				arr[k]=0;
			}
			cnt--;
		}
		
		out=0; 
		for(j=0;j<40;j++){
			out+=qpow(2,j)*arr[j];
		}
		printf("%d\n",out);
		temp=read();
	}
	
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
