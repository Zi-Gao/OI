/***
 * @Author: Zi_Gao
 * @Date: 2022-02-10 15:53:31
 * @LastEditTime: 2022-02-10 16:03:02
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include<iostream>
#include<cstring>
 
using namespace std;
int a[15];
int ans[15];
int dp[1001];
int n, m;
int maxv = 0;
int cale(int num){
    if(!num)    return 0;
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    int i = 0;
    while(dp[i]<=n){
    	i++;
    	for(int j=1;j<=num && a[j]<=i; j++)
            dp[i] = min(dp[i-a[j]] + 1, dp[i]);
	}
	return i-1;
}
void dfs(int num){
    if(num >= m){
        int c = cale(m);
        if(c <= maxv)    return;
        for(int i = 1;i <= m; i++)
            ans[i] = a[i];
        maxv = c;
        return;
    }else{
        int temp = cale(num);
        for(int i = temp + 1;i > a[num]; i--){
            a[num + 1] = i;
            dfs(num + 1);
        }
    }
}
int main(){
    cin >> n;
    m=4;
    dfs(0);
    cout<<ans[1];
    for(int i = 2;i <= m;i++)
        cout<<" "<<ans[i];
    cout<<endl;
    cout<<"MAX="<<maxv;
    return 0;
}