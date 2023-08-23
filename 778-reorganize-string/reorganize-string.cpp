class Solution {
public:
    string reorganizeString(string s) {
         int n = s.size();
        std::vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a']++;
        }

        std::priority_queue<std::pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                pq.push({count[i], 'a' + i});
            }
        }

        std::string result = "";

        while (!pq.empty()) {
            std::pair<int, char> curr = pq.top();
            pq.pop();

            if (result.empty() || result.back() != curr.second) {
                result += curr.second;
                if (curr.first > 1) {
                    pq.push({curr.first - 1, curr.second});
                }
            } else {
                if (pq.empty()) {
                    return ""; 
                }
                std::pair<int, char> next = pq.top();
                pq.pop();
                result += next.second;
                if (next.first > 1) {
                    pq.push({next.first - 1, next.second});
                }
                pq.push(curr);
            }
        }

        return result;
    }
};