#include <iostream>
#include <string>
using namespace std;

/*  
c++ ʵ�� ���������������������������Ϊ 0 ������������������������������Ϊһ�顣��20 �֣�
���룺1234
12345
123456
�����1,234
12,345
123,456
*/
void formatNumber(string num) {
    int len = num.length();
    // ��������ÿ����λ�Ӷ���
    for (int i = 0; i < len; i++) {
        cout << num[i];
        // �ж��Ƿ���Ҫ�Ӷ��ţ��������һ������ && ���滹�� 3 �ı���������
        if (i != len - 1 && (len - i - 1) % 3 == 0) {
            cout << ",";
        }
    }
    cout << endl;
}

int main() {
    string number;
    
    // ѭ�����룬ֱ������ 0
    while (true) {
        cin >> number;
        
        // ����Ƿ�Ϊ 0
        if (number == "0") {
            break;
        }
        
        // ��ʽ���������
        formatNumber(number);
    }
    
    return 0;
}
