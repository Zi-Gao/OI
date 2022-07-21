/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
using namespace std;
inline int read();

#define MAX_SIZE 5000+10
struct fa{
	int arr[MAX_SIZE],rank[MAX_SIZE];
	
	fa(){
		for(int i=1;i<MAX_SIZE;i++){
			arr[i]=i;
			rank[i]=1;
		}
		return;
	}
	
//	inline int find(int x){
//		return x==arr[x]?x:(arr[x]=find(arr[x]));
//	}
	
	inline int find(int x){
		while(arr[x]!=x){
			x=arr[x]=arr[arr[x]];//What the fuck?
		}
		return x;
	}
	
	inline void merge(int i,int j){
		arr[find(i)]=find(j);
		return;
	}
	
	inline void merge_b(int i,int j){
		if(rank[i]<rank[j]){
			arr[find(i)]=find(j);
		}else{
			arr[find(j)]=find(i);
		}
		
		if(rank[i]==rank[j]&&i!=j){
			rank[j]++;
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
	int n=read();
	int m=read();
	int p=read();
	
	for(int i=0;i<m;i++){
		f.merge_b(read(),read());
	}
	
	for(int i=0;i<p;i++){
		puts(f.find(read())==f.find(read())?"Yes":"No");
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
