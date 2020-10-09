def solution(brown, yellow):
	# 갈색 테두리 4개의 모퉁이를 없애고 2로 나누면 노란색 칸들의 가로와 세로의 합
    for i in range(1, max(yellow, 2)):
    	# 1~yellow 개수까지 세로+가로가 brown개수와 같은 것을 찾으면 바로 return 
        if i*(yellow//i) == yellow and i+(yellow//i) == (brown-4)/2:
            return [yellow//i+2, i+2] #yellow//i+2 가 항상 i보다 크1