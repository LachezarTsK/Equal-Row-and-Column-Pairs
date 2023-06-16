
import java.util.Map;
import java.util.HashMap;

public class Solution {

    public int equalPairs(int[][] grid) {
        Trie trie = new Trie();
        for (int[] row : grid) {
            trie.addToTrie(row);
        }

        int countMatchesBetweenRowsAndColumns = 0;

        for (int c = 0; c < grid[0].length; ++c) {
            int[] temp = new int[grid.length];
            for (int r = 0; r < grid.length; ++r) {
                temp[r] = grid[r][c];
            }
            countMatchesBetweenRowsAndColumns += trie.frequencyInTrie(temp);
        }
        return countMatchesBetweenRowsAndColumns;
    }
}

class Trie {

    private final Node root = new Node();

    private class Node {

        Map<Integer, Node> mapValueToNode = new HashMap<>();
        int frequencyOfValue;
    }

    void addToTrie(int[] input) {
        Node current = root;
        for (int i = 0; i < input.length; ++i) {
            if (!current.mapValueToNode.containsKey(input[i])) {
                current.mapValueToNode.put(input[i], new Node());
            }
            current = current.mapValueToNode.get(input[i]);
        }
        ++current.frequencyOfValue;
    }

    int frequencyInTrie(int[] input) {
        Node current = root;
        for (int i = 0; i < input.length; ++i) {
            if (!current.mapValueToNode.containsKey(input[i])) {
                return 0;
            }
            current = current.mapValueToNode.get(input[i]);
        }
        return current.frequencyOfValue;
    }
}
