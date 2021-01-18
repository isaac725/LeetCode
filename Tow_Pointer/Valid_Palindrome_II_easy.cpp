class Solution 
{
  public:
    bool validPalindrome(string s) 
    {
        auto check_substr = [&s](int h, int t)
        {
            for (;h < t; h++, t--)
                if (s[h] != s[t])
                    return false;
            return true;
        };
        for (
              int head = 0, tail = s.size() - 1
            ; head < tail
            ; head++, tail--
        )
        {
            if (s[head] != s[tail])
                return     check_substr(head + 1, tail) 
                        || check_substr(head, tail - 1);
        }
        return true;
    }
};