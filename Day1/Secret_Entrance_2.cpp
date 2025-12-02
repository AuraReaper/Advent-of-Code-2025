#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Count zero hits inside a rotation
long long countZeroDuring(long long pos, char dir, long long dist) {
    long long k0;

    if (dir == 'R') {
        // First k such that (pos + k) % 100 == 0
        k0 = (100 - pos) % 100;
        if (k0 == 0) k0 = 100;
    } else {
        // First k such that (pos - k) % 100 == 0
        k0 = pos % 100;
        if (k0 == 0) k0 = 100;
    }

    if (k0 > dist) return 0;

    // After first hit, every +100 steps is another hit
    return 1 + (dist - k0) / 100;
}

long long decodePassword(vector<string>& input) {
    long long n = input.size();
    long long dial = 50;
    long long countZero = 0;
    
    for (long long i = 0; i < n; i++) {
        char dir = input[i][0];
        long long num = stoll(input[i].substr(1));

        // Count hits DURING the rotation
        countZero += countZeroDuring(dial, dir, num);

        // Move final dial position
        if (dir == 'L') {
            dial = (dial - num) % 100;
            if (dial < 0) dial += 100;
        } else {
            dial = (dial + num) % 100;
        }

        // (DON'T count final dial==0 here; that's Part 1 behavior)
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
