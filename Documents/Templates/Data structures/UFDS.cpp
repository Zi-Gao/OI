/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
using namespace std;
inline int read();

const int MAX_SIZE=100;
struct UFDS{
	int parents[MAX_SIZE];

	UFDS(){
		for(register int i=1;i<MAX_SIZE;++i)
			parents[i]=i;
		return;
	}

	inline int find(int x){
		return x==parents[x]?x:(parents[x]=find(parents[x]));
	}

	inline int find_b(int x){
		while(parents[x]!=x)
			x=parents[x];
		return x;
	}

	inline void merge(int i,int j){
		parents[find(i)]=find(j);
		return;
	}

	void clear(){
		for(int i=1;i<MAX_SIZE;i++)
			parents[i]=i;
		return;
	}
};


int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif


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
