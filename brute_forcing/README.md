
# 그래프
## BRUTE FORCE 완전탐색
  - 가장 단순한 알고리즘이자 모든 알고리즘의 시작점
  - 무식하게 푼다(Brute Force)라는 의미로 모든 경우의 수를 생각해야함
  - 반복문(for loop) 혹은 순열과 조합 또는 재귀호출을 사용한다. 

### 많이 등장하는 완전탐색 유형
1. 모든 순열 만들기
     - permutation -> N! 으로 구하지만, N이 10이 넘어간다면 완전탐색 말고 다른 방법을 생각해야함. 
     - C++ -> 내장 라이브러리(algorithm)를 통해 next_permutation() 혹은 prev_permutation()을 사용 => O(N)
        - 1234 -> 1243 -> 1324 -> 1342 -> ... 4321 -> (false) 
     - 다른 언어 -> 재귀 호출로 구현해야함...!!
         
  
2. 모든 조합 만들기 
    - combination -> nCr
    - ex) n개의 원소 중에서 r개를 고르는 모든 조합을 구하는 경우         
  
    1. 중첩되는 반복문 사용시 ( if r == 4 ?)

        for(int i = 0; i < n; ++i)       
            for(int j = i+1; j < n; ++j)       
                for(int k = j+1; k < n; ++k)
                    for(int l = k+1; l < n; ++l)  
                        cout << i << " "  << j << " " << k << " " << l << endl;

    2. 재귀호출 사용시 
   
        void pick(int n, vector<int>& picked, int toPick) {
          if(toPick == 0) 
            {
              print_pick(picked);
              return;
            }
          int smallest = picked.empty() ? 0 : picked.back() + 1;

          for(int next = smallest; next < n; ++next) {
            picked.push_back(next);
            pick(n, picked, toPick-1);
            picked.pop_back();
          }
        }



3. 2^n 가지 경우의 수 만들기 
    - n개의 질문에 대한 답이 yes / no 중의 하나라고 할 때, 가능한 답의 모든 조합의 수는 2^n 
    - 이 때, 각 조합을 하나의 n 비트 정수로 표현한다고 하면, 재귀 호출 대신, 1차원의 for loop으로 가능 
    - boj_17825 주사위 윷놀이 문제

풀어보면 좋은 종만북 문제들 ㅎ_ㅎ
https://algospot.com/judge/problem/read/PICNIC
https://algospot.com/judge/problem/read/BOARDCOVER

[출처] 알고리즘 문제해결전략 - 구종만 