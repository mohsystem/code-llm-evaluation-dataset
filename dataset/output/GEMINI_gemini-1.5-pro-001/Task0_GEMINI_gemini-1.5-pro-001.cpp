#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <filesystem>

namespace fs = std::filesystem;

std::unordered_map<std::string, std::mutex> file_mutexes;

void process_file(const std::string& file_path) {
    std::lock_guard<std::mutex> lock(file_mutexes[file_path]);
    // Simulate file processing
    std::cout << "Thread " << std::this_thread::get_id() << " is processing file: " << file_path << std::endl;
    // Add your file processing logic here
}

int main() {
    std::string directory_path = "path/to/your/directory"; // Replace with your directory path

    for (const auto& entry : fs::directory_iterator(directory_path)) {
        if (entry.is_regular_file()) {
            file_mutexes[entry.path()] = {}; 
            std::thread t(process_file, entry.path());
            t.detach(); 
        }
    }

    // Keep the main thread alive to allow detached threads to complete
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}