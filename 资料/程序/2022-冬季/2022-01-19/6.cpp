/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 08:40:08
 * @LastEditTime: 2022-01-19 08:50:43
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    char a[10][10];
    int n = 0;
    cin >> n;
    //cin.get();   $$$$$去除cin >> n的换行都进去
    for (int i = 0; i < n; i++){
        cin.getline(a[i],10);//可以把cin >> n换行都读进去
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << endl;
    }

	return 0;
}