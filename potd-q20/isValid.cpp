#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> st;
    if(input.empty()){
      return true;
    }
    for(int i = 0; i < int(input.length()); i++){
      if(input[i] == '['||input[i] == ']'||input[i] == '{'||input[i] == '}'||input[i] == '('||input[i] == ')'){
        if(input[i] == '['||input[i] == '{'||input[i] == '('){
          st.push(input[i]);
        }
        else{
          if(st.empty()){return false;}
          else if(st.top() == '(' && input[i] == ')'){
            st.pop();
          }
          else if(st.top() == '{' && input[i] == '}'){
            st.pop();
          }
          else if(st.top() == '[' && input[i] == ']'){
            st.pop();
          }
          else{
            return false;
          }
        }
      }
      else{
        continue;
      }
    }
    if(st.empty()){return true;}
    else{return false;}
}
