// author: Danila "akshin_" Axyonov

#include "../include/graph.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

int main() {
    srand(time(nullptr));

    int n,
        k;
    std::cout << "n = ";
    std::cin >> n;
    assert(n > 0 and "(n) must be positive integer");
    std::cout << "k = ";
    std::cin >> k;
    assert(k > 0 and "(k) must be positive integer");
    assert(k <= n and "(k) can't be greater than (n)");

    auto points = algoses::lab3::generate_points(n);

    auto d_sqr = algoses::lab3::calculate_d_sqr(points, n);

    auto MST = algoses::lab3::build_MST(d_sqr, n);
    std::sort(MST.begin(), MST.end(), [&d_sqr](rib r1, rib r2) {
        return d_sqr[r1.u][r1.v] < d_sqr[r2.u][r2.v];
    });

    std::vector<rib> ribs;
    std::copy(MST.begin(), MST.begin() + (n - k), std::back_inserter(ribs));

    auto G = algoses::lab3::build_graph(ribs, n);

    auto components = algoses::lab3::identify_components(G, n, k);



    char cmd;
    std::cout << algoses::lab3::LONG_LINE << std::endl
              << "Print points coordinates? [y/n]" << std::endl
              << "> ";
    std::cin >> cmd;
    if (cmd == 'y') {
        std::cout << algoses::lab3::SHORT_LINE << std::endl;
        for (int i = 0; i < n; ++i)
            std::cout << i << ": (" << points[i].x << ", " << points[i].y << ')' << std::endl;
    }

    std::cout << algoses::lab3::LONG_LINE << std::endl
              << "Print (d_sqr) matrix? [y/n]" << std::endl
              << "> ";
    std::cin >> cmd;
    if (cmd == 'y') {
        std::cout << algoses::lab3::SHORT_LINE << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                std::cout << d_sqr[i][j] << ' ';
            std::cout << std::endl;
        }
    }

    std::cout << algoses::lab3::LONG_LINE << std::endl
              << "Print components structure (points)? [y/n]" << std::endl
              << "> ";
    std::cin >> cmd;
    if (cmd == 'y')
        for (int i = 0; i < k; ++i) {
            std::cout << algoses::lab3::SHORT_LINE << std::endl
                      << "Component #" << i << std::endl;
            for (int j : components[i])
                std::cout << j << ": (" << points[j].x << ", " << points[j].y << ')' << std::endl;
        }

    std::cout << algoses::lab3::LONG_LINE << std::endl
              << "Print short info about components? [y/n]" << std::endl
              << "> ";
    std::cin >> cmd;
    if (cmd == 'y')
        for (int i = 0; i < k; ++i) {
            std::cout << algoses::lab3::SHORT_LINE << std::endl
                      << "Component #" << i << std::endl;
            auto short_info = algoses::lab3::get_component_short_info(points, components[i]);
            auto [
                component_size,
                min_x,
                max_x,
                min_y,
                max_y,
                centroid_x,
                centroid_y
            ] = short_info;
            std::cout << "Component size = " << component_size << std::endl
                      << "min_x = " << min_x << " | max_x = " << max_x << std::endl
                      << "min_y = " << min_y << " | max_y = " << max_y << std::endl
                      << "centroid_x = " << centroid_x << std::endl
                      << "centroid_y = " << centroid_y << std::endl;
        }



    return 0;
}
