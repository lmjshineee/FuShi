#include <iostream>
#include <vector>
#include <algorithm>
/*
输入学生数，学生的学号与英语成绩，按英语成绩从高到低输出学号与成绩，
若成绩相同，则按学号从小到大的顺序输出。（10 分）
输入：
5
1 90
2 91
3 78
4 90
5 88
输出：
2 91
1 90
4 90
5 88
3 78
*/
int main() {
    // 输入学生数
    int n;
    std::cin >> n;
    
    // 创建 vector 存储学号和成绩
    std::vector<std::pair<int, int>> students(n);
    
    // 输入每位学生的学号和成绩
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].first >> students[i].second;
    }
    
    // 按要求排序：成绩降序，成绩相同时学号升序
    std::sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second; // 成绩降序
        } else {
            return a.first < b.first; // 学号升序
        }
    });
    
    // 输出排序后的结果
    for (const auto& student : students) {
        std::cout << student.first << " " << student.second << std::endl;
    }
    
    return 0;
}