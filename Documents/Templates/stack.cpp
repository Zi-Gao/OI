/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define int long long
//#define file
#define stack_type int
inline int read();

const int maxstack = 100100;
struct stack{
	stack_type _null,s[maxstack];
	int s_top;

	stack(){
		s_top=0;
		memset(s,0,sizeof(s));		
		_null.second=-1;
		_null.first=0;
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
			s[s_top-1]=_null;
			s_top--;
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
	
	void clear(){
		s_top=0;
	}
};
signed main(){
	#ifdef file
	freopen("rain.in", "r", stdin);
	freopen("rain.out", "w", stdout);
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
