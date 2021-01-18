class Solution 
{
  public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        ///如果輸入為空集合，則回傳空。
        if (numbers.size() == 0)
            return {};
        /** 想像成一個矩陣
              j 0 1 2 3
            i 0 * - - S
              1 * * - -
              2 * * * -
              3 * * * *
            而-號是我們需要搜尋的部分，
            為了避免O(n*n)的情況出現，
            用雙指標來解，如果今天target>A[0]+A[3] = S，
            而A[j]又已經是最大值，所以A[0]~A[2]的加總絕對小於A[0]+A[3]，
            故第一列可以完全不看，以此類推，這樣可以避免O(n*n)，
              j 0 1 2 3
            i 0 * * * *
              1 * * - -
              2 * * * -
              3 * * * *
        **/
        for (int i = 0, j = numbers.size() - 1; i < j;)
        {
            int sum = numbers[i] + numbers[j];
            if (target == sum)
                return {i+1, j+1};
            else if (target > sum)
                i++;
            else
                j--;
        }
        return {};
    }
};