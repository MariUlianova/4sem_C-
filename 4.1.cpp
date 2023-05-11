#include <iostream>
#include <vector>

int sumEven(const std::vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) {
            sum += v[i];
        }
    }
    return sum;
}

int main() {
    std::vector<int> v;
    int x;
    while (std::cin >> x) { 
        v.push_back(x);
    }
    std::cout << "The sum of even numbers is: " << sumEven(v) << std::endl;
    return 0;
}
