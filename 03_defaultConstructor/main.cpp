/* 
   Default constructor, constructs an element without any arguments.
   Required only for certain operations, such as the vector::resize()
   method with one argument, and the map::operator[] access
*/

#include <iostream>
#include <memory>
#include <vector>
using std::allocator;
using std::cout;
using std::endl;

template <class T, class Allocator = allocator<T>>
class MyVector {
public:
    // Default constructor
    constexpr MyVector() noexcept(noexcept(Allocator())) {
        cout << "Default constructor call" << endl;
    }
};

int main() 
{
    MyVector<int> vec;

    return 0;
}
