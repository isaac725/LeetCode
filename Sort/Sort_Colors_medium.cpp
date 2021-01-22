class Solution 
{
  public:
    void sortColors(vector<int>& nums) 
    {
        int i = -1, front = 0, end = nums.size();
        while (front < end)
        {
            if (nums[front] == 0)
                swap(nums[++i], nums[front++]);
            else if (nums[front] == 2)
                swap(nums[--end], nums[front]);
            else
                front++;
        }
    }
    
    void swap(int& x, int& y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }
};