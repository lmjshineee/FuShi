#include <iostream>
#include <cmath> // Add this header
#include <iomanip>
using namespace std;

// ���ݶ�Ʊ���������ۿ���
double calculateDiscount(int ticketCount) {
    if (ticketCount < 10) {
        return 0.10; // 10% �ۿ�
    } else if (ticketCount < 20) {
        return 0.15; // 15% �ۿ�
    } else if (ticketCount < 30) {
        return 0.30; // 30% �ۿ�
    } else {
        return 0.45; // 45% �ۿ�
    }
}

// ����Ӧ�����
double calculateTotalPrice(int ticketCount, double ticketPrice, double discountRate) {
    double originalPrice = ticketCount * ticketPrice;
    double discountAmount = originalPrice * discountRate;
    return originalPrice - discountAmount;
}
void testPrice(){
    int ticketCount;
    double ticketPrice;
    
    // ��ȡ�û�����
    cout << "======= ���չ�˾��Ʊ�ۿۼ���ϵͳ =======" << endl;
    cout << "�����붩Ʊ������";
    cin >> ticketCount;
    
    cout << "�����뵥�Ż�Ʊ�۸� (Ԫ): ";
    cin >> ticketPrice;
    
    // ������֤
    if (ticketCount <= 0 || ticketPrice <= 0) {
        cout << "������󣡶�Ʊ������Ʊ�۱���Ϊ������" << endl;
        return;
    }
    
    // �����ۿ��ʺ�Ӧ�����
    double discountRate = calculateDiscount(ticketCount);
    double totalPayment = calculateTotalPrice(ticketCount, ticketPrice, discountRate);
    double discountAmount = ticketCount * ticketPrice * discountRate;
    
    // ��ʾ���
    cout << fixed << setprecision(2); // ����С�������λ
    cout << "\n====== ������Ϣ ======" << endl;
    cout << "��Ʊ������" << ticketCount << " ��" << endl;
    cout << "����Ʊ�ۣ�" << ticketPrice << " Ԫ" << endl;
    cout << "����ԭ�ۣ�" << (ticketCount * ticketPrice) << " Ԫ" << endl;
    cout << "�����ۿۣ�" << (discountRate * 100) << "%" << endl;
    cout << "��ʡ��" << discountAmount << " Ԫ" << endl;
    cout << "Ӧ����" << totalPayment << " Ԫ" << endl;
    cout << "====================" << endl;
}

void IntFlow(){
    int num;
    int countNegOne = 0;    // -1 �ļ���
    int countZero = 0;      // 0 �ļ���
    int countPosOne = 0;    // +1 �ļ���
    
    cout << "������һϵ������������ 1000 ��ʾ��������" << endl;
    
    // ������ȡ���룬ֱ������������� 1000
    while (true) {
        cin >> num;
        
        // ����Ƿ�Ϊ�������
        if (num == 1000) {
            break;
        }
        
        // ��������ֵ���Ӷ�Ӧ����
        if (num == -1) {
            countNegOne++;
        } else if (num == 0) {
            countZero++;
        } else if (num == 1) {
            countPosOne++;
        }
        // �������ֲ���ͳ��
    }
    
    // ���ͳ�ƽ��
    cout << "\nͳ�ƽ����" << endl;
    cout << "-1 ���ֵĴ�����" << countNegOne << endl;
    cout << " 0 ���ֵĴ�����" << countZero << endl;
    cout << "+1 ���ֵĴ�����" << countPosOne << endl;
    cout << "�ܼ�����ֵ������" << (countNegOne + countZero + countPosOne) << endl;
}

int countFactorOfTwo(int num){
    int count = 0;
    if(num < 0){
        return -1;
    }
    while(num % 2 == 0){
        count++;
        num /= 2;
    }
    return count;
}

void testFactorOfTwo(){
    int num;
    cout << "������һ����������";
    cin >> num;
    
    int count = countFactorOfTwo(num);
    if(count == -1){
        cout << "�������������һ����������" << endl;
    } else {
        cout << "������������ 2 �ĸ���Ϊ��" << count << endl;
    }
}

bool checkStairs(int n){
    if (n%2!=1) return false;
    if (n%3!=2) return false;
    if (n%4!=3) return false;
    if (n%5!=4) return false;
    if (n%6!=5) return false;
    return true;
}
void testStairs(){
    for(int i = 7; i < 1000; i=i+7){   // 7 �ı���
        if(checkStairs(i)){
            cout << "��������" << i << endl;
        }
    }
}

void countChickens(){
    int n;
    int count = 0;
    for(int i = 0; i <= 20; i++){
        for(int j = 0; j <= 33; j++){
            for(int k = 0; k <= 100; k+=3){
                if(i + j + k == 100 && i*5 + j*3 + k/3 == 100){
                    count++;
                    cout << "������" << i << " ĸ����" << j << " С����" << k << endl;
                }
            }
        }
    }
    cout << "���� " << count << " �ַ�����" << endl;
}

void SumOfFactors(){
    int sum=0;
    for(int i=13;i<=100;i++){
        if(i%13==0){
            sum+=i;
        }
    }
    cout << "13 �ı���֮��Ϊ��" << sum << endl;
}

void printCal(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=i;j++){
            cout << j << "*" << i << "=" << i*j << " ";
        }
        cout << endl;
    }
}



int countPower(int n) {
    int count = 0;
    while (pow(2, count) < n) {
        count++;
    }
    return count;
}

int main() {
    //testPrice();
    //IntFlow();
    //testFactorOfTwo();
    //testStairs();
    //countChickens();
    //SumOfFactors();
    //printCal();
    cout << countPower(100) << endl;
    return 0;
}