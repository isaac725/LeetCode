class Solution 
{
  public:
    string findLongestWord(string s, vector<string>& d) 
    {
        std::string ret;
        int max = 0;
        auto substr = [](const auto& x, const auto& y)
        {
            int xl = 0, yl = 0;
            while (xl < x.size() && yl < y.size())
            {
                if (x[xl] == y[yl])
                    yl++;
                xl++;
            }
            return yl == y.size();
        };
        for (const auto& i : d)
        {
            if (max > i.size() || (max == i.size() && ret.compare(i) < 0))
                continue;
            if (substr(s, i))
            {
                ret = i;
                max = ret.size();
            }
        }
        return ret;
    }
};