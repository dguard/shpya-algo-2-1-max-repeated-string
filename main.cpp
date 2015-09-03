#include <iostream>
#include <vector>
#include <string>

std::vector<size_t> prefix_function(std::string s) {
    size_t n = s.length();
    std::vector<size_t> pi(n);
    for (size_t i = 1; i < n; ++i) {
        size_t j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    std::string str;
    std::cin >> str;

    size_t max_repeat_count = 1;
    size_t str_len = str.length();

    for (size_t j = 0; j < str_len; j++) {
        std::string part_of_str = str.substr(j);
        std::vector<size_t> prefix_vector = prefix_function(part_of_str);
        size_t prefix_vector_size = prefix_vector.size();

        for (int i = 0; i < prefix_vector_size; i++) {
            size_t len = i + 1;
            if (prefix_vector[i] * 2 >= len) {
                size_t repeat_count = len / (len - prefix_vector[i]);
                if (repeat_count > max_repeat_count) {
                    max_repeat_count = repeat_count;
                }
            }
        }
    }
    std::cout << max_repeat_count << std::endl;

    return 0;
}