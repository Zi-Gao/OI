/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
//#define file
using namespace std;
inline int read();
char first[100+10];
char bfs[100+10];
int n;

void count(int l,int r){
	if(l+1==r){
		return 1;
	}
	if(l>=r) return 0;
	for(int i=0;i<n;i++)
		for(int j=l;j<r;j++)
			if(first[i]==middle[j]){
				printf("%d",middle[j])
				count(l,j);
				count(j+1,r);
				return t;
			}
}

int main(){
	#ifdef file
	freopen("btout.in", "r", stdin);
	freopen("btout.out", "w", stdout);
	#endif

	scanf("%s",first);
	getchar();
	scanf("%s",bfs);
	
	n=strlen(first);

	
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
