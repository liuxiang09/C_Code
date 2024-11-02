/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

示例 1：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]

示例 2：
输入：root = [1,2,3], targetSum = 5
输出：[]

示例 3：
输入：root = [1,2], targetSum = 0
输出：[]
 
提示：

树中节点总数在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/5dy6pt/
来源：力扣（LeetCode）
*/
#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathTarget(TreeNode *root, int target) {

        dfs(root, target);
        return res;
    }

  private:
    void dfs(TreeNode *cur, int target, int sum = 0) {
        if (cur == nullptr) return;
        sum += cur->val;
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr && sum == target) {
            res.push_back(path);
        }
        dfs(cur->left, target, sum);
        dfs(cur->right, target, sum);
        path.pop_back();
    }
};

int main() {
    Solution sol;

    // 创建一个简单的二叉树
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    // 进行路径总和
    vector<vector<int>> result = sol.pathTarget(root, 22);
    for (vector<int> &path : result) {
        for (int &num : path) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}