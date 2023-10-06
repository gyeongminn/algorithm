#include <iostream>
#include <regex>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    std::string pattern = "((100+1+)|(01))+";  // 정규표현식 패턴
    std::regex re(pattern);  // 정규표현식 객체 생성

    while (T--) {
        std::string s;
        std::cin >> s;
        if (std::regex_match(s, re)) {  // 정규표현식에 맞는지 검사
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
