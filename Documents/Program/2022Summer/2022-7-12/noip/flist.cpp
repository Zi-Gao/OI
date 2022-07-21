/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#define file
using namespace std;
inline int read();
char middle[100+10];
char bfs[100+10];
int n;

void count(int l,int r){
	if(l+1==r){
		printf("%c",middle[l]);
		return;
	}
	if(l>=r) return;
	for(int i=0;i<n;i++)
		for(int j=l;j<r;j++)
			if(bfs[i]==middle[j]){
				printf("%c",middle[j]);
				count(l,j);
				count(j+1,r);
				return;
			}
}

int main(){
	#ifdef file
	freopen("flist.in", "r", stdin);
	freopen("flist.out", "w", stdout);
	#endif

	scanf("%s",middle);
	getchar();
	scanf("%s",bfs);
	
	n=strlen(middle);
	
	count(0,n);

	
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
