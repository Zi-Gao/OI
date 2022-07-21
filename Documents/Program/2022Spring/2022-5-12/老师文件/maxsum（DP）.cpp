/*
DP����dp[i]��ʾ����� i ����ʱ��a[1]��a[i]���������͡�
״̬ת�Ʒ���Ϊ�� dp[i] = max(dp[i-1]+a[i], a[i])��
*/ 

#include <iostream>
#include <cstdio>
using namespace std;

int dp[100005]; //dp[i]: �Ե�i ����Ϊ��β�����ֵ

int main(){
	freopen("maxsum.in", "r", stdin);
	freopen("maxsum.out", "w", stdout);
	int t; cin>>t;
	for(int i = 1; i <= t; i++){
		int n; scanf("%d", &n);
		for(int j = 1; j <= n; j++) scanf("%d", &dp[j]); //cin >> dp[j];
		int start = 1, end = 1, p = 1; //��㣬�յ㣬ɨ��λ��
		int maxsum = dp[1];
		for(int j = 2; j <= n; j++){
			if(dp[j-1] >= 0){ //dp[i-1]����0�����dp[i]�й���
				dp[j] = dp[j-1] + dp[j]; //ת�Ʒ���
			}
			else {
				p = j;
			}				
			if(dp[j] > maxsum ) {
				maxsum = dp[j];
				start = p;
				end = j;
			}
		}
		printf("Case %d:\n", i);
		printf("%d %d %d\n", maxsum, start, end);
		if(i != t) printf("\n");
	}
	
	return 0;
}

/*
����:
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5

���:
Case 1:
14 1 4

Case 2:
7 1 6
*/
