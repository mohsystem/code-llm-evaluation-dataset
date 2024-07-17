#include <thread>
#include <mutex>
#include <dirent.h>
#include <iostream>

std::mutex mtx;

void process_file(const char *filename) {
    mtx.lock();
    // Process the file here
    mtx.unlock();
}

void process_files(const char *path) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            std::thread(process_file, dir->d_name).detach();
        }
        closedir(d);
    }
}