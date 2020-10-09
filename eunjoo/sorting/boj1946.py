import sys
input = sys.stdin.readline

for T in range(int(input())): 
	test = { i: 0 for i in range(1, int(input()) + 1)}

	# dict 이용 서류 성적 등수로 정렬
	for i in range(len(test)):
		one, two = input().rstrip().split()
		test[int(one)] = int(two) 

	ans, min = 1, test[1]
	# 서류 성적과 면접 시험 중 둘 중 하나는 높은 것만 ++
	for idx in range(2, len(test)+1):
		if test[idx] < min:
			ans, min = ans+1, test[idx]

			

	print(ans)