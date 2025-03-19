#include <iostream>
#include <string>
using namespace std;

string xorCipher(const string& text, char key) {
    string result = text;
    for (size_t i = 0; i < result.length(); i++) {
        // 对每个字符执行异或操作
        result[i] = result[i] ^ key;
    }
    return result;
}

void testXorCipher(){
    string text;
    char key;
    // 获取用户输入的文本
    cout << "请输入要加密的文本 (不超过 20 个字符): ";
    getline(cin, text);
    
    // 确保文本不超过 20 个字符
    if (text.length() > 20) {
        cout << "输入文本超过 20 个字符，已截断。" << endl;
        text = text.substr(0, 20);
    }
    // 获取密钥字符
    cout << "请输入密钥字符：";
    cin >> key;
    // 加密
    string encrypted = xorCipher(text, key);
    cout << "加密后的文本：" << encrypted << endl;
    
    // 解密 (异或运算的特性使得再次应用相同的密钥可以解密)
    string decrypted = xorCipher(encrypted, key);
    cout << "解密后的文本：" << decrypted << endl;
}
/*  
请输入要加密的文本 (不超过 20 个字符): Hello world!
请输入密钥字符：K
加密后的文本：.''$k<$9'/j
解密后的文本：Hello world!
*/

int countDays(int year, int month){
    int days = 0;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                days = 29;
            } else {
                days = 28;
            }
            break;
        default:
            break;
    }
    return days;
}
void testCountdays(){
    int year, month;
    cout << "请输入年份：";
    cin >> year;
    cout << "请输入月份：";
    cin >> month;
    int days = countDays(year, month);
    cout << year << " 年 " << month << " 月有 " << days << " 天。" << endl;
}

double calculateTollFree(int vehicleType){
    switch (vehicleType) {
        case 1: // 自行车
            return 0.0;
        case 2: // 摩托车
            return 2.0;
        case 3: // 小汽车
            return 5.0;
        case 4: // 大客车与货车
            return 8.0;
        case 5: // 货柜车
            return 12.0;
        default:
            return -1.0; // 无效的车辆类型
    }
}

void displayVehicleTypes() {
    cout << "车辆类型编码：" << endl;
    cout << "1 - 自行车 (免费)" << endl;
    cout << "2 - 摩托车 (2 元)" << endl;
    cout << "3 - 小汽车 (5 元)" << endl;
    cout << "4 - 大客车与货车 (8 元)" << endl;
    cout << "5 - 货柜车 (12 元)" << endl;
}

void testTollCalculator() {
    int vehicleType;
    char continueChoice;
    double totalFee = 0.0;
    int vehicleCounts[6] = {0}; // 用于统计各类型车辆数量，索引 0 不使用
    
    cout << "===== 大桥过桥费计算系统 =====" << endl;
    
    do {
        // 显示车辆类型编码
        displayVehicleTypes();
        
        // 获取用户输入
        cout << "\n请输入车辆类型编码 (1-5): ";
        cin >> vehicleType;
        
        // 计算并显示过桥费
        double fee = calculateTollFree(vehicleType);
        if (fee >= 0) {
            cout << "该车辆应缴纳过桥费：" << fee << " 元" << endl;
            totalFee += fee;
            vehicleCounts[vehicleType]++; // 增加对应类型的车辆计数
        } else {
            cout << "无效的车辆类型编码！请输入 1-5 之间的数字。" << endl;
        }
        
        // 询问是否继续计算
        cout << "\n是否继续计算？(y/n): ";
        cin >> continueChoice;
        cout << endl;
        
    } while (continueChoice == 'y' || continueChoice == 'Y');
    
    // 显示统计结果
    cout << "===== 过桥费统计 =====" << endl;
    cout << "自行车数量：" << vehicleCounts[1] << " 辆，费用：0 元" << endl;
    cout << "摩托车数量：" << vehicleCounts[2] << " 辆，费用：" << vehicleCounts[2] * 2.0 << " 元" << endl;
    cout << "小汽车数量：" << vehicleCounts[3] << " 辆，费用：" << vehicleCounts[3] * 5.0 << " 元" << endl;
    cout << "大客车与货车数量：" << vehicleCounts[4] << " 辆，费用：" << vehicleCounts[4] * 8.0 << " 元" << endl;
    cout << "货柜车数量：" << vehicleCounts[5] << " 辆，费用：" << vehicleCounts[5] * 12.0 << " 元" << endl;
    cout << "总车辆数量：" << (vehicleCounts[1] + vehicleCounts[2] + vehicleCounts[3] + vehicleCounts[4] + vehicleCounts[5]) << " 辆" << endl;
    cout << "总收费金额：" << totalFee << " 元" << endl;
    cout << "程序结束，谢谢使用！" << endl;
}

void testExam(){
    int exam;
    cout << "请输入考试成绩：";
    cin >> exam;
    if (exam < 60) {
        cout << "No Pass" << endl;
    } else if (exam < 70) {
        cout << "Pass" << endl;
    } else if (exam < 80) {
        cout << "Good" << endl;
    } else if (exam < 90) {
        cout << "Very GOod" << endl;
    } else if (exam < 100) {
        cout << "Excellent" << endl;
    }else{
        cout << "Invalid score" << endl;
    }

}

int main() {

    //testXorCipher();
    //testCountdays();
    //testTollCalculator();
    testExam();
    return 0;
}