<<<<<<< HEAD
#ifndef COMMON_H
#define COMMON_H

#endif // COMMON_H

#include <algorithm>

template<typename Type> Type* resize(Type* arr, int oldSize, int newSize) {
    Type* temp = new Type[std::min(oldSize, newSize)];
    for (int i = 0; i < std::min(oldSize, newSize); i++)
        temp[i] = arr[i];
    delete[] arr;
    arr = new Type[newSize];
    for (int i = 0; i < std::min(oldSize, newSize); i++)
        arr[i] = temp[i];
    delete[] temp;
    return arr;
}
=======
#ifndef COMMON_H
#define COMMON_H

#endif // COMMON_H

#include <algorithm>

template<typename Type> Type* resize(Type* arr, int oldSize, int newSize) {
    Type* temp = new Type[std::min(oldSize, newSize)];
    for (int i = 0; i < std::min(oldSize, newSize); i++)
        temp[i] = arr[i];
    delete[] arr;
    arr = new Type[newSize];
    for (int i = 0; i < std::min(oldSize, newSize); i++)
        arr[i] = temp[i];
    delete[] temp;
    return arr;
}
>>>>>>> 584cbfa (Добавил бинарники)
