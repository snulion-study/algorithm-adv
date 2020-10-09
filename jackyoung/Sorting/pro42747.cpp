#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 내림차순으로 정렬
bool compare(int a, int b){
  return a >= b;
}

int solution(vector<int> citations) {
    int answer = 0;
    // 내림차순 정렬
    sort(citations.begin(), citations.end(), compare);
    int count = 1;
    for(vector<int>::iterator iter = citations.begin(); iter!= citations.end(); iter++){
      // *iter 번 이상 인용된 논문이 count편 존재함을 확인하는 작업
      if(count > *iter){ 
        break;
      }else{ 
        answer = count;
      }
      count ++;
    }
    return answer;
}

int main(){
  vector<int> citations{3,0,6,1,5};
  cout << solution(citations)<< endl;
}