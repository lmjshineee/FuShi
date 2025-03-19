# include <iostream>
# include <cmath> // Add this header
# include <iomanip>
using namespace std;

void countFish(){
    // ��ʼ���������8000 �򣩺�ÿ����ٵı�����3.5%��
    double initialFishCount = 8.0e7;  // ʹ�� double ���ͣ�����������Χ����
    double reductionRate = 0.035;     // 3.5% �ļ�����
    
    // ��������ٵ�һ�����������
    double currentFishCount = initialFishCount;
    int yearsToHalf = 0;
    while (currentFishCount > initialFishCount / 2) {
        currentFishCount *= (1 - reductionRate);
        yearsToHalf++;
    }
    
    // ��������ٵ�ʮ��֮һ���������
    currentFishCount = initialFishCount;
    int yearsToTenth = 0;
    while (currentFishCount > initialFishCount / 10) {
        currentFishCount *= (1 - reductionRate);
        yearsToTenth++;
    }
    
    cout << "�齭�����������ٵ�Ŀǰ��һ����Ҫ " << yearsToHalf << " �ꡣ" << endl;
    cout << "�齭�����������ٵ�Ŀǰ��ʮ��֮һ��Ҫ " << yearsToTenth << " �ꡣ" << endl;
    
}

// ���һԪ���η���
void solveQuadraticEquation(double a, double b, double c) {
    cout << "\n��ⷽ�̣�" << a << "x? + " << b << "x + " << c << " = 0" << endl;
    
    // �ж��Ƿ�ΪһԪ���η���
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "������������" << endl;
            } else {
                cout << "�����޽�" << endl;
            }
        } else {
            // �˻�Ϊһ�η���
            double x = -c / b;
            cout << "�����˻�Ϊһ�η��̣���Ϊ��x = " << x << endl;
        }
        return;
    }
    
    // �����б�ʽ
    double discriminant = b * b - 4 * a * c;
    
    // �����б�ʽ�жϸ������
    if (fabs(discriminant) < 1e-10) {  // ����Ϊ 0�����⸡�����
        // ��������ȵ�ʵ��
        double x = -b / (2 * a);
        cout << "������������ȵ�ʵ����x1 = x2 = " << x << endl;
    } else if (discriminant > 0) {
        // ����������ȵ�ʵ��
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "��������������ȵ�ʵ����" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } else {
        // �����������
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "�����������������" << endl;
        cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

// �������һԪ���η���
void testSolveQuadraticEquation() {
    cout << "һԪ���η��������" << endl;
    cout << "��� ax? + bx + c = 0 �ĸ�" << endl;
    
    // ���ø�������ʾ����
    cout << fixed << setprecision(4);
    
    // ������������
    cout << "\n===== �������ݼ� =====" << endl;
    
    // ��׼��������������ȵ�ʵ��
    solveQuadraticEquation(1, -5, 6);   // x? - 5x + 6 = 0����Ϊ 2 �� 3
    
    // ��׼�������һ���ظ�
    solveQuadraticEquation(1, -4, 4);   // x? - 4x + 4 = 0����Ϊ 2
    
    // ��׼����������������
    solveQuadraticEquation(1, 2, 5);    // x? + 2x + 5 = 0������
    
    // �߽������a = 0���˻�Ϊһ�η���
    solveQuadraticEquation(0, 2, -4);   // 2x - 4 = 0����Ϊ 2
    
    // �߽������a = 0��b = 0��c != 0���޽�
    solveQuadraticEquation(0, 0, 5);    // 5 = 0���޽�
    
    // �߽������a = 0��b = 0��c = 0��������
    solveQuadraticEquation(0, 0, 0);    // 0 = 0��������
    
    // ϵ��Ϊ���������
    solveQuadraticEquation(-1, -2, -1); // -x? - 2x - 1 = 0������
    
    // ϵ���ܴ�����
    solveQuadraticEquation(1000, 2000, -3000);
    
    // ϵ����С�����
    solveQuadraticEquation(0.0001, 0.0002, 0.0003);
}

void countScores(){
    int sum=0, count=0,low,high;
    while(true){
        int score;
        cout << "������һ��ѧ���ɼ������� -1 ��������";
        cin >> score;
        // ��������Ƿ���Ч
        if (cin.fail()) {
            cin.clear();  // �������״̬  
            cin.ignore(1024, '\n');  // ��ջ�����
            cout << "������Ч��������һ����Ч�����֡�" << endl;
            continue;
        }
        // ����Ƿ�Ϊ������־
        if (score == -1) {
            break;
        }
        // ���ɼ��Ƿ��ں���Χ�ڣ�����ɼ��� 0-100 ֮�䣩
        if (score < 0 || score > 100) {
            cout << "�ɼ�Ӧ�� 0-100 ֮�䣬���������롣" << endl;
            continue;//continue ������ڽ�����ǰѭ�������治���ˣ���������һ��ѭ��
        }
        if(count==0){
            low=score;
            high=score;
        }
        sum+=score;
        count++;
        if(score<low){
            low=score;
        }
        if(score>high){
            high=score;
        }
    }
    cout << "������ " << count << " ��ѧ���ɼ���" << endl;
    cout << "��ͷ֣�" << low << " ��߷֣�" << high << " ƽ���֣�" << sum/count << endl;
}

int main() {
    //countFish();
    //testSolveQuadraticEquation();
    countScores();
    return 0;
}