import sys
input = sys.stdin.readline

all_btn = [str(d) for d in range(0,10)]

def brokenNum(N, btn_list):
    res = False
    for digit in str(N):
        if digit in btn_list:
            res = True
            break
    return res

def solution(N, btn_list):
    filtered_btns = list(filter(lambda x: x not in btn_list, all_btn))
    startFromHundered = abs(N-100) # 100에서 +,-를 눌러서 도달하는 횟수
    min_count = startFromHundered

    for i in range(1000001):
        if brokenNum(i, btn_list): 
            continue
        press_count = abs(N-i) + len(str(i))
        min_count = min(min_count, press_count)
    
    return min_count

# Driver Code
if __name__ == "__main__":
    N = int(input())
    broken_count = int(input())
    broken_btns = input()

    if broken_count==0:
        print(solution(N, []))
    else:
        btn_list = broken_btns.rstrip('\n').split(' ')
        print(solution(N, btn_list))