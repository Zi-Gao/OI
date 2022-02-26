/***
 * @Author: Zi_Gao
 * @Date: 2022-01-23 09:01:51
 * @LastEditTime: 2022-01-23 11:04:44
 * @LastEditors: Zi_Gao
 * @Description: 高精度算法（模板）
 */
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
string Add(string a, string b);
string Sub(string a, string b);
string Mult(string a, string b);
string Div(string a, string b);
string Mod(string a, string b);
string stringGcd(string a, string b);
string stringLcm(string a, string b);
int main()
{
    freopen("a+b.in","r",stdin);
	freopen("a+b.out","w",stdout);
    string a, b;
    char f_a,f_b;

    char temp;
    f_a=getchar();
    temp=getchar();
    while(temp!='\n'){
        a+=temp;
        temp=getchar();
    }


    f_b=getchar();
    temp=getchar();
    while(temp!=EOF){
        b+=temp;
        temp=getchar();
    }

    if(f_a=='-'&&f_b!='-'){
        b=f_b+b;
        cout << Sub(b,a);
    }
    if(f_a!='-'&&f_b=='-'){
        a=f_a+a;
        cout << Sub(a,b);
    }
    if(f_a=='-'&&f_b=='-'){
        putchar('-');
        cout << Add(a,b);
    }
    if(f_a!='-'&&f_b!='-'){
        a=f_a+a;
        b=f_b+b;
        cout << Add(a,b);
    }


    return 0;
}
//清除前缀0，如果结果是空字符串则设为0
inline void clear(string& a)
{
    while(a.length()>0 && a[0]=='0')
        a.erase(0, 1);
    if(a == "")
        a = "0";
}

//如果a>=b则返回真（如果包含前缀零会被消除）
bool Big(string a, string b)
{
    clear(a);
    clear(b);
    if(a.length() > b.length())
        return true;
    if(a.length()==b.length() && a>=b)
        return true;
    return false;
}

//两个高精度正整数加法 a+b
string Add(string a, string b)
{
    //1、对位，将两个数补零直到其具有相同长度
    while(a.length() < b.length())
        a = '0' + a;
    while(a.length() > b.length())
        b = '0' + b;
    //2、补零，在开头再加一个0以便进位
    a = '0' + a;
    b = '0' + b;
    //3、从低位开始相加，注意进位
    for(int i=a.length()-1; i>=0; i--)
	{
        a[i] = a[i] + b[i] - '0';
        if(a[i] > '9')
		{
            a[i] = a[i] - 10;
            a[i-1] += 1;
        }
    }
    clear(a);
    return a;
}

//两个高精度正整数减法 a-b
string Sub(string a, string b)
{
    bool aBigger = true;
    //1、对位，将两个数补零直到其具有相同长度
    while(a.length() < b.length())
        a = '0' + a;
    while(a.length() > b.length())
        b = '0' + b;
    //2、推测结果正负值，调整为前大后小
    if(a < b)
    {
        aBigger = false;
        string buf = b;
        b = a;
        a = buf;
    }
    //3、从低位开始相减，注意借位
    for(int i=a.length()-1; i>=0; i--)
	{
        if(a[i] >= b[i])
		{
            a[i] = a[i] - (b[i] - '0');
        }
		else
		{
            a[i] = a[i] + 10;
            a[i-1] -= 1;
            a[i] = a[i] - (b[i] - '0');
        }
    }
    clear(a);
    if(!aBigger)
        a = '-' + a;
    return a;
}

//两个高精度正整数乘法 a*b
//依赖加法
string Mult(string a, string b)
{
    string result = "0";
    if(a.length() < b.length())
	{
        string buf = a;
        a = b;
        b = buf;
    }
    //多位数乘一位数可以直接使用加法
    //多位数乘以形如d*10^n的数可以转化为多位数乘以一位数
    //多位数乘以多位数可以转化为若干个多位数乘以一位数相加
    for(int i=b.length()-1; i>=0; i--)
	{
        for(int j=0; j<b[i]-'0'; j++)
		{
            result = Add(result, a);
        }
        a = a + '0';
    }
    clear(result);
    return result;
}

//两个高精度正整数除法 a/b
//依赖减法
string Div(string a, string b)
{
    clear(a);
    clear(b);
    if(b == "0")
        return "⑨";

    string result = "";
    string remainder = "";
    //从高位开始除，和手算除法一样
    // 一旦取位刚好大于被除数则开始用减法求商
    for(int i=0; i<a.length(); i++)
	{
        remainder = remainder + a[i];
        result = result + '0';
        while(Big(remainder, b))
		{
            result[result.length()-1]++;
            remainder = Sub(remainder, b);
        }
    }
    clear(result);
    return result;
}

//两个高精度正整数求余 a%b
//依赖减法
string Mod(string a, string b)
{
    clear(a);
    clear(b);
    if(b == "0")
        return "⑨";

    string result = "";
    string remainder = "";
    //和除法唯一的区别就是返回值不一样
    for(int i=0; i<a.length(); i++)
	{
        remainder = remainder + a[i];
        result = result + '0';
        while(Big(remainder, b))
		{
            result[result.length()-1]++;
            remainder = Sub(remainder, b);
        }
    }
    clear(remainder);
    return remainder;
}
//两个高精度数求最大公约数 gcd(a,b)
//依赖求余
string stringGcd(string a, string b)
{
    clear(a);
    clear(b);
    if(!Big(a, b))
	{
        string buf = a;
        a = b;
        b = buf;
    }
    //使用辗转相除法求最大公约数
    if(b == "0")
	{
        return a;
    }
	else
	{
        return stringGcd(b, Mod(a, b));
    }
}

//两个高精度数求最小公倍数 lcm(a,b)
//依赖乘法
//依赖除法
//依赖最大公约数
string stringLcm(string a, string b)
{
    clear(a);
    clear(b);
    string buf = Mult(a, b);
    //使用公式 lcm(a,b)=a*b/gcd(a,b)
    if(buf == "0")
	{
        return "0";
    }
	else
	{
        return Div(buf, stringGcd(a, b));
    }
}