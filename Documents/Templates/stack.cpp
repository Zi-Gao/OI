/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
//#define file

//**********
//#define STL_stack

#ifdef STL_stack
#include <stack>
#endif

#ifndef STL_stack
#define stack_type int
const int maxstack = 100000;
struct stack
{
	stack_type _null,s[maxstack];
	int s_top;

	stack(){
		s_top=0;
		memset(s,0,sizeof(s));
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
			s_top--;
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
		printf("empty:%d\n\n", size());
	}
};
#endif
//**********
using namespace std;

inline int read();

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	stack s;

	s.push(1);
	s.push(2);

	printf("%d\n", s.read(1));

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
