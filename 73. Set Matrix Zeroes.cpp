// mid
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); // row
        int n = matrix[0].size(); // col
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// leetcode - 90% faster
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(); //row
        int n=matrix[0].size(); //col
        
        vector<int>row;
        vector<int>col;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        // make the whole row [index] = 0
        for(int i=0;i<row.size();i++){
            int index=row[i];
            for(int j=0;j<n;j++) matrix[index][j]=0;
        }
        // make the whole col [index] = 0
        for(int i=0;i<col.size();i++){
            int index=col[i];
            for(int j=0;j<m;j++) matrix[j][index]=0;
        }

        return;

    }
};
