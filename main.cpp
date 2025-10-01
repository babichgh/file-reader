#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string path;
    std::cout << "File path: ";
    std::getline(std::cin, path);

    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "The path is invalid. Try again: ";
        std::getline(std::cin, path);
        file.open(path, std::ios::binary);
    }

    const size_t bufferSize = 1024;
    char buffer[bufferSize + 1];
    buffer[bufferSize] = '\0';

    while (file.read(buffer, bufferSize)) {
        buffer[file.gcount()] = '\0';
        std::cout << buffer;
    }
    buffer[file.gcount()] = '\0';
    std::cout << buffer;

    std::cout << std::endl;

    file.close();

    return 0;
}