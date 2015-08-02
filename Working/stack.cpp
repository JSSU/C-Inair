// comparing size, capacity and max_size
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int> > map(m+1,vector<int>(n+1,0));
        for(int i=2; i<m+1; i++)
         map[i][0]=grid[i-2][0]+map[i-1][0];
        for(int j=2; j<n+1; j++)
         map[0][j]=grid[0][j-2]+map[0][j-1];
        // cout<<"----initial map:----"<<endl;
        // for(auto x: map)
        // { for(auto y: x)
        //   cout<<y<<" ";
        //   cout<<endl;
        // }
        // cout<<"----end----"<<endl;
        
        //map[1][1]=grid[0][0];
        //vector<vector<int>> map(m+1,vector<int>(n+1,0));
        //for(int i=1; i<m; i++)
        // for(int j=1; j<n; j++)
        //   map[i][j]=grid[i-1][j-1];
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                map[i][j]=grid[i-1][j-1]+min(map[i-1][j],map[i][j-1]);
                        // cout<<"----map:----"<<i<<" "<<j<<endl;
                        // for(auto x: map)
                        //   { for(auto y: x)
                        //     cout<<y<<" ";
                        //     cout<<endl;
                        //   }
                        // cout<<"----end----"<<i<<" "<<j<<endl;
            }
        }
        return map[m][n];
    }
};
int main ()
{
  Solution s;
  vector<vector<int> > g;
  vector<int> mafan;
  mafan.push_back(1);mafan.push_back(3);mafan.push_back(1);
  g.push_back(mafan);
  mafan.clear();
  mafan.push_back(1);mafan.push_back(5);mafan.push_back(1);
  g.push_back(mafan);
  mafan.clear();
  mafan.push_back(4);mafan.push_back(2);mafan.push_back(1);
  g.push_back(mafan);
  cout<<s.minPathSum(g)<<endl;
  return 0;
}