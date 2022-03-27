/***
 * @Author: Zi_Gao
 * @Date: 2022-03-27 07:57:19
 * @LastEditTime: 2022-03-27 07:59:37
 * @LastEditors: Zi_Gao
 * @Description: 
 */
/***
 * @Author: Zi_Gao
 * @Description: 
6 5
1 0 1 1 1 0
0 1 0 1 1 1
0 0 1 0 1 0
1 0 1 0 1 0
0 1 0 1 0 0
1 0 1 0 1 0
 */
#include <cstdio>
// #define file
using namespace std;
inline int read();
char arr[20000];
int main(){
	#ifdef file
	freopen("kingdom.in", "r", stdin);
	freopen("kingdom.out", "w", stdout);
	#endif

	int n=read();
	int m=read();
	int cnt;
	int ju=m/2;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			arr[j]+=read();
		}
	}
	
	cnt=0;
	for(int i=0;i<n;++i){
		if((read()==1)==(arr[i]>ju)){
			++cnt;
		}
	}
	
	printf("%d",cnt);

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
