#include <iostream>
#include <vector>
#include <string>

/*  
N 个同学围成一圈，序号分别为 ABCDEF…，输入参与的人数，
输出所有两两不相邻的组合，顺序相反的组合算一个，如 AC，CA；且字母小的在前面。（20 分）
输入：5
输出：AC AD BD BE CE
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