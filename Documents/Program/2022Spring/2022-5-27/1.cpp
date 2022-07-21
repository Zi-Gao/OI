/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
using namespace std;
inline int read();
int swap(int* l,int* r){
	while(l<r){
		*l^=*r;
		*r=*l^*r;
		*l=*l^*r;
		l++;
		r--;
	}
}
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	int arr[20]={0};
	
	for(int i=0;i<20;i++){
		arr[i]=i+1;
	}
	
	int n=7;
	int m=5;
	
	swap(arr,arr+n+m-1);
	swap(arr,arr+m-1);
	swap(arr+m,arr+n+m-1);

	for(int i=0;i<20;i++){
		printf("%d ",arr[i]);
	}

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
