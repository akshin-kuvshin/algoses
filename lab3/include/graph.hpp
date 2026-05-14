// author: Danila "akshin_" Axyonov

#ifndef GRAPH__HPP
#define GRAPH__HPP

#include <string>
#include <vector>
#include <tuple>

typedef long long int lli;

struct point {
    int x;
    int y;
};

struct rib {
    int u;
    int v;

    rib() : u(-1), v(-1) {}
    rib(int __u, int __v) : u(__u), v(__v) {}
};

struct wrib {
    int u;
    int v;
    lli w;

    wrib() : u(-1), v(-1), w(0LL) {}
    wrib(int __u, int __v, lli __w) : u(__u), v(__v), w(__w) {}

    bool operator<(const wrib& wr) const {
        return w > wr.w;
    }
};

namespace algoses {
namespace lab3 {



const std::string LONG_LINE = "--------------------------------------------------",
                  SHORT_LINE = "-------------------------";

std::vector<point> generate_points(int n);
std::vector<std::vector<lli>> calculate_d_sqr(const std::vector<point>& points, int n);
std::vector<rib> build_MST(const std::vector<std::vector<lli>>& d_sqr, int n);
std::vector<std::vector<int>> build_graph(const std::vector<rib>& ribs, int n);
std::vector<std::vector<int>> identify_components(const std::vector<std::vector<int>>& G, int n, int k);
std::tuple<int, int, int, int, int, double, double> get_component_short_info
    (const std::vector<point>& points, const std::vector<int>& cc);



}}

#endif
