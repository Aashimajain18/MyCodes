
/*
Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.
*/

/*Method 2 (Using Stack)

Push the first element to stack.
Pick rest of the elements one by one and follow the following steps in loop.
Mark the current element as next.
If stack is not empty, compare top element of stack with next.
If next is greater than the top element,Pop element from stack. next is the next greater element for the popped element.
Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
Finally, push the next in the stack.
After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.*/

// A Stack based C++ program to find next
// greater element for all array elements.
#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
//time complexity-O(N)
void printNGE(int arr[], int n) {
	stack < int > s;

	/* push the first element to stack */
	s.push(arr[0]);

	// iterate for rest of the elements
	for (int i = 1; i < n; i++) {

		if (s.empty()) {
			s.push(arr[i]);
			continue;
		}

		/* if stack is not empty, then
		   pop an element from stack.
		   If the popped element is smaller
		   than next, then
		a) print the pair
		b) keep popping while elements are
		smaller and stack is not empty */
		while (s.empty() == false && s.top() < arr[i])
		{
			cout << s.top() << " --> " << arr[i] << endl;
			s.pop();
		}

		/* push next to stack so that we can find
		next greater for it */
		s.push(arr[i]);
	}

	/* After iterating over the loop, the remaining
	elements in stack do not have the next greater
	element, so print -1 for them */
	while (s.empty() == false) {
		cout << s.top() << " --> " << -1 << endl;
		s.pop();
	}
}

/* Driver program to test above functions */
int main() {
	int arr[] = {11, 13, 21, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}