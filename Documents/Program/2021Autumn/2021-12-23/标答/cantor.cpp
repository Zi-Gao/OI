#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	long long int n, i, j; //n�����ֵ�Ѿ����������ͷ�Χ����˶���Ϊ������
	freopen("cantor.in", "r", stdin);
	freopen("cantor.out", "w", stdout);
	scanf("%lld", &n);
	i = 0;  //б�����ų�ʼ��
	j = n;  //�� n���λ�� j ��ʼ��
	do{ //ȷ�����ڵ�б��
		i++;
		j -= i;		
	}while(j > 0);
	j += i; //������ j
    if(i % 2 == 0) //���ݱ��ȷ��б�ߵķ���
		printf("%lld/%lld\n", j , i + 1 - j);   // ��n����ż����б����
	else 
        printf("%lld/%lld\n", i + 1 - j, j) ;  //��n����������б����
    fclose(stdin);
    fclose(stdout);

	return 0;
}

