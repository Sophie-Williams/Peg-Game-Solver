// 8puzzle.h

#ifndef _8PUZZLE_H
#define _8PUZZLE_H

#include <array>
#include <vector>
#include <iostream>
#include <functional>
#include <stack>
#include <set>

//enum class Move { l, r, lu, ru, ld, rd };
using State = std::array<std::array<int,5>,5>;

using Vertex = State;
using Path = std::vector<Vertex>;

class Graph
{
public:
    typename std::vector<Vertex>::const_iterator cbegin(Vertex v) const;
    typename std::vector<Vertex>::const_iterator cend() const;
private:
    mutable std::vector<Vertex> adjacents;
};

class Point {
public:
    int x, y;
    Point (int,int);
    Point();
};

Point::Point (int a, int b) {
    x = a;
    y = b;
}

Point::Point() {

}

class Move {
public:
    Move (Point,Point,Point);
    Point current, middle, target;
};

Move::Move (Point a, Point b, Point c) {
    current = a;
    middle = b;
    target = c;
}

std::ostream &operator<<(std::ostream &os, const Vertex &state);

Vertex doMove(const Vertex &v, const Move &m);
Path dfs(const Graph &graph, const Vertex &start, std::function<bool(const Vertex &vertex)> goalTest);
Path bfs(const Graph &graph, const Vertex &start, std::function<bool(const Vertex &vertex)> goalTest);
std::vector<Move> getMoves(const Vertex &v, int x, int y);
int checkPoint(const Vertex &v, int x, int y);
bool checkBoard(const Vertex &v);

#endif // _8PUZZLE_H