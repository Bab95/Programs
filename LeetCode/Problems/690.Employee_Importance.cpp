/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        unordered_map<int,int> id_index;
        int i = 0;
        for(auto it:employees){
            id_index[it->id] = i;
            i++;
        }
        vector<bool> included(n,false);
        int ans = 0;
        dfs(employees,included,ans,id_index,id);
        return ans;
    }
    void dfs(vector<Employee*>& employees,vector<bool>& included,int& ans,unordered_map<int,int>& id_index,int id){
        int index = id_index[id];
        ans += employees[index]->importance;
        included[index] = true;
        for(int i=0;i<employees[index]->subordinates.size();++i){
            if(!included[id_index[employees[index]->subordinates[i]]]){
                dfs(employees,included,ans,id_index,employees[index]->subordinates[i]);
            }
        }
    }
};
