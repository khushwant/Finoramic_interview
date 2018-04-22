void fn_sum(TreeNode* root, int sum, vector <int>& line_vector, vector<vector<int> >& final_vector)
{
  line_vector.push_back(root->val);
  sum = sum - root->val;
  if(root->left == NULL && root->right == NULL)
  {
      if(sum == 0)
      {
          final_vector.push_back(line_vector);
      }
  }
  if(root->left)
  {
      fn_sum(root->left, sum, line_vector, final_vector);
      line_vector.pop_back();
  }
  if(root->right)
  {
      fn_sum(root->right, sum, line_vector, final_vector);
      line_vector.pop_back();
  }
  
} 

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
     
    vector<vector<int> > final_vector;
    vector<int> line_vector;
    
    if(root == NULL){
        return final_vector;
    }
    
    fn_sum(root, sum, line_vector, final_vector);
    
    return final_vector;
}
