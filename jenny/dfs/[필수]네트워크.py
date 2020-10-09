from collections import defaultdict

# adjacency list 만들기
def makeAdjacencyList(computers):
    adj_list = defaultdict(set)
    for i in range(len(computers)):
        neighbors = []
        for j in range(len(computers[i])):
            if j!=i and computers[i][j]==1:
                neighbors.append(j)
        adj_list.update({i: set(neighbors)})
    return adj_list

def solution(n, computers):
    answer = 0
    adj_list = makeAdjacencyList(computers)
    count_networks = 1
    visited = []
    stack = [0] # 0 부터 시작
    unvisited = list(range(n))
    while unvisited:
        while stack: 
            node = stack.pop()
            if node not in visited:
                visited.append(node)
                if node in unvisited:
                    unvisited.remove(node)
                stack += adj_list[node]-set(visited)
        if unvisited:
            stack.append(unvisited.pop())
            count_networks+=1

    return count_networks


print(solution(3,[[1, 1, 0], [1, 1, 0], [0, 0, 1]]))
print(solution(3,[[1, 1, 0], [1, 1, 1], [0, 1, 1]]))