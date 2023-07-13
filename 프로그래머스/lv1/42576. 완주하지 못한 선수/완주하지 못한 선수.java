import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> map = new HashMap<>();
        for (var person : participant) {
            if (map.containsKey(person)) {
                map.put(person, map.get(person) + 1);
            } else {
                map.put(person, 1);
            }
        }
        for (var person : completion) {
            if (map.containsKey(person) == true) {
                int a = map.get(person);
                if (a <= 0) {
                    return person;
                }
                map.put(person, a - 1);
            } else {
                return person;
            }
        }
        for (var person : participant) {
            if (map.get(person) > 0) {
                return person;
            }
        }
        return answer;
    }
}