#include "dijkstra.h"

#include <limits>

namespace dijkstra {

std::vector<Edge> findWay(const std::vector<std::vector<int>>& W) {
    const auto n{W.size() - 1};  // Number of vertices left

    std::vector<Edge> F;  // The set of egdes reflecting the shortest way from the source (v1) to to all other nodes in the graph
    F.reserve(n);         // We need ways from v1 vertice to all other

    std::vector<int> touch(n, 0);  // v1 (pos = 0) is the last vertice in the current shortest way
    std::vector<int> length;       // The current shortest way length, that include only vertices belonging to the Y46trt
    length.reserve(n);

    for (int i = 0; i < n; i++) {
        length.push_back(W[0][i + 1]);  // Assigning lengths as if the way from v1 to vi was the shortest one
    }

    for (int i = 0; i < n; i++) {
        auto min{std::numeric_limits<int>::max()};
        int vnear{-1};
        for (int j = 0; j < n; j++) {
            if (0 <= length.at(j) && length[j] < min) {
                min = length[j];
                vnear = j;
            }
        }

        Edge egde{touch[vnear], vnear + 1};
        F.push_back(egde);

        for (int j = 0; j < n; j++) {
            if (length[j] > 0) {                             // check if the j-th vertice is not already used
                const auto newPath{W[vnear + 1][j + 1]};     //
                if (newPath != 0) {                          // checking if new path even exists
                    const auto p1{length[vnear] + newPath};  // Path through new vertice
                    const auto p2{length[j]};                // Current shortest path

                    if (p1 < p2) {
                        length[j] = p1;
                        touch[j] = vnear + 1;
                    }

                    length[vnear] = -1;  // Set the vnear-th vertice as used
                }
            }
        }
    }

    return F;
}

}  // namespace dijkstra