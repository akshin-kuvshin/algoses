// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>

#include "../include/intTree.hpp"
using namespace algoses::lab2;

int main() {
    std::vector<int> data = {9, 0, 1, 4, 5, -7, 12, -100, -101, 1, 2, 0, 1, 5};
    int data_size = (int)data.size();
    std::cout << "data = [" << data[0];
    for (int i = 1; i < data_size; ++i)
        std::cout << ' ' << data[i];
    std::cout << ']' << std::endl;

    auto tree = new intTree;
    tree->build(data);

    auto keys = tree->get_keys();
    int keys_size = (int)keys.size();
    std::cout << "keys = [" << keys[0];
    for (int i = 1; i < keys_size; ++i)
        std::cout << ' ' << keys[i];
    std::cout << ']' << std::endl;

    delete tree;
    return 0;
}
