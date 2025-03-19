#include <iostream>
#include <string>
using namespace std;

/*  
c++ 实现 输入若干组正整数，输入的数据为 0 代表输入结束，输出数据以三个数字为一组。（20 分）
输入：1234
12345
123456
输出：1,234
12,345
123,456
*/
void formatNumber(string num) {
    int len = num.length();
    // 从右往左每隔三位加逗号
    for (int i = 0; i < len; i++) {
        cout << num[i];
        // 判断是否需要加逗号：不是最后一个数字 && 后面还有 3 的倍数个数字
        if (i != len - 1 && (len - i - 1) % 3 == 0) {
            cout << ",";
        }
    }
    cout << endl;
}

int main() {
    string number;
    
    // 循环输入，直到遇到 0
    while (true) {
        cin >> number;
        
        // 检查是否为 0
        if (number == "0") {
            break;
        }
        
        // 格式化输出数字
        formatNumber(number);
    }
    
    return 0;
}
