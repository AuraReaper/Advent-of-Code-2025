#include <bits/stdc++.h>
#include <numeric>
#include <string>
using namespace std;

pair<char,int> maxInRange(string& bank, int start, int end) {
    char maxNum = '0';
    int index = -1;
    
    if(start > end) {
        return {maxNum, -1};
    }
    
    for(int i = start ; i <= end ; i++) {
        if(bank[i] > maxNum) {
            maxNum = bank[i];
            index = i;
        }
    }
    
    return {maxNum, index};
}

long long maxJoltageSum(vector<string>& arr) {
    vector<long long> maxJoltageForBank;
    
    for(string& bank : arr) {
        string maxJoltage;
        int need = 12;
        int n = bank.length();
        int start = 0;
        
        while(need > 0) {
            int end = n - need;
            auto temp = maxInRange(bank, start, end);
            
            if(temp.second == -1) {
                break;
            }
            
            maxJoltage.push_back(temp.first);
            start = temp.second + 1;
            need--;
        }
        
        if(maxJoltage.length() == 12) {
            maxJoltageForBank.push_back(stoll(maxJoltage));
        }
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
