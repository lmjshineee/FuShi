#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/**
 * ���Ҷ�ά���������о�Ϊ���ֵ��Ԫ��
 * @param matrix ����Ķ�ά����
 */
void findMaxInRowAndCol(const vector<vector<int>>& matrix) {
    // ��������Ƿ�Ϊ��
    if (matrix.empty() || matrix[0].empty()) {
        cout << "����Ϊ�գ�" << endl;
        return;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // ���ڴ洢�����Ԫ�ؼ���λ��
    vector<pair<int, pair<int, int>>> results;
    
    // ����ÿһ��
    for (int i = 0; i < rows; i++) {
        // �ҳ����е����ֵ
        int maxInRow = matrix[i][0];
        int maxColIndex = 0;
        
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
                maxColIndex = j;
            }
        }
        
        // ����Ԫ���Ƿ�Ҳ���������е����ֵ
        bool isMaxInCol = true;
        for (int k = 0; k < rows; k++) {
            if (matrix[k][maxColIndex] > maxInRow) {
                isMaxInCol = false;
                break;
            }
        }
        
        // �����Ԫ�����к����Ͼ�Ϊ������¼���
        if (isMaxInCol) {
            results.push_back({maxInRow, {i, maxColIndex}});
        }
    }
    
    // ������
    if (results.empty()) {
        cout << "û���ҵ�����������Ԫ�أ�" << endl;
    } else {
        cout << "�ҵ� " << results.size() << " ������������Ԫ�أ�" << endl;
        for (const auto& result : results) {
            int value = result.first;
            int row = result.second.first;
            int col = result.second.second;
            cout << "Ԫ��ֵ��" << value << ", λ�ã�(" << row << ", " << col << ")" << endl;
        }
    }
}
void test1(){
    // �������� 1: ������������Ԫ��
    vector<vector<int>> matrix1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << "�������ݣ�" << endl;
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