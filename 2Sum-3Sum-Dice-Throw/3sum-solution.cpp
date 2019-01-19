#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
private:
    void sort3(int arr[]) 
    { 
        // Insert arr[1] 
        if (arr[1] < arr[0]) 
        swap(arr[0], arr[1]); 
    
        // Insert arr[2] 
        if (arr[2] < arr[1]) 
        { 
            swap(arr[1], arr[2]); 
            if (arr[1] < arr[0]) 
                swap(arr[1], arr[0]); 
        } 
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        map<vector<int>,int> result_map;
        
        for(int index = 0 ; index < nums.size() - 1; index++) {
            if (index > 0 && nums[index] == nums[index-1]) {
                continue;
            }
            
            map<int,int> temp_map;
            
            for(int iindex = index + 1; iindex < nums.size(); iindex++) {
                int current = nums[index] + nums[iindex];

                if(temp_map.count(-current) == 1) {
                    vector<int> answer = {nums[index], nums[iindex], temp_map[-current]};
                    sort(answer.begin(), answer.end());
                    
                    
                    if(result_map.count(answer) == 0) {
                        result_map.insert(pair<vector<int>, int>(answer, 1));
                    }
                }
                else {
                    temp_map.insert(pair<int,int>(nums[iindex], nums[iindex]));
                }
        }
    }
    
    for(auto itor = result_map.begin(); itor != result_map.end(); itor++) {
        result.push_back((*itor).first);
    }
    
    return result;
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