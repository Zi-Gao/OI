#define queue_type int
const int QUEUE_SIZE = MAX_N;
struct queue{
	queue_type q[MAX_N];
	int head,tail,num;

	queue(){
		head=0;
		tail=0;
		num=0;
		return;
	}

	void push(queue_type in){
		if(num < QUEUE_SIZE){
			q[tail] = in;
			++tail;
			tail%=QUEUE_SIZE;
			++num;
		}
		return;
	}

	void pop(){
		if(num>0){
			++head;
			--num;
			head%=QUEUE_SIZE;
		}
		return;
	}

	queue_type front(){
		return q[head];
	}

	bool empty(){
		if(head==tail){
			return true;
		}else{
			return false;
		}
	}
};