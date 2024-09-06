
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <filesystem>
#include <chrono>
#include <algorithm>

namespace fs = std::filesystem;

class FileProcessor {
private:
    std::string directory;
    std::vector<std::string> processedFiles;
    std::mutex mtx;

public:
    FileProcessor(const std::string& dir) : directory(dir) {}

    void processFile(const std::string& filename) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (std::find(processedFiles.begin(), processedFiles.end(), filename) != processedFiles.end()) {
                return;
            }
            processedFiles.push_back(filename);
        }

        std::cout << "Processing file: " << filename << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate file processing
        std::cout << "Finished processing file: " << filename << std::endl;
    }

    void processDirectory() {
        std::vector<std::thread> threads;

        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.path().extension() == ".txt") {
                threads.emplace_back(&FileProcessor::processFile, this, entry.path().filename().string());
            }
        }

        for (auto& thread : threads) {
            thread.join();
        }
    }
};

int main() {
    FileProcessor processor("./files");
    processor.processDirectory();
    return 0;
}
