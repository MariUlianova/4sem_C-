#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include <string>
#include <span>
#include <string_view>

template <typename Container>
std::vector<std::pair<typename Container::value_type, 
    typename Container::value_type>>

get_odd_even_pairs(const Container& c) {
    std::vector<std::pair<typename Container::value_type,
        typename Container::value_type>> result;
    auto size = c.size();
    if (size % 2 != 0) {
        size -= 1;
    }
    for (std::size_t i = 0; i < size; i += 2) {
        result.push_back(std::make_pair(c[i], c[i + 1]));
    }
    if (c.size() % 2 != 0) {
        result.push_back(std::make_pair(c.back(), typename Container::value_type{}));
    }
    return result;
}

int main() {
    std::vector<int> v{ 10, 20, 30, 40, 50 };
    auto result1 = get_odd_even_pairs(v);
    for (const auto& pair : result1) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    std::array<std::string, 4> arr{ "cat", "dog", "mouse", "lion" };
    auto result2 = get_odd_even_pairs(arr);
    for (const auto& pair : result2) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    std::string str = "Hello";
    auto result3 = get_odd_even_pairs(str);
    for (const auto& pair : result3) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    std::span<const int> s{v};
    auto result4 = get_odd_even_pairs(s);
    for (const auto& pair : result4) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    std::string_view sv = "Hello";
    auto result5 = get_odd_even_pairs(sv);
    for (const auto& pair : result5) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    return 0;
}