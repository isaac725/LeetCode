class Solution 
{
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        /*
        int x = 0;
        for (int i = m; i < nums1.size(); i++)
        {
            nums1[i] = nums2[x];
            x++;
        }
        std::sort(nums1.begin(), nums1.end());
        */
        int len = m + n - 1;
        int fir = m - 1, sec = n - 1;
        while (fir >=0 || sec >= 0)
        {
            if (fir < 0)
                nums1[len--] = nums2[sec--];
            else if (sec < 0)
                nums1[len--] = nums1[fir--];
            else if (nums1[fir] > nums2[sec])
                nums1[len--] = nums1[fir--];
            else
                nums1[len--] = nums2[sec--];
        }
    }
};