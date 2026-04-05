// author: Danila "akshin_" Axyonov

#ifndef INTTREE__HPP
#define INTTREE__HPP

#include "intNode.hpp"

#include <vector>
#include <tuple>

#define LEVEL_NOT_FOUND -1
#define TREE_EMPTY      -2

namespace algoses {
namespace lab2 {



class intTree
{
private:
    intNode* root;

    void build(const std::vector<int>& data, int l, int r, intNode** pnode);
    bool add(int key, intNode** pnode);
    void get_keys(std::vector<int>& keys, intNode* node) const;
    void clear(intNode* node);
    std::tuple<intNode*, intNode*, int> find(int key, intNode* node, intNode* p, int h) const;
    void find_range(int l, int r, std::vector<int>& keys, intNode* node) const;
    void max_avg_level(int& cnt, int& sum, int& max, intNode* node, int h) const;

public:
    intTree(intNode* root = nullptr) : root(root) {}
    void build(const std::vector<int>& original_data);
    bool add(int key);
    std::vector<int> get_keys() const;
    bool remove(int key);
    void clear();
    intNode* find(int key) const;
    std::vector<int> find_range(int l, int r) const;
    int level(int key) const;
    std::pair<int, double> max_avg_level() const;
};



}}

#endif
