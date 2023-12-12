class Solution {
public:
    void mySwap(vector<int>& nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    
    void myReverse(vector<int>& nums, int start_index) {
        int end_index = nums.size() - 1;
        while (end_index > start_index) {
            mySwap(nums, start_index, end_index);
            start_index++;
            end_index--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        if (N < 2) return; 
        
        // Find pos where a[i] > a[i-1]
        int inflection_index = N - 1;
        while (inflection_index > 0) {
            if (nums[inflection_index] > nums[inflection_index - 1]) {
                //cout << "Found the condition!" << inflection_index << endl;
                break;
            }
            inflection_index--;
        }
        
        if (inflection_index <= 0) {
            inflection_index = 0;
        } else {
            int ref_number = nums[inflection_index - 1];

            // starting from here look for the element greater than a[i-1]
            int swap_index = inflection_index;
            while (swap_index < N) {
                if (nums[swap_index] <= ref_number) {
                    break;
                }
                swap_index++;
            }
            swap_index--;

            // do the swap
            mySwap(nums, inflection_index - 1, swap_index);
        }
        // reverse the order of the array starting from the inflection point.
        myReverse(nums, inflection_index);
    }
};