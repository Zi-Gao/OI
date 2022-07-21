/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
inline int read();
char tree[200+10];
bool flag;
int n;
void dfs(int now){
	if(flag) return;
	if(tree[now<<1]^tree[(now<<1)+1]){
		flag=true;
		return;
	}
	if(tree[now<<1]){
		dfs(now<<1);
		dfs((now<<1)+1);
	}
}
int main(){
	#ifdef file
	freopen("tree_c.in", "r", stdin);
	freopen("tree_c.out", "w", stdout);
	#endif

	char t;
	n=1;
	while(~scanf("%c",&t)){
		if(t=='\n') break;
		if(t!='#'){
			tree[n]=1;
		}
		n++;
	}
	
	dfs(1);
	
	if(flag){
		printf("No");
	}else{
		printf("Yes");
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
