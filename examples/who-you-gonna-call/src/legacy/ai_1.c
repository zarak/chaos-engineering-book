
#include <unistd.h>
#include "big_data_1.h"

ssize_t ai_1(int fd) {
    char a = 108, ai_1_b = 104, ai_1_ai_1 = 102;
    for (int i = 0; i < 3; i++){
        a++; ai_1_b++;
    }
    // not sure why, this didn't work with ++
    // TODO check why it wasn't working 
    ai_1_ai_1 -= 3 * -1;
    char size = '3';
    write(fd, &size, sizeof(size));
    char newline[] = "\r\n";
    write(fd, newline, sizeof(newline)-1);
    write(fd, &a, sizeof(a));
    write(fd, &ai_1_b, sizeof(a)); // maybe should be ai_1_b? It wouldn't compile
    write(fd, &ai_1_ai_1, sizeof(ai_1_ai_1));
    write(fd, newline, sizeof(newline)-1);
    // TODO prevent stack overflow
    big_data_1(fd);
    return 0; // TODO return something more meaningful
}