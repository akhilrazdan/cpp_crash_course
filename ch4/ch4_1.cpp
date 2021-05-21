//
// Created by Razdan, Akhil on 2021/05/16.
//
#include <ctime>
#include <cstdio>

struct TimerClass {
    TimerClass() {
        timestamp = std::time(nullptr);
    }

    std::time_t timestamp;
};
int main() {
    TimerClass timerClass{};
    printf("timestamp : %ld", timerClass.timestamp);
    return 0;
}