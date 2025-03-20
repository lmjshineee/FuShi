#include <iostream>
#include <vector>
using namespace std;

/*
T 次查询 从 m 到 n 每次输出最大值并将其置为 0
*/
void test() {
    int N, T;
    cin >> N >> T;
    
    // 使用正确的数组声明
    vector<int> a(N);
    vector<int> b(T);
    
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < T; i++) {
       int m, n;
       cin >> m >> n;
       int temp = m;
       for(int j = m; j <= n; j++) {
           if(a[temp] < a[j]) {
               temp = j;  // 修正：应该是 j 而不是 i
           }
       }
       b[i] = a[temp];
       a[temp] = 0;
    }
    
    for(int i = 0; i < T; i++) {
        cout << b[i] << " "; 
    }
}

int main() {
    test();
    return 0;
}
/*
3 3
1 2 3
1 3
1 2
2 3
3 2 0 
*/