import sys
input = sys.stdin.readline

nums = [list(map(int, input().split(' '))) for _ in range(int(input()))]
nums.sort()
prev_r, prev_l, tot_len = 0, 0, 0

for curr_l, curr_r in nums:
    if tot_len == 0:
        tot_len = abs(curr_r - curr_l)
        prev_r, prev_l = curr_r, curr_l
        continue
        
    if prev_l <= curr_l and prev_r >= curr_r:
        continue
            
    if curr_l < prev_r:
        tot_len -= abs(prev_r - curr_l)
        
    tot_len += abs(curr_r - curr_l)
    prev_l, prev_r = curr_l, curr_r

print(tot_len)
