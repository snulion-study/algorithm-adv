#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string* countingSort(string* A, int N,int range = 50){
  int* count = new int[range+1]{0};
  int* count_copy = new int[range+1]{0};
  for(int i = 0; i< N; i++){
    count[A[i].length()]++;
  }
  for(int i = 0; i<range+1; i++){
    if (i> 1) count[i]+= count[i-1];
    count_copy[i] = count[i];
  }
  string* B = new string[N+1]{""};
  for(int i=N-1; i>= 0; i--){
    B[count[A[i].length()]--] = A[i];
  }
  for(int i = 1; i< range+1; i++){
    sort(B+count_copy[i-1]+1,B+count_copy[i]+1);
  }

  return B;
}

int main(){
  int N;
  cin >> N;

  string arr[20000];
  int max_len = 0;
  for (int i=0; i< N ; i++){
    cin >> arr[i];
    if(arr[i].length() > max_len) max_len = arr[i].length();
  }
  string* result = new string[N];
  result = countingSort(arr, N, max_len);
  // cout << "---------------------" << endl;
  string prev = "A";
  for (int i = 1; i<N+1; i++){
    if(prev!=result[i]){
      cout << result[i]  << endl;
      prev = result[i];
    }

  }

  return 0;
}