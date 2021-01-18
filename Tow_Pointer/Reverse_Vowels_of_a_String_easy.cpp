class Solution 
{
  public:
    string reverseVowels(string s) 
    {
        std::vector<char> vow{
            'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
        };
        
        auto vowel = [&vow](const char chr)
        {
            for (auto i : vow)
                if (chr == i)
                    return true;
            return false;
        };
        int first = 0, last = s.size()-1;
        while(first <= last)
        {
            bool ans_f = vowel(s[first]);
            bool ans_l = vowel(s[last]);
            if (ans_f && ans_l)
            {
                char tmp = s[first];
                s[first] = s[last];
                s[last] = tmp;
                first++;
                last--;
            }
            else if (ans_f && !ans_l)
                last--;
            else if (!ans_f && ans_l)
                first++;
            else
            {
                first++;
                last--;
            }
        }
        return s;
    }
};