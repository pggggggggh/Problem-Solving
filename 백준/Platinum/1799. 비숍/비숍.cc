#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[15][15];
int pls[25], mins[25]; // 우측 대각선과 좌측 대각선 사용 여부
int n;
vector<pair<int,int>> pos[2]; // 두 색(0: (i+j)%2==0, 1: (i+j)%2==1)의 위치 저장

// DFS로 해당 색에서 놓을 수 있는 비숍의 최대 개수를 구하는 함수
int dfs(int color, int idx) {
    if (idx == pos[color].size()) return 0;
    int ret = 0;
    int i = pos[color][idx].first;
    int j = pos[color][idx].second;
    // 해당 위치에 비숍을 놓을 수 있으면
    if (a[i][j] == 1 && !pls[i+j] && !mins[j-i+10]) {
        pls[i+j] = 1;
        mins[j-i+10] = 1;
        ret = max(ret, dfs(color, idx + 1) + 1);
        pls[i+j] = 0;
        mins[j-i+10] = 0;
    }
    ret = max(ret, dfs(color, idx + 1));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            // (i+j)%2가 같으면 한 색, 다르면 다른 색으로 분리합니다.
            if ((i + j) % 2 == 0)
                pos[0].push_back({i, j});
            else
                pos[1].push_back({i, j});
        }
    }
    
    int ans = dfs(0, 0) + dfs(1, 0);
    cout << ans << "\n";
    return 0;
}
