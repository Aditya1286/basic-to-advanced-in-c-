#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
    unordered_map<string, int> table;
    
public:
    Spreadsheet(int rows) {}
    
    void setCell(string cell, int value) {
        table[cell] = value;
    }
    
    void resetCell(string cell) {
        table.erase(cell);
    }
    
    int getValue(string formula) {
        if (formula[0] != '=') return stoi(formula);
        
        int sum = 0;
        stringstream ss(formula.substr(1));
        string token;
        
        while (getline(ss, token, '+')) {
            if (isalpha(token[0])) {
                sum += table.count(token) ? table[token] : 0;
            } else {
                sum += stoi(token);
            }
        }
        
        return sum;
    }
};
