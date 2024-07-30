#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> numbers;

    std::cout << "Enter some integers (end with Ctrl+D): ";

    // Use std::istream_iterator to read integers from std::cin
    std::istream_iterator<int> input_it(std::cin);
    std::istream_iterator<int> end_of_stream;

    // Copy input from the stream into the vector
    std::copy(input_it, end_of_stream, std::back_inserter(numbers)); // when pressed CTRL+D , input_it will be equal to end_of_stream;

    std::cout << "You entered: ";
    for (auto it : numbers) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}

