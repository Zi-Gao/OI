/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 16:01:28
 * @LastEditTime: 2022-01-24 16:09:34
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cmath>
double EPS=1e-8;
double f(double x){
    return 2*x-x*x;
}
int main(){
    double root,x1=0,x2=1,y;
    root=x1+(x2-x1)/2;
    while(fabs(y)>EPS){
        if(y>0){
            x2=root;
        }else{
            x1=root;
        }
        y=f(root);
        root=x1+(x2-x1)/2;
    }
    printf("%lf\n",root);
}
