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
	stack s;//���������ջ 
	int ini=0,t;//ini�����±� t��ʱ 
	while(in[ini]!='\0'){
		if(in[ini]!='+'&&in[ini]!='-'&&in[ini]!='*'&&in[ini]!='/'&&in[ini]!='^'){//������ֱ�Ӵ� 
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
	int ini=0,outi=0;//����ʹ�õ������±� 

	//���ȼ��� 
	int map[256]={0};
	map['+']=1;
	map['-']=1;
	map['*']=2;
	map['/']=2;
	map['^']=3;
	
	
	t=in[ini];
	++ini; 
	while(t!='\0'){
		if(in[ini]!='+'&&in[ini]!='-'&&in[ini]!='*'&&in[ini]!='/'&&in[ini]!='^'){//�������ֵ 
			out[outi]=t;
			++outi;
		}else if((t=='(')){//���� 
			s.push(t);//Ĭ�����ȼ���0���ͺ�ˬ 
		}else if(t==')'){//���� 
			while(s.top()!='('){
				out[outi]=s.top();
				++outi;
				s.pop();
			}
			s.pop();
		}else{
			while((!s.empty())&&((map[t]<=map[s.top()]))){//����ջά�� 
				out[outi]=s.top();
				++outi;
				s.pop();
			}
			s.push(t);
		}
		t=in[ini];
		++ini;
	}
	
	
	while(!s.empty()){//���ʣ�µķ��� 
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
