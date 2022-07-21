/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
inline int read();
#define MAX_N 300+10
#define INF 64 
char arr[MAX_N][MAX_N];
int main(){
	#ifdef file
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	#endif
	
	int T=read();
	for(int TT=1;TT<=T;TT++){
		//init
		for(int i=0;i<MAX_N;i++){
			for(int j=0;j<MAX_N;j++){
				arr[i][j]=0; 
			} 
		}
		
		//read
		int m=read();
		int n=read();
		
		for(int i=0;i<n;i++){
			arr[read()][read()]=1;
		}
		
		//judge
		for(int i=0;i<m;i++){
			
			int cnt=0;
			for(int t=0;t<m;t++){
				cnt+=arr[t][i];
				if(cnt>1){//一个点有两条如边 
					for(int j=0;j<m;j++){
						if(arr[j][i]){//找到这条边 
							for(int k=0;k<m;k++){// 
								if(arr[k][i]&&!arr[k][j]){
									printf("Case #%d: No\n",TT);
									goto loop;
								}
							} 
						}
					}
				}
			}

		}
		printf("Case #%d: Yes\n",TT);
		loop:;
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
