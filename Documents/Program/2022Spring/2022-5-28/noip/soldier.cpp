/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
#include <list>
#define file
using namespace std;
inline int read();
list<int> l;
int main(){
	#ifdef file
	freopen("soldier.in", "r", stdin);
	freopen("soldier.out", "w", stdout);
	#endif

	
	int n=read();
	int cnt=0;
	list<int>::iterator it;
	while(n--){
		l.clear();
		int p=read();
		for(int i=1;i<=p;i++){
			l.push_back(i);
		}
		while(1){
			int i=1;
			if(l.size()<=3){
				goto loop;
			}
			for (it=l.begin(); it!=l.end(); ++it){
				if(i%2==0){
					it=--l.erase(it);
				}
				i++;

			}
			if(l.size()<=3){
				goto loop;
			}
			i=1;
			for (it=l.begin(); it!=l.end(); ++it){
				if(i%3==0){
					it=--l.erase(it);
				}
				i++;
			}

		}
		loop:;
		for (it=l.begin(); it!=l.end(); ++it)
			printf("%d ",*it);
		putchar('\n');
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
