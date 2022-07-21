#include <cstdio>
#include <iostream>
using namespace std;

struct node {
	int x;   //������ 
	int y;   //������ 
	int s;   //���� 
};

int main() {
	int n, m, startx, starty, p, q, tx, ty;
	struct node que[2501];
	int head, tail;
	int nxt[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};   //�����ߡ������ߡ������ߡ�������
	int a[51][51] = {0}, book[51][51 ] ={0};
	
	//���� n�� m,nΪ�У�mΪ�� 
	cin >> n >> m;
	//�����Թ�
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		} 
	}		
	//���������յ�����
	cin >> startx >> starty >> p >> q;	
	//���г�ʼ��
	head = tail = 1;
	//��������
	que[tail].x = startx;
	que[tail].y = starty;	
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	int flag = 0;   //��������Ƿ񵽴�Ŀ��㣬0��ʾ��ʱ��û�е��1��ʾ����
	while(head < tail) {  //�����зǿ�ʱѭ��
		//˳ʱ��ö���ĸ�������߷�
		for(int k = 0; k < 4; k++) {
			//������һ���������
			tx = que[head].x + nxt[k][0];
			ty = que[head].y + nxt[k][1];
			//�ж��Ƿ�Խ��
			if(tx < 1 || tx > n || ty < 1 || ty > m)
				continue;
			//�жϸõ��Ƿ�Ϊ�ϰ�������Ѿ���·����
			if(a[tx][ty] == 0 && book[tx][ty] == 0)	{
				book[tx][ty] = 1;        //���������Ѿ��߹�
			    //�����µĵ㵽������
				que[tail].x = tx;
				que[tail].y = ty;			
				que[tail].s = que[head].s + 1;   //��������һ�ڵ�Ĳ���+1 
				tail++; 
			} 
			//�����Ŀ����ˣ�ֹͣ��չ������������˳�ѭ��
			if(tx == p && ty == q) {
				flag = 1;
				break;
			} 
		} 
		if(flag == 1) break;
	    head++;    //��չ�굱ǰ��֮�󣬰��������ӣ���head++���������ܼ�����չ����ĵ�		
	} 	
	//��ӡ������ĩβ��Ŀ��㣩�Ĳ���
	cout << que[tail-1].s;
	
	return 0;
}


