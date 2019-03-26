#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::pair;

void string_split(const string & str,
                  const string & sep,
                  vector<string> * strs,
                  bool ignore_empty) {
    if (strs == NULL) {
        return;
    }
    size_t start = 0;
    size_t found = str.find_first_of(sep, start);
    while (string::npos != found) {
        string tmp = str.substr(start, found - start);
        if (!ignore_empty || tmp != "") {
            strs->push_back(tmp);
        }
        start = found + 1;
        found = str.find_first_of(sep, start);
    }
    string tmp = str.substr(start, str.size() - start);
    if (!ignore_empty || tmp != "") {
        strs->push_back(tmp);
    }
}

int main(){
    std::string str;
    std::vector<std::string> terms;
    str = "ssss\t3e\t555";
    string_split(str, "\t", &terms, true);
    std::cout << terms.size();
}