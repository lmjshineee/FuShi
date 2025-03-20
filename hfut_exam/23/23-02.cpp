#include <algorithm> // ���� std::max �� std::abs
#include <cstdio>    // ���� printf
#include <cstdlib>   // ���� NULL

/*
�ж�һ�����Ƿ�Ϊƽ�������������Ƿ��� true�����Ƿ��� false��
*/

// �������ڵ㶨��
struct TreeNode {
    int val;           // �ڵ�ֵ
    TreeNode *left;    // ���ӽڵ�ָ��
    TreeNode *right;   // ���ӽڵ�ָ��
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // ���������ж����Ƿ�ƽ��
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    // �������������������߶Ȳ����ƽ����
    int checkHeight(TreeNode* node) {
        // �սڵ�߶�Ϊ 0
        if (node == nullptr) {
            return 0;
        }

        // �ݹ�����������߶�
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) {
            return -1; // ��������ƽ�⣬ֱ�ӷ��� -1
        }

        // �ݹ�����������߶�
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) {
            return -1; // ��������ƽ�⣬ֱ�ӷ��� -1
        }

        // ��鵱ǰ�ڵ��ƽ������
        if (std::abs(leftHeight - rightHeight) > 1) {
            return -1; // �߶Ȳ���� 1������ -1 ��ʾ��ƽ��
        }

        // ���ص�ǰ�ڵ�ĸ߶�
        return 1 + std::max(leftHeight, rightHeight);
    }
};

// ���Դ���
int main() {
    // ����һ�ö�����
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // ������Ƿ�ƽ��
    Solution solution;
    bool isBalanced = solution.isBalanced(root);
    if(isBalanced) {
        printf("The tree is balanced.\n");
    } else {
        printf("The tree is not balanced.\n");
    }
}