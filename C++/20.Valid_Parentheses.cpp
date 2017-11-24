class Solution {
public:
    bool isValid(string s) {
        vector<char> temp;
        int i = 0;
        temp.push_back('$');
        while(s[i]) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
                temp.push_back(s[i]);
            } else if (s[i] == ')') {
                if(temp.back() == '(') {
                    temp.pop_back();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if(temp.back() == '{') {
                    temp.pop_back();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if(temp.back() == '[') {
                    temp.pop_back();
                } else {
                    return false;
                }
            }
            i++;
        }
        if(temp.back() != '$') 
            return false;
        else
            return true;
    }
};
