class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(const string &token: tokens){
            
            int num1 ;
            int num2;
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                int res ;
                if(token == "+")
                    res = num2 + num1;
                else if (token  == "-")
                    res = num2 - num1;
                else if (token == "*"){
                    res = num2 * num1;
                }else
                    res = num2 / num1;

                st.push(res);
            }else{
                st.push(stoi(token));
            }
        }

        return st.top();

    }
};