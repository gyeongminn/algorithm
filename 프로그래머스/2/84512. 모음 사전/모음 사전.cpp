#include <iostream>
#include <string>
#include <vector>

using namespace std;;

vector<char> items = {'A', 'E', 'I', 'O', 'U'};

int count = 0;
int ans;

void recursive(const string word, int depth, string s) {
    if (depth == 6) return;
    
    if (word == s) {
        ans = count;
    }
    
    count += 1;
    
    for (char c : items) {
        recursive(word, depth + 1, s + c);
    }
}

int solution(string word) {
    int answer = 0;
    
    recursive(word, 0, "");
    
    answer = ans;
    
    return answer;
}