#include <iostream>
#include <hello.h>

int main(int argc, char *argv[])
{
    Hello hi;
    std::cout << hi.print() << std::endl;
    return 0;
}