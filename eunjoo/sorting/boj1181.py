# set 으로 중복 제거, labmda로 길이순, 알파벳순 정렬 
words = [ input().rstrip() for _ in range(int(input()))]
for ret in sorted(set(words), key = lambda x : (len(x), x)):
    print(ret)
순