/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <ctime>
#include <cstdlib>
#define file
using namespace std;
inline int read();
const int num=19;
char names[19*6+1]="张文扬何岱松刘子沫梁家旗杨天赐张月涵刘治君姚涵轩张耒丰陈宥宇王馨尧邹佳禾刘晗  高翊宸王子谦赵嘉宸刘昕麟周梓桦王星童";

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif
	
	srand(time(NULL));
	
	char p[num];
	
	int week=0;
	
	while(week++<3){
		printf("week %d:\n",week);
		for(int i=0;i<num;i++)p[i]=0;
		for(int i=1;i<=4;i++){
			printf("day %d:\n",i);
			for(int j=0;j<4;j++){
				loop:int t=rand()%num;
				if(p[t]==0){
					printf("%c%c%c%c%c%c ",names[t*6],names[t*6+1],names[t*6+2],names[t*6+3],names[t*6+4],names[t*6+5]);
					p[t]=1;
				}else{
					goto loop;
				}
			}
			putchar('\n');
		}
		printf("day 5:\n");
		for(int j=0;j<num;j++){
			if(p[j]==0)
				printf("%c%c%c%c%c%c ",names[j*6],names[j*6+1],names[j*6+2],names[j*6+3],names[j*6+4],names[j*6+5]);
		}
		putchar('\n');
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
