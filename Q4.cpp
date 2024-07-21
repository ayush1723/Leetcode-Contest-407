class Solution {
public:
    long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            arr[i] = target[i] - nums[i];
        }

        vector<int> list;
        bool pos = true;
        bool exp;

        long result = 0;

        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                result += solve(list);
                list.clear();
                pos = true;
            } else {
                exp = arr[i] > 0;

                if (exp != pos) {
                    result += solve(list);
                    list.clear();
                }

                list.push_back(abs(arr[i]));
                pos = exp;
            }
        }

        result += solve(list);

        return result;
    }

private:
    long solve(vector<int>& list) {
        int min = 0;
        long result = 0;

        for (int num : list) {
            if (num > min) {
                result += num - min;
            }

            min = num;
        }

        return result;
    }
};