#include <iostream>
#include <string>
using namespace std;

string xorCipher(const string& text, char key) {
    string result = text;
    for (size_t i = 0; i < result.length(); i++) {
        // ��ÿ���ַ�ִ��������
        result[i] = result[i] ^ key;
    }
    return result;
}

void testXorCipher(){
    string text;
    char key;
    // ��ȡ�û�������ı�
    cout << "������Ҫ���ܵ��ı� (������ 20 ���ַ�): ";
    getline(cin, text);
    
    // ȷ���ı������� 20 ���ַ�
    if (text.length() > 20) {
        cout << "�����ı����� 20 ���ַ����ѽضϡ�" << endl;
        text = text.substr(0, 20);
    }
    // ��ȡ��Կ�ַ�
    cout << "��������Կ�ַ���";
    cin >> key;
    // ����
    string encrypted = xorCipher(text, key);
    cout << "���ܺ���ı���" << encrypted << endl;
    
    // ���� (������������ʹ���ٴ�Ӧ����ͬ����Կ���Խ���)
    string decrypted = xorCipher(encrypted, key);
    cout << "���ܺ���ı���" << decrypted << endl;
}
/*  
������Ҫ���ܵ��ı� (������ 20 ���ַ�): Hello world!
��������Կ�ַ���K
���ܺ���ı���.''$k<$9'/j
���ܺ���ı���Hello world!
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
    cout << "��������ݣ�";
    cin >> year;
    cout << "�������·ݣ�";
    cin >> month;
    int days = countDays(year, month);
    cout << year << " �� " << month << " ���� " << days << " �졣" << endl;
}

double calculateTollFree(int vehicleType){
    switch (vehicleType) {
        case 1: // ���г�
            return 0.0;
        case 2: // Ħ�г�
            return 2.0;
        case 3: // С����
            return 5.0;
        case 4: // ��ͳ������
            return 8.0;
        case 5: // ����
            return 12.0;
        default:
            return -1.0; // ��Ч�ĳ�������
    }
}

void displayVehicleTypes() {
    cout << "�������ͱ��룺" << endl;
    cout << "1 - ���г� (���)" << endl;
    cout << "2 - Ħ�г� (2 Ԫ)" << endl;
    cout << "3 - С���� (5 Ԫ)" << endl;
    cout << "4 - ��ͳ������ (8 Ԫ)" << endl;
    cout << "5 - ���� (12 Ԫ)" << endl;
}

void testTollCalculator() {
    int vehicleType;
    char continueChoice;
    double totalFee = 0.0;
    int vehicleCounts[6] = {0}; // ����ͳ�Ƹ����ͳ������������� 0 ��ʹ��
    
    cout << "===== ���Ź��ŷѼ���ϵͳ =====" << endl;
    
    do {
        // ��ʾ�������ͱ���
        displayVehicleTypes();
        
        // ��ȡ�û�����
        cout << "\n�����복�����ͱ��� (1-5): ";
        cin >> vehicleType;
        
        // ���㲢��ʾ���ŷ�
        double fee = calculateTollFree(vehicleType);
        if (fee >= 0) {
            cout << "�ó���Ӧ���ɹ��ŷѣ�" << fee << " Ԫ" << endl;
            totalFee += fee;
            vehicleCounts[vehicleType]++; // ���Ӷ�Ӧ���͵ĳ�������
        } else {
            cout << "��Ч�ĳ������ͱ��룡������ 1-5 ֮������֡�" << endl;
        }
        
        // ѯ���Ƿ��������
        cout << "\n�Ƿ�������㣿(y/n): ";
        cin >> continueChoice;
        cout << endl;
        
    } while (continueChoice == 'y' || continueChoice == 'Y');
    
    // ��ʾͳ�ƽ��
    cout << "===== ���ŷ�ͳ�� =====" << endl;
    cout << "���г�������" << vehicleCounts[1] << " �������ã�0 Ԫ" << endl;
    cout << "Ħ�г�������" << vehicleCounts[2] << " �������ã�" << vehicleCounts[2] * 2.0 << " Ԫ" << endl;
    cout << "С����������" << vehicleCounts[3] << " �������ã�" << vehicleCounts[3] * 5.0 << " Ԫ" << endl;
    cout << "��ͳ������������" << vehicleCounts[4] << " �������ã�" << vehicleCounts[4] * 8.0 << " Ԫ" << endl;
    cout << "����������" << vehicleCounts[5] << " �������ã�" << vehicleCounts[5] * 12.0 << " Ԫ" << endl;
    cout << "�ܳ���������" << (vehicleCounts[1] + vehicleCounts[2] + vehicleCounts[3] + vehicleCounts[4] + vehicleCounts[5]) << " ��" << endl;
    cout << "���շѽ�" << totalFee << " Ԫ" << endl;
    cout << "���������ллʹ�ã�" << endl;
}

void testExam(){
    int exam;
    cout << "�����뿼�Գɼ���";
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