// author: Danila "akshin_" Axyonov

#include "../include/intTree.hpp"

#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>

namespace algoses {
namespace lab2 {



void intTree::build(const std::vector<int>& original_data) {
    clear();

    auto data = original_data;
    std::sort(data.begin(), data.end());
    auto last = std::unique(data.begin(), data.end());
    auto n = (int)(last - data.begin());

    if (n > 0)
        build(data, 0, n, &root);
}

void intTree::build(const std::vector<int>& data, int l, int r, intNode** pnode) {
    auto m = (l + r) / 2;
    *pnode = new intNode(data[m]);

    if (l < m)
        build(data, l, m, &((*pnode)->left));
    if (m + 1 < r)
        build(data, m + 1, r, &((*pnode)->right));
}

bool intTree::add(int key) {
    return add(key, &root);
}

bool intTree::add(int key, intNode** pnode) {
    if (*pnode == nullptr) {
        *pnode = new intNode(key);
        return true;
    }
    if ((*pnode)->key == key)
        return false;
    return add(key, key < (*pnode)->key ? &((*pnode)->left) : &((*pnode)->right));
}

std::vector<int> intTree::get_keys() const {
    std::vector<int> keys;
    get_keys(keys, root);
    return keys;
}

void intTree::get_keys(std::vector<int>& keys, intNode* node) const {
    if (node == nullptr)
        return;

    get_keys(keys, node->left);
    keys.push_back(node->key);
    get_keys(keys, node->right);
}

bool intTree::remove(int key) {
    auto t = find(key, root, nullptr, 0);
    auto node = std::get<0>(t),
         p    = std::get<1>(t);
    if (node == nullptr)
        return false;

    if (node->left == nullptr or node->right == nullptr)
        (p != nullptr ? (node == p->left ? p->left : p->right) : root) = (node->left != nullptr ? node->left : node->right);
    else {
        auto max_node = node->left,
             max_p    = node;
        while (max_node->right != nullptr) {
            max_p = max_node;
            max_node = max_node->right;
        }

        (max_node == max_p->left ? max_p->left : max_p->right) = nullptr;
        (p != nullptr ? (node == p->left ? p->left : p->right) : root) = max_node;
        max_node->left = node->left;
        max_node->right = node->right;
    }
    delete node;
    return true;
}

void intTree::clear() {
    clear(root);
    root = nullptr;
}

void intTree::clear(intNode* node) {
    if (node == nullptr)
        return;

    clear(node->left);
    clear(node->right);
    delete node;
}

intNode* intTree::find(int key) const {
    return std::get<0>(find(key, root, nullptr, 0));
}

std::tuple<intNode*, intNode*, int> intTree::find(int key, intNode* node, intNode* p, int h) const {
    if (node == nullptr)
        return std::make_tuple(nullptr, nullptr, LEVEL_NOT_FOUND);
    if (node->key == key)
        return std::make_tuple(node, p, h);
    return find(key, key < node->key ? node->left : node->right, node, h + 1);
}

std::vector<int> intTree::find_range(int l, int r) const {
    std::vector<int> keys;
    find_range(l, r, keys, root);
    return keys;
}

void intTree::find_range(int l, int r, std::vector<int>& keys, intNode* node) const {
    if (node == nullptr)
        return;

    if (l <= node->key - 1)
        find_range(l, r, keys, node->left);
    if (l <= node->key and node->key < r)
        keys.push_back(node->key);
    if (node->key + 1 < r)
        find_range(l, r, keys, node->right);
}

int intTree::level(int key) const {
    return std::get<2>(find(key, root, nullptr, 0));
}

std::pair<int, double> intTree::max_avg_level() const {
    int cnt = 0,
        sum = 0,
        max = std::numeric_limits<int>::min();
    max_avg_level(cnt, sum, max, root, 0);
    return cnt > 0
         ? std::make_pair(max, (double)sum / (double)cnt)
         : std::make_pair(TREE_EMPTY, 0.);
}

void intTree::max_avg_level(int& cnt, int& sum, int& max, intNode* node, int h) const {
    if (node == nullptr)
        return;

    ++cnt;
    sum += h;
    max = std::max(max, h);

    max_avg_level(cnt, sum, max, node->left, h + 1);
    max_avg_level(cnt, sum, max, node->right, h + 1);
}



}}
