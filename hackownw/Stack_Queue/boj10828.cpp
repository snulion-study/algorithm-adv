#include "stackcopy.h"

StackCopy::StackCopy() {
	stack.clear();
}

void StackCopy::push(int x) {
	stack.push_back(x);
}

void StackCopy::pop() {
	stack.erase(stack.begin()+stack.size()-1);
}

int StackCopy::top() {
	return stack.back();
}

int StackCopy::size() {
	return stack.size();
}

bool StackCopy::empty() {
	return stack.empty();
}