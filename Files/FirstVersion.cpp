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
}

void FirstVersion::solve()
{
    using namespace std;

    string txt, s;
    int L = 0;
    while (cin >> s)
    {
        L = max(L, (int)s.length());
        if (txt.size() > 0)
            txt.push_back(' ');
        for (int id = 0; id < s.length(); id++)
        {
            char ch = s[id];
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
    vector<pair<int, string>> ans[L + 1];
    for (auto value : countStrings)
    {
        ans[(int)value.first.size()].push_back({value.second, value.first});
    }
    for (int n = 1; n <= L; n++)
    {
        sort(ans[n].rbegin(), ans[n].rend());
        for (auto res : ans[n])
            cout << res.second << " ";
        cout << endl;
    }
}