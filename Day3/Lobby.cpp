#include <bits/stdc++.h>
#include <climits>
#include <numeric>
#include <string>
using namespace std;

long long maxJoltageSum(vector<string>& arr) {
    vector<int> maxJoltageForBank;
    
   for(string& bank : arr) {
        int n = bank.length();
        string maxJoltage = "00";
        for(int i = 0 ; i < n ; i++) {
            string joltage = "00";
            joltage[0] = bank[i];
            for(int j = i + 1 ; j < n ; j++) {
                joltage[1] = bank[j];
                maxJoltage = max(maxJoltage, joltage);
            }
        }
       
        maxJoltageForBank.push_back(stoll(maxJoltage));
    }
    
    long long sum = accumulate(maxJoltageForBank.begin(), maxJoltageForBank.end(), 0LL);
    
    return sum;
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open input.txt\n";
        return 1;
    }
    
    vector<string> arr;
    string s;
    
    while (file >> s) {
        arr.push_back(s);
    }

    file.close();
    
    cout << maxJoltageSum(arr) << "\n";
    
    return 0;
}
