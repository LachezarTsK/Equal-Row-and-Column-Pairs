

using System;
using System.Collections.Generic;

public class Solution
{
    public int EqualPairs(int[][] grid)
    {
        Trie trie = new Trie();
        foreach (var row in grid)
        {
            trie.addToTrie(row);
        }

        int countMatchesBetweenRowsAndColumns = 0;

        for (int c = 0; c < grid[0].Length; ++c)
        {
            int[] temp = new int[grid.Length];
            for (int r = 0; r < grid.Length; ++r)
            {
                temp[r] = grid[r][c];
            }
            countMatchesBetweenRowsAndColumns += trie.frequencyInTrie(temp);
        }
        return countMatchesBetweenRowsAndColumns;
    }
}


class Trie
{
    private readonly Node root = new Node();

    private class Node
    {
        public readonly Dictionary<int, Node> mapValueToNode = new Dictionary<int, Node>();
        public int frequencyOfValue;
    }

    public void addToTrie(int[] input)
    {
        Node current = root;
        for (int i = 0; i < input.Length; ++i)
        {
            if (!current.mapValueToNode.ContainsKey(input[i]))
            {
                current.mapValueToNode.Add(input[i], new Node());
            }
            current = current.mapValueToNode[input[i]];
        }
        ++current.frequencyOfValue;
    }

    public int frequencyInTrie(int[] input)
    {
        Node current = root;
        for (int i = 0; i < input.Length; ++i)
        {
            if (!current.mapValueToNode.ContainsKey(input[i]))
            {
                return 0;
            }
            current = current.mapValueToNode[input[i]];
        }
        return current.frequencyOfValue;
    }
}
