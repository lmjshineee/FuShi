#include <algorithm> // 用于 std::max 和 std::abs
#include <cstdio>    // 用于 printf
#include <cstdlib>   // 用于 NULL

/*
判断一棵树是否为平衡二叉树，如果是返回 true，不是返回 false。
*/

// 二叉树节点定义
struct TreeNode {
    int val;           // 节点值
    TreeNode *left;    // 左子节点指针
    TreeNode *right;   // 右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 主函数：判断树是否平衡
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    // 辅助函数：计算子树高度并检查平衡性
    int checkHeight(TreeNode* node) {
        // 空节点高度为 0
        if (node == nullptr) {
            return 0;
        }

        // 递归计算左子树高度
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) {
            return -1; // 左子树不平衡，直接返回 -1
        }

        // 递归计算右子树高度
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) {
            return -1; // 右子树不平衡，直接返回 -1
        }

        // 检查当前节点的平衡条件
        if (std::abs(leftHeight - rightHeight) > 1) {
            return -1; // 高度差大于 1，返回 -1 表示不平衡
        }

        // 返回当前节点的高度
        return 1 + std::max(leftHeight, rightHeight);
    }
};

// 测试代码
int main() {
    // 创建一棵二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // 检查树是否平衡
    Solution solution;
    bool isBalanced = solution.isBalanced(root);
    if(isBalanced) {
        printf("The tree is balanced.\n");
    } else {
        printf("The tree is not balanced.\n");
    }
}