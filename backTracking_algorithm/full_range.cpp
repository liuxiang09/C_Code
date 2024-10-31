#include <iostream>
#include <vector>
#include <string>
using namespace std;

void permute(string &str, int l, int r, vector<string> &result) {
    if (l == r) {
        result.push_back(str);
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r, result);
            swap(str[l], str[i]); // 回溯
        }
    }
}

int main() {
    string str = "abc";
    vector<string> result;
    permute(str, 0, str.size() - 1, result);

    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}