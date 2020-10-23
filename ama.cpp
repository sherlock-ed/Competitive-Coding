int FMP(int n; int m; vector<vector<int>> costs){
	vector<vector<int>> minleft(n,vector<int>(m,0));
	vector<vector<int>> minright(n,vector<int>(m,0));
	vector<vector<int>> minup(n,vector<int>(m,0));
	vector<vector<int>> mindown(n,vector<int>(m,0));
	for (int i = 0; i < n; ++i)
	{
		minleft[i][0]=0;
		minright[i][n-1]=0;
	}
	for (int i = 0; i < m; ++i)
	{
		minup[0][i]=0;
		mindown[n-1][i]=0;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			minleft[i][j]= min(0,minleft[i][j-1]+costs[i][j-1]);
			minright[i][n-j-1]=min(0,minright[i][n-j],costs[i][n-j]);
		}
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			minup[i][j]= min(0,minup[i-1][j]+costs[i-1][j]);
			mindown[n-i-1][j]=min(0,minright[n-i][j],costs[n-i][j]);
		}
	}
	int msf=(int)1e9+4;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			msf = min(msf, minup[i][j]+mindown[i][j]+minright[i][j]+minleft[i][j]+costs[i][j]);
		}
	}
	return msf;

}