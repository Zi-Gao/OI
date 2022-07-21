/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#define file
using namespace std;

struct w{
	int x,y,v;
};

#define stack_type w

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
int _max,max_x,max_y,n,m;
char arr[110][110];
int d[4][2]=
{
{0,1},
{0,-1},
{1,0},
{-1,0}
};

int cnt(int i,int j){
	int x=i,y=j;
	int p=0;
    while(true){
        if(arr[x][y]=='#'){
            break;
        }else if(arr[x][y]=='G'){
            p++;
        }
        x--;
    }
    x=i,y=j;
    while(true){
        if(arr[x][y]=='#'){
            break;
        }else if(arr[x][y]=='G'){
            p++;
        }
        x++;
    }
    x=i,y=j;
    while(true){
        if(arr[x][y]=='#'){
            break;
        }else if(arr[x][y]=='G'){
            p++;
        }
        y--;
    }
    x=i,y=j;
    while(true){
        if(arr[x][y]=='#'){
            break;
        }else if(arr[x][y]=='G'){
            p++;
        }
        y++;
    }
    
    return p;
}

stack s;

void dfs(int x,int y){

	s.push((w){x,y,cnt(x,y)});

	//book
	arr[x][y]=0;
	//go
	for(int i=0;i<4;i++){
		if(arr[x+d[i][0]][y+d[i][1]]=='.'){
			
			dfs(x+d[i][0],y+d[i][1]);
		}
	}
}

bool cmp(w a,w b){
    if(a.v!=b.v){
        return a.v>b.v;
    }else if(a.x!=b.x){
        return a.x<b.x;
    }else{
        return a.y<b.y;
    }
}

int main(){
	#ifdef file
	freopen("bomberman.in", "r", stdin);
	freopen("bomberman.out", "w", stdout);
	#endif
	
	
	//init
	int p,q;
	_max=-1;
	for(int i=0;i<110;i++)
		for(int j=0;j<110;j++)
			arr[i][j]='#';
	//read
	
	n=read();
	m=read();
	p=read();
	q=read();
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j]=getchar();
			if(arr[i][j]=='\n'){
				arr[i][j]=getchar();
			}
		}
	}
	
	//work
	
	dfs(p,q);
	
	//print
	
	sort(s.s,s.s+s.size(),cmp);
	
	_max=s.read(0).v;
	
	for(int i=0;i<s.size();i++){
		if(s.read(i).v==_max){
			printf("%d %d\n",s.read(i).x,s.read(i).y);
		}
	}
	
	printf("%d",_max);

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
