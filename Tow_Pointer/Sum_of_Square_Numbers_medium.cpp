class Solution 
{
  public:
    bool judgeSquareSum(int c) 
    {
        if (c == 0)
            return true;
        int first = 0;
        int last = std::sqrt(c);
        while (first <= last)
        {
            long int ans = std::pow(first, 2) + std::pow(last, 2);
            if (ans == c)
                return true;
            else if (ans > c)
                last--;
            else
                first++;
        }
        return false;
    }
};