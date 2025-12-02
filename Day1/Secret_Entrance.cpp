#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long decodePassword(vector<string>& input) {
    long long n = input.size();
    long long dial = 50;
    long long countZero = 0;
    
    for(long long i = 0 ; i < n ; i++) {
        char dir = input[i][0];
        long long  num = stoi(input[i].substr(1));
        // L -> x - val
        // R -> x + val
        // 
        if(dir == 'L') {
            dial = (dial - num) % 100;
        } else {
            dial = (dial + num) % 100;
        }
        
        if(dial == 0) {
            countZero++;
        }
    }
    
    return countZero;
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open input.txt\n";
        return 1;
    }
    
    vector<string> input;
    string s;
    
    while (file >> s) {
        input.push_back(s);
    }
    
    file.close();
    
    cout << decodePassword(input) << "\n";
    
    return 0;
}
