#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> factorization(int n) {

    std::vector<std::pair<int, int>> result;

    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            result.emplace_back(i, count);

            }
        i++;
    }
    
    if (n > 1) {
        result.emplace_back(n, 1);
    }
    return result;
}

int main() {

    std::vector<int> numbers = { 60, 626215995, 107};

    for (int n : numbers) {

        //std::map
        std::vector<std::pair<int, int>> factors = factorization(n);
        std::cout << "Factorization of " << n << ": ";

        for (auto f : factors) {
            std::cout << "(" << f.first << "^" << f.second << ")";
        }
        std::cout << std::endl;
    }
    return 0;
}
