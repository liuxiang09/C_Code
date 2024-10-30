#include <iostream>
#include <vector>
using namespace std;

// 定义二叉树节点的结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 后序遍历函数
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    // 递归访问左子树
    postorderTraversal(root->left);
    // 递归访问右子树
    postorderTraversal(root->right);
    // 访问根节点
    cout << root->val << " ";
}

int main() {
    // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 进行后序遍历
    postorderTraversal(root);
    cout << endl;

    return 0;
}