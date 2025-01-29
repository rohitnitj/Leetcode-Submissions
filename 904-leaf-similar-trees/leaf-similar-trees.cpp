class Solution {
private:
    bool isLeaf(TreeNode* node ) {
        return !(node -> left || node -> right ) ;
    }

    void dfs( TreeNode* root, vector<int> &arr ) {
        if( root == NULL ) return ;

        if(isLeaf(root ) ) arr.push_back(root -> val ) ;
        dfs(root -> left, arr ) ;
        dfs(root -> right, arr ) ;
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2 ;

        dfs(root1, arr1 ) ;
        dfs(root2, arr2 ) ;

        if( arr1.size() != arr2.size() ) return false ;
        for( int i = 0 ; i < arr1.size() ; i++ ) {
            if(arr1[i] != arr2[i] ) return false ;
        }

        return true ;
    }
};