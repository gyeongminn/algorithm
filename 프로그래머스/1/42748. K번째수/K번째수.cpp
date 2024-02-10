#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto command : commands) {
        int i = command[0] - 1;
        int j = command[1] - 1;
        int k = command[2] - 1;
        
        vector<int> tmp;
        for (int idx = i; idx <= j; idx++) {
            tmp.push_back(array[idx]);
        }
        sort(tmp.begin(), tmp.end());
        
        answer.push_back(tmp[k]);
    }
    
    return answer;
}