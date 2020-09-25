# 시간초과 
# Python -> input 대신 sys.stdin.readline을 사용하면 시간 빨라진다.
# 맨 끝의 개행문자까지 같이 입력받기 때문에 문자열을 저장시, .rstrip()을 추가로 해준다.


import sys 
input = sys.stdin.readline

class Stack():
	def __init__(self):
		self.stack = []
		self.len = 0

	def push(self, num):
		self.stack.append(num)
		self.len += 1

	def pop(self):
		item = -1 if self.len == 0 else self.stack[-1]
		if item != -1:
			del self.stack[-1]
			self.len -= 1
		return item

	def size(self):
		return self.len

	def empty(self):
		return 0 if self.len > 0 else 1

	def top(self):
		return -1 if self.len == 0 else self.stack[-1]


num = int(input().rstrip())
stack = Stack()

for i in range(num):
	order = input().rstrip()

	if order.startswith("push"):
		ret = order.split(" ")[1]
		stack.push(ret)

	elif order == "top":
		print(stack.top())

	elif order == "size":
		print(stack.size())

	elif order == "empty":
		print(stack.empty())

	elif order == "pop":
		print(stack.pop())


