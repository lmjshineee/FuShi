#include <iostream>
#include <vector>
using namespace std;

/*
T �β�ѯ �� m �� n ÿ��������ֵ��������Ϊ 0
*/
void test() {
    int N, T;
    cin >> N >> T;
    
    // ʹ����ȷ����������
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
               temp = j;  // ������Ӧ���� j ������ i
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