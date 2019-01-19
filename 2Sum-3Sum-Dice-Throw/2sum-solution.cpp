class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> source;
        for(int i = 0 ; i < nums.size(); i++) {
            int left = target - nums[i];
            if(source.find(left) != source.end()) {
                int min_n = min(i, source[left]);
                int max_n = max(i, source[left]);
                
                result.push_back(min_n);
                result.push_back(max_n);
                return result;
            }
            source.insert(pair<int,int>(nums[i], i));
        }
        return result;
    }
};