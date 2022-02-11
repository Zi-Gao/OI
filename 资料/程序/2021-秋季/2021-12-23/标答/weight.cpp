#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int a[5], t[5], m;
	int i, j, s, temp, b[5] = {81, 27, 9, 3, 1};
	freopen("weight.in", "r", stdin);
	freopen("weight.out", "w", stdout);
	
	scanf("%d", &m);

	for(a[0] = -1; a[0] <= 1; a[0]++)
		for(a[1] = -1; a[1] <= 1; a[1]++)
			for(a[2] = -1; a[2] <= 1; a[2]++)
				for(a[3] = -1; a[3] <= 1; a[3]++)
					for(a[4] = -1; a[4] <= 1; a[4]++)
					{
						s = 0;
						for(i = 0; i < 5; i++)
						{
							t[i] = a[i] * b[i];
							s += t[i];
						}
						if(m == s)
						{
							for(i = 0; i < 4; i++)
								for(j = i + 1; j < 5; j++)
								{
									if(t[i] > t[j])
									{
										temp = t[i];
										t[i] = t[j];
										t[j] = temp;
									}
								}
							for(i = 0; i < 5; i++)
								if(t[i] != 0) 
									printf("%d ", -t[i]);												
						}
					}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
