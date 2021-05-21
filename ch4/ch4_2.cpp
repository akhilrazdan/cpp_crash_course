//
// Created by Razdan, Akhil on 2021/05/19.
//

#include <ctime>
#include <cstdio>

struct TimerClass {
    TimerClass() {
        timestamp = std::time(nullptr);
    }
    ~TimerClass() noexcept{
        auto age = std::time(nullptr) - timestamp;
        printf("%ld", age);
    }

private:
    std::time_t timestamp;
};
int main() {
    TimerClass timerClass{};
    return 0;
}