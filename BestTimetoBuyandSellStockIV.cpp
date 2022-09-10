class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n =p.size();
        if(n<=1) return 0;
        
        if(k>n)k=n;
        
        vector<vector<int>> dp(k+1, vector<int>(n, 0));
        for(int i=1; i<k+1; i++)
        {
            int var = -p[0]+dp[i-1][0];
            for(int j=1; j<n; j++)
            {
                for(int prevj = 1; prevj<j; prevj++)
                {
                    var = max(var, -p[prevj]+dp[i-1][prevj]);
                }
                dp[i][j] = max(p[j]+var, dp[i][j-1]);
            }
        }
        return dp[k][n-1];
    }
};
