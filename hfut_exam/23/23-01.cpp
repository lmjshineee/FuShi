#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // 用于控制输出精度
/*  
在文体比赛中，n 个评委打分，通常要去掉一个最低分和一个最高分，再对剩下的数求平均分。
输出去掉的最高分、最低分与平均分
*/
int main() {
    // 输入评委数量
    int n;
    std::cout << "请输入评委数量：";
    std::cin >> n;
    
    // 检查评委数量是否合法（至少需要 3 个评委）
    if (n < 3) {
        std::cout << "至少需要 3 个评委。" << std::endl;
        return 1;
    }
    
    // 输入 n 个分数
    std::vector<double> scores(n);
    std::cout << "请输入 " << n << " 个分数：";
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
    }
    
    // 找到最高分和最低分
    double max_score = *std::max_element(scores.begin(), scores.end());
    double min_score = *std::min_element(scores.begin(), scores.end());
    
    // 计算所有分数的总和
    double total = 0;
    for (double score : scores) {
        total += score;
    }
    
    // 计算去掉最高分和最低分后的总和
    double sum_without_extremes = total - max_score - min_score;
    
    // 计算平均分
    double average = sum_without_extremes / (n - 2);
    
    // 输出结果，平均分保留两位小数
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "去掉的最高分：" << max_score << std::endl;
    std::cout << "去掉的最低分：" << min_score << std::endl;
    std::cout << "平均分：" << average << std::endl;
    
    return 0;
}