#include <iostream>
#include <vector>
#include <algorithm>
/*
����ѧ������ѧ����ѧ����Ӣ��ɼ�����Ӣ��ɼ��Ӹߵ������ѧ����ɼ���
���ɼ���ͬ����ѧ�Ŵ�С�����˳���������10 �֣�
���룺
5
1 90
2 91
3 78
4 90
5 88
�����
2 91
1 90
4 90
5 88
3 78
*/
int main() {
    // ����ѧ����
    int n;
    std::cin >> n;
    
    // ���� vector �洢ѧ�źͳɼ�
    std::vector<std::pair<int, int>> students(n);
    
    // ����ÿλѧ����ѧ�źͳɼ�
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].first >> students[i].second;
    }
    
    // ��Ҫ�����򣺳ɼ����򣬳ɼ���ͬʱѧ������
    std::sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second; // �ɼ�����
        } else {
            return a.first < b.first; // ѧ������
        }
    });
    
    // ��������Ľ��
    for (const auto& student : students) {
        std::cout << student.first << " " << student.second << std::endl;
    }
    
    return 0;
}