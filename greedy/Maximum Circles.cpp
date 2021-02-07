/*There are n circles arranged on x-y plane. All of them have their centers on x-axis. You have to remove some of them, such that no two circles are overlapping after that. Find the minimum number of circles that need to be removed.

Input Format
First line contains a single integer, n, denoting the number of circles. Next line contains two integers, c and r each, denoting the circle with radius r and center, (c,0).

Constraints
1<=n<=10^5 |c|<=10^9 1<=r<=10^9

Output Format
Print a single integer denoting the answer.

Sample Input
4
1 1
2 1
3 1
4 1
Sample Output
2
Explanation
We can remove 1st and 3rd circle, or 2nd and 4th circle.

*/
#include <iostream>
#include <algorithm>
using namespace std;

class Circle
{
public:
	long int center;
	long int radius;
};
/// I sorted based on ending index of the circle (starting  index is {center-radius} and ending index  is {center+radius})
bool comparator(Circle a, Circle b)
{ return (a.center + a.radius) < (b.center + b.radius); }

int main()
{
	unsigned int N;
	cin >> N;
	Circle arr[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].center >> arr[i].radius;
	}
	sort(arr, arr + N, comparator);
	int C = 1;
	int end = arr[0].center + arr[0].radius;
	for (int i = 1; i < N; i++)
	{
		int srt = arr[i].center - arr[i].radius;
		if (end <= srt)
		{
			C++;
			end = arr[i].center + arr[i].radius;
		}
	}
	/// C is the no of Circles which is not to be removed
	cout << (N - C) << endl;
	return 0;
}