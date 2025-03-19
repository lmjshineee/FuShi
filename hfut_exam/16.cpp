# include <iostream>
# include <cmath> // Add this header
# include <iomanip>
using namespace std;

void countFish(){
    // 初始鱼的数量（8000 万）和每年减少的比例（3.5%）
    double initialFishCount = 8.0e7;  // 使用 double 类型，避免整数范围限制
    double reductionRate = 0.035;     // 3.5% 的减少率
    
    // 计算鱼减少到一半所需的年数
    double currentFishCount = initialFishCount;
    int yearsToHalf = 0;
    while (currentFishCount > initialFishCount / 2) {
        currentFishCount *= (1 - reductionRate);
        yearsToHalf++;
    }
    
    // 计算鱼减少到十分之一所需的年数
    currentFishCount = initialFishCount;
    int yearsToTenth = 0;
    while (currentFishCount > initialFishCount / 10) {
        currentFishCount *= (1 - reductionRate);
        yearsToTenth++;
    }
    
    cout << "珠江鱼类数量减少到目前的一半需要 " << yearsToHalf << " 年。" << endl;
    cout << "珠江鱼类数量减少到目前的十分之一需要 " << yearsToTenth << " 年。" << endl;
    
}

// 求解一元二次方程
void solveQuadraticEquation(double a, double b, double c) {
    cout << "\n求解方程：" << a << "x? + " << b << "x + " << c << " = 0" << endl;
    
    // 判断是否为一元二次方程
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "方程有无穷多解" << endl;
            } else {
                cout << "方程无解" << endl;
            }
        } else {
            // 退化为一次方程
            double x = -c / b;
            cout << "方程退化为一次方程，解为：x = " << x << endl;
        }
        return;
    }
    
    // 计算判别式
    double discriminant = b * b - 4 * a * c;
    
    // 根据判别式判断根的情况
    if (fabs(discriminant) < 1e-10) {  // 近似为 0，避免浮点误差
        // 有两个相等的实根
        double x = -b / (2 * a);
        cout << "方程有两个相等的实根：x1 = x2 = " << x << endl;
    } else if (discriminant > 0) {
        // 有两个不相等的实根
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "方程有两个不相等的实根：" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } else {
        // 有两个共轭复根
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "方程有两个共轭复根：" << endl;
        cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

// 测试求解一元二次方程
void testSolveQuadraticEquation() {
    cout << "一元二次方程求解器" << endl;
    cout << "求解 ax? + bx + c = 0 的根" << endl;
    
    // 设置浮点数显示精度
    cout << fixed << setprecision(4);
    
    // 测试用例集合
    cout << "\n===== 测试数据集 =====" << endl;
    
    // 标准情况：有两个不等的实根
    solveQuadraticEquation(1, -5, 6);   // x? - 5x + 6 = 0，根为 2 和 3
    
    // 标准情况：有一个重根
    solveQuadraticEquation(1, -4, 4);   // x? - 4x + 4 = 0，根为 2
    
    // 标准情况：有两个共轭复根
    solveQuadraticEquation(1, 2, 5);    // x? + 2x + 5 = 0，复根
    
    // 边界情况：a = 0，退化为一次方程
    solveQuadraticEquation(0, 2, -4);   // 2x - 4 = 0，解为 2
    
    // 边界情况：a = 0，b = 0，c != 0，无解
    solveQuadraticEquation(0, 0, 5);    // 5 = 0，无解
    
    // 边界情况：a = 0，b = 0，c = 0，无穷多解
    solveQuadraticEquation(0, 0, 0);    // 0 = 0，无穷多解
    
    // 系数为负数的情况
    solveQuadraticEquation(-1, -2, -1); // -x? - 2x - 1 = 0，复根
    
    // 系数很大的情况
    solveQuadraticEquation(1000, 2000, -3000);
    
    // 系数很小的情况
    solveQuadraticEquation(0.0001, 0.0002, 0.0003);
}

void countScores(){
    int sum=0, count=0,low,high;
    while(true){
        int score;
        cout << "请输入一个学生成绩（输入 -1 结束）：";
        cin >> score;
        // 检查输入是否有效
        if (cin.fail()) {
            cin.clear();  // 清除错误状态  
            cin.ignore(1024, '\n');  // 清空缓冲区
            cout << "输入无效，请输入一个有效的数字。" << endl;
            continue;
        }
        // 检查是否为结束标志
        if (score == -1) {
            break;
        }
        // 检查成绩是否在合理范围内（假设成绩在 0-100 之间）
        if (score < 0 || score > 100) {
            cout << "成绩应在 0-100 之间，请重新输入。" << endl;
            continue;//continue 语句用于结束当前循环，下面不做了，并进入下一次循环
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
    cout << "共输入 " << count << " 个学生成绩。" << endl;
    cout << "最低分：" << low << " 最高分：" << high << " 平均分：" << sum/count << endl;
}

int main() {
    //countFish();
    //testSolveQuadraticEquation();
    countScores();
    return 0;
}