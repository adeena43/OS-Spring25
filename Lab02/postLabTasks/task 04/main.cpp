#include <iostream>
#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"

int main() {
    std::string filename = "sample.txt";

    LetterCount letterCounter;
    WordCount wordCounter;
    LineCount lineCounter;

    int letters = letterCounter.countLetters(filename);
    int words = wordCounter.countWords(filename);
    int lines = lineCounter.countLines(filename);

    if (letters == -1 || words == -1 || lines == -1) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::cout << "Letter Count: " << letters << std::endl;
    std::cout << "Word Count: " << words << std::endl;
    std::cout << "Line Count: " << lines << std::endl;

    return 0;
}
