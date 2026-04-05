// author: Danila "akshin_" Axyonov

#ifndef INTNODE__HPP
#define INTNODE__HPP

namespace algoses {
namespace lab2 {



class intNode
{
public:
    int key;
    intNode* left;
    intNode* right;

    explicit intNode(int key = 0) : key(key), left(nullptr), right(nullptr) {}
    intNode(int key, intNode* left, intNode* right) : key(key), left(left), right(right) {}
};



}}

#endif
