#ifndef ANTAHKARANA_ENGINE_H
#define ANTAHKARANA_ENGINE_H

#include <vector>
#include <thread>

/**
 * @brief Level 50 - AntahkaranaEngine: The Primary Task Scheduler
 * Manages the C++17 thread pool to distribute Vedic Sutra operations across CPU cores.
 */
class AntahkaranaEngine {
private:
    unsigned int threadCount;
public:
    AntahkaranaEngine() {
        threadCount = std::thread::hardware_concurrency();
        if (threadCount == 0) threadCount = 2;
    }

    void parallel_invoke(const std::vector<std::function<void()>>& tasks) {
        std::vector<std::thread> pool;
        for(auto& task : tasks) {
            pool.emplace_back(task);
        }
        for(auto& t : pool) {
            if(t.joinable()) t.join();
        }
    }

    unsigned int getThreadCount() const { return threadCount; }
};
#endif
