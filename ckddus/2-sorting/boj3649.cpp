#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int wid;
    while (cin >> wid) {
        wid *= 10000000;
        int n;
        cin >> n;
        vector<int> block(n);
        for (int i = 0; i < n; i++) {
            cin >> block[i];
        }
        if (wid > 200000000 || n < 2) {
            cout << "danger\n";
            continue;
        }
        sort(block.begin(), block.end());
        int s = 0;
        int e = n - 1;
        bool flag = false;
        while (s < e) {
            if (block[s] + block[e] > wid)
                e--;
            else if (block[s] + block[e] < wid)
                s++;
            else {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "yes " << block[s] << " " << block[e] << "\n";
        } else {
            cout << "danger\n";
        }
    }
    return 0;
}