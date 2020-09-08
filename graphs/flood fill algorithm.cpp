#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;

int r;
int c;

void print(char a[][50]) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	return;
}

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};


void floodfil(char a[][50], int i, int j, char ch, char colour) {
//base case-matrix bounds
	if (i < 0 || j < 0 || i >= r || j >= c) {
		return ;
	}
	//figure boundary condition
	if (a[i][j] != ch) {
		return ;
	}
	//recursive call
	a[i][j] = colour;
// floodfil(a,i+1,j,ch,colour);
// floodfil(a,i-1,j,ch,colour);
// floodfil(a,i,j+1,ch,colour);
// floodfil(a,i,j-1,ch,colour);
	for (int k = 0; k < 4; k++)
	{
		floodfil(a, i + dx[k], j + dy[k], ch, colour);
	}
	return ;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int r, c;
	cin >> r >> c;
	char a[15][50];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}

	floodfil(a, 8, 13, '.', 'o');
	print(a);
	return 0;


}
