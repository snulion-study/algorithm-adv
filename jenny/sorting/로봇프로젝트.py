"""
[정렬] 백준 3649번

1. input 무한정 받을 때 개극혐 런타임 에러 때문에 고생하다가 try, catch 문으로 해결 
2. O(n^2)으로 풀었다가 시간 초과나서 2 pointer 알고리즘 써서 시작, 끝 인덱스로 좁혀가면서 해결

  ^                  ^
start     ...       end

둘의 합의 크기를 구벙 크기랑 비교해서 start pointer를 증가, end pointer를 감소시켜서 
절댓값의 크기가 최대인 combination을 O(n)에 구해낼 수 있다

"""
import sys
input = sys.stdin.readline


def solution(hole_size, legos):
    legos.sort()
    hole_size_in_nano = 10000000 * hole_size
    i = 0
    j = len(legos)-1

    # 2 pointer 알고리즘으로 O(n)에 풀었음
    while i<j:
        if (legos[i]+legos[j])>hole_size_in_nano:
            j-=1
        elif (legos[i]+legos[j])<hole_size_in_nano:
            i+=1
        else:
            print('yes {} {}'.format(legos[i],legos[j]))
            return 0

    print('danger')
    return 0

"""
시간 초과 났던 풀이 O(n^2)

for i in range(len(legos)):
    if hole_size_in_nano-legos[i] in legos:
        print('yes {} {}'.format(legos[i],hole_size_in_nano-legos[i]))
        return 0
"""

# Driver Code
if __name__ == "__main__":
    # 테스트 케이스 직접 입력 받을때 try catch 안해주면 런타임 에러남.. 극혐
    while True:
        try:
            hole_size = int(input()) 
            legos = []
            for _ in range(int(input())):
                legos.append(int(input()))
            solution(hole_size,legos)

        except:
            break