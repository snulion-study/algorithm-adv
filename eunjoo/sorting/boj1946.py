import sys
input = sys.stdin.readline

for T in range(int(input())):
	test = { i: 0 for i in range(1, int(input()) + 1)}

	for i in range(len(test)):
		one, two = input().rstrip().split()
		test[int(one)] = int(two)

	ans, min = 1, test[1]
	for idx in range(2, len(test)+1):
		if test[idx] < min:
			ans, min = ans+1, test[idx]

			

	print(ans)