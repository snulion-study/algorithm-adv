#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int N;
  cin >> N ;

  vector<vector<int>> arr;
  for (int i =0; i< N; i++){
    int h,t;
    cin >> h >> t;
    arr.push_back({h,t});
  }

  // 먼저 시작하는 순서대로 정렬
  sort(arr.begin(),arr.end());
  
  // 끝을 저장
  int tail = arr.at(0).at(1);
  int answer = tail-arr.at(0).at(0);

  for(vector<vector<int>>::iterator iter = arr.begin() +1; iter!=arr.end();iter++){
    int now_h = iter->at(0);
    int now_t = iter->at(1);
    if(tail < now_t){ // 현재 선이 이전 선에 포함되지 않는 경우만 계산
      if(tail >= now_h){ // 겹치는 경우
        answer += now_t - tail;
      }
      else{ // 아예 독립적인 경우
        answer += now_t-now_h;
      }
      // tail update
      tail = now_t;
    }
  }
  cout <<answer <<endl;

  return 0;
}

// array version --> timeout
// bool compare(int *a, int *b){
//   return a[0] < b[0];
// }

// int main(){
//   int N;
//   cin >> N ;

//   int ** arr, **arr_rev;
//   arr = new int*[N];
//   for(int i = 0; i<N ; i++){
//     arr[i] = new int[2];
//   }
//   for (int i =0; i< N; i++){
//     cin >> arr[i][0] >> arr[i][1];
//   }
//   sort(arr,arr+N,compare);
  
//   int answer=arr[0][1]-arr[0][0];

//   int head = arr[0][0];
//   int tail = arr[0][1];

//   for(int i = 1; i< N; i++){
//     if(tail < arr[i][1]){
//       if(tail >= arr[i][0]){
//         answer += arr[i][1] - tail;
//         tail = arr[i][1];
//       }
//       else{

//         answer += arr[i][1]-arr[i][0];
//         head = arr[i][0];
//         tail = arr[i][1];
//       }
//     }
//   }
//   cout <<answer <<endl;

//   for (int i = 0; i< N;i++){
//     delete[] arr[i];
//   }
//   delete[] arr;
//   return 0;
// }

// vector version

