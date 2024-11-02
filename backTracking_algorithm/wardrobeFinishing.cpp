/*
家居整理师将待整理衣橱划分为 m x n 的二维矩阵 grid，其中 grid[i][j] 代表一个需要整理的格子。整理师自 grid[0][0] 开始 逐行逐列 地整理每个格子。

整理规则为：在整理过程中，可以选择 向右移动一格 或 向下移动一格，但不能移动到衣柜之外。同时，不需要整理 digit(i) + digit(j) > cnt 的格子，其中 digit(x) 表示数字 x 的各数位之和。

请返回整理师 总共需要整理多少个格子。

示例 1：

输入：m = 4, n = 7, cnt = 5
输出：18
 

提示：

1 <= n, m <= 100
0 <= cnt <= 20

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/9h6vo2/
来源：力扣（LeetCode）
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int wardrobeFinishing(int m, int n, int cnt) {
        vector<vector<int>> visited(m + 1, vector<int>(n + 1, 0));
        int count = dfs(m, n, cnt, 0, 0, visited);
        return count;
    }

  private:
    int dfs(int m, int n, int cnt, int x, int y, vector<vector<int>> &visited) {
        if (x >= m || y >= n || visited[x][y] || digit(x) + digit(y) > cnt) return 0;
        visited[x][y] = 1;
        // 仔细学习这里的递归调用
        return 1 + dfs(m, n, cnt, x + 1, y, visited) + dfs(m, n, cnt, x, y + 1, visited);
    }
    int digit(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};

int main() {
    Solution sol;

    // 测试样例 1
    int result1 = sol.wardrobeFinishing(4, 7, 5);
    cout << result1 << endl;
    // 期望输出: 18

    // 测试样例 2
    int result2 = sol.wardrobeFinishing(3, 3, 0);
    cout << result2 << endl;
    // 期望输出: 1

    return 0;
}