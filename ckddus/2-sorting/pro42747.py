# 간단하니 읽어보세용
def solution(citations):
    answer = 0
    citations.sort()
    for a in reversed(citations):
        if answer + 1 > a:
            break
        answer += 1
    return answer


ans = solution([24, 32, 42, 12, 1, 3, 5, 2])
print(ans)
