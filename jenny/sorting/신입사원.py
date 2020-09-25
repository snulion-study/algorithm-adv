"""
[정렬] 백준 1946번

Sort 자체보다는 greedy로 생각하는게 좀 빡셌던 것 같당 

핵심은 
1. 서류 기준으로 정렬 
2. greedy하게 면접 등수의 min (제일 잘한거)를 저장하고 있음으로써, 
만약에 서류 점수는 낮지만, min 등수가 더 적으면 뽑힐 수 있는 거니까 count 증가 

"""
import sys
input = sys.stdin.readline

def solution(newbie_list):
    # 서류 기준으로 정렬
    sort_by_paper = sorted(newbie_list, key=lambda x: x[0])
    count = 0
    min_ = float('inf')

    for paper,interview in sort_by_paper:
        if interview < min_:
            min_ = interview
            count+=1
    return count

# Driver Code
if __name__ == "__main__":
    for _ in range(int(input())):
        newbie_list = []
        for __ in range(int(input())):
            newbie_list.append(list(map(int, input().split(' '))))
        print(solution(newbie_list))
