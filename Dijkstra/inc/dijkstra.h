#pragma once

#include <vector>

namespace dijkstra {

typedef std::pair<int, int> Edge;

std::vector<Edge> findWay(const std::vector<std::vector<int>>& W);

}  // namespace dijkstra