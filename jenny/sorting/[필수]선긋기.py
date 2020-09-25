"""
[정렬] 백준 2170번

1. 처음에 시작점을 기준으로 올림차순 sorting을 함
2. 시작: 끝 을 저장하고 있는 dictionary 를 사용. 
3. sort된 arr 를 순서대로 조건에 맞게 dict update 
4. loop을 모두 돈 후 dictionary에서 길이 합 구하기

"""

# 요 아이 추가 안해주면 파이썬에서는 시간 초과 ㅠㅠ#
import sys
input = sys.stdin.readline
########################################

def solution(line_edges):
    line_edges.sort(key=lambda x: x[0]) # start 기준으로 오름차순 정렬
    s,e = line_edges[0]
    edge_dict = {s: e} 

    for start,end in line_edges:
        if start>=s and edge_dict[s]>=start:
            if end>=edge_dict[s]:
                edge_dict.update({s: end})
        else:
            edge_dict.update({start: end})

    total = 0
    for e in edge_dict:
        total+= (edge_dict[e]-e)

    return total

# Driver Code
if __name__ == "__main__":
    line_edges = []
    for _ in range(int(input())):
        line_edges.append(list(map(int,input().split(' '))))
    
    print(solution(line_edges))
