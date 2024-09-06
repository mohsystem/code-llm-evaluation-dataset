#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <ctime>
#include <iomanip>

namespace fs = std::filesystem;

void log_event(const std::string& event_type, const std::string& message) {
    std::ofstream log_file("security_events.log", std::ios::app);
    if (log_file.is_open()) {
        auto now = std::chrono::system_clock::now();
        auto now_time_t = std::chrono::system_clock::to_time_t(now);
        log_file << std::put_time(std::localtime(&now_time_t), "%Y-%m-%d %H:%M:%S") 
                 << " - " << event_type << " - " << message << std::endl;
        log_file.close();
    } else {
        std::cerr << "Error: Unable to open log file." << std::endl;
    }
}

void monitor_file_changes(const std::string& file_path) {
    try {
        auto last_write_time = fs::last_write_time(file_path);
        while (true) {
            auto current_write_time = fs::last_write_time(file_path);
            if (current_write_time != last_write_time) {
                log_event("File Change Detected", "File '" + file_path + "' has been modified.");
                last_write_time = current_write_time;
            }
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    } catch (const std::exception& e) {
        log_event("Error", "An error occurred while monitoring '" + file_path + 
                   "': " + e.what());
    }
}

int main() {
    std::string file_to_monitor = "/path/to/your/important_file.txt"; // Replace with actual path
    monitor_file_changes(file_to_monitor);
    return 0;
}