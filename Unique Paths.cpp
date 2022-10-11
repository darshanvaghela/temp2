Method 1: Recurtion
// TLE
int dfs(int i, int j, int m, int n)
{
    if(i == m-1 && j == n-1)return 1;
    if(i >= m || j >= n)return 0;
    
    return dfs(i+1, j, m, n) + dfs(i, j+1, m, n);
}
int uniquePaths(int m, int n) {
    return dfs(0,0,m,n);
}

Method 2:  DP recursive
vector<vector<int>> dp;
int dfs(int i, int j, int m, int n)
{
    if(i == m-1 && j == n-1)return 1;
    if(i >= m || j >= n)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    return dp[i][j] = (dfs(i+1, j, m, n) + dfs(i, j+1, m, n));
}
int uniquePaths(int m, int n) {
	 // set -1 to dp vector
    dp.resize(m,vector<int> (n,-1));
    return dfs(0,0,m,n);
}

Method 3: DP iterative
int uniquePaths(int m, int n) 
{
    int dp[m][n];
    for(int i=0;i<n;i++)
    {
        dp[m-1][i]=1;
    }
    for(int i=0;i<m;i++)
    {
        dp[i][n-1]=1;
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            dp[j][i]=dp[j+1][i]+dp[j][i+1];
        }
    }
    return dp[0][0];
}

Method 4: Combanitation.
int uniquePaths(int m, int n)
{
    double ans = 1;
    //  total we take n + m - 2 turn. from start to end we reached.
    //  So in n + m -2 , we take select m -1 position with right.
    //  calculate (n+m-2)C(m-1).   
    //  ex. m = 3, n = 3.
    //  we calculate 4C2.
    //  i start from 3 to 4 and m from 1 to 2.
    for(double i = n, j = 1; j <= m-1; j++,i++)
    {
        ans = (ans * i)/j;
    }
    return ans;
}
