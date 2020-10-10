from itertools import combinations 

L, C = map(int, input().split())
moeum = ['a', 'e', 'i', 'o', 'u']
words = input().split()
words.sort()
combis = list(combinations(words, L))

for combi in combis:
	mo = 0
	for let in combi:
		mo = mo+1 if let in moeum else 0
	
  # 최소 한 개의 모음, 두 개 의 자음
	if mo >= 1 and len(combi)-mo>= 2:
		print("".join(combi))


'''
    import 된 조합 library가 아닌 recursive로 직접 구현한 version
'''
# def recursive_version():
# 	L, C = map(int, input().split())
# 	moeum = ['a', 'e', 'i', 'o', 'u']
# 	words = input().split()
# 	words.sort()

# 	def pick(src, combi, ja, mo):
# 		if len(combi) == L:
# 			if ja >= 2 and mo >= 1:
# 				print("".join(combi))
# 			return

# 		for i in range(src, C):
# 			combi.append(words[i])
# 			if words[i] in moeum:
# 				pick(i+1, combi, ja, mo+1)
# 			else:
# 				pick(i+1, combi, ja+1, mo)
# 			combi.pop(-1)

# 	pick(0, [], 0, 0)
