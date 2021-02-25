#include "SecondVersion.hpp"
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

SecondVersion::SecondVersion(TaskGenerator *task)
{
}

void SecondVersion::solve()
{
    using namespace std;

    string txt, s;
    int L = 0;

    set<pair<string, int>> strings;
    map<string, int> count_strings;

    while (cin >> s)
    {
        L = max(L, (int)s.length());
        if (txt.size() > 0)
            txt.push_back(' ');
        for (int id = 0; id < s.length(); id++)
        {
            char ch = s[id];
            txt.push_back(ch);
            string CH = "";
            CH.push_back(ch);
            strings.insert({CH, txt.size() - 1});
            count_strings[CH]++;
        }
    }

    for (int n = 1; n <= L; n++)
    {

        set<string> unique_strings;
        vector<pair<int, string>> v;
        for (auto st : strings)
            unique_strings.insert(st.first);
        for (auto st : unique_strings)
            v.push_back({count_strings[st], st});
        sort(v.rbegin(), v.rend());
        for (auto st : v)
            cout << st.second << " ";
        cout << endl;

        set<pair<string, int>> new_strings;
        for (auto st : strings)
        {
            int id = st.second;
            string now_string = st.first;
            if (id != txt.size() - 1 && txt[id + 1] != ' ')
            {

                now_string.push_back(txt[id + 1]);
                new_strings.insert({now_string, id + 1});
                count_strings[now_string]++;
            }
        }
        for (auto st : strings)
            count_strings[st.first] = 0;
        strings = new_strings;
    }
}