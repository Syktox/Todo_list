#include <iostream>
#include "lib/test.h"

int main() {
    Window window(2);

    int wert = window.test();
    std::cout << wert << std::endl;

    return 0;
}
