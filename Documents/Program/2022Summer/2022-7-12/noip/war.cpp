/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
#define file
using namespace std;
inline int read();

#define MAX_SIZE 30000+10
struct fa{
	int arr[MAX_SIZE],w[MAX_SIZE];
	
	fa(){
		for(int i=1;i<MAX_SIZE;i++){
			arr[i]=i;
			w[i]=1;
		}
		return;
	}
	
	inline int find_b(int x){
		while(arr[x]!=x){
			x=arr[x];
		}
		return x;
	}
	
	inline int find(int i,int j){
		int x=i;
		int y=j;
		int cnt=0;
		while(true){
			if(x==j)return cnt-1;
			if(arr[x]==x)break;
			x=arr[x];
			cnt++;
		}
		
		cnt=0;
		while(true){
			if(y==i)return cnt-1;
			if(arr[y]==y)break;
			y=arr[y];
			cnt++;
		}

		return -1;
	}
	
	inline void merge(int i,int j){
		arr[find_b(i)]=arr[j];
		return;
	}
	
	void clear(){
		for(int i=1;i<MAX_SIZE;i++){
			arr[i]=i;
		}
		return;
	}
}f;
/*
4 
M 2 3 
C 1 2 
M 2 4 
C 4 2
*/
int main(){
	#ifdef file
	freopen("war.in", "r", stdin);
	freopen("war.out", "w", stdout);
	#endif
	
	fa f;
	
	int T=read(),a,b;
	char op;
	for(int i=0;i<T;i++){
		loop:op=getchar();
		if(op=='\n') goto loop;
		a=read();
		b=read();
		if(op=='M'){
			f.merge(a,b);
		}else{
			if(a==b){
				printf("0\n");
			}else{
				printf("%d\n",f.find(a,b));
			}
		}
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
