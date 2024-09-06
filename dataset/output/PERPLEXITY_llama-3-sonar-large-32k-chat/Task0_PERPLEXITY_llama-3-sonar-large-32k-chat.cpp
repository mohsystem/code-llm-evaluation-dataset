#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>
#include <filesystem>

std::mutex lock;

void processFile(const std::string& fileName) {
    std::lock_guard<std::mutex> guard(lock);
    std::cout << "Processing file: " << fileName << std::endl;
    std::ifstream file(fileName);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::cout << "File content: " << content << std::endl;
    std::cout << "Finished processing file: " << fileName << std::endl;
}

int main() {
    std::string directory = "./files";
    std::vector<std::thread> threads;
    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        threads.emplace_back(processFile, entry.path().string());
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}