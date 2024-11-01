#include <iostream>
#include <vector>
using namespace std;

// 定义二叉树节点的结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 前序遍历函数
void preorderTraversal(TreeNode *root) {
    if (root == NULL) return;
    // 访问根节点
    cout << root->val << " ";
    // 递归访问左子树
    preorderTraversal(root->left);
    // 递归访问右子树
    preorderTraversal(root->right);
}

int main() {
    // 创建一个简单的二叉树
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 进行前序遍历
    preorderTraversal(root);
    cout << endl;

    return 0;
}