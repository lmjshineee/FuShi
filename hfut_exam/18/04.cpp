#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 判断点阵是否为“A”
bool isA(const vector<string>& grid, int n, int m) {
    if (n < 3 || m < 3) return false; // A 至少需要 3x3

    // 寻找顶点：第一行只有一个 '#'
    int apex = -1;
    int count = 0;
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == '#') {
            apex = j;
            count++;
        }
    }
    if (count != 1) return false; // 顶点必须唯一

    // 检查从顶点向下扩展成 A 形
    int left = apex, right = apex;
    bool foundLegs = false;
    for (int i = 1; i < n; i++) {
        // 扩展斜边
        if (left >= 0 && right < m) {
            if (grid[i][left] == '#' && grid[i][right] == '#') {
                // 如果左右脚对称分开
                if (left != right) foundLegs = true;
                left--;
                right++;
            } else {
                return false; // 不符合 A 的形状
            }
        } else {
            return false; // 超出边界
        }
    }
    return foundLegs; // 必须有分开的两条腿
}

// 判断点阵是否为“H”
bool isH(const vector<string>& grid, int n, int m) {
    if (n < 3 || m < 3) return false; // H 至少需要 3x3

    // 寻找两侧的竖线
    int leftCol = -1, rightCol = -1;
    for (int j = 0; j < m; j++) {
        bool allHash = true;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] != '#') {
                allHash = false;
                break;
            }
        }
        if (allHash) {
            if (leftCol == -1) leftCol = j;
            else if (rightCol == -1) rightCol = j;
            else return false; // 超过两条竖线
        }
    }
    if (leftCol == -1 || rightCol == -1 || leftCol + 1 == rightCol) return false;

    // 检查中间横杠
    bool hasCrossbar = false;
    for (int i = 0; i < n; i++) {
        bool crossbar = true;
        for (int j = leftCol; j <= rightCol; j++) {
            if (grid[i][j] != '#') {
                crossbar = false;
                break;
            }
        }
        if (crossbar) {
            hasCrossbar = true;
            break;
        }
    }
    return hasCrossbar;
}

int main() {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i]; // 输入每一行
        }

        if (isA(grid, n, m)) {
            cout << "A" << endl;
        } else if (isH(grid, n, m)) {
            cout << "H" << endl;
        } else {
            cout << "Neither" << endl;
        }
    return 0;
}