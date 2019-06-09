#include <iostream>
#include <string>
#include "autocomplete.hpp"

using namespace std;

int main() {
    vector<term> reqs;
    int reqc;
    cin >> reqc;
    for (int i = 0; i < reqc; i++) {
        std::string temp, p;
        int t;
        cin >> t;
        getline(std::cin, p);
        int pos = p.find(' ');
        temp = p.substr(pos + 1);
        term s(temp, t);
        reqs.push_back(s);
    }
    autocomplete res(reqs);
    int qc;
    cin >> qc;
    string temp;
    getline(cin, temp);
    for (int i = 0; i < qc; i++) {
        string request, word, p;
        getline(cin, p);
        int pos = p.find(' ');
        request = p.substr(0, pos);
        word = p.substr(pos + 1);
        if (request == "matches") {
            auto ans = res.all_matches(word);
            for (term &one : ans) {
                cout << one << " ";
            }
            cout << "\n";
        } else if (request == "number") {
            cout << res.number_of_matches(word) << "\n";
        }
    }
    return 0;

}
