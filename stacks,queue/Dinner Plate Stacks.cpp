/*You have an infinite number of stacks arranged in a row and numbered (left to right) from 0, each of the stacks has the same maximum capacity.

Implement the DinnerPlates class:

DinnerPlates(int capacity) Initializes the object with the maximum capacity of the stacks.
void push(int val) Pushes the given positive integer val into the leftmost stack with size less than capacity.
int pop() Returns the value at the top of the rightmost non-empty stack and removes it from that stack, and returns -1 if all stacks are empty.
int popAtStack(int index) Returns the value at the top of the stack with the given index and removes it from that stack, and returns -1 if the stack with that given index is empty.
Example:

Input:
["DinnerPlates","push","push","push","push","push","popAtStack","push","push","popAtStack","popAtStack","pop","pop","pop","pop","pop"]
[[2],[1],[2],[3],[4],[5],[0],[20],[21],[0],[2],[],[],[],[],[]]
Output:
[null,null,null,null,null,null,2,null,null,20,21,5,4,3,1,-1]

Explanation:
DinnerPlates D = DinnerPlates(2);  // Initialize with capacity = 2
D.push(1);
D.push(2);
D.push(3);
D.push(4);
D.push(5);         // The stacks are now:  2  4
                                           1  3  5
                                           ﹈ ﹈ ﹈
D.popAtStack(0);   // Returns 2.  The stacks are now:     4
                                                       1  3  5
                                                       ﹈ ﹈ ﹈
D.push(20);        // The stacks are now: 20  4
                                           1  3  5
                                           ﹈ ﹈ ﹈
D.push(21);        // The stacks are now: 20  4 21
                                           1  3  5
                                           ﹈ ﹈ ﹈
D.popAtStack(0);   // Returns 20.  The stacks are now:     4 21
                                                        1  3  5
                                                        ﹈ ﹈ ﹈
D.popAtStack(2);   // Returns 21.  The stacks are now:     4
                                                        1  3  5
                                                        ﹈ ﹈ ﹈
D.pop()            // Returns 5.  The stacks are now:      4
                                                        1  3
                                                        ﹈ ﹈
D.pop()            // Returns 4.  The stacks are now:   1  3
                                                        ﹈ ﹈
D.pop()            // Returns 3.  The stacks are now:   1
                                                        ﹈
D.pop()            // Returns 1.  There are no stacks.
D.pop()            // Returns -1.  There are still no stacks.


Constraints:

1 <= capacity <= 20000
1 <= val <= 20000
0 <= index <= 100000
At most 200000 calls will be made to push, pop, and popAtStack.*/


// Having two extra-variable for storing leftmost non-full stack and right most non-empty stack.
// Leftmost non-full stack variable will show the index of the leftmost stack which is not fully filled means that stack size is not equal to capacity, so I can use this variable to push the value to the leftmost stack efficiently.
// Rightmost non-empty stack variable will show the index of the rightmost stack which is not empty so using that variable we can efficiently perform the pop from the rightmost stack.
// I will try to update these two variables in all functions so we can implement this method easily.

class DinnerPlates {
	int cap;
	vector<stack<int>> stks;
	int leftMost, rightMost;
public:
	DinnerPlates(int capacity) {
		cap = capacity;
		leftMost = 0;
		rightMost = 0;
	}

	void push(int val) {
		// traverse the leftMost
		while (leftMost < stks.size() and stks[leftMost].size() == cap) {
			leftMost++;
		}

		// at the end
		if (leftMost == stks.size()) {
			stack<int> stk;
			stk.push(val);
			stks.push_back(stk);
		}
		else { // stack already created
			stks[leftMost].push(val);
		}

		// finally update the rightMost value
		rightMost = max(leftMost, rightMost);
	}

	int pop() {
		while (rightMost >= 0 and stks[rightMost].empty()) {
			rightMost--;
		}

		if (rightMost < 0) return -1;

		int top = stks[rightMost].top();
		stks[rightMost].pop();
		leftMost = min(leftMost, rightMost);
		return top;
	}

	int popAtStack(int index) {
		//if the particular stack is not present in stks
		if (stks.size() <= index) {
			return -1;
		}

		// if the stack is empty at given index
		if (stks[index].empty()) {
			return -1;
		}

		// if stack is not empty then return the value
		int tp = stks[index].top();
		stks[index].pop();

		leftMost = min(leftMost, index);

		return tp;
	}
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
