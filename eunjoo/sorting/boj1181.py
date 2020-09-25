words = [ input().rstrip() for _ in range(int(input()))]
for ret in sorted(set(words), key = lambda x : (len(x), x)):
    print(ret)
