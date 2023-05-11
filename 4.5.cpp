#include <iostream>
#include <vector>

template<typename T>
T findMax(const std::vector<T>& v) {
    T maxElem = v[0];
    for (const auto& elem : v) {
        if (elem > maxElem) {
            maxElem = elem;
        }
    }
    return maxElem;
}

int main() {
    std::vector<int> values;
    int n;
    std::cout << " Enter the number of values: ";
    std::cin >> n;
    std::cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        values.push_back(value);
    }
    int maxVal = findMax(values);
    std::cout << "Max value: " << maxVal << std::endl;
    return 0;
}
