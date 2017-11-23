class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp_map;
        vector<int> result;
        unordered_map<int, int>::iterator hit;
        int index = 0;
        int temp = 0;
        if(nums.size() < 2) {
            return result;
        }
        
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            temp_map.insert(make_pair(*iter, index));
            index++;
        }
        
        index = 0;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            temp = target - *iter;
            hit = temp_map.find(temp);
            if(hit != temp_map.end()) {
                if(index != hit->second) {
                    if(index < hit->second) {
                        result.push_back(index);
                        result.push_back(hit->second);
                    } else {
                        result.push_back(hit->second); 
                        result.push_back(index);
                    }
                    return result;    
                }
            }
            index++;
        }
    return result;
    }
};
