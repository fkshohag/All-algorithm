#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a data structure to hold a cluster of sequences
struct Cluster {
    int id;                  // Cluster ID
    vector<string> sequences;   // String sequences in the cluster
    double height;           // Height of the cluster (used for tree visualization)
};

// Function to calculate the average distance between two clusters
double averageDistance(const vector<vector<double>>& distMatrix, const Cluster& cluster1, const Cluster& cluster2) {
    double totalDist = 0.0;
    for (const string& seq1 : cluster1.sequences) {
        for (const string& seq2 : cluster2.sequences) {
            // Replace this with your custom distance calculation function
            // For string sequences, you may consider using methods like Hamming distance or Levenshtein distance.
            // For simplicity, we'll assume equal distance for this example.
            totalDist += 1.0;
        }
    }
    int numPairs = cluster1.sequences.size() * cluster2.sequences.size();
    return totalDist / numPairs;
}

// Function to perform UPGMA clustering
vector<Cluster> upgma(vector<vector<double>>& distMatrix, const vector<string>& sequences) {
    int n = distMatrix.size();

    // Initialize clusters (each sequence is initially a cluster)
    vector<Cluster> clusters(n);
    for (int i = 0; i < n; ++i) {
        clusters[i].id = i;
        clusters[i].sequences = {sequences[i]};
        clusters[i].height = 0.0;
    }

    // UPGMA iterations
    while (clusters.size() > 1) {
        // Find the two closest clusters
        double minDist = numeric_limits<double>::max();
        int cluster1Idx, cluster2Idx;
        for (int i = 0; i < clusters.size(); ++i) {
            for (int j = i + 1; j < clusters.size(); ++j) {
                double dist = averageDistance(distMatrix, clusters[i], clusters[j]);
                if (dist < minDist) {
                    minDist = dist;
                    cluster1Idx = i;
                    cluster2Idx = j;
                }
            }
        }

        // Merge the two closest clusters
        Cluster mergedCluster;
        mergedCluster.id = n; // New ID for the merged cluster
        mergedCluster.sequences = clusters[cluster1Idx].sequences;
        mergedCluster.sequences.insert(mergedCluster.sequences.end(),
            clusters[cluster2Idx].sequences.begin(), clusters[cluster2Idx].sequences.end());
        mergedCluster.height = minDist / 2.0;

        // Update the distance matrix after merging
        vector<vector<double>> newDistMatrix(n - 1, vector<double>(n - 1, 0.0));
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (i != cluster1Idx && i != cluster2Idx) {
                int l = 0;
                for (int j = 0; j < n; ++j) {
                    if (j != cluster1Idx && j != cluster2Idx) {
                        if (i == j) {
                            newDistMatrix[k][l] = 0.0;
                        } else {
                            double dist = 0.0;
                            if (i < j) {
                                dist = averageDistance(distMatrix, clusters[i], clusters[j]);
                            } else {
                                dist = distMatrix[j][i];
                            }
                            newDistMatrix[k][l] = dist;
                        }
                        l++;
                    }
                }
                k++;
            }
        }

        // Update the clusters vector
        clusters.push_back(mergedCluster);
        clusters.erase(clusters.begin() + max(cluster1Idx, cluster2Idx));
        clusters.erase(clusters.begin() + min(cluster1Idx, cluster2Idx));
        n--;

        distMatrix = newDistMatrix;
    }

    return clusters;
}

// Function to display the final distance matrix
void displayDistanceMatrix(const vector<vector<double>>& distMatrix) {
    cout << "Final Distance Matrix:" << endl;
    for (const auto& row : distMatrix) {
        for (const double dist : row) {
            cout << dist << "\t";
        }
        cout << endl;
    }
}

// Function to display the phylogenetic tree in a tabular format
void displayTree(const vector<Cluster>& phylogeneticTree) {
    cout << "ID\tSequences\tHeight" << endl;
    for (const Cluster& cluster : phylogeneticTree) {
        cout << cluster.id << "\t";
        for (const string& seq : cluster.sequences) {
            cout << seq << " ";
        }
        cout << "\t" << cluster.height << endl;
    }
}

int main() {
    // Example string sequences of length 12
    vector<string> sequences = {
        "ATCGTGGTACTG",
        "ATGGTGAAAGTG",
        "CCGGAAAACTTG",
        "CCGGAGAACTAG",
        "TGGCCCTGTATC",
        "AACGTGCTACTG"
    };

    // Example distance matrix (replace this with your actual distance matrix)
    vector<vector<double>> distanceMatrix = {
        {0, 0.2, 0.5, 0.8, 0.6, 0.3},
        {0.2, 0, 0.4, 0.7, 0.5, 0.2},
        {0.5, 0.4, 0, 0.3, 0.1, 0.4},
        {0.8, 0.7, 0.3, 0, 0.9, 0.6},
        {0.6, 0.5, 0.1, 0.9, 0, 0.7},
        {0.3, 0.2, 0.4, 0.6, 0.7, 0}
    };

    vector<Cluster> phylogeneticTree = upgma(distanceMatrix, sequences);

    // Display the final distance matrix
    displayDistanceMatrix(distanceMatrix);

    // Display the tree
    displayTree(phylogeneticTree);

    return 0;
}
