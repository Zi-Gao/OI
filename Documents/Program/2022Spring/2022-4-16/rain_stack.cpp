/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <set>
//#include <stack>
using namespace std;
#define file
#define stack_type pair<int,int>
inline int read();

const int maxstack = 30000;
struct stack{
	stack_type s[maxstack],_null;
	int s_top;

	stack(){
		s_top=0;
		memset(s,0,sizeof(s));		
		memset(s,0,sizeof(_null));	
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
};
int main(){
	#ifdef file
	freopen("rain.in", "r", stdin);
	freopen("rain.out", "w", stdout);
	#endif

	stack s;
	pair<int,int> t;
	t.second=0;
	int out=0;
	while(~scanf("%d",&t.first)){
		t.second=1;
		if((!s.empty())&&(t.first>s.top().first)){//push
			int w=0;
			int cnt=0;
			int h=t.first;
			while((!s.empty())&&(s.top().first<t.first)){
				h=s.top().first;
				w+=s.top().second;
				cnt+=s.top().second*(t.first-s.top().first);
				s.pop();
			}
			if(s.empty()){
				out+=cnt-((t.first-h)*w);
			}else{
				out+=cnt;
			}
			t.second=w+1;
			s.push(t);
		}else{
			s.push(t);
		}
	}
	
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
