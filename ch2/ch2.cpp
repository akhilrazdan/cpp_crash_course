#include <iostream>
int absolute_value(int x){
    if (x>=0) return x;
    else return -1*x;
}


enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Calculator(Operation o){
        operation = o;
    }
    int calculate(int a, int b){
        if (operation == Operation::Add){
            return a + b;
        }
        return 0;
    }
private:
    Operation operation;
};

int main() {
    int x = -12;
    printf("Absolute value %d\n", absolute_value(x));
    Calculator c{Operation::Add};
    printf("Answer from calculator = %d", c.calculate(2,4));
}
