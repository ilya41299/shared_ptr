#include <iostream>
#include <algorithm>
#include <cassert>

template <typename T>
class scoped_ptr {
private:
    T * ptr_;
public:
    scoped_ptr(); // конструктор сборка указателя
    scoped_ptr(T * ptr); // конструктор конкретного значения (указывает на конкретный объект)
    ~scoped_ptr();  // деструктор
    void reset(T * ptr); // функция переопределения значения
    T & operator *() const; // вернет конкретное значение содержащееся в памяти по данному указателю
    T * operator ->() const;
    T * get() const;  // возвращает указатель на данную область памяти
    void swap(scoped_ptr & other); // меняем указатели двух объектов
    scoped_ptr & operator=(scoped_ptr const &) = delete; // Конструкция delete запрещает компилятору использовать оператор присваивающего копирования.
    scoped_ptr(scoped_ptr const &) = delete;// Конструкция delete запрещает компилятору использовать оператор копирования.
};

template <typename T>
scoped_ptr<T>::scoped_ptr()
{
    ptr_ = nullptr;
}

template <typename T>
scoped_ptr<T>::scoped_ptr(T * ptr) {
    ptr_ = ptr;
}

template <typename T>
scoped_ptr<T>::~scoped_ptr() {
    if (ptr_) {
        delete ptr_;
    }
}
template <typename T>
void scoped_ptr<T>::reset(T * ptr) {
    if (ptr_) {
        delete ptr_;
    }
    ptr_ = ptr;
}

template <typename T>
T & scoped_ptr<T>::operator *() const {
    return *ptr_;
}

template <typename T>
T * scoped_ptr<T>::operator ->() const {
    return ptr_;
}

template <typename T>
T * scoped_ptr<T>::get() const {
    return ptr_;
}

template <typename T>
void scoped_ptr<T>::swap(scoped_ptr & other) {
    std::swap(ptr_, other.ptr_);
}
