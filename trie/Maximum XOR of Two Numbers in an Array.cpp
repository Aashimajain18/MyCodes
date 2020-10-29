
/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j],
where 0 ≤ i ≤ j < n.

Follow up: Could you do this in O(n) runtime?



Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [0]
Output: 0
Example 3:

Input: nums = [2,4]
Output: 6
Example 4:

Input: nums = [8,10,2]
Output: 10
Example 5:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127


Constraints:

1 <= nums.length <= 2 * 104
0 <= nums[i] <= 231 - 1
*/
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Structure of Trie
class node {
public:
	node* left;
	node* right;
};

// Function to insert binary
// representation of element x
// in the Trie
void insert(int x, node* head)
{
	// Store the head
	node* curr = head;

	for (int i = 30; i >= 0; i--) {

		// Find the i-th bit
		int val = (x >> i) & 1;

		if (val == 0) {

			// If curr->left is NULL
			if (!curr->left)
				curr->left = new node();

			// Update curr to curr->left
			curr = curr->left;
		}
		else {

			// If curr->right is NULL
			if (!curr->right)
				curr->right = new node();

			// Update curr to curr->right
			curr = curr->right;
		}
	}
}

// Function that finds the maximum
// Bitwise XOR value for all such pairs
int findMaximumXOR(int arr[], int n)
{
	// head Node of Trie
	node* head = new node();

	// Insert each element in trie
	for (int i = 0; i < n; i++) {
		insert(arr[i], head);
	}

	// Stores the maximum XOR value
	int ans = 0;

	// Traverse the given array
	for (int i = 0; i < n; i++) {

		// Stores the XOR with current
		// value arr[i]
		int curr_xor = 0;

		int M = pow(2, 30);

		node* curr = head;

		for (int j = 30; j >= 0; j--) {

			// Finding ith bit
			int val = (arr[i] >> j) & 1;

			// Check if the bit is 0
			if (val == 0) {

				// If right node exists
				if (curr->right) {

					// Update the currentXOR
					curr_xor += M;
					curr = curr->right;
				}

				else {
					curr = curr->left;
				}
			}

			else {

				// Check if left node exists
				if (curr->left) {

					// Update the currentXOR
					curr_xor += M;
					curr = curr->left;
				}
				else {
					curr = curr->right;
				}
			}

			// Update M to M/2 for next set bit
			M /= 2;
		}

		// Update the maximum XOR
		ans = max(ans, curr_xor);
	}

	// Return the maximum XOR found
	return ans;
}

// Driver Code
int main()
{
	// Given array arr[]
	int arr[] = { 1, 2, 3, 4 };

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << findMaximumXOR(arr, N);

	return 0;
}