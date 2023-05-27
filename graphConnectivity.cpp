#include<bits/stdc++.h>
using namespace std;

bool vis[30];
vector<int>adj[30];

int charToNumber(char c) {
    return c - 'A' + 1;
}


void dfs(int node) {
    vis[node] = true;
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
int TC, V;
	char c, a, b;
	char input[10];

	scanf("%d", &TC);
	while(TC--)
	{
		memset(vis, false, sizeof(vis));
		cin >> c;
		V = c - '0' - 16;
		while(getchar() != '\n');
		while(gets(input) && sscanf(input, "%c%c", &a, &b) == 2)
		{
			int u, v;
			u = a - '0' - 16;
			v = b - '0' - 16;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int ans=0 ;
		for(int i=1 ;i<=V ;i++)
        {
            if(!vis[i])
            {
                ans++ ;
                dfs(i);
            }
        }
        printf("%d\n",ans);
		if(TC)
			printf("\n");
			for(int i=0; i<30; i++)
			adj[i].clear();

	}

	return 0;
}
