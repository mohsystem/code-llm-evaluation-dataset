#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <dirent.h>

std::mutex lock;

void processFile(const std::string& filename) {
    lock.lock();
    std::cout << "Processing file: " << filename << std::endl;
    // Process the file
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate processing time
    std::cout << "Finished processing file: " << filename << std::endl;
    lock.unlock();
}

int main() {
    DIR* dir;
    struct dirent* ent;
    dir = opendir("files");
    if (dir != NULL) {
        std::vector<std::thread> threads;
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                threads.emplace_back(processFile, std::string(ent->d_name));
            }
        }
        closedir(dir);
        for (auto& thread : threads) {
            thread.join();
        }
    } else {
        std::cout << "Could not open directory" << std::endl;
        return 1;
    }
    return 0;
}