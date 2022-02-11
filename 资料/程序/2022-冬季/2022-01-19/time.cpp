/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 09:16:32
 * @LastEditTime: 2022-01-19 09:24:14
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <ctime>
using namespace std;
int main(){
    clock_t start_time, end_time;
    start_time = clock();   //获取开始执行时间



    end_time = clock();     //获取结束时间
    double Times = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("%f seconds\n", Times);
	return 0;
}