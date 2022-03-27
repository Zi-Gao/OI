#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int compare ( int a, int b ) {
	return a > b;
}
int main () {
	freopen ( "mindistance.in", "r", stdin );
	freopen ( "mindistance.out", "w", stdout );
	int n;
	scanf ( "%d", &n );
	for ( int z = 0; z < n; z ++ ) {
		int x, a [ 12 ];
		memset ( a, 0, sizeof ( a ) );
		scanf ( "%d", &x );
		for ( int i = 0; i < x; i ++ ) {
			scanf ( "%d", &a [ i ] );
		}
		sort ( a, a + x, compare );
		if ( x == 2 ) {
			printf ( "%d\n", a [ 0 ] - a [ 1 ] );
			continue;
		}
		int a1 = 0, b1 = 0;
		if ( x % 2 == 0 ) {
			int minn = 10, cnt, medium = 10;
			for ( int i = 0; i < x && a [ i + 1 ] != 0; i ++ ) {
				int sum = 0;
				if ( i >= x / 2 ) {
					sum = i - x / 2 + 1;
				}else{
					sum = x / 2 - i;
				}
				if ( a [ i ] - a [ i + 1 ] < minn || ( a [ i ] - a [ i + 1 ] == minn && sum < medium ) ) {
					minn = a [ i ] - a [ i + 1 ];
					cnt = i;
					medium = sum;
				}
			}
			a1 += a [ cnt ];
			b1 += a [ cnt + 1 ];
			a [ cnt ] = -1;
			a [ cnt + 1 ] = -1;
			int l = 0, r = x - 1, sum = 0;
			while ( l <= r ) {
				if ( sum == 0 ) {
					while ( l <= r ) {
						if ( a [ r ] != -1 ) {
							a1 = a1 * 10 + a [ r ];
							a [ r ] = -1;
							r --;
							break;
						}
						r --;
					}
				}else{
					while ( l <= r ) {
						if ( a [ l ] != -1 ) {
							b1 = b1 * 10 + a [ l ];
							a [ l ] = -1;
							l ++;
							break;
						}
						l ++;
					}
				}
				if ( sum == 0 ) {
					sum ++;
				}else{
					sum --;
				}
			}
		}else{
			int maxn, cnt;
			for ( int i = x - 1; i >= 0; i -- ) {
				if ( a [ i ] != 0 ) {
					maxn = a [ i ];
					cnt = i;
					break;
				}
			}
			a1 += a [ cnt ];
			a [ cnt ] = -1;
			int l = 0, r = x - 1, sum = 0;
			while ( l <= r ) {
				if ( sum == 0 ) {
					while ( l <= r ) {
						if ( a [ r ] != -1 ) {
							a1 = a1 * 10 + a [ r ];
							a [ r ] = -1;
							r --;
							break;
						}
						r --;
					}
				}else{
					while ( l <= r ) {
						if ( a [ l ] != -1 ) {
							b1 = b1 * 10 + a [ l ];
							a [ l ] = -1;
							l ++;
							break;
						}
						l ++;
					}
				}
				if ( sum == 0 ) {
					sum ++;
				}else{
					sum --;
				}
			}
		}
		printf ( "%d\n", a1 - b1 );
	}
	fclose ( stdin );
	fclose ( stdout );
	return 0;
}
/*
1
4
7 3 5 2 
*/
