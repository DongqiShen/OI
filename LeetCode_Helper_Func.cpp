/*
 * Description: Leetcode 辅助函数
 */
#include "LeetCode_Helper_Func.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>


using namespace std;

vector<vector<int>> to_vvi(ifstream& fin)
{
    string str = "";
    string tmp_str;
    regex r("\"");
    while (fin >> tmp_str) {
        str += tmp_str;
    }
    string new_str = regex_replace(str, r, "");
    vector<vector<int>> ret;
    vector<int> tmp;
    bool left_flag = false;
    bool mid_flag = false;
    bool minus = false;
    int num = 0;
    for (int i = 0; i < new_str.size(); ++i) {
        char ch = new_str[i];
        if (ch == '[' && left_flag == false) {
            left_flag = true;
            continue;
        }
        if (ch == '[') {
            tmp.clear();
            mid_flag = false;
        }
        if (ch == ']' && !mid_flag) {
            mid_flag = true;
            num = minus ? -num : num;
            tmp.emplace_back(num);
            ret.emplace_back(tmp);
            minus = false;
            num = 0;
        }
        if (ch == ',' && mid_flag == false) {
            num = minus ? -num : num;
            tmp.emplace_back(num);
            minus = false;
            num = 0;
        }
        if (ch == '-') {
            minus = true;
        }
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }
    }
    return ret;
}