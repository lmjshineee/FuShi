#include <iostream>
using namespace std;
/*
ͳ���ַ����е������ַ�����
*/
void test() {
    int T;
    cin >> T;
    int a[T];
    for(int i = 0; i < T; i++) {
        string s;
        cin >> s;
        int count = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] >= '0' && s[j] <= '9') {
                count++;
            }
        }
        a[i] = count;
    }
    for(int i = 0; i < T; i++) {
        cout << a[i] << " ";
    }
}
int main() {
    test();
    return 0;
}