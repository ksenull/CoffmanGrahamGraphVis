#pragma once

#include <iostream>
#include <vector>

#include <NamedType.h>

using namespace std;

struct VertexParameter {};
struct EdgesParameter {};
struct GraphParameter {};

using Vertex = NamedType<int, VertexParameter>;
using Edges = NamedType<vector<Vertex>, EdgesParameter>;
using Graph = NamedType<vector<Edges>, GraphParameter>;

void PrintGraph(const Graph& g);
