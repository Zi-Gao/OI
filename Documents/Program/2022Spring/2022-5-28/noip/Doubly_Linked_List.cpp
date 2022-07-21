/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
#include <list>
//#define file
using namespace std;
inline int read();

int main(){
	#ifdef file
	freopen("Doubly_Linked_List.in", "r", stdin);
	freopen("Doubly_Linked_List.out", "w", stdout);
	#endif

	
	int n=read();
	int cnt=0;
	list<int>::iterator it;
	list<int> l;
	while(n--){
		
		char op[20]={0};
		scanf("%s",op);
		int a=0;
		if(op[0]=='i'){
			int in=read();
			l.push_front(in);
		}else if(op[0]=='d'&&op[6]=='\0'&&!l.empty()){
			int in=read();
			for (it=l.begin(); it!=l.end(); ++it)
				if(*it==in){
					l.erase(it);
					break;
				}
		}else if(op[0]=='d'&&op[6]=='F'&&!l.empty()){
			l.erase(l.begin());
		}else if(op[0]=='d'&&op[6]=='L'&&!l.empty()){
			l.erase(l.end());
		}
	}
	
	for (it=l.begin(); it!=l.end(); ++it)
		printf("%d ",*it);

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
