#include <cstdio>
//
// Created by Razdan, Akhil on 2021/05/12.
//
struct Element {
    Element* next{};
    Element* previous{};
    void insert_before(Element* new_element) {
        new_element->previous = previous;
        this->previous = new_element;
    }
    void insert_after(Element* new_element) {
        new_element->next = next;
        next = new_element;
    }
    char prefix[2];
    short operating_number;
};
int main(){
    printf("Traversing forward\n");
    Element trooper1, trooper2, trooper3;
    trooper1.prefix[0] = 'T';
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 42;
    trooper1.insert_after(&trooper2);
    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 43;
    trooper2.insert_after(&trooper3);
    trooper3.prefix[0] = 'L';
    trooper3.prefix[1] = 'S';
    trooper3.operating_number = 44;
    trooper3.insert_before(&trooper2);
    trooper2.insert_before(&trooper1);



    for (Element *it = &trooper1;  it; it = it->next){
        printf("stormtropper %c%c-%d\n", it->prefix[0], it->prefix[1], it->operating_number);
    }

    for (Element *it = &trooper3;  it; it = it->previous){
        printf("stormtropper %c%c-%d\n", it->prefix[0], it->prefix[1], it->operating_number);
    }
}
