#include <iostream>
#include <vector>
using namespace std;

int length_of_LIS(vector<int>& v) {
    vector<int> memory(v.size(), 1);
    int longest_length = 1;

    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                memory[i] = max(memory[i], memory[j] + 1);
            }
        }
        longest_length = max(longest_length, memory[i]);
    }

    return longest_length;
}

int main() {
    vector<int> v = {0, 1, 0, 3, 2, 3};
    cout << length_of_LIS(v);
    return 0;
}

