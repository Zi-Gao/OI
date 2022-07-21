/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
//#define file
using namespace std;
//********
#include <queue>
#include <cstring>
#define SIZE_HTree 1000
#define Haff_data_type char
struct HaffTreeNode{
	int lChild,rChild;
};

struct queueNode{
	int w,h,p;
	
	bool operator < (const queueNode & in) const{
		if(w!=in.w)
			return w<in.w;
		return h<in.h;
	}
};

struct codeNode{
	int code[SIZE_HTree],len;
	Haff_data_type data;
};

struct HaffmanCode{
	HaffTreeNode tree[SIZE_HTree];
	codeNode data[SIZE_HTree];
	int head,rear,nowcode[SIZE_HTree];
	
	HaffmanCode(){
		head=-1;
		memset(tree,0,sizeof(tree));
		return;
	}
	
	void ctree(int w[SIZE_HTree],int size){
		priority_queue<queueNode> q;
		
		for(int i=0;i<size;i++){
			tree[i].lChild=-1;
			tree[i].rChild=-1;
			q.push((queueNode){-w[i],-1,i});
		}
		
		rear=size-1;
		queueNode temp;
		
		while(!q.empty()){
			temp.w=q.top().w;
			temp.h=q.top().h;
			tree[++rear].rChild=q.top().p;
			q.pop();
			if(q.empty()){
				rear--;
				head=rear;
				break;
			}
			temp.w+=q.top().w;
			temp.h=max(q.top().h,temp.h)+1;
			temp.p=rear;
			tree[rear].lChild=q.top().p;
			q.pop();
			q.push(temp);
		}
		
		return;
	}
	
	void dfs(int now,int step){
		if(now==-1){
			return;
		}
		if(tree[now].lChild==-1&&tree[now].rChild==-1){
			memcpy(data[now].code,nowcode,sizeof(nowcode));
			data[now].len=step;
			return;
		}
		nowcode[step]=0;
		dfs(tree[now].lChild,step+1);
		nowcode[step]=1;
		dfs(tree[now].rChild,step+1);
	}
	
	void readData(Haff_data_type in[SIZE_HTree],int size){
		for(int i=0;i<size;i++)
			data[i].data=in[i];
		return;
	}

	void countCode(){
		dfs(head,0);
		
		return;
	}
	
	void clear(){
		head=-1;
		memset(tree,0,sizeof(tree));
		return;
	}
};
//********
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
