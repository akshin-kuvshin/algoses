// author: Danila "akshin_" Axyonov

#ifndef SORT__HPP
#define SORT__HPP

#include <stdexcept>

namespace algoses {
namespace lab1 {



template <typename T>
class Sort
{
private:
    static int sedgewick(int i);

public:
    Sort() = delete;

    static int insert_sort(T** data, int size);
    static int shell_sort(T** data, int size);
    static int merge_sort(T** data, int size);

    static bool is_sorted(const T** data, int size);
};





template <typename T>
int Sort<T>::sedgewick(int i)
{
    if (i < 0)
        throw std::domain_error("[ERROR]: i in sedgewick(int i) must be non-negative.");
    if (i % 2 == 0)
        return 9 * (1 << i) - 9 * (1 << (i / 2)) + 1;
    return 8 * (1 << i) - 6 * (1 << ((i + 1) / 2)) + 1;
}

template <typename T>
int Sort<T>::insert_sort(T** data, int size)
{
    int global_comps = 0;
    for (int i = 1; i < size; ++i) {
        int local_comps = 1;
        for (int j = i; j - 1 >= 0 and *data[j - 1] > *data[j]; --j, ++local_comps)
            std::swap(data[j - 1], data[j]);
        global_comps += local_comps;
    }
    return global_comps;
}

template <typename T>
int Sort<T>::shell_sort(T** data, int size)
{
    int i_max = 0;
    while (3 * sedgewick(++i_max) <= size);
    --i_max;

    int global_comps = 0;
    for (int i = i_max; i >= 0; --i) {
        int step = sedgewick(i);
        for (int j = step; j < size; ++j) {
            int local_comps = 1;
            for (int k = j; k - step >= 0 and *data[k - step] > *data[k]; k -= step, ++local_comps)
                std::swap(data[k - step], data[k]);
            global_comps += local_comps;
        }
    }
    return global_comps;
}

template <typename T>
int Sort<T>::merge_sort(T** data, int size)
{
    if (size == 1)
        return 0;

    int global_comps = 0,
        half_size = size / 2;
    global_comps += merge_sort(data, half_size);
    global_comps += merge_sort(data + half_size, size - half_size);

    T** sorted_data = new T*[size];
    int i = 0,
        i_max = half_size,
        j = half_size,
        j_max = size,
        top = 0;
    while (i < i_max and j < j_max) {
        if (*data[i] <= *data[j])
            sorted_data[top++] = data[i++];
        else
            sorted_data[top++] = data[j++];
        ++global_comps;
    }
    while (i < i_max)
        sorted_data[top++] = data[i++];
    while (j < j_max)
        sorted_data[top++] = data[j++];

    for (int k = 0; k < size; ++k)
        data[k] = sorted_data[k];

    return global_comps;
}

template <typename T>
bool Sort<T>::is_sorted(const T** data, int size)
{
    for (int i = 0; i + 1 < size; ++i)
        if (*data[i] > *data[i + 1])
            return false;
    return true;
}



}}

#endif
