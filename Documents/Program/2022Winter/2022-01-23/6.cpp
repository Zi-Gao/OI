/***
 * @Author: Zi_Gao
 * @Date: 2022-01-23 09:01:51
 * @LastEditTime: 2022-01-23 10:11:32
 * @LastEditors: Zi_Gao
 * @Description: �߾����㷨��ģ�壩
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
    string a, b;

    cin >> a >> b;
    cout << Add (a, b) << endl ;
    cout << Sub (a, b) << endl ;
	cout << Mult(a, b) << endl ;
    cout << Div (a, b) << endl ;
    cout << Mod (a, b) << endl ;
	cout << stringGcd (a,b) <<endl ;
	cout << stringLcm (a,b) <<endl ;

    return 0;
}
//���ǰ׺0���������ǿ��ַ�������Ϊ0
inline void clear(string& a)
{
    while(a.length()>0 && a[0]=='0')
        a.erase(0, 1);
    if(a == "")
        a = "0";
}

//���a>=b�򷵻��棨�������ǰ׺��ᱻ������
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

//�����߾����������ӷ� a+b
string Add(string a, string b)
{
    //1����λ��������������ֱ���������ͬ����
    while(a.length() < b.length())
        a = '0' + a;
    while(a.length() > b.length())
        b = '0' + b;
    //2�����㣬�ڿ�ͷ�ټ�һ��0�Ա��λ
    a = '0' + a;
    b = '0' + b;
    //3���ӵ�λ��ʼ��ӣ�ע���λ
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

//�����߾������������� a-b
string Sub(string a, string b)
{
    bool aBigger = true;
    //1����λ��������������ֱ���������ͬ����
    while(a.length() < b.length())
        a = '0' + a;
    while(a.length() > b.length())
        b = '0' + b;
    //2���Ʋ�������ֵ������Ϊǰ���С
    if(a < b)
    {
        aBigger = false;
        string buf = b;
        b = a;
        a = buf;
    }
    //3���ӵ�λ��ʼ�����ע���λ
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

//�����߾����������˷� a*b
//�����ӷ�
string Mult(string a, string b)
{
    string result = "0";
    if(a.length() < b.length())
	{
        string buf = a;
        a = b;
        b = buf;
    }
    //��λ����һλ������ֱ��ʹ�üӷ�
    //��λ����������d*10^n��������ת��Ϊ��λ������һλ��
    //��λ�����Զ�λ������ת��Ϊ���ɸ���λ������һλ�����
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

//�����߾������������� a/b
//��������
string Div(string a, string b)
{
    clear(a);
    clear(b);
    if(b == "0")
        return "��";

    string result = "";
    string remainder = "";
    //�Ӹ�λ��ʼ�������������һ��
    // һ��ȡλ�պô��ڱ�������ʼ�ü�������
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

//�����߾������������� a%b
//��������
string Mod(string a, string b)
{
    clear(a);
    clear(b);
    if(b == "0")
        return "��";

    string result = "";
    string remainder = "";
    //�ͳ���Ψһ��������Ƿ���ֵ��һ��
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
//�����߾����������Լ�� gcd(a,b)
//��������
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
    //ʹ��շת����������Լ��
    if(b == "0")
	{
        return a;
    }
	else
	{
        return stringGcd(b, Mod(a, b));
    }
}

//�����߾���������С������ lcm(a,b)
//�����˷�
//��������
//�������Լ��
string stringLcm(string a, string b)
{
    clear(a);
    clear(b);
    string buf = Mult(a, b);
    //ʹ�ù�ʽ lcm(a,b)=a*b/gcd(a,b)
    if(buf == "0")
	{
        return "0";
    }
	else
	{
        return Div(buf, stringGcd(a, b));
    }
}