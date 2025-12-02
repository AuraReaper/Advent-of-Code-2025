#include <bits/stdc++.h>
#include <cstddef>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

bool isRepeatedPattern(long long num) {
    string s = to_string(num);
    regex pattern(R"((\d+)\1+)");
    return regex_match(s, pattern);
}

void findInvalidID(long long start, long long end, vector<long long>& invalidId) {
    while(start <= end) {
        if(isRepeatedPattern(start)) {
            invalidId.push_back(start);
        }
        start++;
    }
}

long long findInvalidIDSum(vector<string>& arr) {
    vector<long long> invalidId;
    
    for(string &data : arr) {
        size_t pos = data.find('-');
        long long start = stoll(data.substr(0, pos));
        long long end = stoll(data.substr(pos + 1));
        
        findInvalidID(start, end, invalidId);
    }
    
    long long sum = accumulate(invalidId.begin(), invalidId.end(), 0LL);
    
    return sum;
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open input.txt\n";
        return 1;
    }
    
    string input;
    getline(file, input);
    file.close();
    
    vector<string> arr;
    string temp;
    stringstream ss(input);
    
    while (getline(ss, temp, ',')) {
        arr.push_back(temp);
    }
    
    long long sum = findInvalidIDSum(arr);
    cout << sum << "\n";
    
    return 0;
}
