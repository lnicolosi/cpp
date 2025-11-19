#include <iostream>
#include "Serializer.hpp"

int main() {
    Data d; d.a = 42; d.word = "hello";
    Data* original = &d;

    uintptr_t raw = Serializer::serialize(original);
    Data* back = Serializer::deserialize(raw);

    std::cout << "original: " << original << "\n"
              << "back    : " << back << "\n"
              << ((back == original) ? "OK" : "KO") << std::endl;
}
