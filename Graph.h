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

//using Vertex = int;
//using Edges = vector<Vertex>;
//using Graph = vector<Edges>;

void PrintGraph(const Graph& g);
