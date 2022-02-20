/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 08:40:08
 * @LastEditTime: 2022-01-19 08:43:09
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    char weekday[7][11];
    for (int i = 0; i < 7; i++)
    {
        cin.getline(weekday[i],11);//可以读空格
    }
    for (int i = 0; i < 7; i++)
    {
        cout << weekday[i] << endl;
    }

	return 0;
}