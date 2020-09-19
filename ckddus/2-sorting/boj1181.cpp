#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool comp(string a, string b) {
    if (a.size() < b.size()) {
        return true;
    } else if (a.size() > b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i])
            continue;
        else if (a[i] < b[i])
            return true;
        else
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt;
    cin >> cnt;
    vector<string> strvector(cnt);
    for (int i = 0; i < cnt; i++) {
        cin >> strvector[i];
    }
    sort(strvector.begin(), strvector.end(), comp);
    for (int i = 0; i < cnt; i++) {
        if (i > 0 && strvector[i] == strvector[i - 1]) continue;
        cout << strvector[i] << endl;
    }
    return 0;
}