# include <iostream>
# include <vector>
# include <queue>
# include <set>
using namespace std;

/*
����һ�����飬����� k С��������10 �֣�
������
���룺
10 3
10 20 30 10 20 30 40 40 50 60
�����
30
*/
int findKthSmallest(vector<int>& arr, int k) {
    set<int> s(arr.begin(), arr.end());
    arr.assign(s.begin(), s.end());
    if(arr.size()<k) return -1;
    // ����С����
    priority_queue<int> minHeap;
    
    // �������飬ά����СΪ k �Ķ�
    for (int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }
    // �Ѷ��ǵ� k С����
    return minHeap.top();
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = findKthSmallest(arr, k);
    cout << result << endl;
    return 0;
}