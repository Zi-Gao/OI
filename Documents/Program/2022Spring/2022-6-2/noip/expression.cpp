/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
//#define file
#define stack_type int
inline int read();
char in[50];
int step;
int count(int now){
	int x=0;
	char c;
	if(in[step]<='9'&&in[step]>='0'){
		c=in[step];
	    while(c>='0'&&c<='9'){
	        x=(x<<3)+(x<<1)+(c&15);
	        c=in[step++];
	    }
	}else if(in[step]=='-'&&in[step+1]<='9'&&in[step+1]>='0'){
		step++;
		c=in[step];
	    while(c>='0'&&c<='9'){
	        x=(x<<3)+(x<<1)+(c&15);
	        c=in[step++];
	    }
	}
}
int main(){
	#ifdef file
	freopen("expression.in", "r", stdin);
	freopen("expression.out", "w", stdout);
	#endif

	scanf("%d")

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int qpow(int a, int b) {
    int ans = 1;
    if(b==0){
        return 1;
    }
    if(b%2==0){
        ans=qpow(a,b/2);
        ans=ans*ans;
    }else{
        ans=qpow(a,b-1);
        ans=ans*a;
    }
    return ans;
}

int countpostfix(int in[]){
	stack s;//存操作数的栈 
	int ini=0,t;//ini数组下标 t临时 
	while(in[ini]!='\0'){
		if(in[ini]!='+'&&in[ini]!='-'&&in[ini]!='*'&&in[ini]!='/'&&in[ini]!='^'){//操作数直接存 
			s.push(in[ini]);
		}else{//count 
			if(in[ini]=='+'){
				t=s.top();
				s.pop();
				t+=s.top();
			}else if(in[ini]=='-'){
				t=s.top();
				s.pop();
				t=s.top()-t;
			}else if(in[ini]=='*'){
				t=s.top();
				s.pop();
				t*=s.top();
			}else if(in[ini]=='/'){
				t=s.top();
				s.pop();
				t=s.top()/t;
			}else if(in[ini]=='^'){
				t=s.top();
				s.pop();
				t=qpow(t,s.top());
			}
			s.pop();
			s.push(t);
		}
		ini++;
	}
	return s.top();
}

void infixtopostfix(int in[],int out[]){
	stack s;
	char t;
	int ini=0,outi=0;//正在使用的数组下表 

	//优先级表 
	int map[256]={0};
	map['+']=1;
	map['-']=1;
	map['*']=2;
	map['/']=2;
	map['^']=3;
	
	
	t=in[ini];
	++ini; 
	while(t!='\0'){
		if(in[ini]!='+'&&in[ini]!='-'&&in[ini]!='*'&&in[ini]!='/'&&in[ini]!='^'){//输出操作值 
			out[outi]=t;
			++outi;
		}else if((t=='(')){//特判 
			s.push(t);//默认优先级是0，就很爽 
		}else if(t==')'){//特判 
			while(s.top()!='('){
				out[outi]=s.top();
				++outi;
				s.pop();
			}
			s.pop();
		}else{
			while((!s.empty())&&((map[t]<=map[s.top()]))){//单调栈维护 
				out[outi]=s.top();
				++outi;
				s.pop();
			}
			s.push(t);
		}
		t=in[ini];
		++ini;
	}
	
	
	while(!s.empty()){//清除剩下的符号 
		out[outi]=s.top();
		++outi;
		s.pop();
	}
	
	return;
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
