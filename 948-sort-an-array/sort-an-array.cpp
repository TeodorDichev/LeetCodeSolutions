class Solution {
    void merge(vector<int> &arr, vector<int> &temp, int left_start, int right_start, int right_end)
    {
        int left = left_start;
        int left_end = right_start - 1;
        int index = left_start;
        int right = right_start;

        while (left <= left_end && right <= right_end)
        {
            if (arr[left] <= arr[right])
            {
                temp[index++] = arr[left++];
            }
            else
            {
                temp[index++] = arr[right++];
            }
        }

        while (left <= left_end)
        {
            temp[index++] = arr[left++];
        }

        while (right <= right_end)
        {
            temp[index++] = arr[right++];
        }

        for (int i = left_start; i <= right_end; i++)
        {
            arr[i] = temp[i];
        }
    }

    void merge_sort(vector<int> &arr, vector<int> &temp, int start, int end)
    {
        if (start < end)
        {
            int middle = start + (end - start) / 2;

            merge_sort(arr, temp, start, middle);
            merge_sort(arr, temp, middle + 1, end);
            merge(arr, temp, start, middle + 1, end);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        merge_sort(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};