#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int,int>> divide(int a){
  vector<pair<int,int>> result;
  int N = sqrt(a);
  for (int i=1; i<= N; i++){
    if((float)(a/i)==(float)a/i){
      pair<int,int> item;
      item.first = a/i;
      item.second = i;
      result.push_back(item);
    }
  }
  return result;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int,int>> list;
    list = divide(yellow);
    for(vector<pair<int,int>>::iterator iter=list.begin(); iter!=list.end();iter++){
      if(iter->first + iter->second +2 == brown/2){
        answer.push_back(iter->first + 2);
        answer.push_back(iter->second + 2);
      }
    }

    return answer;
}

