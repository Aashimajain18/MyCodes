// You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
// Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
// If A is already sorted, output -1.

// Example :

// Input 1:

// A = [1, 3, 2, 4, 5]

// Return: [1, 2]

// Input 2:

// A = [1, 2, 3, 4, 5]

// Return: [-1]
// In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.


//method-1
vector<int> Solution::subUnsort(vector<int> &a) {
	vector<int>b ;
	vector<int>c;
	b = a;
	sort(b.begin(), b.end());
	int size = a.size();
	int i = 0, j = size - 1, s = INT_MIN, e = INT_MIN;
	while (size--) {
		if (b[i] != a[i]) {
			s = i;
			break;
		}

		i++;
	}
	while (size--) {
		if (b[j] != a[j]) {
			e = j;
			break;
		}
		j--;
	}
	if (s == INT_MIN || e == INT_MIN) {
		c.push_back(-1);
	}
	else {
		c.push_back(s);
		c.push_back(e);
	}
	return c;
}


//method-2
vector<int> Solution::subUnsort(vector<int> &arr) {
	int startIndex = -1;
	int endIndex = -1;
	vector<int> output;
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] > arr[i + 1] ) {
			startIndex = i;
			break;
		}
	}
	if (startIndex == -1) {
		output.push_back(-1);
		return output;
	}
	for (int i = arr.size() - 1; i > 0; i--) {
		if (arr[i - 1] > arr[i]) {
			endIndex = i;
			break;
		}
	}
	int minEle = INT_MAX, maxEle = INT_MIN;
	for (int i = startIndex; i <= endIndex; i++) {
		minEle = min(minEle, arr[i]);
		maxEle = max(maxEle, arr[i]);
	}
	int minIndex = startIndex;
	int maxIndex = endIndex;
	for (int i = startIndex - 1 ; i >= 0; i--) {
		if (arr[i] > minEle) {
			minIndex = i;
		}
	}
	for (int i = endIndex + 1; i < arr.size(); i++) {
		if (arr[i] < maxEle) {
			maxIndex = i;
		}
	}
	output.push_back(minIndex);
	output.push_back(maxIndex);
	return output;
}

