/***
 * @Author: Zi_Gao
 * @Date: 2022-01-20 08:28:10
 * @LastEditTime: 2022-01-20 08:32:25
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
float expression(){
    char in[105];
    cin >> in;
    switch(in[0]){
        case '+':
            return expression()+expression();break;
        case '-':
            return expression()-expression();break;
        case '*':
            return expression()*expression();break;
        case '/':
            return expression()/expression();break;
        default:
            return atof(in);
    }
}
int main(){
    freopen("expression.in","r",stdin);
    freopen("expression.out","w",stdout);
    printf("%.6f\n",expression());
}
