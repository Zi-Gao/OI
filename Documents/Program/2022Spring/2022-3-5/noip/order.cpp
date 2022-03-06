#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
int main(){
	freopen("order.in","r",stdin);
	freopen("order.out","w",stdout);

	int n=read();
	int arr[1100]={0};
	for(int i=0;i<n;i++){
		arr[i]=read(); 
	}
	
	stable_sort(arr,arr+n);
	
	float j=0;
	for(int i=0;i<n;i++){
		j+=arr[i]*(n-i);
	}
	
	printf("%.2f",j/n);	
}
