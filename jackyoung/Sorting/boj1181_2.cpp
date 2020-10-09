#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
  if(a.length() == b.length()){ // 길이가 같으면 사전 순서대로 정렬
    return a < b;
  }else{  // 일단은 길이 순서대로 정렬
    return a.length()<b.length();
  }
}


int main(){
  int N;
  cin >> N;

  string arr[20000];
  int max_len = 0;
  for (int i=0; i< N ; i++){
    cin >> arr[i];
  }
  // 정렬 
  sort(arr, arr+N, compare);
  string prev = "A";
  for (int i = 0; i<N; i++){
    if(prev!=arr[i]){
      cout << arr[i]  << endl;
      prev = arr[i];
    }
  }
  return 0;
}