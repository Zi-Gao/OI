/*
�����Ҫ��ĳһ�ε��������ֵ 
Ҫ��O(1)�������
ֻ����ǰ׺�� 
*/
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
deque<int> q;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n,m;//��Ŀ�е�n,m 
	cin >> n >> m;
	int a[300001]={0};
	
	for(int i=1;i<=n;i++){
		cin >> a[i];//���� 
		a[i]=a[i]+a[i-1];//��ǰ׺�� 
	}
	
	int Max=a[1];//�����ֵMax 
	//������ 
	for(int i=1;i<=n;i++){
		//ά�ֵ������� 
		while(!q.empty() && a[q.back()]>=a[i]) q.pop_back();//ά�ֵ����� 
		q.push_back(i);//�������

		//��α��ִ�i��i-m�������ĳ�������ֵ��� 
		//���������Ҷ˵�Խ����˵�ԽС
		//������ֵԽ�� 
		//��ǰ׺������ȥǰ׺����С��ͷ��β��
		Max=max(Max,a[q.back()]-a[q.front()]);
		if(i-m>0){
			//ά���������� 
			if(q.front()==i-m){
				q.pop_front();
			}
			if(q.back()==i-m){
				q.pop_back();
			}
		}
	}
	cout << Max;	
	return 0;
}
/*
���� 
1,-3,5,1,-2,3
6 4 
1 -3 5 1 -2 3
*/
