//
// Created by Razdan, Akhil on 2021/05/12.
//
#include <cstdio>

int main(){
    auto original = 100;
    auto& original_ref = original;
    printf("Original: %d\n", original);
    printf("Reference: %d\n", original_ref);

    auto new_value = 200;
    original_ref = new_value;
    printf("Original: %d\n", original);
    printf("New Value: %d\n", new_value);
    printf("Reference: %d\n", original_ref);
}
