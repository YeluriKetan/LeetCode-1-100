class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> monoStack;
        int index = 0;
        while (index < num.size()) {
            if (monoStack.empty() || monoStack.back() <= num[index]) {
                monoStack.push_back(num[index++]);
                continue;
            }
            while (k > 0 && !monoStack.empty()  && monoStack.back() > num[index]) {
                monoStack.pop_back();
                k--;
            }
            monoStack.push_back(num[index++]);
        }
        while (!monoStack.empty() && k-- > 0) {
            monoStack.pop_back();
        }
        while (!monoStack.empty() && monoStack.front() == '0') {
            monoStack.pop_front();
        }
        if (monoStack.empty()) {
            return "0";
        }
        string ans = "";
        while (!monoStack.empty()) {
            ans += monoStack.front();
            monoStack.pop_front();
        }
        return ans;
    }
};