class Solution {
    string record[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(string digits, string prefix, vector<string> &res) {
        int digits_length = digits.length();
        int i = 0;
        if(digits_length == 0) return;
        
        if(digits[0] < '2' || digits[0] > '9') {
            return;
        }
        
        while(i < record[digits[0]-'2'].length()) {
            if(digits_length == 1) {
                res.push_back(prefix + record[digits[0]-'2'][i]);
            } else {
            backtrack(digits.substr(1, digits_length - 1), prefix + record[digits[0]-'2'][i], res);
            }
            i++;
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        int digits_length = 0;
        vector<string> res;
        string prefix = "";
        
        backtrack(digits, prefix, res);
        
        return res;        
    }
};
