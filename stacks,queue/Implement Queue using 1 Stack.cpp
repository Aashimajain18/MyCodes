// You can implement queue using just one stack by either making push process costlier or pop costlier. Since we have two functions (top() and pop()) which require the top element of the stack, well make the push() function costlier - that is, for pushing a new element, we recursively pop the stack till it is empty and push it at the bottom of the stack, and take advantage of the recursive call to push back in the popped elements once the recursive call hits the base condition and returns. This implementation makes pop() and peek() functions easier. pop() is just going to pop off the top element in stack and peek() will return the top most element.

class Queue {
public:
	stack<int> s;

	// Push element x to the back of queue.
	void push(int x) {
		pushHelper(x);
	}
	void pushHelper(int x) {
		if (s.size() == 0) {
			s.push(x);
			return;
		}
		int data;
		data = s.top();
		s.pop();
		pushHelper(x);
		s.push(data);
		return;

	}

	// Removes the element from in front of queue.
	void pop(void) {
		s.pop();
	}

	// Get the front element.
	int peek(void) {
		return s.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return (s.size() == 0);
	}
};