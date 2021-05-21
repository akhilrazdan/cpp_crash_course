//
// Created by Razdan, Akhil on 2021/05/20.
//
#include <cstdio>
#include <cstring>

struct Logger {
    virtual ~Logger() = default;

    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    ConsoleLogger(const char* prefix) {
        const auto prefix_len = strlen(prefix);
        buffer = new char[200];
        strncpy(buffer, prefix,prefix_len );
    }

    void log_transfer(long from, long to, double amount) override {
        printf("[%s] %ld > %ld: %f\n", buffer, from, to, amount);
    }
private:
    char* buffer;
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {

    }
};

struct AccountDatabase {
    virtual int getAmount(long account_id) = 0;

    virtual void setAmount(long account_id, double amount) = 0;
};

struct InMemoryAccountDatabase : AccountDatabase {
    int getAmount(long account_id) override {
        printf("Getting amount in account %ld: %f\n", account_id, 0.0);
        return 0;
    }

    void setAmount(long account_id, double amount) override {
        printf("Setting amount in account %ld: %f\n", account_id, amount);

    }

};

struct Bank {
    Bank(Logger &logger, AccountDatabase &accountDatabase) : logger{logger} , accountDatabase{accountDatabase}{}

    void make_transfer(long from, long to, double amount) {
        logger.log_transfer(from, to, amount);
        accountDatabase.setAmount(from, accountDatabase.getAmount(from) - amount);
        accountDatabase.setAmount(to, accountDatabase.getAmount(to) + amount);
    }

private:
    Logger &logger;
    AccountDatabase &accountDatabase;
};
int main(){
    ConsoleLogger logger{"HelloWorld"};
    InMemoryAccountDatabase accountDatabase{};
    Bank bank{logger, accountDatabase};
    accountDatabase.setAmount(1234, 2000);
    accountDatabase.setAmount(3456, 10000);
    bank.make_transfer(1234, 3456, 20.00);
}