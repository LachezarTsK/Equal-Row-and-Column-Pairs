
#include <vector>
using namespace std;

class Trie {

    struct Node {
        unordered_map<int, shared_ptr<Node>> mapValueToNode;
        int frequencyOfValue = 0;
    };

    shared_ptr<Node> root{make_shared<Node>()};

public:
    void addToTrie(const vector<int>& input) const {
        shared_ptr<Node> current = root;
        for (int i = 0; i < input.size(); ++i) {
            if (current->mapValueToNode.find(input[i]) == current->mapValueToNode.end()) {
                current->mapValueToNode[input[i]] = make_shared<Node>();
            }
            current = current->mapValueToNode[input[i]];
        }
        ++current->frequencyOfValue;
    }

    int frequencyInTrie(const vector<int>& input) const {
        shared_ptr<Node> current = root;
        for (int i = 0; i < input.size(); ++i) {
            if (current->mapValueToNode.find(input[i]) == current->mapValueToNode.end()) {
                return 0;
            }
            current = current->mapValueToNode[input[i]];
        }
        return current->frequencyOfValue;
    }
};

class Solution {
    
public:
    int equalPairs(const vector<vector<int>>& grid) const {
        Trie trie;
        for (const auto& row : grid) {
            trie.addToTrie(row);
        }

        int countMatchesBetweenRowsAndColumns = 0;

        for (int c = 0; c < grid[0].size(); ++c) {
            vector<int> temp(grid.size());
            for (int r = 0; r < grid.size(); ++r) {
                temp[r] = grid[r][c];
            }
            countMatchesBetweenRowsAndColumns += trie.frequencyInTrie(temp);
        }
        return countMatchesBetweenRowsAndColumns;
    }
};
