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
char middle[100+10];
int len[100+10];
int now;
int n;

int count(int l,int r,int depth){
	if(l+1==r){
		len[now++]=1;
		return 1;
	}
	if(l>=r) return 0;
	for(int i=0;i<n;i++)
		for(int j=l;j<r;j++)
			if(first[i]==middle[j]){
				int t=count(l,j,depth+1)+count(j+1,r,depth+1);
				len[now++]=t;
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
	scanf("%s",middle);
	
	n=strlen(first);
	
	count(0,n,0);
	
//	for(int i=0;i<n;i++){
//		printf("%d ",len[i]);
//	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<len[n-i-1];j++){
			putchar(first[i]);
		}
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
