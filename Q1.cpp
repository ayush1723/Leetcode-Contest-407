class Solution {
public:
    int minChanges(int n, int k) {
        if (k > n) {
            return -1;
        }
        vector<int> s;
        vector<int> t;
        int temp = n;
        int semp = k;
        while (temp) {
            int x = temp % 2;
            temp /= 2;
            s.push_back(x);
        }
        while (semp) {
            int x = semp % 2;
            semp /= 2;
            t.push_back(x);
        }
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == 1 && t[i] == 1 || s[i] == 0 && t[i] == 0) {
                i++;
                j++;
                continue;
            } else if (s[i] != t[i] && s[i] == 0) {
                return -1;
            } else if (s[i] != t[i] && s[i] == 1) {
                i++;
                j++;
                cnt++;
            }
        }
        while (i < s.size()) {
            if (s[i] == 0) {
                i++;
                continue;
            }
            i++;
            cnt++;
        }
        return cnt;
    }
};