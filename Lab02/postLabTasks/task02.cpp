#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

int findMissingElement(const std::vector<int>& numbers) {
    int n = numbers.size();
    int sum_of_series = 0;
    int expected_sum = 0;
    int min_num = *std::min_element(numbers.begin(), numbers.end());
    int max_num = *std::max_element(numbers.begin(), numbers.end());
    
    expected_sum = (n + 1) * (min_num + max_num) / 2;
    
    for (int num : numbers) {
        sum_of_series += num;
    }
    
    return expected_sum - sum_of_series;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Please provide integers as command-line arguments." << std::endl;
        return 1;
    }

    std::vector<int> numbers;

    for (int i = 1; i < argc; i++) {
        try {
            int num = std::stoi(argv[i]);
            numbers.push_back(num);
        } catch (std::invalid_argument& e) {
            std::cerr << "Error: Invalid argument '" << argv[i] << "'. Please provide valid integers." << std::endl;
            return 1;
        }
    }

    int missingElement = findMissingElement(numbers);
    
    std::ofstream outputFile("missing_element.txt");
    if (!outputFile) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return 1;
    }

    outputFile << "The missing element is: " << missingElement << std::endl;
    outputFile.close();

    return 0;
}
