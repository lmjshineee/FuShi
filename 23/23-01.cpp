#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // ���ڿ����������
/*  
����������У�n ����ί��֣�ͨ��Ҫȥ��һ����ͷֺ�һ����߷֣��ٶ�ʣ�µ�����ƽ���֡�
���ȥ������߷֡���ͷ���ƽ����
*/
int main() {
    // ������ί����
    int n;
    std::cout << "��������ί������";
    std::cin >> n;
    
    // �����ί�����Ƿ�Ϸ���������Ҫ 3 ����ί��
    if (n < 3) {
        std::cout << "������Ҫ 3 ����ί��" << std::endl;
        return 1;
    }
    
    // ���� n ������
    std::vector<double> scores(n);
    std::cout << "������ " << n << " ��������";
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
    }
    
    // �ҵ���߷ֺ���ͷ�
    double max_score = *std::max_element(scores.begin(), scores.end());
    double min_score = *std::min_element(scores.begin(), scores.end());
    
    // �������з������ܺ�
    double total = 0;
    for (double score : scores) {
        total += score;
    }
    
    // ����ȥ����߷ֺ���ͷֺ���ܺ�
    double sum_without_extremes = total - max_score - min_score;
    
    // ����ƽ����
    double average = sum_without_extremes / (n - 2);
    
    // ��������ƽ���ֱ�����λС��
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "ȥ������߷֣�" << max_score << std::endl;
    std::cout << "ȥ������ͷ֣�" << min_score << std::endl;
    std::cout << "ƽ���֣�" << average << std::endl;
    
    return 0;
}