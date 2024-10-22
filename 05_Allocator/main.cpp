#include <iostream>
#include <vector>
#include <memory>
using std::allocator;
using std::cout;
using std::endl;

template <class T, class Allocator = allocator<T>>
class MyVector {
public:
    // Constructor explícito con tamaño, valor y asignador
    constexpr MyVector(std::size_t count, const T& value, const Allocator& alloc = Allocator()) noexcept
        : allocator_(alloc), data_(nullptr), size_(0) {
        std::cout << "Constructor con tamaño, valor y Allocator llamado" << endl;
        // Asignar memoria para 'count' elementos
        data_ = allocator_.allocate(count);
        size_ = count;

        // Inicializar todos los elementos con 'value'
        std::uninitialized_fill_n(data_, count, value);
    }

    ~MyVector() {
        // Destruir los elementos
        if (data_ != nullptr) {
            for (std::size_t i = 0; i < size_; ++i) {
                data_[i].~T();
            }
            // Liberar memoria
            allocator_.deallocate(data_, size_);
        }
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
    int value = 42;

    // Crear un objeto de MyVector con tamaño, valor y asignador
    MyVector<int> vec(10, value, alloc);

    return 0;
}
