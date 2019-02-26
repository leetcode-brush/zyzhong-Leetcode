class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        assert(tokens.size() > 0);
        stack<int> stack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                if(tokens[i] == "+")
                    stack.push(b + a);
                else if(tokens[i] == "-")
                    stack.push(b - a);
                else if(tokens[i] == "*")
                    stack.push(b * a);
                else if(tokens[i] == "/")
                    stack.push(b / a);
            } else {
                    stack.push(stoi(tokens[i]));
            }
        }
        return stack.top();
    }
};