/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */
class Solution
{
public:
    string countAndSay(int n)
{
    switch (n)
    {
    case 0:return "";
    case 1:return "1";
    }
    string temp = countAndSay(n - 1);
    int size = temp.size();
    string res = "";
    int cur_cnt = 1;

    for (int i = 1; i < size; i++)
    {
        if (temp[i] == temp[i - 1])
        {
            cur_cnt++;
            continue;
        }
        else
        {
            string sub = to_string(cur_cnt) + temp[i - 1];
            res += sub;
            cur_cnt = 1;
            //cout<<cur_cnt<<" "<<res<<endl;
        }
    }

    res.append(to_string(cur_cnt));
    res.append(1, temp[temp.length() - 1]);

    return res;
}
};
