class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> m;
        for(auto city: paths){
            m[city[0]] = 0;
            m[city[1]] = 0;
        }
        
        for(auto first:paths){
            m[first[0]] = 1; 
        }
        string dest;
        for(auto sec: m){
            if(sec.second!=1){
                dest = sec.first;
            }
        }
        return dest;
    }
};
