#include <cstdio>
//
// Created by Razdan, Akhil on 2021/05/12.
//
struct Element {
    Element* next{};
    Element* previous{};
    void insert_after(Element* new_element) {
        new_element->next = next;
        next = new_element;
    }
    char prefix[2];
    short operating_number;
};
int main(){
    printf("Hello World");
    return 0;
}
