#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    Base* basePtr = generate();
    Base &baseReference = *basePtr;
    identify(basePtr);
    identify(baseReference);
    delete basePtr;
    return 0;
}