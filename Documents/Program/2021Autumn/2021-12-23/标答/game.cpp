/*
����Ѿ�������n - 1 ���ˣ���
�� ����� n - 1 ��������������� n ���˿���������Ҳ������Ů��
�� ����� n - 1 ������Ů������� n ����ֻ��������
Ҳ����˵��
�� ����� n��������������� n - 1 ���˿���������Ҳ������Ů��
�� ����� n������Ů������� n - 1 ����ֻ��������

���Ƴ��������� = ǰ����� + ��ǰ�������Ҳ���� f(n) = f(n - 1) + f(n - 2)��
�����쳲��������С� 
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int N;
	long long int boy = 1, girl = 0;
	cin >> N;
    for(int i = 1; i <= N; i++){
    	//�������� n-1 ��ʱ��״̬
    	long long int boy_pre = boy;
    	boy = (boy % 1000007 + girl % 1000007) % 1000007;
    	girl = boy_pre;
    }    
    cout << (boy % 1000007 + girl % 1000007) % 1000007;
    fclose(stdin);
    fclose(stdout);
	return 0;
}


