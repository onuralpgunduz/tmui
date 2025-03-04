#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include "../include/sys_monitor.hpp"

using namespace ftxui;

// Function to update system stats
std::string GetStats() {
    SystemMonitor monitor;
    return "CPU Usage: " + std::to_string(monitor.GetCPUUsage()) + "%\n"
           "Memory Usage: " + std::to_string(monitor.GetMemoryUsage()) + "MB";
}

int main() {
    auto screen = ScreenInteractive::Fullscreen();

    // Reactive text that updates dynamically
    auto system_stats = Renderer([&] {
        return vbox({
            text("System Monitor"),
            separator(),
            text(GetStats()),
        }) | border;
    });

    auto update_loop = [&] {
        while (true) {
            screen.PostEvent(Event::Custom); // Trigger UI refresh
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    };

    std::thread(update_loop).detach();
    screen.Loop(system_stats);

    return 0;
}
