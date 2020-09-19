#include <iostream>
#include <string>
#include <vector>


using namespace std;


vector<vector<int>> rotate(vector<vector<int>> data){
  int size = data.size();
  vector<vector<int>> result;
  vector<int> row;
  for (int i = size-1; i>=0 ; i--){
    for(vector<vector<int>>::iterator it = data.begin(); it != data.end(); ++it){
      row.push_back(it -> at(i));
    }
    result.push_back(row);
    row.clear();
  }
  return result;
}

vector<vector<int>> makebigger(vector<vector<int>> data, int size){
  int lock_size = data.size();
  vector<vector<int>> result;
  for(int i = 0; i< 2*size + lock_size; i++){
    vector<int> row;
    row.assign(2*size+lock_size,0);
    result.push_back(row);
  }
  for( int i=size; i<size+lock_size; i++){
    for(int j = size; j<size+lock_size; j++){
      result.at(i).at(j) = data.at(i-size).at(j-size);
    }
  }
  return result;
}

bool check_help(vector<vector<int>> biglock, vector<vector<int>> key, int a, int b){
  int i_start = a>key.size()? a : key.size();
  int i_end = a+key.size() > biglock.size()-key.size()? biglock.size()-key.size() : a+key.size();
  int j_start = b>key.size()? b : key.size();
  int j_end = b+key.size() > biglock.size()-key.size()? biglock.size()-key.size() : b+key.size();

  for(int i = i_start ; i< i_end;i++){
    for(int j = j_start ; j< j_end ; j++){
      biglock.at(i).at(j) += key.at(i-a).at(j-b);
    }
  }
  for(int m = key.size() ; m < biglock.size()-key.size(); m++){
    for( int n = key.size() ; n < biglock.size()-key.size(); n++){
      if(biglock.at(m).at(n)!=1) return false;
    }
  }
  return true;
}

bool check(vector<vector<int>> lock, vector<vector<int>> key){
  vector<vector<int>> biglock = makebigger(lock, key.size());
  for(int i=0;i<key.size() + lock.size(); i++){
    for (int j=0; j< key.size() + lock.size(); j++){
      bool tmp = check_help(biglock, key, i, j);
      if(tmp) return true;
    }
  }
  return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock){
  bool tmp = check(lock,key);
  if(tmp) return true;
  for(int i = 0; i< 3 ; i++){
    key = rotate(key);
    tmp = check(lock,key);
    if(tmp) return true;
  }
  return false;
}


int main(){
  vector<vector<int>> key{{0,0,0},{1,0,0},{0,1,1}};
  vector<vector<int>> lock{{1,1,1},{1,1,0},{1,0,1}};
  bool result = solution(key,lock);
  string a = result ? "True" : "False" ;
  cout <<  a << endl;
  return 0;
}