#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <filesystem>
#include <chrono>

std::mutex mtx;

void processFile(const std::string& filename) {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Processing " << filename << " by " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate file processing
}

int main() {
    std::vector<std::thread> threads;
    std::string directory = "shared_directory";

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            threads.emplace_back(processFile, entry.path().string());
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Control creation speed
        }
    }

    for (auto& thr : threads) {
        thr.join();
    }
    return 0;
}