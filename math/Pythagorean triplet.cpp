#include<iostream>
//#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<utility>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;


int32_t main() {


	int sum = 1000;
	for (int a = 1; a <= sum / 3; a++)
	{
		for (int b = a + 1; b <= sum / 2; b++)
		{
			int c = sum - a - b;//because a+b+c=1000
			if ( a * a + b * b == c * c ) {//because Pythagorean triplet follows conditon (a^2 + b^2 =c^2)
				cout << "a is " << a << endl;
				cout << "b is " << b << endl;
				cout << "c is " << c << endl;

				break;
			}
		}
	}
	return 0;
}

