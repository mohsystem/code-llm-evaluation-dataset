
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

const std::string DIRECTORY_PATH = "shared_directory";
const int NUM_THREADS = 4;

std::mutex mtx;

void processFile(const fs::path& file) {
    std::cout << "Processing file: " << file.filename() << " by thread: " << std::this_thread::get_id() << std::endl;
    // Simulating file processing
    std::this_thread::sleep_for(std::chrono::seconds(2));
    // Delete the processed file
    fs::remove(file);
}

void processFiles() {
    while (true) {
        fs::path file_to_process;

        {
            std::lock_guard<std::mutex> lock(mtx);
            for (const auto& entry : fs::directory_iterator(DIRECTORY_PATH)) {
                if (fs::is_regular_file(entry)) {
                    file_to_process = entry.path();
                    break;
                }
            }
        }

        if (!file_to_process.empty()) {
            processFile(file_to_process);
        } else {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

int main() {
    fs::create_directories(DIRECTORY_PATH);

    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(processFiles);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
