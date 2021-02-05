//given an array find the max subarray sum

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
using namespace std;


int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*
		int n;
		cin >> n;
		int a[1000];

		for (int i = 1; i < n; i++)
		{
			cin >> a[i];
		}

		//METHOD 1:
		//time complexity o(n^3)
		int max_sum = 0;
		int left=-1;
		int right=-1;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				int currentsum = 0;
				for (int k = i; k <= j; k++)
				{
					currentsum += a[k] ;
				}
				if (currentsum > max_sum) {
					max_sum = currentsum;
					left = i;
					right = j;
				}

			}
		}
		cout << max_sum << endl;
	//printing the subarray with max sum:
		for (int k = left; k <= right; k++)
		{
			cout << a[k] << " ";
		}
	*/

	/*
		//METHOD 2:
		//time complexity o(n^2)
		int n;
		cin >> n;
		int a[1000];
		int cum_sum[1000] = {0};
		int max_sum = 0;
		int currentsum = 0;

		int left = -1;
		int right = -1;

		cin >> a[0];
		cum_sum[0] = a[0];
		for (int i = 1; i < n; i++)
		{
			cin >> a[i];
			cum_sum[i] = cum_sum[i - 1] + a[i];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				currentsum = 0;
				currentsum = cum_sum[j] - cum_sum[i - 1];
				if (currentsum > max_sum) {
					max_sum = currentsum;
					left = i;
					right = j;
				}


			}
		}
		cout << max_sum << endl;
	//printing the subarray with max sum:
		for (int k = left; k <= right; k++)
		{
			cout << a[k] << " ";
		}

	*/
	//METHOD 3:
	//time complexity o(n)
	//kadane's algorithm
	//works only if max subarray sum is positive

	int n;
	cin >> n;
	int a[1000];
	int max_sum = 0;
	int currentsum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	for (int i = 0; i < n; ++i)
	{
		currentsum = currentsum + a[i];
		if (currentsum < 0) {
			currentsum = 0;
		}
		max_sum = max(currentsum, max_sum)	;
	}
	cout << max_sum << endl;


	return 0;
}

//method 4
//dp
//works on negative numbers as well
int maxSubArraySum(int a[], int size) 
{ 
   int max_so_far = a[0]; 
   int curr_max = a[0]; 
  
   for (int i = 1; i < size; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
} 


