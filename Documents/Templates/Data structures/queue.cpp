/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>

//#define file

//**********
#include <cstring>
#define queue_type int
const int QUEUE_SIZE = 1000;
struct QUEUE{
	queue_type _null,q[QUEUE_SIZE];
	int head,tail,num;

	QUEUE(){
		head=0;
		tail=0;
		num=0;
		memset(&_null,0,sizeof(_null));
		return;
	}

	inline void push(queue_type in){
		q[tail] = in;
		++tail;
		tail%=QUEUE_SIZE;
		++num;
		return;
	}

	inline void pop(){
		q[head]=_null;
		++head;
		--num;
		head%=QUEUE_SIZE;
		return;
	}

	inline queue_type front(){
		return q[head];
	}

	inline queue_type back(){
		return q[tail-1];
	}

	inline void clear(){
		head=0;
		tail=0;
		return;
	}

	inline bool empty(){
		if(head==tail){
			return true;
		}else{
			return false;
		}
	}

	inline int size(){
		return num;
	}

	queue_type read(int in){
		return q[(head+in)%QUEUE_SIZE];
	}
};
//**********

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
