#include <stack>

class MyQueue
{
public:
	MyQueue()
	{
	}

	void push(int x)
	{
		for (; !q.empty(); q.pop())
		{
			st.push(q.top());
		}

		st.push(x);

		for (; !st.empty(); st.pop())
		{
			q.push(st.top());
		}
	}

	int pop()
	{
		int res = q.top();
		q.pop();
		return res;
	}

	int peek()
	{
		return q.top();
	}

	bool empty()
	{
		return q.empty();
	}

private:
	std::stack<int> q;
	std::stack<int> st;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */