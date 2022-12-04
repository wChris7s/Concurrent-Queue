//
// Created by chris on 4/12/2022.
//

#ifndef CONCURRENT_QUEUE_CONCURRENT_QUEUE_H
#define CONCURRENT_QUEUE_CONCURRENT_QUEUE_H

#include "queue.h"
#include <condition_variable>

template<typename T>
class ConcurrentQueue {
public:
    void push(const T &data);

    T pop();

private:
    queue<T> queue_;
    std::mutex queue_mutex_;
    std::condition_variable cv;
};

template<typename T>
void ConcurrentQueue<T>::push(const T &data) {
    std::unique_lock<std::mutex> lock(queue_mutex_);
    queue_.push(data);
    cv.notify_one();
}

template<typename T>
T ConcurrentQueue<T>::pop() {
    std::unique_lock<std::mutex> lock(queue_mutex_);
    while (queue_.empty())
        cv.wait(lock);
    T result = queue_.front();
    queue_.pop();
    return result;
}

#endif //CONCURRENT_QUEUE_CONCURRENT_QUEUE_H
