/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
inline int read();
inline void write(int x);
void swap(int &a,int &b){
	a=a+b;
	b=a-b;
	a=a-b;
}
int main(){
	int a=-10,b=1;
//	swap(a,b);
//	printf("%d %d",a,b);
	write(a);
//	printf("%d");
	
    return 0;
}
inline void write(int x){
	if(x&0x80000000){
		putchar('-');
		x=-x;
	}
	while(x){
		putchar(x%10+'0');
//		x=(x>>3)+(x>>1);
		x/=10;
	}
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
