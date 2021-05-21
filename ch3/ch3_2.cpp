#include <cstdio>
//
// Created by Razdan, Akhil on 2021/05/11.
//

char read_from(char* characters, size_t size, int position){
    if (position>=size || position < 0){
        printf("Error occured");
        return 0;
    }
    return characters[position];
}

void write_to(char* characters, size_t size, int position, char elementToinsert){
    if (position >= size || position < 0){
        printf("Error occured");
        return;
    }
    characters[position] = elementToinsert;
}
int main() {
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char* upper_ptr = upper; // Equivalent: &upper[0]

    lower[3] = 'd'; // lower now contains a b c d e \0
    upper_ptr[3] = 'D'; // upper now contains A B C D E \0

    char letter_d = lower[3]; // letter_d equals 'd'
    char letter_D = upper_ptr[3]; // letter_D equals 'D'

    printf("lower: %s\nupper: %s", lower, upper);
    write_to(lower, sizeof(lower)/sizeof(char), 'u', 3);
    write_to(upper, sizeof(upper)/sizeof(char), 'U', 3);

    printf("lower: %s\nupper: %s\n", lower, upper);

    write_to(lower, sizeof(lower)/sizeof(char), 'g', 7);
    write_to(upper, sizeof(upper)/sizeof(char), 'G', 7);

    write_to(lower, sizeof(lower)/sizeof(char), 'g', -1);
    write_to(upper, sizeof(upper)/sizeof(char), 'G', -1);

    printf("lower: %s\nupper: %s\n", lower, upper);

    printf("%lu", sizeof(lower)/sizeof(char));
    printf("Read from position 5: %c\n", read_from(lower, sizeof(lower)/sizeof(char), 5));
    printf("Read from position 4: %c", read_from(lower, sizeof(lower)/sizeof(char), 4));
}