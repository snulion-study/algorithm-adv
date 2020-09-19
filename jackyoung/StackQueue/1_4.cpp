#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
  string origin;
  cin >> origin;

  string bomb;
  cin >> bomb;

  stack<char> result;
  stack<int> save_index;
  int index = 0;
  int now = 0;
  int total_length = origin.length();

  for(int i = 0; i< total_length; i++){
    if(origin[i]==bomb[index]){
      if(index==bomb.length()-1){
        now-=bomb.length()-1;
        if(save_index.empty()){
          index = 0;
        }
        else{
          index = save_index.top();
          save_index.pop();
        }
      }
      else{
        index++;
        origin[now++]=origin[i];
      }
    }
    else if(origin[i]==bomb[0]){
      save_index.push(index);
      index = 1;
      origin[now++]=origin[i];
    }
    else{
      index = 0;
      origin[now++]=origin[i];
      while(!save_index.empty()){
        save_index.pop();
      }
    }
  }

  if(now==0){
    cout << "Lion" << endl;
    return 0;
  }

  for(int i = 0; i< now; i++){
    cout << origin[i];
  }

  return 0;
}