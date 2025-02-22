class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            stack<TreeNode*> st;  
            int i = 0;
            while (i < traversal.size()) {
                int level = 0;
                while (i < traversal.size() && traversal[i] == '-') {
                    level++;
                    i++;
                }
                
                int val = 0;
                while (i < traversal.size() && isdigit(traversal[i])) {
                    val = val * 10 + (traversal[i] - '0');
                    i++;
                }
                
                TreeNode* node = new TreeNode(val);
                
                while (st.size() > level) {
                    st.pop();
                }
                
                if (!st.empty()) {
                    if (st.top()->left == nullptr)
                        st.top()->left = node;
                    else
                        st.top()->right = node;
                }
                
                st.push(node);
            }
            
            while (st.size() > 1) {
                st.pop();
            }
            
            return st.top();
        }
};

// gfg

class Solution {
    public:
      int maxLength(string& s) {
          // code here
          stack<int> st;
          st.push(-1);
          int maxlen=0;
          
          for(int i=0; i<s.size(); i++){
              if(s[i] == '('){
                  st.push(i);
              }else{
                  st.pop();
                  if(!st.empty()){
                      maxlen=max(maxlen, i-st.top());
                  }else{
                      st.push(i);
                  }
              }
          }
          return maxlen;
      }
  }
;