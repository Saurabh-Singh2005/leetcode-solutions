#include <vector>
#include <string>
#include <set>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        stack<set<string>> operandStack;
        stack<char> operatorStack;

        auto combineConcat = [](const set<string>& set1, const set<string>& set2) {
            set<string> res;
            for (const string& s1 : set1) {
                for (const string& s2 : set2) {
                    res.insert(s1 + s2);
                }
            }
            return res;
        };

        auto combineUnion = [](const set<string>& set1, const set<string>& set2) {
            set<string> res = set1;
            res.insert(set2.begin(), set2.end());
            return res;
        };

        auto evaluateTop = [&](char op) {
            set<string> right = operandStack.top(); operandStack.pop();
            set<string> left = operandStack.top(); operandStack.pop();
            if (op == '*') {
                operandStack.push(combineConcat(left, right));
            } else if (op == ',') {
                operandStack.push(combineUnion(left, right));
            }
        };

        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];

            if (i > 0) {
                char prev = expression[i - 1];
                if ((isalpha(prev) || prev == '}') && (isalpha(c) || c == '{')) {
                    while (!operatorStack.empty() && operatorStack.top() == '*') {
                        evaluateTop(operatorStack.top());
                        operatorStack.pop();
                    }
                    operatorStack.push('*');
                }
            }

            if (isalpha(c)) {
                string str(1, c);
                operandStack.push({str});
            } else if (c == '{') {
                operatorStack.push('{');
            } else if (c == ',') {
                while (!operatorStack.empty() && operatorStack.top() != '{') {
                    evaluateTop(operatorStack.top());
                    operatorStack.pop();
                }
                operatorStack.push(',');
            } else if (c == '}') {
                while (!operatorStack.empty() && operatorStack.top() != '{') {
                    evaluateTop(operatorStack.top());
                    operatorStack.pop();
                }
                operatorStack.pop();
            }
        }

        while (!operatorStack.empty()) {
            evaluateTop(operatorStack.top());
            operatorStack.pop();
        }

        set<string> resultSet = operandStack.top();
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};