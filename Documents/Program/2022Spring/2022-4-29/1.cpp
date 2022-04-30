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
void infixtopostfix(char in[],char out[]);
int countpostfix(char in[]);

const int maxstack = 100100;
struct stack{
	stack_type _null,s[maxstack];
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
	
	void clear(){
		s_top=0;
	}
};
int main(){
	#ifdef file
	freopen("rain.in", "r", stdin);
	freopen("rain.out", "w", stdout);
	#endif


	//a*(b*(c+d/e)-f)
	//2*(3*(1+4/2)-1) = 16 
	char infix[100]={0},postfix[100]={0};
	scanf("%s",infix);
	infixtopostfix(infix,postfix);
	printf("%s\n",postfix);
	int cntpostfix=countpostfix(postfix);
	printf("%d",cntpostfix);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int countpostfix(char in[]){
	stack s;//存操作数的栈 
	int ini=0,t;//ini数组下标 t临时 
	while(in[ini]!='\0'){
		if('0'<=in[ini]&&'9'>=in[ini]){//操作数直接存 
			s.push(in[ini]-'0');
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
			}
			s.pop();
			s.push(t);
		}
		ini++;
	}
	return s.top();
}

void infixtopostfix(char in[],char out[]){
	stack s;
	char t;
	int ini=0,outi=0;//正在使用的数组下表 

	//优先级表 
	int map[256]={0};
	map['+']=1;
	map['-']=1;
	map['*']=2;
	map['/']=2;
	
	
	t=in[ini];
	++ini; 
	while(t!='\0'){
		if(('a'<=t&&'z'>=t)||('0'<=t&&'9'>=t)){//输出操作值 
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
