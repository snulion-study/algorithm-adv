N, M = int(input()), int(input())
# 고장난 버튼이 하나도 없는 경우와 모든 버튼이 고장난 경우를 고려.
buttons = input().split(" ") if M != 0 else []
ans = abs(N-100) # 가능한 정답 중 가장 큰 값(모든 버튼이 고장난 경우)
        
# 0 ~ 1000000(위에서 내려오는 경우 고려)
for cn in range(1000000):
	# 고장나지 않은 버튼의 조합으로 갈 수 있는 채널이 있다면,
	if(len([ _ for _ in str(cn) if _ in buttons ]) == 0):
		# 정답 = 현재채널"cn" 을 위한 버튼개수 + |(목표로 하는 채널(N) - 현재채널(cn))|
        ans = min(ans, len(str(cn))+abs(N-cn))
		
print(ans)



