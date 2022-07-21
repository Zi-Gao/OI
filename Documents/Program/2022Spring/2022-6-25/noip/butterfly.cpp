/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>

struct node{
	int h;
	long long w;
};

//**********
//#define STL_stack
#include <cstring>
#include <set>
using namespace std;
#ifdef STL_stack
#include <stack>
#endif

#ifndef STL_stack
#define stack_type node

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
			s[s_top].h=in.h;
            s[s_top].w=in.w;
            // s[s_top]=in;
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
//**********

#define file

inline int read();

int arr[1000010];

int main(){
	#ifdef file
	freopen("butterfly.in", "r", stdin);
	freopen("butterfly.out", "w", stdout);
	#endif

	stack s;
    node now;

	int n=read();
    int k=read();

    for(int i=0;i<n;i++){
        arr[i]=read();
    }

    long long cnt;
    long long best=0;

    int small;

	int in;

    for(int i=0;i<=n;i++){
        if(i<n){
			in=read();
			now.h=in<arr[i]?in:arr[i];
            now.w=(((arr[i]+in)%k)==0);
        }else{
			now.h=-1;
            now.w=0;
        }

        cnt=0;
		if(!s.empty()){
			while((now.h<s.top().h)&&(!s.empty())){
				cnt+=s.top().w;
				small=s.top().h;
				s.pop();
			}
			// if(cnt){
			s.push((node){now.h,cnt});
			cnt*=small;
			best=best>cnt?best:cnt;
			// }
		}

        s.push(now);
    }


    printf("%d",best);


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
