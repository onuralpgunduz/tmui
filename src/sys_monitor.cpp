#include "../include/sys_monitor.hpp"
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <sstream>

#ifdef __linux__
#include <sys/sysinfo.h>
#endif

float SystemMonitor::GetCPUUsage() {
    std::ifstream file("/proc/stat");
    std::string line;
    std::getline(file, line);
    
    std::istringstream ss(line);
    std::string cpu;
    unsigned long long user, nice, system, idle;
    ss >> cpu >> user >> nice >> system >> idle;

    static unsigned long long prev_idle = 0, prev_total = 0;
    unsigned long long total = user + nice + system + idle;
    unsigned long long totald = total - prev_total;
    unsigned long long idled = idle - prev_idle;

    prev_total = total;
    prev_idle = idle;

    return (totald - idled) * 100.0 / totald;
}

float SystemMonitor::GetMemoryUsage() {
    struct sysinfo info;
    sysinfo(&info);
    return (info.totalram - info.freeram) / (1024.0 * 1024.0);
}
