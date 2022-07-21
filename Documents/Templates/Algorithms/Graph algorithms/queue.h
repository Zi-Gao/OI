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

	void push(queue_type in){
		q[tail] = in;
		++tail;
		tail%=QUEUE_SIZE;
		++num;
		return;
	}

	void pop(){
		q[head]=_null;
		++head;
		--num;
		head%=QUEUE_SIZE;
		return;
	}

	queue_type front(){
		return q[head];
	}

	queue_type back(){
		return q[tail-1];
	}

	void clear(){
		head=0;
		tail=0;
		return;
	}

	bool empty(){
		if(head==tail){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		return num;
	}

	queue_type read(int in){
		return q[(head+in)%QUEUE_SIZE];
	}
};