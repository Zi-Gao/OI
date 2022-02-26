/***
 * @Author: Zi_Gao
 * @Date: 2022-01-27 14:04:17
 * @LastEditTime: 2022-01-27 14:05:39
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <stack>
#include <string>
#include <vector>
#include <iostream>

int main() {
    std::vector<std::string> vecs;// 矩阵
    std::string s;// 先保存输入的每一行
    while (std::cin >> s)
        vecs.push_back(s);
    std::cout << vecs.size();// 矩阵大小
    s.clear();// 先清空，之后存长串
    for (auto i : vecs)// 用范围 for 循环（C++11）实现，代码更精简
        s += i;
    /*
    不用范围 for 循环的实现
    for (int i = 0; i < vecs.length(); ++i)
        s += vecs[i];
    */
    std::stack<bool> stk;// 栈
    bool now = false;// 状态
    for (int i = 0; i <= s.length(); ++i) {// 这里要避免陷阱，文末解释
        stk.push(s[i] - '0');// s[i] 是 char 类型，需要减去 '0' 才能正常转化为 bool 
        if (now != s[i] - '0') {
            stk.pop();// 先出栈，一会再进
            std::cout << " " << stk.size();// 按照格式输出后面的内容
            while (!stk.empty())// 全部出栈
                stk.pop();
            stk.push(s[i]);// 新的栈只有当前一个数字
            now = !now;// 状态转移
        }
    }
}