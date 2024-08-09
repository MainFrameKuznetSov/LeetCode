class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(i+2>=grid.size() || j+2>=grid[0].size()) 
                    continue; 
                int diag1=0,diag2=0,rowsum=-1,colsum=-1; 
                set<int>st; 
                for(int ki=0;ki<3;++ki)
                {
                    int temprow=0,tempcol=0;
                    for(int kj=0;kj<3;++kj)
                    {
                        if(grid[ki+i][kj+j]>9 || grid[ki+i][kj+j]<=0) 
                            continue;
                        st.insert(grid[ki+i][kj+j]);
                        if(ki==kj) 
                            diag1+=grid[ki+i][kj+j];
                        if(ki+kj==2) 
                            diag2+=grid[ki+i][kj+j];
                        temprow+=grid[ki+i][kj+j];
                        tempcol+=grid[kj+i][ki+j];
                    }
                    if((rowsum!=-1 && temprow!=rowsum) || (colsum!=-1 && tempcol!=colsum))
                        break; 
                    else 
                    {
                        rowsum=temprow;
                        colsum=tempcol;
                    }
                }
                if(st.size()==9 && diag1==diag2 && diag1==rowsum && rowsum==colsum) 
                    ++ans; 
            }
        }
        return ans;
    }
};