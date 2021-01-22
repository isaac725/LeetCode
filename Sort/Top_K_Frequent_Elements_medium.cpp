class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> sep;
        for (const auto& i : nums)
        {
            auto check_ = std::find_if(
                sep.begin()
                , sep.end()
                , [&i](const auto& x){return x.first == i;}
            );
            if (check_ != sep.end())
                (*check_).second++;
            else
                sep.insert({i, 1});
        }
        std::vector<std::pair<int, int>> res;
        for (const auto i : sep)
            res.emplace_back(std::make_pair(i.first, i.second));
        
        std::sort(
            res.begin()
            , res.end()
            , [](auto& x, auto& y){return x.second > y.second;}
        );
        std::vector<int> ret(k, 0);
        for (auto i = 0; i < k; i++)
            ret[i] = res[i].first;
        
        return ret;
    }
};