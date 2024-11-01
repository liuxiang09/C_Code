#include <iostream>
#include <queue>
using namespace std;

// 定义二叉树节点的结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层次遍历函数
void levelOrderTraversal(TreeNode *root) {
    if (root == NULL) return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
}

int main() {
    // 创建一个简单的二叉树
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 进行层次遍历
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}