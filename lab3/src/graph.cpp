// author: Danila "akshin_" Axyonov

#include "../include/graph.hpp"

#include <vector>
#include <tuple>
#include <queue>
#include <cstdlib>

namespace algoses {
namespace lab3 {



std::vector<point> generate_points(int n) {
    const static auto HALF_RAND_MAX = RAND_MAX / 2 + RAND_MAX % 2;

    std::vector<point> points(n);
    for (auto& p : points) {
        p.x = rand() - HALF_RAND_MAX;
        p.y = rand() - HALF_RAND_MAX;
    }
    return points;
}

std::vector<std::vector<lli>> calculate_d_sqr(const std::vector<point>& points, int n) {
    std::vector<std::vector<lli>> d_sqr(n, std::vector<lli>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j) {
            int dx = points[i].x - points[j].x,
                dy = points[i].y - points[j].y;
            d_sqr[i][j] = d_sqr[j][i] = 1LL * dx * dx + 1LL * dy * dy;
        }
    return d_sqr;
}

std::vector<rib> build_MST(const std::vector<std::vector<lli>>& d_sqr, int n) {
    std::vector<rib> MST;

    std::vector<bool> used(n);
    std::priority_queue<wrib> q;

    used[0] = true;
    for (int i = 1; i < n; ++i)
        q.emplace(0, i, d_sqr[0][i]);

    while (not q.empty()) {
        auto wr = q.top();
        q.pop();

        if (used[wr.v])
            continue;
        used[wr.v] = true;

        MST.emplace_back(wr.u, wr.v);
        for (int i = 0; i < n; ++i) {
            if (used[i])
                continue;
            q.emplace(wr.v, i, d_sqr[wr.v][i]);
        }
    }

    return MST;
}

std::vector<std::vector<int>> build_graph(const std::vector<rib>& ribs, int n) {
    std::vector<std::vector<int>> G(n);
    for (auto r : ribs) {
        G[r.u].push_back(r.v);
        G[r.v].push_back(r.u);
    }
    return G;
}

std::vector<std::vector<int>> identify_components(const std::vector<std::vector<int>>& G, int n, int k) {
    std::vector<std::vector<int>> components(k);
    int top = 0;

    std::vector<bool> used(n);
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (used[i])
            continue;
        used[i] = true;
        q.push(i);

        while (not q.empty()) {
            int cur = q.front();
            q.pop();

            components[top].push_back(cur);
            for (int nb : G[cur]) {
                if (used[nb])
                    continue;
                used[nb] = true;
                q.push(nb);
            }
        }

        ++top;
    }

    return components;
}

std::tuple<int, int, int, int, int, double, double> get_component_short_info
(const std::vector<point>& points, const std::vector<int>& component) {
    int component_size = (int)component.size();
    int min_x = points[component[0]].x,
        max_x = points[component[0]].x,
        min_y = points[component[0]].y,
        max_y = points[component[0]].y;
    lli x_sum = 0LL,
        y_sum = 0LL;

    for (int i : component) {
        min_x = std::min(min_x, points[i].x);
        max_x = std::max(max_x, points[i].x);
        min_y = std::min(min_y, points[i].y);
        max_y = std::max(max_y, points[i].y);
        x_sum += points[i].x;
        y_sum += points[i].y;
    }

    return std::make_tuple(
        component_size,
        min_x,
        max_x,
        min_y,
        max_y,
        (double)x_sum / (double)component_size,
        (double)y_sum / (double)component_size
    );
}



}}
