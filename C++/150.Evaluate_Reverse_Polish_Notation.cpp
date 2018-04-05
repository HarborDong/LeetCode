class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        int a, b;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" ) {
                a = mystack.top(); mystack.pop();
                b = mystack.top(); mystack.pop();
                mystack.push(a + b);
            } else if(tokens[i] == "*") {
                a = mystack.top(); mystack.pop();
                b = mystack.top(); mystack.pop();
                mystack.push(a * b);
            } else if(tokens[i] == "-") {
                a = mystack.top(); mystack.pop();
                b = mystack.top(); mystack.pop();
                mystack.push(b - a);                
            } else if (tokens[i] == "/") {
                a = mystack.top(); mystack.pop();
                b = mystack.top(); mystack.pop();
                mystack.push(b / a);
            } else {
                mystack.push(stoi(tokens[i]));
            }
        }
        return mystack.top();
    }
};
