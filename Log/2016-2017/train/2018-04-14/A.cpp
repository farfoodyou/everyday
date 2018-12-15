long long DFS(Node* root) {
    if (root == NULL) {
        return -INF;
    }
    long long maxVale = -INF;  
​    maxValue = max(root->w);  
    maxValue = max(DFS(root->left));  
    maxValue = max(DFS(root->right));  
    return maxValue;
​}