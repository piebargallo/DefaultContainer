#include <iostream>
#include <vector>
#include <memory>
using std::allocator;
using std::cout;
using std::endl;

template <class T, class Allocator = allocator<T>>
class MyVector {
public:
    // Constructor explícito por defecto con allocator
    constexpr explicit MyVector(const Allocator& alloc) noexcept
        : allocator_(alloc), data_(nullptr), size_(0) {
        std::cout << "Constructor explícito llamado con Allocator" << endl;
    }

    // Otros métodos del vector...

private:
    Allocator allocator_;
    T* data_;
    std::size_t size_;
};

int main() {
    setlocale(LC_ALL, "es-Es.utf8");
    allocator<int> alloc;

    // Crear un objeto de MyVector usando el constructor explícito con allocator
    MyVector<int> vec(alloc);

    return 0;
}
