#include <iostream>
#include <vector>
#include <string>

/*  
N ��ͬѧΧ��һȦ����ŷֱ�Ϊ ABCDEF������������������
����������������ڵ���ϣ�˳���෴�������һ������ AC��CA������ĸС����ǰ�档��20 �֣�
���룺5
�����AC AD BD BE CE
*/
int main() {
    int N;
    std::cin >> N; // Read the number of classmates
    
    std::vector<std::string> result; // Store all non-adjacent pairs

    // Generate all possible pairs and filter non-adjacent ones
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            // Check if i and j are not adjacent in the circle
            if (j - i != 1 && j - i != N - 1) {
                char first = 'A' + i;  // Convert first number to letter
                char second = 'A' + j; // Convert second number to letter
                // Create the pair as a string and add to result
                result.push_back(std::string(1, first) + std::string(1, second));
            }
        }
    }

    // Output all pairs with proper spacing
    for (size_t k = 0; k < result.size(); k++) {
        std::cout << result[k];
        if (k < result.size() - 1) {
            std::cout << " "; // Add space between pairs, but not after the last one
        }
    }
    std::cout << std::endl; // Newline at the end

    return 0;
}