# h의 최대값은 1000(= 논문의 수의 최대값) -> 큰 수부터 0까지 check check!
# h번 이상 인용된 논문의 수가 h이상이면 정답

def solution(citations):
    for h in range(len(citations), -1, -1):
        if(len([cite for cite in citations if cite>= h]) >= h):
            return h
