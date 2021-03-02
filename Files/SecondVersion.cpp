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
    old_text = task->getString();
}

void SecondVersion::solve()
{
    using namespace std;

    string txt;
    int L = 0;

    set<pair<string, int>> strings;
    map<string, int> count_strings;
    for (int i = 0; i < old_text.size(); i++)
    {
        if (old_text[i] == ' ')
            continue;
        int j = i;
        string res;
        while (j < (int)old_text.size() && old_text[j] != ' ')
            j++;
        for (int k = i; k < j; k++)
            res.push_back(old_text[k]);
        i = j - 1;
        L = std::max(L, (int)res.length());
        if (txt.size() > 0)
            txt.push_back(' ');
        for (int id = 0; id < res.length(); id++)
        {
            char ch = res[id];
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
        sort(v.begin(), v.end(), [](pair<int, string> a, pair<int, string> b) {
            return a.first > b.first || a.first == b.first && a.second < b.second;
        });
        for (auto st : v)
        {
            cout << st.second << " ";
            //cout << st.first << " " << st.second << endl;
        }
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