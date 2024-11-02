/*
字母迷宫游戏初始界面记作 m x n 二维字符串数组 grid，请判断玩家是否能在 grid 中找到目标单词 target。
注意：寻找单词时 必须 按照字母顺序，通过水平或垂直方向相邻的单元格内的字母构成，同时，同一个单元格内的字母 不允许被重复使用 。

示例 1：
输入：grid = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], target = "ABCCED"
输出：true

示例 2：
输入：grid = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], target = "SEE"
输出：true

示例 3：
输入：grid = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], target = "ABCB"
输出：false
 
提示：
m == grid.length
n = grid[i].length
1 <= m, n <= 6
1 <= target.length <= 15
grid 和 target 仅由大小写英文字母组成

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/58wowd/
来源：力扣（LeetCode）
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool wordPuzzle(vector<vector<char>> &grid, string target) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (dfs(grid, target, i, j, 0)) return true;
            }
        }
        return false;
    }

  private:
    bool dfs(vector<vector<char>> &grid, string &target, int i, int j, int k) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != target[k]) return false;
        if (k == target.size() - 1) return true;
        grid[i][j] = '\0';
        bool res = dfs(grid, target, i + 1, j, k + 1) || dfs(grid, target, i - 1, j, k + 1) || dfs(grid, target, i, j + 1, k + 1) || dfs(grid, target, i, j - 1, k + 1);
        grid[i][j] = target[k];
        return res;
    }
};

int main() {
    Solution sol;

    // 测试样例 1
    vector<vector<char>> grid1 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string target1 = "ABCCED";
    cout << sol.wordPuzzle(grid1, target1) << endl; // 期望输出: true

    // 测试样例 2
    vector<vector<char>> grid2 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string target2 = "SEE";
    cout << sol.wordPuzzle(grid2, target2) << endl; // 期望输出: true

    // 测试样例 3
    vector<vector<char>> grid3 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string target3 = "ABCB";
    cout << sol.wordPuzzle(grid3, target3) << endl; // 期望输出: false

    return 0;
}