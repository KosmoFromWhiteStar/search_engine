
#include "../incl/Converter_JSON.h"
//#include "Converter_JSON.cpp"

int main() {
    Converter_JSON test1;
    test1.start();
    std::cout << test1.GetResponseLimit();
    return 0;
}
