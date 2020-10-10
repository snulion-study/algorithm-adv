#include <iostream>
#include <cmath>

using namespace std;

int getdigit(int a){
  int d=1;
  while(a/pow(10,d) >= 1){
    d+=1;
  }
  return d;
}

bool check(int* button,int M, int num){
  int d = getdigit(num);
  for(int i = 0; i< d ; i++){
    int a = num/pow(10,i);
    a%=10;
    // 한자리씩 비교
    for(int j = 0; j< M; j++){
      if(a==button[j]) return false;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  // 불가능한 버튼
  int* empty = new int[M];
  for(int i =0; i< M; i++){
    cin >> empty[i];
  }

  // 100 근처
  if(N >= 98 && N <= 103){
    cout << abs(N-100);
    return 0;
  }

  // 몇자리 숫자인지 알아내기
  int d=1;
  while(N/pow(10,d) >= 1){
    d+=1;
  }

  // BT
  int answer_u = 0,answer_l = 0;
  bool upper = false, lower = false;
  for(int i = 0; i< 500000; i++){
    if(check(empty, M, N+i) && !upper){
      answer_u = N+i;
      upper = true;
    }
    if(check(empty,M,N-i) && !lower){
      if(N-i<0){
        answer_l = 10000000;
        lower = true;
      }
      else{
        answer_l = N-i;
        lower = true;
      }
    }
    if(upper && lower) break;
  }

  // 몇자리인지 알아내기
  int answer = abs(N-answer_u)+getdigit(answer_u);
  answer = (answer<abs(N-answer_l)+getdigit(answer_l))?answer:abs(N-answer_l)+getdigit(answer_l);

  cout << answer;

  return 0;
}