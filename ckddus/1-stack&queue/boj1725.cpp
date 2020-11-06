#include <iostream>
#include <stack>
using namespace std;

int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while (n) {
        stack<int> s1, s2;
        long long maxarea = 0;
        int tmp;
        s1.push(0);
        s2.push(0);
        for (int i = 1; i <= n + 1; i++) {
            if (i == n + 1) {
                tmp = 0;
            } else {
                cin >> tmp;
            }
            while (tmp < s1.top()) {
                long long h = s1.top();
                s1.pop();
                s2.pop();
                long long tmparea = h * (i - s2.top() - 1);
                maxarea = tmparea < maxarea ? maxarea : tmparea;
            }
            s1.push(tmp);
            s2.push(i);
        }
        cout << maxarea << '\n';
        n = 0;
    }
    return 0;
}