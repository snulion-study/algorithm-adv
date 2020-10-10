#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// vector<char> pick(vector<char> input, vector<char>& picked, int toPick){
//   if(toPick ==0){
//     return picked;
//   }
//   int smallest = picked.empty() ? 0 : picked.back() +1;
//   for (int next = smallest; next < input.size(); ++next){
//     picked.push_back(input.at(next));
//     pick(n,picked,toPick-1);
//     picked.pop_back();
//   }
// }

bool ConVow(char a){
  if(a =='a' || a=='e' || a=='i'|| a=='o'|| a=='u') return true;
  return false;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int L,C;
  cin >> L >> C ;

  vector<char> input(C); 
  vector<int> sub(C);
  vector<string> result;

  for(int i = 0; i< C; i++){
    cin >> input.at(i);
  }

  for(int i = C-L;i < C; i++){
    sub.at(i) = 1;
  }
  sort(input.begin(),input.end());

  do{
    string a="";
    int con=0;
    int vow=0;
    for(int i = 0; i < C; i++){
      if(sub.at(i)==1){
        a += input.at(i);
        if(ConVow(input.at(i))) con++;
        else vow++;
      }
    }
    if(con>=1 && vow>=2) result.push_back(a);
  }while(next_permutation(sub.begin(),sub.end()));

  sort(result.begin(),result.end());

  for(vector<string>::iterator iter=result.begin(); iter!=result.end(); iter++){
    cout << *iter <<endl;
  }




  return 0;
}