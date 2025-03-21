class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size() ;
        unordered_map<string, vector<string>> graph ;
        unordered_map<string, int> indegree ;
        queue<string> q ;
        vector<string> ans ;

        for( int i = 0 ; i < n ; i++ ) {
            indegree[recipes[i]] = ingredients[i].size() ;

            for( auto &ing : ingredients[i] ) {
                graph[ing].push_back(recipes[i]) ;
            }
        }

        for( auto &s : supplies) q.push(s ) ;

        while( !q.empty() ) {
            string curr = q.front(); q.pop() ;

            if( find(recipes.begin(), recipes.end(), curr ) != recipes.end()) ans.push_back(curr) ;

            for( auto &r : graph[curr] ) {
                indegree[r]-- ;
                if( indegree[r]== 0 ) {
                    q.push(r) ;
                }
            }
        }

        return ans ;
    }
};