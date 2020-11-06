#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int L, C;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    vector<char> let(C);
    for (int i = 0; i < C; i++) {
        cin >> let[i];
    }
    sort(let.begin(), let.end());
    vector<int> bo(C);
    for (int i = 0; i < C - L; i++) {
        bo[i] = 0;
    }
    for (int i = C - L; i < C; i++) {
        bo[i] = 1;
    }
    vector<string> ss;
    do {
        int mo = 0;
        int ja = 0;
        for (int i = 0; i < C; i++) {
            if (bo[C - i - 1]) {
                if (let[i] == 'a' || let[i] == 'e' || let[i] == 'i' ||
                    let[i] == 'o' || let[i] == 'u') {
                    mo++;
                } else {
                    ja++;
                }
            }
        }
        if (mo < 1 || ja < 2) continue;
        string ts;
        for (int i = 0; i < C; i++) {
            if (bo[C - i - 1]) {
                ts.push_back(let[i]);
            }
        }
        ss.push_back(ts);
    } while (next_permutation(bo.begin(), bo.end()));
    sort(ss.begin(), ss.end());
    for (int i = 0; i < ss.size(); i++) {
        cout << ss[i] << endl;
    }
    return 0;
}