# BFS

## Breadth-First-Search, 너비 우선 탐색

**루트노드에서 시작해서 인접한 노드를 먼저 탐색하는 방법**

- 연결된 가장 빠른 정점들을 방문하는 방식 
- 최단길이 보장해야할 때 많이 사용

![bfs](https://t1.daumcdn.net/cfile/tistory/216E924B5858D62B37)


![bfs](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbLMK90%2FbtqKrJ9aUXI%2FhvWf1krFJb6R0WlIKx1Vk0%2Fimg.gif)

### 장점

1. 노드의 수가 적고 깊이가 얕은 경우 빠르게 동작할 수 있다.
2. 단순 검색 속도가 깊이 우선 탐색(DFS)보다 빠름
3. 너비를 우선 탐색하기에 답이 되는 경로가 여러개인 경우에도 최단경로임을 보장한다.
4. 최단경로가 존재한다면 어느 한 경로가 무한히 깊어진다해도 최단경로를 반드시 찾을 수 있다.



### BFS의 구현: 큐 이용 

**① queue의 가장 앞에 있는 노드를 pop** 

**② 현재 노드에 인접한 모든 노드들 중 아직 방문하지 않은 노드들을 queue에 push**

**③ queue가 비어있지 않으면, ①번부터 다시 실행**

출처: https://sarah950716.tistory.com/13 [주니어 개발자의 대나무숲]



![image-20201027170555966](https://gmlwjd9405.github.io/images/algorithm-dfs-vs-bfs/bfs-example.png)

<br>


## 코드

**while(queue가 비어있지 않은 동안)**

**{**

​	① queue의 가장 앞에 있는 노드를 pop 

​	② 현재 노드에 인접한 모든 노드들 중 아직 방문하지 않은 노드들을 queue에 push

**}**



```
BFS (G, s)                   //G: 대상 그래프, s: 시작 노드
      let Q = queue
      Q.enqueue( s ) // 시작 노드를 큐에 삽입 
      mark s as visited.
      while ( Q is not empty)
           // 큐에서 노드를 꺼내고, 그 노드의 이웃 노드를 방문 => 큐가 빌 때까지 반복
           v  =  Q.dequeue( )

          // v의 이웃 노드 방문 
          for all neighbours w of v in Graph G
               if w is not visited 
                        Q.enqueue( w )             
                        mark w as visited.
```

* Complexity: O(V+E)



### C++ 코드

```c++
void BFS(int idx)
{
       q.push(idx);
        visited[idx] = 1;
        while (!q.empty())
        {
                 idx = q.front();
                 q.pop();
                 cout << idx << " ";
             //BFS는 해당 노드에 인접한 노드들을 모두 추가한 뒤 BFS 진행
	               for(int i=1; i<=N; i++)
										if (adjacent[idx][i] && !visited[i])
											{
                                 visited[i] = 1;
                                 q.push(i);
                       }
        }
}

 

int main(void)

{
        cin >> N >> M >> V;
        for (int i = 0; i < M; i++)
        {
                 int from, to;
                 cin >> from >> to;
                 adjacent[from][to] = 1;
                 adjacent[to][from] = 1;
        }

        visited[V] = 1; //V에서 시작하므로
        memset(visited, false, sizeof(visited));
        BFS(V);
        return 0;

}

```

