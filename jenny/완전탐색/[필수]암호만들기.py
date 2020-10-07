import sys
from itertools import combinations

input = sys.stdin.readline

def solution(char_list, L):
    char_list.sort()
    vowels = ['a','e','i','o','u']
    combs = list(combinations(char_list,L))
    res = []
    for comb in combs:
        count_vowels = 0
        for char in comb:
            if char in vowels:
                count_vowels+=1
        if count_vowels>=1 and L-count_vowels>=2:
            res.append(comb)

    for r in res:
        print(''.join(r))

    return



# Driver Code
if __name__ == "__main__":
    L, C = map(int, input().split(' '))
    char_list = input().rstrip('\n').split(' ')
    solution(char_list,L)