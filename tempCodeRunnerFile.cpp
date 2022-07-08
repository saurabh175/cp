 map<char, int> m, m1;
    int cnt = 0;
    int ans = 0;
    for (auto x : pat)
    {
        m[x]++;
    }
    m1 = m;
    cnt = m.size();
    int i = 0, j = 0;
    while (j < txt.size())
    {
        if (m.count(txt[j]) > 0)
        {

            m[txt[j]]--;
            if (m[txt[j]]==0)
            {
                cnt--;
            }
        }
        if (j - i + 1 < pat.size())
        {
            j++;
        }
        else if (j - i + 1 == pat.size())
        {
            if (cnt == 0)
            {
                ans++;
            }
            if (m[txt[i]]==0)
            {
                cnt++;
            }
            if (m1.count(txt[i]) > 0)
            {
                m[txt[i]]++;
            }
            i++;
            j++;
        }
    }
    cout << ans << endl;