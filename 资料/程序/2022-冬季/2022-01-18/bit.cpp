#include <iostream>
#include <cstdio>
using namespace std;
//几种统计一个二进制数内有几个1的方法
//方法一：
int f1(int temp) {
	int num = 0;
	while(temp) {
		int t = temp%2;
		if(t == 1 || t == -1)
		num ++;
		temp /= 2;
	}
	return num;
}
//除法的效率比移位运算要低，这种方法不建议使用

//--------------------------------------------------------------

//方法二：
int f2(int n) {
	int num = 0;
	while(n) {
		if(n & 1) num++;
		n >>= 1;
	}
	return num;
}
//方法二把除法改成了移位，但次方法不能处理负数。
//可能有人会有疑问为什么处理不了，这里举个例子：
//N = -9;
//第一次右移后，N = -5;
//第二次右移后，N = -3;
//第三次右移后，N = -2;
//第四次右移后，N = -1;
//第五次右移后，N = -1;
//第六次右移后，N = -1;
//会陷入死循环，所有此方法也不建议使用

//--------------------------------------------------------------

//方法三：
int f3(int n) {
	int num = 0;
	unsigned int flag = 1;
	while(flag) {
		if(n & flag)
		num++ ;
		flag <<= 1;
	}
	return num;
}
//为了避免死循环，我们可以不右移输入的数字n。
//首先把n和1做与运算，判断n的最低位是不是1,
//接着把1左移一位得到2 ，再和n做与运算，
//就能判断n的次第位是不是为1
//反复左移运算，每次都能判断n的其中一位是不是1。
//此种解法的次数等于整数二进制的位数，32位的整数需要循环32次。

//--------------------------------------------------------------

//方法四：
int f4(int n) {
	int num = 0;
	while(n) {
		num++;
		n &= (n-1);
	}
	return num;
}
// 对于这种情况：分两种情况讨论：
//情况一：二进制末尾为1，减一后末尾为0 ，例如：1111 &（1110） = 1110
//情况二：末尾为0，需要向前借位，
//例如 1110 &（1101） = 1100
// 1100 &（1011） = 1000
// 1000 &（0111） = 0000
// 这个程序可以理解为：这个二进制有几个1运行几次
//以上算法时间复杂度都为大于O（1）

//--------------------------------------------------------------

//O（1)算法
int f5(int x){
	x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
	x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
	x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
	x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
	x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
	return x;
}


int main() {
	freopen("bit.in", "r", stdin);
	freopen("bit.out", "w", stdout);
	int n;
	while(cin >> n){
		int t = f4(n);
		cout << t << endl;	
	}	
	return 0;
}
