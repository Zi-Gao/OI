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
#define stack_type pair<int,int>
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
stack s1,s2,out;
signed main(){
	#ifdef file
	freopen("rain.in", "r", stdin);
	freopen("rain.out", "w", stdout);
	#endif

	int n=read(),arr[100100];
	int cnt=0;
	
	pair<int,int> t;
	
	
//	int cnt=0;
	
	for(int i=0;i<n;i++){
		arr[i]=read();
	}
	
	for(int i=n-1;i>=0;i--){
		t.second=i;
		t.first=arr[i];
		while((!s1.empty())&&(t.first>=s1.top().first)){
			s2.push(s1.top());
			s1.pop();
		}
		
		
		out.push(s1.top()+1);
		s1.push(t);
		
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}

	while((!out.empty())){
			printf("%d\n",out.top().second+1);
		out.pop();
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
