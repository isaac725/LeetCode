/**
 * 方法一：暴力法，排序後搜尋目標。O(nlogn)/O(1)，空間O(1)
 * 方法二：堆疊法，適用在動態資料，用容量限制大小來過濾資料，O(nlogk)，O(k)
 * 方法三：快速搜尋，給定一隨機目標作為基準，調整其他值之位置Ave O(n)/O(nn),O(1)
 */

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) 
    {
/* solution 1: brute
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
*/
/* solution 2: stack
        auto cmp = [](int l, int r){return l > r;};
        std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
        for (int val : nums) 
        {
            pq.push(val);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
*/
/* solution 3: quick
*/
        Quick_sort(nums, 0, nums.size()-1);
        return nums[nums.size()-k];
    }

    void swap(std::vector<int>& arr, int i, int j)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    int partition(std::vector<int>& arr, int front, int end)
    {
        int pivot = arr[end];
        int i = front - 1;
        for (int j = front; j < end; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr, i, j);
            }
        }
        i++;
        swap(arr, i, end);
        return i;
    }

    void Quick_sort(std::vector<int>& arr, int front, int end)
    {  
        if (front < end)
        {
            int pivot = partition(arr, front, end);
            Quick_sort(arr, front, pivot-1);
            Quick_sort(arr, pivot+1, end);
        }
    }
};
/**
 * 補充：
 * 低等排序：
 *      氣泡
 *      選擇
 *      插入
 * 高級排序：
 *      快速
 *      合併
 *      堆疊
 * 第k個
 *      快速
 *      堆疊
 *
 */