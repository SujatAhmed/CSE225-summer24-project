// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "Database.h"
#include <matplot/matplot.h>
#include "matplot/axes_objects/histogram.h"
#include <algorithm>

class Graph {
public:
    static void heightDistribution(Database *d);
    static void weightDistribution(Database *d);
};

#endif // GRAPH_H

