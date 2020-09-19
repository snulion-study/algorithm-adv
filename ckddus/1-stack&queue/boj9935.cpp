#include <iostream>
#include <string>
using namespace std;
char res[1000000];
int idx = 0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string og, bomb;
    cin >> og;
    cin >> bomb;
    int bsize = bomb.size();
    for (int i = 0; i < og.size(); i++) {
        res[idx] = og[i];
        idx++;
        if (idx < bsize) continue;
        if (res[idx - 1] == bomb[bsize - 1]) {
            bool flag = false;
            for (int j = 0; j < bsize - 1; j++) {
                if (res[idx - 2 - j] != bomb[bsize - 2 - j]) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;
            else
                idx -= bsize;
        }
    }
    if (idx == 0)
        cout << "FRULA";
    else {
        for (int i = 0; i < idx; i++) {
            cout << res[i];
        }
    }
    return 0;
}