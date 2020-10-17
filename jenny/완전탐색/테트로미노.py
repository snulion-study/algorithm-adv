import sys
input = sys.stdin.readline

shapes = [
    [(0,0),(0,1),(0,2),(0,3)],   #shape1
    [(0,0),(1,0),(2,0),(3,0)],   #shape1
    [(0,0),(0,1),(1,0),(1,1)],   #shape2
    [(0,0),(1,0),(2,0),(2,1)],   #shape3
    [(0,0),(1,0),(2,0),(2,-1)],  #shape3
    [(0,0),(0,1),(0,2),(-1,2)],  #shape3
    [(0,0),(1,0),(1,1),(1,2)],   #shape3
    [(0,0),(0,1),(1,1),(2,1)],   #shape3
    [(0,0),(1,0),(2,0),(0,1)],   #shape3
    [(0,0),(1,0),(0,1),(0,2)],   #shape3
    [(0,0),(0,1),(0,2),(1,2)],   #shape3
    [(0,0),(1,0),(1,1),(2,1)],   #shape4
    [(0,0),(1,-1),(1,0),(2,-1)], #shape4
    [(0,0),(0,1),(-1,1),(-1,2)], #shape4
    [(0,0),(0,1),(1,1),(1,2)],   #shape4
    [(0,0),(0,1),(0,2),(-1,1)],  #shape5
    [(0,0),(0,1),(0,2),(1,1)],   #shape5
    [(0,0),(1,0),(2,0),(1,1)],   #shape5
    [(0,0),(0,1),(-1,1),(1,1)],  #shape5
]

def solution(grid,h,w):
    max_ = 0
    for i in range(h):
        for j in range(w):
            start = (i,j)
            for shape in shapes:
                blocks = []
                total = 0
                halt = False
                for point in shape:
                    if 0<=start[0]+point[0]<h and 0<=start[1]+point[1]<w:
                        total += grid[start[0]+point[0]][start[1]+point[1]]
                    else:
                        halt = True
                        break
                if halt:
                    continue
                if total>max_:
                    max_ = total

    return max_


if __name__ == '__main__':
    h,w = map(int,input().split(' '))
    grid = []
    for _ in range(h):
        grid.append(list(map(int,input().split(' '))))
    print(solution(grid, h, w))