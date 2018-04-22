int Solution::isValidSudoku(const vector<string> &A) {
        vector<vector<char> > char_matrix;
        vector<char> v;
	
        for(int i = 0; i < A.size(); i++){
    	    copy(A[i].begin(), A[i].end(), back_inserter(v));
    	    char_matrix.push_back(v);
    	    v.clear();
    	}
	bool row_matrix[9][9] = {false}, column_matrix[9][9] = {false}, sub_section_matrix[9][9] = {false};
        
        for(int i = 0; i < char_matrix.size(); ++ i)
            for(int j = 0; j < char_matrix[i].size(); ++ j)
                if(char_matrix[i][j] != '.')
                {
                    int num = char_matrix[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(row_matrix[i][num] || column_matrix[j][num] || sub_section_matrix[k][num])
                        return 0;
                    row_matrix[i][num] = column_matrix[j][num] = sub_section_matrix[k][num] = true;
                }
        
        return 1;
}