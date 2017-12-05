#include <string>
#include <iostream>
#include <cmath>

// Calculates what layer the input is on
int calcLayer (int n) {
    return std::ceil((std::sqrt(n)-1)/2)+1;
}

// Calculates the largest value in the layer
int calcLayerEnd (int layer) {
    return (1+2*(layer-1))*(1+2*(layer-1));
}

// Calculates what offset a number occupies within a layer
int calcLayerOffset (int layer, int n) {
    return n - calcLayerEnd(layer-1);
}

// Calculates the maximum distance required to reach the center from a layer
int calcMaxDist (int layer) {
    return std::sqrt(calcLayerEnd(layer)) - 1;
}

// Calculates the manhattan distance given an offset within a layer and the maximum distance for that layer
int calcManhattan (int offset, int dist) {
    return dist/2 + std::abs(dist/2 - ((offset)%dist));
}

int main() {
	int input = 347991;

    int layer = calcLayer(input);
    int offset = calcLayerOffset(layer, input);
    int max_dist = calcMaxDist(layer);
    int manhattan = calcManhattan(offset, max_dist);
    
    // Print the result
    printf("Layer: %d\nOffset: %d\nMax Dist: %d\nManhattan: %d\n", layer, offset, max_dist, manhattan);
