/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <list>
#define file
using namespace std;
inline int read();
int main(){
	#ifdef file
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	#endif
	
	int n=read();
	int m=read();
	
	list<int> l;
	
	
	for(int i=1;i<=n;i++)
		l.push_back(i);
		
	while(!l.empty()){
		list<int>::iterator it=l.begin();
		for(int i=1;i<m;i++){
			int t=l.front();
			l.erase(it);
			l.push_back(t);
			it=l.begin();
		}
		it=l.begin();
		printf("%d ",l.front());
		l.erase(it);
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
