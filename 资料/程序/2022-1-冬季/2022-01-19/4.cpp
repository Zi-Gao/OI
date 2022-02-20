/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 08:27:06
 * @LastEditTime: 2022-01-19 08:42:49
 * @LastEditors: Zi_Gao
 * @Description: cin.get
 */
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    char ch[20];

    cin.get(ch,20);//可以 单个参数

    cin.get(ch,30,'o');//输入30个字符，输入的字符是o时结束 ****不含o  越界自动舍弃
    cout << ch << endl;

    //cin.getline(ch);****报错

    cin.getline(ch,20);//必须 多个参数

    cin.getline(ch,20,'o');//必须 多个参数 输入的字符是o时结束 ****含o

	return 0;
}