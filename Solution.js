
/**
 * @param {number[][]} grid
 * @return {number}
 */
var equalPairs = function (grid) {
    const trie = new Trie();
    for (let row of grid) {
        trie.addToTrie(row);
    }

    let countMatchesBetweenRowsAndColumns = 0;

    for (let c = 0; c < grid[0].length; ++c) {
        const temp = new Array(grid.length);
        for (let r = 0; r < grid.length; ++r) {
            temp[r] = grid[r][c];
        }
        countMatchesBetweenRowsAndColumns += trie.frequencyInTrie(temp);
    }
    return countMatchesBetweenRowsAndColumns;
};

class Node {
    mapValueToNode = new Map();//Map<number, Node>
    frequencyOfValue = 0;
}

class Trie {

    root = new Node();

    /**
     * @param {number[]} input
     * @return {void}
     */
    addToTrie(input) {
        let current = this.root;
        for (let i = 0; i < input.length; ++i) {
            if (!current.mapValueToNode.has(input[i])) {
                current.mapValueToNode.set(input[i], new Node());
            }
            current = current.mapValueToNode.get(input[i]);
        }
        ++current.frequencyOfValue;
    }

    /**
     * @param {number[]} input
     * @return {number}
     */
    frequencyInTrie(input) {
        let current = this.root;
        for (let i = 0; i < input.length; ++i) {
            if (!current.mapValueToNode.has(input[i])) {
                return 0;
            }
            current = current.mapValueToNode.get(input[i]);
        }
        return current.frequencyOfValue;
    }
}
