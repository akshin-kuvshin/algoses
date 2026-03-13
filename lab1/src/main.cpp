// author: Danila "akshin_" Axyonov

#include "../include/Sort.hpp"
#include "../include/ContestParticipant.hpp"
using namespace algoses::lab1;

#include <iostream>
#include <cstdlib>

void print_cp_table(const ContestParticipant* const* participants, int size);

int main()
{
    srand(time(nullptr));

    const int BIG_N = 34;

    int n;
    std::cout << "n = ";
    std::cin >> n;

    int*** a = new int**[3];
    for (int i = 0; i < 3; ++i) {
        a[i] = new int*[n];
        for (int j = 0; j < n; ++j)
            a[i][j] = new int;
    }
    for (int i = 0; i < n; ++i)
        *a[0][i] = *a[1][i] = *a[2][i] = ContestParticipant::randint(-n, n);
    if (n < BIG_N) {
        for (int i = 0; i < n; ++i)
            std::cout << *a[0][i] << ' ';
        std::cout << std::endl;
    }

    std::cout << "insert sort: " << Sort<int>::insert_sort(a[0], n) << " comps";
    if (n < BIG_N) {
        std::cout << " | ";
        for (int i = 0; i < n; ++i)
            std::cout << *a[0][i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "shell sort: " << Sort<int>::shell_sort(a[1], n) << " comps";
    if (n < BIG_N) {
        std::cout << " | ";
        for (int i = 0; i < n; ++i)
            std::cout << *a[1][i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "merge sort: " << Sort<int>::merge_sort(a[2], n) << " comps";
    if (n < BIG_N) {
        std::cout << " | ";
        for (int i = 0; i < n; ++i)
            std::cout << *a[2][i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

void print_cp_table(const ContestParticipant* const* participants, int size)
{
    ContestParticipant::print_header();
    for (int i = 0; i < size; ++i)
        std::cout << *participants[i];
    ContestParticipant::print_footer();
}
