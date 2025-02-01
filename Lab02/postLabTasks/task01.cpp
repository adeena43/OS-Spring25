#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Please provide at least one integer as an argument." << std::endl;
        return 1;
    }

    int* numbers = new int[argc - 1];
    int sum = 0;

    for (int i = 1; i < argc; i++) {
        try {
            int num = std::stoi(argv[i]);
            numbers[i - 1] = num;
            sum += num;
        } catch (std::invalid_argument& e) {
            std::cerr << "Error: Invalid argument '" << argv[i] << "'. Please provide valid integers." << std::endl;
            delete[] numbers;
            return 1;
        }
    }

    double average = static_cast<double>(sum) / (argc - 1);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;

    delete[] numbers;
    return 0;
}
