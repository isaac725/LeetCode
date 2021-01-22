class Solution 
{
  public:
    string frequencySort(string s) 
    {
        std::map<char, int> feq;
        for (const auto& i : s)
        {
            auto count = std::find_if(
                  feq.begin()
                , feq.end()
                , [&i](const auto& x){return x.first == i;}
            );
            if (count != feq.end())
                (*count).second++;
            else
                feq.insert({i, 1});
        }
        
        std::vector<std::pair<char, int>> res;
        for (const auto& i : feq)
            res.push_back(std::make_pair(i.first, i.second));
        
        std::sort(
              res.begin()
            , res.end()
            , [](const auto& x, const auto& y){return x.second > y.second;}
        );
        
        std::string ret;
        
        for (const auto& i : res)
        {
            std::string tmp(i.second, i.first);
            ret += tmp;
        }
        
        return ret;
    }
};