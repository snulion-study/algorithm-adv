import sys
from collections import defaultdict
input = sys.stdin.readline

def makeAdjacencyList(edges):
    adj_list = defaultdict(set)
    for edge in edges:
        n1, n2 = edge
        adj_list[n1].add(n2)
        adj_list[n2].add(n1)
    return adj_list

def solution(computers, edges):
    adj_list = makeAdjacencyList(edges)
    visited = []
    stack = [1] # 0 부터 시작
    while stack: 
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            stack += adj_list[node]-set(visited)
    return len(visited)-1
# Driver Code
if __name__ == "__main__":
    computers = int(input())
    num_edges = int(input())
    edges = []
    for edge in range(num_edges):
        edges.append(list(map(int,input().split(' '))))
    print(solution(computers, edges))