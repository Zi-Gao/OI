/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>

//#define file

//**********
#include <cstring>
#define stack_type int
const int STACK_SIZE = 10000;
struct stack{
	stack_type _null,s[STACK_SIZE];
	int s_top;

	stack(){
		s_top=0;
		memset(&_null,0,sizeof(_null));
		return;
	}

	inline void push(stack_type in){
		s[s_top] = in;
		++s_top;
		return;
	}

	inline void pop(){
		--s_top;
		return;
	}

	void pop(int in){
		s_top-=in;
		return;
	}

	inline stack_type top(){
		return s[s_top-1];
	}

	inline void clear(){
		s_top=0;
	}

	inline bool empty(){
		if(s_top==0){
			return true;
		}else{
			return false;
		}
	}

	inline int size(){
		return s_top;
	}

	stack_type read(int in){
		return s[in];
	}
};
//**********

inline int read();

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif



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
