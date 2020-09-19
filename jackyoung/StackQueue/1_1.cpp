#include <iostream>
#include <string>

class stack{
  private:
    int tail;
    int *item;
  public:
    void push(int a){
      tail++;
      item[tail] = a;
    }
    int pop(){
      return tail>=0 ? item[tail--] : -1;
    }
    int size(){
      return tail+1;
    }
    int empty(){
      return tail>=0 ? 0 : 1;
    }
    int top(){
      return tail>=0 ? item[tail] : -1;
    }

    stack(){
      tail = -1;
      item = new int[10000];
    }
    ~stack(){

    }
};

using namespace std;
int main(){
  int iter;
  cin >> iter;

  stack jstack = stack();
  for (int i=0 ; i<iter; i++){
    string fnc;
    cin >> fnc;
    if(fnc=="push"){
      int item;
      cin >> item;
      jstack.push(item);
    }
    else if(fnc=="pop"){
      cout << jstack.pop() << endl;
    }
    else if(fnc=="size"){
      cout << jstack.size() << endl;
    }
    else if(fnc=="empty"){
      cout << jstack.empty() << endl;
    }
    else if(fnc=="top"){
      cout << jstack.top() << endl;
    }
  }
  return 0;
}