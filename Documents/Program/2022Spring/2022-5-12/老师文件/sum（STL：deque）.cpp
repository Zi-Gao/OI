#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
deque<int> dq;
int s[100005];

int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &s[i]);
	for(int i = 1; i <= n; i++) s[i] = s[i] + s[i-1]; //����ǰ׺��
	int ans = -1E8;
	dq.push_back(0);
	for(int i = 1; i <= n;i++) {
		while(!dq.empty() && dq.front() < i - m) //��ͷ���� m ��Χ��ɾͷ
		dq.pop_front();
		if(dq.empty()) {
			ans = max(ans, s[i]);	
		}	
		else{
			ans = max(ans, s[i] - s[dq.front()]); //��ͷ������С��s[k]
		}  
		while(!dq.empty() && s[dq.back()] >= s[i]){ //��β����s[i]��ȥβ
			dq.pop_back();
		}
		dq.push_back(i);
	}
	printf("%d\n", ans);
	return 0;
}

/*
Sample Input:
6 4 
1 -3 5 1 -2 3

Sample Output:
7
*/
