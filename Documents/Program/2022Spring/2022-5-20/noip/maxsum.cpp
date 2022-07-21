/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#define file
using namespace std;
struct pair{
	int first,second; 
};
#define stack_type pair 
const int maxstack = 100100;
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
	
	stack_type back(){
		if(s_top>0){
			return s[0];
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
inline int read();
int arr[110000];
int main(){
	#ifdef file
	freopen("maxsum.in", "r", stdin);
	freopen("maxsum.out", "w", stdout);
	#endif
	
	int T=read();
	int n;
	for(int i=1;i<=T;++i){
		memset(arr,0,sizeof(arr));
		printf("Case %d:\n",i);
		n=read();
		pair now;
		now.first=0;
		now.second=0;
		stack q;
		q.push(now); 
		for(int j=1;j<=n;j++){
			now.first+=read();
			now.second=j;
			if((!q.empty())&&(q.top().first>now.first)){
			}else{
				q.push(now);
			} 
			
		}
		printf("%d %d %d\n\n",q.top().first-q.back().first,q.back().second+1,q.top().second);
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
