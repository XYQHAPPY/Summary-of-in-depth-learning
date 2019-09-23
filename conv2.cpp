class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>>k={{1,1,1},{1,1,1},{1,1,1}};
        vector<vector<int>>M_temp(M.size(),vector<int>(M[0].size()));
        
        // for(int i=0;i<M.size();i++)
        // {
        //     M[i].insert(M[i].begin(),1,0);
        //     M[i].push_back(0);
        // }
        // M.push_back(vector<int>(M[0].size()));
        
        for(int i=0;i<M.size();i++)
        {
            for(int j=0;j<M[0].size();j++)
            {
                int val = 0;
                int count = 0;
                for(int x=-1;x<2;x++)
                {
                    for(int y=-1;y<2;y++)
                        if(i+x>=0&&j+y>=0&&i+x<M.size()&&j+y<M[0].size())
                        {
                            val += k[x+1][y+1]*M[i+x][j+y];
                            count++;
                        }
                }
                M_temp[i][j] = val/count;   
                
            }
        }
        return M_temp;
    }
};
