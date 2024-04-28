// Complexity: 

// O(N^2 * M^2)

// Note: please restart the page if syntax highlighting works bad.
let el = document.querySelector('#header')

function countNumberOfShips(b: number[][]): number[] {
    const numRows = b.length;
    const numCols = b[0].length;
    const res: number[] = [];
    for (let i = 0; i < 3; i++) {
      res.push(0);
    }

    function getNeighbours(coord: [number, number]): [number, number][] {
        const [row, col] = coord;
        const deltaRow = [-1, 0, 1, 0];
        const deltaCol = [0, 1, 0, -1];
        const neighbours: [number, number][] = [];
        
        for (let i = 0; i < deltaRow.length; i++) {
            const rowNeighbour = row + deltaRow[i];
            const colNeighbour = col + deltaCol[i];
            if (rowNeighbour >= 0 && rowNeighbour < numRows && colNeighbour >= 0 && colNeighbour < numCols) {
                neighbours.push([rowNeighbour, colNeighbour]);
            }
        }
        return neighbours;
    }

    //  N*M
    function getSize(start: [number, number]): number {
        const [startRow, startCol] = start;
        if (b[startRow][startCol] === 0) return 0; // Base case: If the cell is empty, return 0.
        
        let size = 1; // Initialize size to 1 for the current cell.
        b[startRow][startCol] = 0; // Mark the current cell as visited.

        // Explore all neighbors of the current cell recursively using DFS.
        for (const [row, col] of getNeighbours(start)) {
            size += getSize([row, col]);
        }
        
        return size;
    }

    // N*M
    for (let i = 0; i < numRows; i++) {
        for (let j = 0; j < numCols; j++) {
            if (b[i][j] === 0) continue;
            const size = getSize([i, j]);
            if (size <= 3) {
                res[size - 1] = (res[size - 1] || 0) + 1;
            }
        }
    }

    return res;
}

// Test input
let b: string[] = ['.##.#', '#.#..', '#...#', '#.##.'];
b = b.map(row => row.replace(/\./g, '0').replace(/#/g, '1').split('').map(Number));
console.log(countNumberOfShips(b)); // Output: [2, 1, 0]
