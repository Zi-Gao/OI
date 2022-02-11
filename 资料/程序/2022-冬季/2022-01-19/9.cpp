/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 15:47:09
 * @LastEditTime: 2022-01-19 15:48:48
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <iostream>
using namespace std;
void change(int a[]){
    a[0]=30;
    a[1]=50;
}
int main(int argc, char const *argv[])
{
    int a[2]={10,20};
    change(a);
    cout<<a[0]<<" "<<a[1]<<endl;
    return 0;
}
