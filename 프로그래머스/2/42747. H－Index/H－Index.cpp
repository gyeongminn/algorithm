#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    
    int answer = 0;
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= citations.size() - i) {
            answer = citations.size() - i;
            break;
        }
    }
    
    return answer;
}