#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
/*  
����ƽ���� n ��������꣨x,y���������νͼ����������� 2 λС������͹���ͣ�
���룺
n����ʾƽ���ϵ�ĸ�����n>=3��
������ n �У����� n �������� x,y����ʱ��˳�򴢴棩
�����
�����Χͼ����������������λС�� 
*/
// �����Ľṹ��
struct Point {
 double x, y;
};

double calculateArea(vector<Point>& points, int n) {
 // Ь����ʽ�������
 double area = 0.0;
 // �����һ�������һ��������
 for(int i = 0; i < n; i++) {
 int j = (i + 1) % n; // ��һ�����������ѭ���ص����
 area += points[i].x * points[j].y;
 area -= points[j].x * points[i].y;//����ʽ
 }
 // ȡ����ֵ������ 2
 area = abs(area) / 2.0;
 return area;
}

int main() {
 int n;
 // �����ĸ���
 cin >> n;
 
 // ������֤
 if(n < 3) {
 cout << "��Ҫ���� 3 ���������ɶ����" << endl;
 return 0;
 }
 
 // �洢��� vector
 vector<Point> points(n);
 
 // ��������������
 for(int i = 0; i < n; i++) {
 cin >> points[i].x >> points[i].y;
 }
 
 // �������
 double area = calculateArea(points, n);
 
 // ��������������λС��
 cout << fixed << setprecision(2) << area << endl;
 
 return 0;
}