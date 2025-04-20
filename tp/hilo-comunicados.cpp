#include <iostream>
#include <string>
#include <map>
using namespace std;
int processInstructionString(string s) {
    int position= 0;
    for (size_t i = 0; i < s.length(); ++i) {
        switch (s[i]) {
            case '+': 
                position++;
                break;
            case '-': 
                position--;
                break;
        }
    }
    return position;
}

void processStringBT(const string& s, int position, double prob, map<int, double> &probabilities) {
    if (s.empty()) {
        probabilities[position] += prob;
        return;
    }
    switch (s[0]) {
        case '+': 
            processStringBT(s.substr(1), position+1, prob, probabilities);
            break;
        case '-': 
            processStringBT(s.substr(1), position-1, prob, probabilities);
            break;
        case '?':
            processStringBT(s.substr(1), position+1, prob * 0.5, probabilities); //+
            processStringBT(s.substr(1), position-1, prob * 0.5, probabilities); //-
    }
}

double computeProb(string s1, string s2) {
    int instructionPosition= processInstructionString(s1);
    map<int, double> probabilities;
    processStringBT(s2, 0, 1.0, probabilities);
    return probabilities[instructionPosition];
}
 
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout.precision(10);
    double result = computeProb(s1, s2);
    cout << result << endl;
    
    return 0;
}