def dfs(numbers, idx, path):
    if idx == len(numbers):
        return path
    else:
        new_path = []
        for p in path:
            pos_path = p[:]
            pos_path.append(numbers[idx])
            neg_path = p[:]
            neg_path.append(-numbers[idx])
            new_path.append(pos_path)
            new_path.append(neg_path)

        return dfs(numbers, idx+1, new_path)

def solution(numbers, target):
    answer = 0
    path = dfs(numbers,1,[[numbers[0]],[-numbers[0]]])
    
    for p in path:
        if sum(p)== target:
            answer+=1
    return answer

print(solution([1,1,1,1,1],3))
