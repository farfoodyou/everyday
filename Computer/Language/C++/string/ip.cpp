#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

void string_split(const std::string & str,
                  const std::string & sep,
                  std::vector<std::string> * strs,
                  bool ignore_empty) {
    if (strs == NULL) {
        return;
    }
    size_t start = 0;
    size_t found = str.find_first_of(sep, start);
    while (std::string::npos != found) {
        std::string tmp = str.substr(start, found - start);
        if (!ignore_empty || tmp != "") {
            strs->push_back(tmp);
        }
        start = found + 1;
        found = str.find_first_of(sep, start);
    }
    std::string tmp = str.substr(start, str.size() - start);
    if (!ignore_empty || tmp != "") {
        strs->push_back(tmp);
    }
}

bool ip_string_to_uint(const std::string * ip_string, uint32_t & ip_int) {
    ip_int = 0;
    std::vector<std::string> sub_ip;
    string_split(*ip_string, ".", &sub_ip, false);
    if (sub_ip.size() != 4) {
        return false;
    }
    for (auto & v : sub_ip) {
        int32_t ip_segment;
        if (atoi(v, &ip_segment) && ip_segment >= 0 && ip_segment <= 255) {
            ip_int = ip_segment + ip_int * 256;
        }
        else {
            return false;
        }
    }
    return true;
}

int main(){
    std::string ip("33.33.33.33");
    uint32_t ip_int;
    ip_string_to_uint(&ip, &ip_int);
    std::cout << ip_int << std::endl;

    return 0;
}