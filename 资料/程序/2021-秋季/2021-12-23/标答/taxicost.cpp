#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	long long int maxint = 200000000LL;	
	long long int s, bestx, x, mincost, cost, temp, pay;
	freopen("taxicost.in", "r", stdin);
	freopen("taxicost.out", "w", stdout);
	cin >> s;
	if(s < 3000)
	{
		bestx = s;
		mincost = 8;
	}
	else
	{
		mincost = maxint;
		for(x = 3000; x <= s; x++)
		{
			temp = x;
			if(temp <= 3000) pay = 8;
			else if(temp <= 15100) pay = 8 + (temp - 3000) / 550;
			else pay = 30 + (temp - 15100) / 370;
			cost = pay;
			temp = s - x;
			if(temp > 0)
			{
				if(temp <= 3000) pay = 8;
				else if(temp <= 15100) pay = 8 + (temp - 3000) / 550;
				else pay = 30 + (temp - 15100) / 370;
			}
			else pay = 0;
			cost += pay;
			if(cost < mincost)
			{
				mincost = cost;
				bestx = x;
			}
		}
	}
	cout << bestx << " " << mincost;
	
	return 0;
}
