"""
[정렬] 백준 1181번

sort의 기준이 정해져 있을 때, 
python 내장 함수의 sorted와 
lambda로 sort 기준의 우선순위를 정해준다.
: sorted(iterable, key= lambda x: [기준])

내장함수 말고 직접 구현하는게 핵심인 것 같은데 난 귀찮으니 생략.

"""

def solution(word_list):
    word_list = sorted(set(word_list), key=lambda x: [len(x), x])
    for w in word_list:
        print(w)
    return 0


# Driver Code
if __name__ == "__main__":
    word_list = []
    for _ in range(int(input())):
        word_list.append(input())
    solution(word_list)
