#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void SimuCal(){
    string input;
    
    cout << "简易四则运算计算器" << endl;
    cout << "支持整数的加 (+)、减 (-)、乘 (*)、除 (/) 运算" << endl;
    cout << "请输入表达式 (例如：5+6): ";
    
    while (getline(cin, input)) {
        if (input.empty()) {
            cout << "输入为空，退出" << endl;
            break;
        }
        
        // 寻找运算符
        size_t pos = 0;
        char op = '\0';
        for (size_t i = 0; i < input.length(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
                op = input[i];
                pos = i;
                break;
            }
        }
        
        // 检查是否找到有效的运算符
        if (op == '\0') {
            cout << "无效的表达式，未找到运算符。请重新输入：";
            continue;
        }
        
        // 提取操作数
        string leftStr = input.substr(0, pos);
        string rightStr = input.substr(pos + 1);
        
        // 检查操作数是否为空
        if (leftStr.empty() || rightStr.empty()) {
            cout << "无效的表达式，操作数不能为空。请重新输入：";
            continue;
        }
        
        // 转换操作数为整数
        int left, right;
        try {
            left = stoi(leftStr);
            right = stoi(rightStr);
        } catch (...) {
            cout << "无效的操作数，请确保输入整数。请重新输入：";
            continue;
        }
        
        // 执行计算
        int result;
        switch (op) {
            case '+':
                result = left + right;
                break;
            case '-':
                result = left - right;
                break;
            case '*':
                result = left * right;
                break;
            case '/':
                if (right == 0) {
                    cout << "错误：除数不能为零！请重新输入：";
                    continue;
                }
                result = left / right;
                break;
        }
        
        // 输出结果
        cout << "=" << result << endl;
        
        // 提示用户继续输入
        cout << "\n请输入新的表达式 (例如：5+6): ";
    }
}

int countChanges(){
    int count = 0;
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= 50; j++){
            for(int k = 1; k <= 100; k++){
                if(i*5 + j*2 + k == 100){
                    count++;
                    cout << "5 分硬币：" << i << " 2 分硬币：" << j << " 1 分硬币：" << k << endl;
                }
            }
        }
    }
    cout << "共有 " << count << " 种方案。" << endl;
    return count;
}

void SimuE(){
    // 设置精度值
    const double epsilon = 1e-8;
    // 计算 e 的初始值（第一项）
    double e = 1.0;  // e = 1 + 1/1! + 1/2! + 1/3! + ...
    // 用于计算阶乘的变量
    double factorial = 1.0;
    // 用于跟踪当前项
    int n = 1;
    // 当前项的值
    double term = 1.0;
    // 当余项 < epsilon 时停止计算
    while (term >= epsilon) {
        // 计算下一项：1/n!
        factorial *= n;     // 计算 n!
        term = 1.0 / factorial;  // 计算 1/n!
        e += term;          // 将当前项加到 e 的值中
        // 移动到下一项
        n++;
    }
    // 输出结果，显示高精度
    cout << "当 ε = " << scientific << setprecision(8) << epsilon << " 时：" << endl;
    cout << "自然对数底 e 的近似值 = " << fixed << setprecision(10) << e << endl;
    cout << "计算了 " << n - 1 << " 项" << endl;
}

int CalFactorial(int n){
    if(n == 0){
        return 1;
    }
    return n * CalFactorial(n - 1);
}

void SumOfFactors(int n){
    if(n <= 0){
        cout << "输入错误！请输入一个正整数。" << endl;
        return;
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += CalFactorial(i);
    }
    cout << "1! + 2! + ... + " << n << "! = " << sum << endl;
}

void CalMul(int n){

    int sum = 0;
    for(int i=1;i<=n;i=i+2){
        sum+=i*(i+1);
    }
    cout << "1*2 + 3*4 + ... + " << n << "*" << n+1 << " = " << sum << endl;
}

// 函数：反向输出正整数
void reverseNumber() {
    int num, reversed = 0;
    
    cout << "请输入一个正整数：";
    cin >> num;
    
    // 检查输入有效性
    if (cin.fail() || num <= 0) {
        cout << "输入无效，请确保输入一个正整数。" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    
    cout << "原始数字：" << num << endl;
    
    // 反向处理数字
    while (num > 0) {
        int digit = num % 10;  // 获取最后一位数字
        reversed = reversed * 10 + digit;  // 将该数字添加到结果中
        num /= 10;  // 移除已处理的最后一位
    }
    
    cout << "反向后的数字：" << reversed << endl;
}

// 函数：查找所有水仙花数
void findNarcissisticNumbers() {
    cout << "\n所有三位水仙花数：" << endl;
    
    int count = 0;
    
    // 检查所有三位数（100-999）
    for (int i = 100; i < 1000; i++) {
        // 提取各个位的数字
        int first = i / 100;          // 百位
        int second = (i / 10) % 10;   // 十位
        int third = i % 10;           // 个位
        
        // 计算各位数字的立方和
        int sum = pow(first, 3) + pow(second, 3) + pow(third, 3);
        
        // 检查是否为水仙花数
        if (sum == i) {
            cout << i << " = " << first << "^3 + " << second << "^3 + " << third << "^3" << endl;
            count++;
        }
    }
    
    cout << "\n共找到 " << count << " 个水仙花数。" << endl;
}

void findSerires(int s,int m){
    int sum,mul;
    for(int i=1;i<=5;i++){
        for(int d=1;d<=5;d++){
            sum=i*4+d*6;
            mul=i*(i+d)*(i+2*d)*(i+3*d);
            if(sum==s&&mul==m){
                cout<<i<<" "<<i+d<<" "<<i+2*d<<" "<<i+3*d<<endl;
            }
        }
    }
}

void findPerfectNum(){
    int count = 0;
    cout << "1000 以内的完数：" << endl;
    
    // 只计算到 1000 即可满足题目要求
    for(int i = 1; i <= 1000; i++){
        int sum = 0;
        int factors[100] = {0};
        int count1 = 0;
        
        // 查找所有因子
        for(int j = 1; j < i; j++){  // 不包括数字本身
            if(i % j == 0){
                sum += j;
                factors[count1++] = j;
            }
        }
        
        // 判断是否为完数
        if(sum == i){
            cout << i << " = ";
            
            // 按照递增顺序输出因子
            for(int k = 0; k < count1; k++){
                cout << factors[k];
                if(k < count1 - 1){
                    cout << " + ";
                }
            }
            cout << endl;
            count++;
        }
    }
    
    cout << "共有 " << count << " 个完数" << endl;
}

void findCouples(){
    for(int i=1;i<=10;i++){
        for(int j=1;j<i;j++){
            cout<<i<<" "<<j<<endl;
        }
    }
}

int main() {
    //SimuCal();
    //countChanges();
    //SimuE();
    //SumOfFactors(7);
    //CalMul(39);
    //reverseNumber();
    //findNarcissisticNumbers();
    //findSerires(26,880);
    //findPerfectNum();
    findCouples();
    return 0;
}