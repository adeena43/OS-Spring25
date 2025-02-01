#include <iostream>
#include <vector>
#include <cstdlib>

void bubbleSort(std::vector<int>& numbers) {
    int n = numbers.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <integer1> <integer2> ... <integerN>" << std::endl;
        return 1;
    }

    std::vector<int> numbers;

    for (int i = 1; i < argc; i++) {
        numbers.push_back(std::atoi(argv[i]));
    }

    bubbleSort(numbers);

    std::cout << "Sorted integers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
