#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations){
    sort(citations.begin(),citations.end(),greater<int>());
    int length = citations.size();
    for (int i=0;i<length;i++){
        if (citations[i] <= i) return i;
    }
}

int main(){
    vector<int> citations;
    solution(citations);
    return 0;
}