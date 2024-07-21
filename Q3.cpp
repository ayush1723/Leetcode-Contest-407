class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int k = i;
                int len = 0;
                while (s[k] == '1' && k < n) {
                    k++;
                    len++;
                }
                if (k == n) {
                    return ans;
                }
                int j = k;
                int cen = 0;
                while (s[j] == '0' && j < n) {
                    cen++;
                    j++;
                }
                ans += len + cnt;
                cnt += len;
                i = j - 1;
                if (i == n) {
                    return ans;
                }
            }
        }
        return ans;
    }
};