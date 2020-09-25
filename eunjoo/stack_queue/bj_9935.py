import sys
input = sys.stdin.readline

line, bomb = input().rstrip(), input().rstrip()
stack = []

for ch in line:
	stack.append(ch)

	if len(stack) >= len(bomb):
		match = True
		for i in range(len(bomb)):
			if bomb[-1-i] != stack[-1-i]:
				match = False
				break;
		if match:
			for i in range(len(bomb)):
				stack.pop(len(stack)-1)

print(''.join(stack)) if len(stack) != 0 else print("FRULA")
