#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <dirent.h>

std::mutex lock;

void processFile(const std::string& filename) {
    lock.lock();
    std::cout << "Processing file: " << filename << std::endl;
    // Simulate file processing
    std::this_thread::sleep_for(std::chrono::seconds(1));
    lock.unlock();
}

int main() {
    DIR* dir;
    struct dirent* ent;
    std::vector<std::thread> threads;

    dir = opendir("files");
    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                threads.emplace_back(processFile, std::string(ent->d_name));
            }
        }
        closedir(dir);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}