#pragma once
#include <vector>

class StackCopy {
public:
	StackCopy();
	~StackCopy();
	void push(int x);
	void pop();
	int top();
	int size();
	bool empty();
	void operator =(StackCopy& forcopy);

private:
	std::vector<int> stack;
};