/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#define file

using namespace std;
//#define STL_stack

#ifdef STL_stack
#include <stack>
#endif

#ifndef STL_stack
#define stack_type int
const int maxstack = 10000;
struct stack{
	stack_type _null,s[maxstack];
	int s_top;

	stack(){
		s_top=0;
		memset(s,0,sizeof(s));
		memset(&_null,0,sizeof(_null));
		return;
	}

	void push(stack_type in){
		if(s_top < maxstack){
			s[s_top] = in;
			++s_top;
		}
		return;
	}

	void pop(){
		if(s_top > 0){
			--s_top;
		}
		return;
	}

	void pop(int in){
		if(s_top >= in){
			s_top-=in;
		}
		return;
	}

	stack_type top(){
		if(s_top>0){
			return s[s_top-1];
		}else{
			return _null;
		}
	}

	void clear(){
		s_top=0;
	}

	bool empty(){
		if(s_top==0){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		return s_top;
	}

	stack_type read(int in){
		if(s_top > in){
			return s[in];
		}else{
			return _null;
		}
	}

	void print(){
		printf("size :%d\n", size());
		printf("empty:%d\n\n", empty());
	}
};
#endif
inline int read();
int n,out;
stack s;
void dfs(int sum,bool flag){
	if(sum==n){
		printf("%d=%d",n,s.read(0));
		for(int i=1;i<s.size();i++){
			printf("+%d",s.read(i));
		}
		out++;
		putchar('\n');
		return;
	}
	if(flag){
		s.push(1);
		dfs(sum+1,false);
		s.pop();
	}
	for(int i=2;i<=3;i++){
		if(i+sum<=n){
			s.push(i);
			dfs(sum+i,true);
			s.pop();
		}
	}
}
int main(){
	#ifdef file
	freopen("tile.in", "r", stdin);
	freopen("tile.out", "w", stdout);
	#endif

	int i=1;
	scanf("%d",&n);
	dfs(0,true);
	printf("%d",out);

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
