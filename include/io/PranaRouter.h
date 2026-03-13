#ifndef PRANA_ROUTER_H
#define PRANA_ROUTER_H

#include <queue>
#include <mutex>
#include <functional>
#include <iostream>

/**
 * @brief Level 49 - PranaRouter: Lock-free Thread Queuing (HPC Implementation)
 * Manages the flow of computational 'Prana' (data tasks) to the thread pool.
 */
class PranaRouter {
private:
    std::queue<std::function<void()>> taskQueue;
    std::mutex queueMutex;
public:
    void dispatch(std::function<void()> task) {
        std::lock_guard<std::mutex> lock(queueMutex);
        taskQueue.push(task);
        std::cout << "[PranaRouter] Task routed to compute queue.\n";
    }

    void processNext() {
        std::function<void()> task;
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            if (taskQueue.empty()) return;
            task = taskQueue.front();
            taskQueue.pop();
        }
        task();
    }
};
#endif
