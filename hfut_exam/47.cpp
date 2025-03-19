#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/**
 * 查找二维数组中行列均为最大值的元素
 * @param matrix 输入的二维数组
 */
void findMaxInRowAndCol(const vector<vector<int>>& matrix) {
    // 检查数组是否为空
    if (matrix.empty() || matrix[0].empty()) {
        cout << "数组为空！" << endl;
        return;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // 用于存储结果的元素及其位置
    vector<pair<int, pair<int, int>>> results;
    
    // 遍历每一行
    for (int i = 0; i < rows; i++) {
        // 找出该行的最大值
        int maxInRow = matrix[i][0];
        int maxColIndex = 0;
        
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
                maxColIndex = j;
            }
        }
        
        // 检查该元素是否也是其所在列的最大值
        bool isMaxInCol = true;
        for (int k = 0; k < rows; k++) {
            if (matrix[k][maxColIndex] > maxInRow) {
                isMaxInCol = false;
                break;
            }
        }
        
        // 如果该元素在行和列上均为最大，则记录结果
        if (isMaxInCol) {
            results.push_back({maxInRow, {i, maxColIndex}});
        }
    }
    
    // 输出结果
    if (results.empty()) {
        cout << "没有找到满足条件的元素！" << endl;
    } else {
        cout << "找到 " << results.size() << " 个满足条件的元素：" << endl;
        for (const auto& result : results) {
            int value = result.first;
            int row = result.second.first;
            int col = result.second.second;
            cout << "元素值：" << value << ", 位置：(" << row << ", " << col << ")" << endl;
        }
    }
}
void test1(){
    // 测试用例 1: 有满足条件的元素
    vector<vector<int>> matrix1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << "矩阵内容：" << endl;
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    findMaxInRowAndCol(matrix1);
}

/*48*/
void showSeries1(int n){
    int A[n][n];
    for(int i=0;i<n;i++){
        A[0][i]=i+1;
        cout<<A[0][i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=(A[i-1][j]+1)%(n+1);
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void showSeries2(int n){
    int A[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=abs(i-j)+1;
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void showSeries3(int n){
    int A[n][n];
    for(int i=0;i<n;i++){
        A[0][i]=(i+1)%n;
        cout<<A[0][i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=(A[i-1][j]+1)%n;
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    //test1();
    //showSeries1(6);
    //showSeries2(6);
    showSeries3(6);
    return 0;
}