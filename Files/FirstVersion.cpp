#include "FirstVersion.hpp"
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

FirstVersion::FirstVersion(TaskGenerator *task)
{
    old_text = task->getString();
}

void FirstVersion::solve()
{
    using namespace std;
    string txt;
    int L = 0;
    for (int i = 0; i < old_text.size(); i++)
    {
        int j = i;
        string res;
        while (j < (int)old_text.size() && old_text[j] != ' ')
            j++;
        for (int k = i; k < j; k++)
            res.push_back(old_text[k]);
        j = j - 1;
        L = std::max(L, (int)res.length());
        for (int id = 0; id < res.length(); id++)
        {
            char ch = res[id];
            txt.push_back(ch);
        }
    }

    map<string, int> countStrings;
    for (int len = 1; len <= L; len++)
    {
        for (int l = 0; l < txt.size(); l++)
        {
            int r = l + len - 1;
            if (r >= txt.size())
                break;
            bool bad = false;
            string st;
            for (int i = l; i <= r; i++)
            {
                if (txt[i] == ' ')
                {
                    bad = true;
                    break;
                }
                st.push_back(txt[i]);
            }
            if (!bad)
                countStrings[st]++;
        }
    }
    vector<vector<pair<int, string>>> ans;
    ans.resize(L + 1);
    for (auto value : countStrings)
    {
        ans[(int)value.first.size()].push_back({value.second, value.first});
    }
    for (int n = 1; n <= L; n++)
    {
        sort(ans[n].rbegin(), ans[n].rend());
        //for (auto res : ans[n])
        //    cout << res.second << " ";
        //cout << endl;
    }
   
}