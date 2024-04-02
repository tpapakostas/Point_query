#include <iostream>
#include <vector>
#include <random>


struct vector3 {
    float x, y, z;
};

struct bim_point {
    int id;
    vector3 pos;
};

struct edge {
    bim_point p0;
    bim_point p1;
    float dist;
};

float euclidean(bim_point pa, bim_point pb) {
    return  sqrt(pow(pa.pos.x-pb.pos.x,2) + pow(pa.pos.y-pb.pos.y,2) + pow(pa.pos.z-pb.pos.z, 2));
}


float find_vertex(const std::vector<edge>& Edges, float target_dist) {

    // Sort the vector of edges based on dist value

    std::vector<edge> sorted_distances = Edges;
    std::sort(sorted_distances.begin(), sorted_distances.end(), [](const edge& a, const edge& b) {
        return a.dist < b.dist;
        });

    // Perform binary search to find the lower bound of the target dist value
    auto it = std::lower_bound(sorted_distances.begin(), sorted_distances.end(), target_dist,
        [](const edge& a, float target) { return a.dist < target; });

    // If iterator is valid and points to the target z-value, return its corresponding x-value
    if (it != sorted_distances.end() && it->dist == target_dist) {
        return it->p0;
    }
    else {
        // Return some default value to indicate that the target z-value was not found
        return std::numeric_limits<double>::quiet_NaN(); // Not-a-Number
    }
}


std::vector<bim_point> bimPoints;
std::vector<float> InputDistances;

int main() {

    //srand(time(0));
    for (int i = 0; i < 5; i++) {
        bim_point bp;
        bp.id = i;
        bp.pos.x = rand();
        bp.pos.y = rand();
        bp.pos.z = rand();

        bimPoints.push_back(bp); 
    }

    std::vector<edge> edges;

    for (int i = 0; i < bimPoints.size(); i++) {
        for (int j = i + 1; j < bimPoints.size(); j++) {
            float dist;
            dist = euclidean(bimPoints[i], bimPoints[j]);
            edge a;
            a = { bimPoints[i],bimPoints[j],dist };
            edges.push_back(a);
        }
    }

    //input
    InputDistances.push_back(21348.7);
    InputDistances.push_back(18431.1);
    InputDistances.push_back(7004.22);
    
    //sort edges based on distances

    std::sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
        return a.dist < b.dist;
        });

    
    


    

    //std::cout << bimPoints.size() << "\n";
    //std::cout << edges.size() << "\n";
    //std::cout << bimPoints[0].pos.x << "\n";
    //std::cout << bimPoints[1].pos.x << "\n";

    
  
}

