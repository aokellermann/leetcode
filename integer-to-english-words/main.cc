#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, const char *> m;

public:
    Solution() {
        m = {
                {1,          "One"},
                {2,          "Two"},
                {3,          "Three"},
                {4,          "Four"},
                {5,          "Five"},
                {6,          "Six"},
                {7,          "Seven"},
                {8,          "Eight"},
                {9,          "Nine"},
                {10,         "Ten"},
                {11,         "Eleven"},
                {12,         "Twelve"},
                {13,         "Thirteen"},
                {14,         "Fourteen"},
                {15,         "Fifteen"},
                {16,         "Sixteen"},
                {17,         "Seventeen"},
                {18,         "Eighteen"},
                {19,         "Nineteen"},
                {20,         "Twenty"},
                {30,         "Thirty"},
                {40,         "Forty"},
                {50,         "Fifty"},
                {60,         "Sixty"},
                {70,         "Seventy"},
                {80,         "Eighty"},
                {90,         "Ninety"},
        };
    }


    string numberToWords(int num) {
        if (num == 0) return "Zero";

        const auto it = m.find(num);
        if (it != m.end()) {
            return it->second;
        }

        if (num < 100) {
            return numberToWords((num / 10) * 10) + (num % 10 != 0 ? " " + numberToWords(num % 10) : string());
        }

        if (num < 1000) {

            return numberToWords((num / 100)) + " Hundred" +
                   (num % 100 != 0 ? " " + numberToWords(num % 100) : string());
        }

        if (num < 1000000) {
            return numberToWords((num / 1000)) + " Thousand" +
                   (num % 1000 != 0 ? " " + numberToWords(num % 1000) : string());
        }

        if (num < 1000000000) {
            return numberToWords((num / 1000000)) + " Million" +
                   (num % 1000000 != 0 ? " " + numberToWords(num % 1000000) : string());
        }

        return numberToWords((num / 1000000000)) + " Billion" +
               (num % 1000000000 != 0 ? " " + numberToWords(num % 1000000000) : string());
    }
};
