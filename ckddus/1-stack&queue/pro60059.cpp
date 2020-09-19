#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>

using namespace std;

bool check3(vector<vector<int>> key, vector<vector<int>> lock, int r, int c) {
    int N = lock.size();
    int M = key.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool flag = i - r >= 0 && j - c >= 0 && i - r < M && j - c < M ? key[i - r][j - c] : false;
            if (!(lock[i][j] ^ flag)) return false;
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int M = key.size();
    int N = lock.size();
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(key, lock, i, j)) return true;
        }
    }
    vector<vector<int>> m1key(M, vector<int>(M));
    vector<vector<int>> m2key(M, vector<int>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m1key[j][M - 1 - i] = key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m1key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m2key[j][M - 1 - i] = m1key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m2key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m1key[j][M - 1 - i] = m2key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m1key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m1key[i][M - 1 - j] = key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m1key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m2key[j][M - 1 - i] = m1key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m2key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m1key[j][M - 1 - i] = m2key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m1key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m2key[j][M - 1 - i] = m1key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m2key, lock, i, j)) return true;
        }
    }
    return false;
}