/*******************************************************
 * open parentheses's number is less than or equal to n
 * close parentheses's number is less than or equal to 
 * that of open.
 */

class Solution {
public:
    void genParenthesis(int open_num, int close_num, int n,  string prefix,vector<string> &res) {
        if (open_num == n && close_num == n) {
            res.push_back(prefix);
        }
        if(open_num > n || close_num > open_num) {
            return;
        }
        genParenthesis(open_num + 1, close_num, n, prefix + '(', res);
        genParenthesis(open_num, close_num + 1, n, prefix + ')', res);
        return;
            
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string prefix = "";
        genParenthesis(0, 0, n, prefix, res);
        return res;
    }
};
