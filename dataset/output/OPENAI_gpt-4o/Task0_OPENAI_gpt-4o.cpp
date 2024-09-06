#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;

void process_file(const std::string& file_path) {
    std::lock_guard<std::mutex> guard(mtx);
    std::ifstream file(file_path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << "Processed by " << std::this_thread::get_id() << ": " << line << std::endl;
        }
        file.close();
    }
}

void process_directory(const std::string& directory_path) {
    std::vector<std::thread> threads;
    for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
        if (entry.is_regular_file()) {
            threads.emplace_back(process_file, entry.path().string());
        }
    }
    for (auto& th : threads) {
        th.join();
    }
}

int main() {
    std::string directory = "path_to_directory";
    process_directory(directory);
    return 0;
}