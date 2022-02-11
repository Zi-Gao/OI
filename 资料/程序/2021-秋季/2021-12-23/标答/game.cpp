/*
如果已经排列了n - 1 个人，则
● 如果第 n - 1 个人是男生，则第 n 个人可以是男生也可以是女生
● 如果第 n - 1 个人是女生，则第 n 个人只能是男生
也就是说，
● 如果第 n个人是男生，则第 n - 1 个人可以是男生也可以是女生
● 如果第 n个人是女生，则第 n - 1 个人只能是男生

可推出，所求数 = 前面的数 + 再前面的数，也就是 f(n) = f(n - 1) + f(n - 2)。
这就是斐波那契数列。 
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
    	//求已排列 n-1 人时的状态
    	long long int boy_pre = boy;
    	boy = (boy % 1000007 + girl % 1000007) % 1000007;
    	girl = boy_pre;
    }    
    cout << (boy % 1000007 + girl % 1000007) % 1000007;
    fclose(stdin);
    fclose(stdout);
	return 0;
}


