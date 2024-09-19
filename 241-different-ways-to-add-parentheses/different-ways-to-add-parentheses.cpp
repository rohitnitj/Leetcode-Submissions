class Solution {
private:
    int perform(int x , int y , char op ) {
        if( op == '+' ) return x + y ;
        if( op == '-' ) return x - y ;
        if( op == '*' ) return x * y ;
        return 0 ;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        
        vector<int> ans ;
        bool isNum = 1 ;

        for( int i = 0 ; i < expression.size() ; i++ ) {
            if( !isdigit(expression[i])) {
                isNum = 0 ;

                vector<int> left = diffWaysToCompute(expression.substr(0, i ) ) ;
                vector<int> right = diffWaysToCompute(expression.substr(i+1 ) ) ;

                for( int x : left ) {
                    for( int y : right ) {
                        int val = perform(x, y, expression[i] ) ;
                        ans.push_back(val ) ;
                    }
                }
            }
        }

        if( isNum == 1 ) ans.push_back(stoi(expression)) ;
        return ans ;
    }
};