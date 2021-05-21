//
// Created by Razdan, Akhil on 2021/05/20.
//

#include <ctime>
#include <cstdio>
#include <cstring>

struct TimerClass {
    TimerClass(const char *timer_name)  {
        timestamp = std::time(nullptr);
        this->timer_name = new char[200];
        std::strncpy(this->timer_name, timer_name, 200);
    }

    // Copy constructor
    TimerClass(const TimerClass &other) : timestamp{other.timestamp} {

    };

    // Move constructor
    TimerClass(TimerClass &&other) : timestamp{other.timestamp} {
        other.timestamp = 0;
    }

    TimerClass &operator=(const TimerClass &other) {
        if (this == &other) return *this;
        this->timestamp = other.timestamp;
        return *this;
    }

    // Move assignment
    TimerClass &operator=(TimerClass &&other) noexcept {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        other.timestamp = 0;
    }

    ~TimerClass() noexcept {
        auto age = std::time(nullptr) - timestamp;
        printf("Timer: %s destructed at time : %ld\n", timer_name, age);
    }

private:
    std::time_t timestamp;
    char *timer_name;
};

int main() {
    TimerClass timerClass {"RazTimer"};
    return 0;
}