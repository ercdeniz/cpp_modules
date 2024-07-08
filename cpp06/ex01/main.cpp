#include "Serialize.hpp"

int main() {
    Data originalData;
    originalData.i = 42;
    std::cout << CYAN << "Original Data Address: " << YELLOW << &originalData << std::endl;

    uintptr_t serializedPointer = Serialize::serialize(&originalData);
    std::cout << CYAN << "Serialized Pointer: " << YELLOW << serializedPointer << std::endl;

    Data *deserializedPointer = Serialize::deserialize(serializedPointer);
    std::cout << CYAN << "Deserialized Pointer: " << YELLOW << deserializedPointer << std::endl;

    if (deserializedPointer == &originalData) {
        std::cout << GREEN << "Deserialization successful!" << std::endl;
        std::cout << CYAN << "Original Data: " << MAGENTA << originalData.i << std::endl;
        std::cout << CYAN << "Deserialized Data: " << MAGENTA << deserializedPointer->i << RESET << std::endl;
    }
    else
        std::cout << RED << "Deserialization failed!" << RESET << std::endl;

    return 0;
}
