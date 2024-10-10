#include<iostream>


int main() {
int b = 5;

auto val = [b]() {
    std::cout << "Hello! My name is Swastik Bhandari, and b is " << b << std::endl;
};

    val();
    return 0;
}
