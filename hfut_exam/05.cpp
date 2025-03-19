#include <iostream>
#include <cmath> // Add this header
#include <iomanip>
using namespace std;

// 根据订票张数计算折扣率
double calculateDiscount(int ticketCount) {
    if (ticketCount < 10) {
        return 0.10; // 10% 折扣
    } else if (ticketCount < 20) {
        return 0.15; // 15% 折扣
    } else if (ticketCount < 30) {
        return 0.30; // 30% 折扣
    } else {
        return 0.45; // 45% 折扣
    }
}

// 计算应付款额
double calculateTotalPrice(int ticketCount, double ticketPrice, double discountRate) {
    double originalPrice = ticketCount * ticketPrice;
    double discountAmount = originalPrice * discountRate;
    return originalPrice - discountAmount;
}
void testPrice(){
    int ticketCount;
    double ticketPrice;
    
    // 获取用户输入
    cout << "======= 航空公司机票折扣计算系统 =======" << endl;
    cout << "请输入订票张数：";
    cin >> ticketCount;
    
    cout << "请输入单张机票价格 (元): ";
    cin >> ticketPrice;
    
    // 输入验证
    if (ticketCount <= 0 || ticketPrice <= 0) {
        cout << "输入错误！订票张数和票价必须为正数。" << endl;
        return;
    }
    
    // 计算折扣率和应付款额
    double discountRate = calculateDiscount(ticketCount);
    double totalPayment = calculateTotalPrice(ticketCount, ticketPrice, discountRate);
    double discountAmount = ticketCount * ticketPrice * discountRate;
    
    // 显示结果
    cout << fixed << setprecision(2); // 设置小数点后两位
    cout << "\n====== 订单信息 ======" << endl;
    cout << "订票张数：" << ticketCount << " 张" << endl;
    cout << "单张票价：" << ticketPrice << " 元" << endl;
    cout << "订单原价：" << (ticketCount * ticketPrice) << " 元" << endl;
    cout << "适用折扣：" << (discountRate * 100) << "%" << endl;
    cout << "节省金额：" << discountAmount << " 元" << endl;
    cout << "应付金额：" << totalPayment << " 元" << endl;
    cout << "====================" << endl;
}

void IntFlow(){
    int num;
    int countNegOne = 0;    // -1 的计数
    int countZero = 0;      // 0 的计数
    int countPosOne = 0;    // +1 的计数
    
    cout << "请输入一系列整数（输入 1000 表示结束）：" << endl;
    
    // 持续读取输入，直到遇到结束标记 1000
    while (true) {
        cin >> num;
        
        // 检查是否为结束标记
        if (num == 1000) {
            break;
        }
        
        // 根据输入值增加对应计数
        if (num == -1) {
            countNegOne++;
        } else if (num == 0) {
            countZero++;
        } else if (num == 1) {
            countPosOne++;
        }
        // 其他数字不做统计
    }
    
    // 输出统计结果
    cout << "\n统计结果：" << endl;
    cout << "-1 出现的次数：" << countNegOne << endl;
    cout << " 0 出现的次数：" << countZero << endl;
    cout << "+1 出现的次数：" << countPosOne << endl;
    cout << "总计特殊值数量：" << (countNegOne + countZero + countPosOne) << endl;
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
    cout << "请输入一个正整数：";
    cin >> num;
    
    int count = countFactorOfTwo(num);
    if(count == -1){
        cout << "输入错误！请输入一个正整数。" << endl;
    } else {
        cout << "该数包含因子 2 的个数为：" << count << endl;
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
    for(int i = 7; i < 1000; i=i+7){   // 7 的倍数
        if(checkStairs(i)){
            cout << "阶梯数：" << i << endl;
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
                    cout << "公鸡：" << i << " 母鸡：" << j << " 小鸡：" << k << endl;
                }
            }
        }
    }
    cout << "共有 " << count << " 种方案。" << endl;
}

void SumOfFactors(){
    int sum=0;
    for(int i=13;i<=100;i++){
        if(i%13==0){
            sum+=i;
        }
    }
    cout << "13 的倍数之和为：" << sum << endl;
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