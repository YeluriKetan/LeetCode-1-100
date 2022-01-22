#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        unordered_map<int, int> tracker;
        int n = height.size();
        unordered_map<int, int>::iterator pointer;
        int maxWater = 0;
        for (int i = 0; i < n; ++i) {
            pointer = tracker.find(height[i]);
            if (pointer != tracker.end()) {
                maxWater = max(maxWater, (i - pointer->second) * height[i]);
            }
            pointer->second = i;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
