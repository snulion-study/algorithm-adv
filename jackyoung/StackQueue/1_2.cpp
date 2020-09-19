#include <iostream>
#include <string>

using namespace std;
int main(){
  int num;
  int *h;
  cin >> num;
  h = new int[num];
  for (int i = 0; i< num; i++){
    cin >>h[i];
  }

  return 0;
}