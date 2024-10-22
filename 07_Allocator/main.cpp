#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
using namespace std;

template <typename T, typename Allocator = allocator<T>>
class MyVector {
public:
    // Constructor con iteradores y asignador
    template <class InputIt>
    constexpr MyVector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) noexcept
        : allocator_(alloc), data_(nullptr), size_(0) {
        cout << "Constructor con iteradores y Allocator llamado" << endl;;

        // Calcular la distancia entre los iteradores
        size_ = std::distance(first, last);

        // Asignar memoria para los elementos
        data_ = allocator_.allocate(size_);

        // Inicializar los elementos copiando desde el rango [first, last)
        std::uninitialized_copy(first, last, data_);
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
    vector<int> source{ 1, 2, 3, 4, 5 };

    // Crear un objeto de MyVector con un rango de elementos de 'source'
    MyVector<int> vec(source.begin(), source.end());

    return 0;
}
