class Solution {
public:
    string convertToTitle(int columnNumber) {
        std::string result = "";

        while (columnNumber > 0) {
            int remainder = (columnNumber - 1) % 26;  // Adjusting to 0-based index
            char c = 'A' + remainder;
            result = c + result;
            columnNumber = (columnNumber - 1) / 26;
        }

        return result;
    }
};