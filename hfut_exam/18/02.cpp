# include <iostream>
# include <vector>
# include <queue>
# include <set>
using namespace std;

/*
输入一个数组，输出第 k 小的数。（10 分）
样例：
输入：
10 3
10 20 30 10 20 30 40 40 50 60
输出：
30
*/
int findKthSmallest(vector<int>& arr, int k) {
    set<int> s(arr.begin(), arr.end());
    arr.assign(s.begin(), s.end());
    if(arr.size()<k) return -1;
    // 定义小根堆
    priority_queue<int> minHeap;
    
    // 遍历数组，维护大小为 k 的堆
    for (int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }
    // 堆顶是第 k 小的数
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