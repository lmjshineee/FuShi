#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void SimuCal(){
    string input;
    
    cout << "�����������������" << endl;
    cout << "֧�������ļ� (+)���� (-)���� (*)���� (/) ����" << endl;
    cout << "��������ʽ (���磺5+6): ";
    
    while (getline(cin, input)) {
        if (input.empty()) {
            cout << "����Ϊ�գ��˳�" << endl;
            break;
        }
        
        // Ѱ�������
        size_t pos = 0;
        char op = '\0';
        for (size_t i = 0; i < input.length(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
                op = input[i];
                pos = i;
                break;
            }
        }
        
        // ����Ƿ��ҵ���Ч�������
        if (op == '\0') {
            cout << "��Ч�ı��ʽ��δ�ҵ�����������������룺";
            continue;
        }
        
        // ��ȡ������
        string leftStr = input.substr(0, pos);
        string rightStr = input.substr(pos + 1);
        
        // ���������Ƿ�Ϊ��
        if (leftStr.empty() || rightStr.empty()) {
            cout << "��Ч�ı��ʽ������������Ϊ�ա����������룺";
            continue;
        }
        
        // ת��������Ϊ����
        int left, right;
        try {
            left = stoi(leftStr);
            right = stoi(rightStr);
        } catch (...) {
            cout << "��Ч�Ĳ���������ȷ���������������������룺";
            continue;
        }
        
        // ִ�м���
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
                    cout << "���󣺳�������Ϊ�㣡���������룺";
                    continue;
                }
                result = left / right;
                break;
        }
        
        // ������
        cout << "=" << result << endl;
        
        // ��ʾ�û���������
        cout << "\n�������µı��ʽ (���磺5+6): ";
    }
}

int countChanges(){
    int count = 0;
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= 50; j++){
            for(int k = 1; k <= 100; k++){
                if(i*5 + j*2 + k == 100){
                    count++;
                    cout << "5 ��Ӳ�ң�" << i << " 2 ��Ӳ�ң�" << j << " 1 ��Ӳ�ң�" << k << endl;
                }
            }
        }
    }
    cout << "���� " << count << " �ַ�����" << endl;
    return count;
}

void SimuE(){
    // ���þ���ֵ
    const double epsilon = 1e-8;
    // ���� e �ĳ�ʼֵ����һ�
    double e = 1.0;  // e = 1 + 1/1! + 1/2! + 1/3! + ...
    // ���ڼ���׳˵ı���
    double factorial = 1.0;
    // ���ڸ��ٵ�ǰ��
    int n = 1;
    // ��ǰ���ֵ
    double term = 1.0;
    // ������ < epsilon ʱֹͣ����
    while (term >= epsilon) {
        // ������һ�1/n!
        factorial *= n;     // ���� n!
        term = 1.0 / factorial;  // ���� 1/n!
        e += term;          // ����ǰ��ӵ� e ��ֵ��
        // �ƶ�����һ��
        n++;
    }
    // ����������ʾ�߾���
    cout << "�� �� = " << scientific << setprecision(8) << epsilon << " ʱ��" << endl;
    cout << "��Ȼ������ e �Ľ���ֵ = " << fixed << setprecision(10) << e << endl;
    cout << "������ " << n - 1 << " ��" << endl;
}

int CalFactorial(int n){
    if(n == 0){
        return 1;
    }
    return n * CalFactorial(n - 1);
}

void SumOfFactors(int n){
    if(n <= 0){
        cout << "�������������һ����������" << endl;
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

// �������������������
void reverseNumber() {
    int num, reversed = 0;
    
    cout << "������һ����������";
    cin >> num;
    
    // ���������Ч��
    if (cin.fail() || num <= 0) {
        cout << "������Ч����ȷ������һ����������" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    
    cout << "ԭʼ���֣�" << num << endl;
    
    // ����������
    while (num > 0) {
        int digit = num % 10;  // ��ȡ���һλ����
        reversed = reversed * 10 + digit;  // ����������ӵ������
        num /= 10;  // �Ƴ��Ѵ�������һλ
    }
    
    cout << "���������֣�" << reversed << endl;
}

// ��������������ˮ�ɻ���
void findNarcissisticNumbers() {
    cout << "\n������λˮ�ɻ�����" << endl;
    
    int count = 0;
    
    // ���������λ����100-999��
    for (int i = 100; i < 1000; i++) {
        // ��ȡ����λ������
        int first = i / 100;          // ��λ
        int second = (i / 10) % 10;   // ʮλ
        int third = i % 10;           // ��λ
        
        // �����λ���ֵ�������
        int sum = pow(first, 3) + pow(second, 3) + pow(third, 3);
        
        // ����Ƿ�Ϊˮ�ɻ���
        if (sum == i) {
            cout << i << " = " << first << "^3 + " << second << "^3 + " << third << "^3" << endl;
            count++;
        }
    }
    
    cout << "\n���ҵ� " << count << " ��ˮ�ɻ�����" << endl;
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
    cout << "1000 ���ڵ�������" << endl;
    
    // ֻ���㵽 1000 ����������ĿҪ��
    for(int i = 1; i <= 1000; i++){
        int sum = 0;
        int factors[100] = {0};
        int count1 = 0;
        
        // ������������
        for(int j = 1; j < i; j++){  // ���������ֱ���
            if(i % j == 0){
                sum += j;
                factors[count1++] = j;
            }
        }
        
        // �ж��Ƿ�Ϊ����
        if(sum == i){
            cout << i << " = ";
            
            // ���յ���˳���������
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
    
    cout << "���� " << count << " ������" << endl;
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