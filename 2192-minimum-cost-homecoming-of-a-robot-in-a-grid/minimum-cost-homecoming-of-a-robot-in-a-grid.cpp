class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        if( startPos == homePos ) return 0 ;

        int sRow = startPos[0] ;
        int sCol = startPos[1] ;
        int hRow = homePos[0] ;
        int hCol = homePos[1] ;

        int totalCost = 0 ;

        while( sRow < hRow ) totalCost += rowCosts[++sRow ] ;
        while( sRow > hRow ) totalCost += rowCosts[--sRow ] ;
        while( sCol < hCol ) totalCost += colCosts[++sCol ] ;
        while( sCol > hCol ) totalCost += colCosts[--sCol ] ;

        return totalCost ;
    }
};