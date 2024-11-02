/*
某店铺将用于组成套餐的商品记作字符串 goods，其中 goods[i] 表示对应商品。请返回该套餐内所含商品的 全部排列方式 。

返回结果 无顺序要求，但不能含有重复的元素。

 

示例 1:

输入：goods = "agew"
输出：["aegw","aewg","agew","agwe","aweg","awge","eagw","eawg","egaw","egwa","ewag","ewga","gaew","gawe","geaw","gewa","gwae","gwea","waeg","wage","weag","wega","wgae","wgea"]
 

提示：

1 <= goods.length <= 8

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/5dfv5h/
来源：力扣（LeetCode）
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<string> goodsOrder(string goods) {
        res.clear();
        dfs(goods, 0);
        return res;
    }

  private:
    vector<string> res;
    void dfs(string goods, int x) {
        if (x == goods.size() - 1) {
            res.push_back(goods); // 添加排列方案
            return;
        }
        set<char> st;
        for (int i = x; i < goods.size(); i++) {
            if (st.find(goods[i]) != st.end()) continue; // 重复，因此剪枝
            st.insert(goods[i]);
            swap(goods[i], goods[x]); // 交换，将 goods[i] 固定在第 x 位
            dfs(goods, x + 1);        // 开启固定第 x + 1 位字符
            swap(goods[i], goods[x]); // 恢复交换
        }
    }
};

int main() {
    Solution sol;

    // 测试样例 1: 基础测试
    vector<string> result1 = sol.goodsOrder("abc");
    for (const string &str : result1)
        cout << str << " ";
    cout << endl;
    // 期望输出: "abc acb bac bca cab cba" 等 6 种排列

    // 测试样例 2: 包含重复字符
    vector<string> result2 = sol.goodsOrder("aab");
    for (const string &str : result2)
        cout << str << " ";
    cout << endl;
    // 期望输出: "aab aba baa" 等 3 种唯一排列

    // 测试样例 3: 单字符字符串
    vector<string> result3 = sol.goodsOrder("a");
    for (const string &str : result3)
        cout << str << " ";
    cout << endl;
    // 期望输出: "a"

    // 测试样例 4: 空字符串
    vector<string> result4 = sol.goodsOrder("");
    for (const string &str : result4)
        cout << str << " ";
    cout << endl;
    // 期望输出: ""（空结果）

    return 0;
}
