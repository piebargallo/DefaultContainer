#include <iostream>
#include <vector>
#include <memory>
using std::allocator;
using std::cout;
using std::endl;

template <class T, class Allocator = allocator<T>>
class MyVector {
public:
    // Constructor explícito con tamaño y asignador
    constexpr explicit MyVector(std::size_t count, const Allocator& alloc = Allocator()) noexcept
        : allocator_(alloc), data_(nullptr), size_(0) {
        cout << "Constructor explícito llamado con tamaño y Allocator" << endl;
        // Asignar memoria para 'count' elementos
        data_ = allocator_.allocate(count);
        size_ = count;
    }

    ~MyVector() {
        // Liberar memoria
        if (data_ != nullptr) {
            allocator_.deallocate(data_, size_);
        }
    }

    // Otros métodos del vector...

private:
    Allocator allocator_;
    T* data_;
    std::size_t size_;
};

int main() 
{
    setlocale(LC_ALL, "es-Es.utf8");
    allocator<int> alloc;

    // Crear un objeto de MyVector con tamaño y asignador
    MyVector<int> vec(10, alloc);

    return 0;
}
