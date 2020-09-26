#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> str_a, pair<string,int> str_b){
    if(str_a.second ==str_b.second) return str_a.first <str_b.first;
    else return str_a.second <str_b.second;
}

vector<string> get(){
    // int num;
    // string str, tem;
    // vector <pair<string, int> > v_pair;
    // cin >> num;

    // vector<string> result;
    // for(int i = 0; i < num; i++){
    //     cin >> str;
    //     v_pair.push_back(pair<string, int>(str, str.size()));
    // }
    // sort(v_pair.begin(), v_pair.end(), compare);

    // for(int i = 0; i < v_pair.size(); i++){
    //     if(i > 0 && v_pair[i].first == v_pair[i-1].first){
    //         continue;
    //     }
    //     result.push_back(v_pair[i].first);
    // }
    // return result;
}

int main(){
    int num;
    string str, tem;
    vector <pair<string, int> > v_pair;
    cin >> num;
    
    for(int i = 0; i < num; i++){
        cin >> str;
        v_pair.push_back(pair<string, int>(str, str.size()));
    }
    sort(v_pair.begin(), v_pair.end(), compare);

    for(int i = 0; i < v_pair.size(); i++){
        if(i > 0 && v_pair[i].first == v_pair[i-1].first){
            continue;
        }
        cout << v_pair[i].first << endl;
    }
    return 0;
}