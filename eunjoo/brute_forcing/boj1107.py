N, M = int(input()), int(input())
# 고장난 버튼이 하나도 없는 경우와 모든 버튼이 고장난 경우를 고려.
buttons = input().split(" ") if M != 0 else []
ans = abs(N-100) 

for cn in range(1000000):
	# 고장나지 않은 버튼으로 갈 수 있는 채널이 있다면, 
	if(len([ _ for _ in str(cn) if _ in buttons ]) == 0):
		# 정답 = (현재 채널을 위한 버튼개수 + |(목표로 하는 채널 - 현재채널)|)
		ans = min(ans, len(str(cn))+abs(N-cn)) 
		
print(ans)



