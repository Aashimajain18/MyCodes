/*Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.



Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false


Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
*/

/* Intuition for the solution */
/***

1) We maintain 2 stacks, entryStack and exitStack
2) Whenever we need to push an element , we simply push it onto the entry stack
3) Now, supoose we have 6 elements in the entryStack
   1 ,2, 3, 4, 5, 6 (with 6 being the latest element pushed into the stack)
4) Suposse we ask 6 queries of the form queue.front, whose answer is
   1, 2, 3, 4, 5, 6
5) Well, since 1 is buried at the bottom, we cannot extract it. So another option is to
   flip the stack and answer the queries in O(1)
6) How do we flip a stack so that it becomes a queue ? Simply put it in the entryStack
   one by one thus reversing their ordere and making it a queue
7) Now, as long as the entryStack is not empty, we can answer the queries of pop, empty and
   top in O(1)
8) Meanwhile, If push queries come, just store them in the entry stack.
9) If the exitStack finishes off, fill it via flipping the entry stack.

***/








class MyQueue
{
public:

	stack<int> entryStack;
	stack<int> exitStack;

public:
	/** Push element x to the back of queue. */
	void push(int x);

	/** Removes the element from in front of queue and returns that element. */
	int pop();

	/** Get the front element. */
	int peek();

	/** Returns whether the queue is empty. */
	bool empty();
};

/* Pushes the element in the queue */
void MyQueue :: push(int x)
{
	// Just push it in the entry stack
	entryStack.push(x);
}

/* Return the front element of the queue*/
int MyQueue :: peek()
{
	// If the exit stack is not empty, then it is first in the queue
	if (!exitStack.empty()) return exitStack.top();

	// Else the exit stack is empty, so we need to flip the contents of the entryStack
	// and put it in the exitStack for future use
	while (!entryStack.empty())
	{
		exitStack.push(entryStack.top());
		entryStack.pop();
	}

	return exitStack.top();
}

/* Checks if the stack is empty or not */
bool MyQueue :: empty()
{
	// Since the elements are distributed in 2 stacks, check if both of them are empty or not
	return (entryStack.empty() && exitStack.empty());
}

/* Returns the top element of the queue */
int MyQueue :: pop()
{
	// First peek the element (which obviously flips the elements and fills it into the exitStack)
	int top = peek();

	// Since the element to be popped is already adjusted to the top of the exitStack
	// (Via the peek function), simply pop it now
	exitStack.pop();

	// Return the saved element
	return top;
}