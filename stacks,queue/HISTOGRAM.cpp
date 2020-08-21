/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be
made of a number of contiguous bars.


Input Format
First line contains a single integer N, denoting the number of bars in th histogram.
Next line contains N integers, ith of which, denotes the height of ith bar in the histogram.

Constraints
1<=N<=10^6
Height of each bar in histogram <= 10^9

Output Format
Output a single integer denoting the area of the required rectangle.

Sample Input
5
1 2 3 4 5
Sample Output
9
Explanation
The largest rectangle can be obtained of breadth=3 and length=3. Its starting index is 2 and ending
index is 4 and it has a height of 3. Hence area = 3*3 = 9
*/
// C++ program to find maximum rectangular area in
// linear time
//below solution is from geeks for geeks
#include<bits/stdc++.h>
using namespace std;

// The main function to find the maximum rectangular
// area under given histogram with n bars
int getMaxArea(int hist[], int n)
{
	// Create an empty stack. The stack holds indexes
	// of hist[] array. The bars stored in stack are
	// always in increasing order of their heights.
	stack<int> s;

	int max_area = 0; // Initialize max area
	int tp;  // To store top of stack
	int area_with_top; // To store area with top bar
	// as the smallest bar

	// Run through all bars of given histogram
	int i = 0;
	while (i < n)
	{
		// If this bar is higher than the bar on top
		// stack, push it to stack
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		// If this bar is lower than top of stack,
		// then calculate area of rectangle with stack
		// top as the smallest (or minimum height) bar.
		// 'i' is 'right index' for the top and element
		// before top in stack is 'left index'
		else
		{
			tp = s.top();  // store the top index
			s.pop();  // pop the top

			// Calculate the area with hist[tp] stack
			// as smallest bar
			area_with_top = hist[tp] * (s.empty() ? i :
			                            i - s.top() - 1);

			// update max area, if needed
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	// Now pop the remaining bars from stack and calculate
	// area with every popped bar as the smallest bar
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i :
		                            i - s.top() - 1);

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}

// Driver program to test above function
int main()
{
	int hist[] = {6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(hist) / sizeof(hist[0]);
	cout << "Maximum area is " << getMaxArea(hist, n);
	return 0;
}
