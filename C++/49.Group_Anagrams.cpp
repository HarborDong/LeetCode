class Solution {
public:
    string strSort(string str) {
        sort(str.begin(), str.end());
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> temp;
        unordered_map<string, vector<string>>::iterator index;
        for(int i = 0; i < strs.size(); i++) {
           // if(temp.find(strSort(strs[i])) != temp.end()) {
                temp[strSort(strs[i])].push_back(strs[i]);
            //} else {
                
           // }
        }
        index = temp.begin();
        while(index != temp.end()) {
            ret.push_back(index->second);
            index++;
        }
        
        return ret;
    }
};
