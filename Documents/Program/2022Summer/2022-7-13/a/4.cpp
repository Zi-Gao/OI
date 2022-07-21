/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
using namespace std;
inline int read();

#define MAX_SIZE 10000
struct fa{
	int arr[MAX_SIZE];
	
	fa(){
		for(int i=1;i<MAX_SIZE;i++){
			arr[i]=i;
		}
		return;
	}
	
	inline int find(int x){
		return x==arr[x]?x:(arr[x]=find(arr[x]));
	}
	
	inline int find_b(int x){
		while(arr[x]!=x){
			x=arr[x];
		}
		return x;
	}
	
	inline void merge(int i,int j){
		arr[find(i)]=find(j);
		return;
	}
	
	void clear(){
		for(int i=1;i<MAX_SIZE;i++){
			arr[i]=i;
		}
		return;
	}
};


int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif
	
	fa f;
	read();
	int m=read();
	int z;
	
	for(int i=0;i<m;i++){
		z=read();
		if(z==1){
			f.merge(read(),read());
		}else{
			if(f.find(read())==f.find(read())){
				printf("Y\n");
			}else{
				printf("N\n");
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
