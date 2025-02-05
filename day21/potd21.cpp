//leetcode-1790
bool areAlmostEqual(string st1, string st2) {
int n = st1.length();
if (n != st2.length()) return false;

vector<int> diff;

for (int i = 0; i < n; i++) {
    if (st1[i] != st2[i]) {
        diff.push_back(i);
    }
}

if (diff.size() == 0) return true;

if (diff.size() == 2) {
    swap(st1[diff[0]], st1[diff[1]]);
    return st1 == st2;
}

return false;
}

//gfg-mirrorTree
void mirror(Node* node) {
    // code here
    if(node == NULL) return ;
    
    mirror(node->left);
    mirror(node->right);
    
    swap(node->left, node->right);
}