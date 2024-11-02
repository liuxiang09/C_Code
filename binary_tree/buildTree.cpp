/*
某二叉树的先序遍历结果记录于整数数组 preorder，它的中序遍历结果记录于整数数组 inorder。请根据 preorder 和 inorder 的提示构造出这棵二叉树并返回其根节点。
注意：preorder 和 inorder 中均不含重复数字。

 
示例 1：
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
 

示例 2:
输入: preorder = [-1], inorder = [-1]
输出: [-1]
 

提示:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/99lxci/
来源：力扣（LeetCode）
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *deduceTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return nullptr;
        // 构建哈希表
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        return buildTree(preorder, inorder_map, 0, 0, inorder.size() - 1);
    }

  private:
    TreeNode *buildTree(vector<int> &preorder, unordered_map<int, int> &inorder_map, int root, int inleft, int inright) {
        if (inleft > inright) return nullptr;
        TreeNode *cur = new TreeNode(preorder[root]);
        int mid = inorder_map[preorder[root]];
        // 左侧递归的root值只需要+1即可
        cur->left = buildTree(preorder, inorder_map, root + 1, inleft, mid - 1);
        // 右侧递归的root值是最难想的
        cur->right = buildTree(preorder, inorder_map, root + 1 + mid - inleft, mid + 1, inright);
        return cur;
    }
};

int main() {
    Solution sol;
    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> inorder = {4, 2, 5, 1, 3};
    TreeNode *root = sol.deduceTree(preorder, inorder);
    // 层序遍历结果: 1 2 3 4 5

    return 0;
}