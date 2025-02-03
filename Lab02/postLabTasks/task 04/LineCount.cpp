#include "LineCount.h"
#include <fstream>

LineCount::LineCount() {}

int LineCount::countLines(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1; // Error opening file
    }

    std::string line;
    int lineCount = 0;
    while (std::getline(file, line)) {
        lineCount++;
    }

    file.close();
    return lineCount;
}
