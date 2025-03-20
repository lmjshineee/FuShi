#include <iostream>
#include <vector>
#include <string>
using namespace std;

// �жϵ����Ƿ�Ϊ��A��
bool isA(const vector<string>& grid, int n, int m) {
    if (n < 3 || m < 3) return false; // A ������Ҫ 3x3

    // Ѱ�Ҷ��㣺��һ��ֻ��һ�� '#'
    int apex = -1;
    int count = 0;
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == '#') {
            apex = j;
            count++;
        }
    }
    if (count != 1) return false; // �������Ψһ

    // ���Ӷ���������չ�� A ��
    int left = apex, right = apex;
    bool foundLegs = false;
    for (int i = 1; i < n; i++) {
        // ��չб��
        if (left >= 0 && right < m) {
            if (grid[i][left] == '#' && grid[i][right] == '#') {
                // ������ҽŶԳƷֿ�
                if (left != right) foundLegs = true;
                left--;
                right++;
            } else {
                return false; // ������ A ����״
            }
        } else {
            return false; // �����߽�
        }
    }
    return foundLegs; // �����зֿ���������
}

// �жϵ����Ƿ�Ϊ��H��
bool isH(const vector<string>& grid, int n, int m) {
    if (n < 3 || m < 3) return false; // H ������Ҫ 3x3

    // Ѱ�����������
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
            else return false; // ������������
        }
    }
    if (leftCol == -1 || rightCol == -1 || leftCol + 1 == rightCol) return false;

    // ����м���
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
            cin >> grid[i]; // ����ÿһ��
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