/*
방법
- 자르는 위치 정렬(앞 위치 기준으로 정렬, 앞이 같으면 뒤 기준으로 정렬)
- 정렬된 순서대로 자르는 부분들을 병합. 
- 병합이 되지 않는 순간이 오면 이미 병합된 부분의 길이를 ans에 누적시킨다. 
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt;
    cin >> cnt;
    vector<pair<int, int>> input(cnt);
    for (int i = 0; i < cnt; i++) {
        pair<int, int> tmp;
        int a, b;
        cin >> a >> b;
        tmp.first = a > b ? b : a;
        tmp.second = a > b ? a : b;
        input[i] = tmp;
    }
    sort(input.begin(), input.end());
    pair<int, int> cur;
    int ans = 0;
    cur.first = input[0].first;
    cur.second = input[0].second;
    for (int i = 1; i < cnt; i++) {
        // 기존 세그먼트와 새로운 세그먼트가 이어지지 않을 경우 기존 세그먼트 길이를 누적 길이에 더해준다.
        if (cur.second < input[i].first) {
            ans += cur.second - cur.first;
            cur.first = input[i].first;
            cur.second = input[i].second;
        } else {
            cur.second = input[i].second > cur.second ? input[i].second : cur.second;
        }
    }
    ans += cur.second - cur.first;
    cout << ans;
    return 0;
}