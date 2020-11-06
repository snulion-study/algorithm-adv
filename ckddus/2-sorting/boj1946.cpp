#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
int num;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for (int tt = 0; tt < tc; tt++) {
        cin >> num;
        vector<ii> em(num);
        for (int i = 0; i < num; i++) {
            cin >> em[i].first >> em[i].second;
        }
        sort(em.begin(), em.end());
        vector<bool> pass(num, true);
        int ans = num;
        int min = num + 1;
        for (int i = 0; i < num; i++) {
            if (em[i].second > min) ans--;
            min = min > em[i].second ? em[i].second : min;
        }
        cout << ans << endl;
    }
}