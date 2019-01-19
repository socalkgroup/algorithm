#include <vector>
#include <map>
#include <iostream>
#include <set>

using namespace std;

class Solution {
    private:
        void sort_three_elements(vector<int>& arr) 
        { 
            if (arr[1] < arr[0]){
                swap(arr[0], arr[1]);
            } 
        
            if (arr[2] < arr[1]) 
            { 
                swap(arr[1], arr[2]); 
                if (arr[1] < arr[0]) {
                    swap(arr[1], arr[0]);
                }
            } 
        }

    public:
        vector<vector<int>> threeSum(vector<int>& nums) {

            vector<vector<int>> result;

            if (nums.size() < 3) {
                return result;
            }
            
            sort(nums.begin(), nums.end());
            set<vector<int>> result_set;

            for(int i = 0 ; i < nums.size() - 1; i++) {

                if (i > 0 && nums[i] == nums[i-1]) {
                    continue;
                }
                
                map<int,int> temp_map;
                
                for(int ii = i + 1; ii < nums.size(); ii++) {
                    int current = nums[i] + nums[ii];

                    if(temp_map.count(-current) == 1) {
                        vector<int> answer = {nums[i], nums[ii], temp_map[-current]};
                        sort_three_elements(answer);
                        result_set.insert(answer);
                    }
                    else {
                        temp_map.insert(pair<int,int>(nums[ii], nums[ii]));
                    }
                }
            }

            vector<vector<int>> output(result_set.begin(), result_set.end());         
            return output;
        }
};

int main(int argc, char const *argv[])
{
    vector<int> input = {-1,-1,-1,1};
    Solution solution;
    vector<vector<int>> output = solution.threeSum(input);
    for(auto o : output) {
        for(auto i : o) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}