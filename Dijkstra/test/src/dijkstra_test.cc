#include "dijkstra.h"

#include <gtest/gtest.h>

using dijkstra::Edge;

TEST(DijkstraTest, algorithm_ok) {
    std::vector<std::vector<int>> W(5, std::vector<int>(5, 0));

    W[0][0] = 0;
    W[0][1] = 7;
    W[0][2] = 4;
    W[0][3] = 6;
    W[0][4] = 1;
    W[1][0] = 0;
    W[1][1] = 0;
    W[1][2] = 0;
    W[1][3] = 0;
    W[1][4] = 0;
    W[2][0] = 0;
    W[2][1] = 2;
    W[2][2] = 0;
    W[2][3] = 5;
    W[2][4] = 0;
    W[3][0] = 0;
    W[3][1] = 3;
    W[3][2] = 0;
    W[3][3] = 0;
    W[3][4] = 0;
    W[4][0] = 0;
    W[4][1] = 0;
    W[4][2] = 0;
    W[4][3] = 1;
    W[4][4] = 0;

    auto result{dijkstra::findWay(W)};

    std::vector<Edge> expectedRes{Edge(0, 4), Edge(4, 3), Edge(0, 2), Edge(3, 1)};

    EXPECT_EQ(result, expectedRes);
}