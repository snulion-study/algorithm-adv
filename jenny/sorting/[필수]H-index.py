"""

[정렬] 프로그래머스 H-index

정렬을 안썼는데 흠 ..

핵심: 
1. 꼭 list에 있는 애가 h-index의 후보가 되는 것은 아님 
2. 가장 적은 인용 개수가 전체 논문 수보다 클 때는 for loop 이 끝나, 그때는 자기 길이 반환

"""


def solution(citations):

    for i in range(max(citations),min(citations)-1,-1):
        if len([j for j in citations if j>=i]) >= i:
            return i
    
    # min 인용 횟수 조차도 전체 논문 개수보다 클 때는 길이를 반환
    return len(citations)

# Driver Code
if __name__ == "__main__":
    citations = [3,3]
    print(solution(citations))