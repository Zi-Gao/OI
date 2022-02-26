/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 14:53:16
 * @LastEditTime: 2022-01-21 14:57:09
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <iostream>
using namespace std;
int* getInt1(){
    int value1=20;
    return &value1;
}
int* getInt2(){
    int value2=30;
    return &value2;
}
int main(){
    int *p,*q;
    p=getInt1();
    q=getInt2();
    cout<<*p<<endl;
    return 0;
}