#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
/*  
给出平面上 n 个点的坐标（x,y），求出所谓图形面积，保留 2 位小数。（凸边型）
输入：
n，表示平面上点的个数（n>=3）
接下来 n 行，输入 n 个点坐标 x,y（按时钟顺序储存）
输出：
输出所围图形面积，结果保留两位小数 
*/
// 定义点的结构体
struct Point {
 double x, y;
};

double calculateArea(vector<Point>& points, int n) {
 // 鞋带公式计算面积
 double area = 0.0;
 // 将最后一个点与第一个点相连
 for(int i = 0; i < n; i++) {
 int j = (i + 1) % n; // 下一个点的索引，循环回到起点
 area += points[i].x * points[j].y;
 area -= points[j].x * points[i].y;//行列式
 }
 // 取绝对值并除以 2
 area = abs(area) / 2.0;
 return area;
}

int main() {
 int n;
 // 输入点的个数
 cin >> n;
 
 // 输入验证
 if(n < 3) {
 cout << "需要至少 3 个点来构成多边形" << endl;
 return 0;
 }
 
 // 存储点的 vector
 vector<Point> points(n);
 
 // 输入各个点的坐标
 for(int i = 0; i < n; i++) {
 cin >> points[i].x >> points[i].y;
 }
 
 // 计算面积
 double area = calculateArea(points, n);
 
 // 输出结果，保留两位小数
 cout << fixed << setprecision(2) << area << endl;
 
 return 0;
}