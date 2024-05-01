/*

Let's analyze the time complexity of the updated countNumberOfShips function using Depth-First Search (DFS):

Iterating over the Board: The function iterates over each cell of the board, which is an N x M grid, 
where N is the number of rows and M is the number of columns. So, the time complexity for this step is O(N * M).
DFS for Each Ship:
For each cell representing the start of a ship (value is 1), the getSize function performs DFS to 
explore the connected ship cells.
In the worst case, each ship can have at most N * M cells.
The DFS operation for each ship can visit each cell at most once, marking it as visited. Therefore, 
the time complexity for DFS in each ship is O(N * M).
Overall Time Complexity:
Since step 1 and step 2 are nested, the overall time complexity is the product of their complexities.
So, the overall time complexity is O(N * M * N * M), which simplifies to O(N^2 * M^2).
Given the size of the input grid, this algorithm also has polynomial time complexity similar to the BFS version. 
It may perform efficiently for small to moderate-sized grids but may become slower for large grids due to its quadratic 
complexity.
*/


function countNumberOfShips(board: string[]): number[] {
    const numRows = board.length;
    const numCols = board[0].length;
    const res: number[] = [];
    for (let i = 0; i < 3; i++) {
        res.push(0);
    }

    // Convert the board string array to a 2D array of numbers
    const grid: number[][] = board.map(row => row.split('').map(cell => cell === '#' ? 1 : 0));

    function getNeighbours(coord: [number, number]): [number, number][] {
        const [row, col] = coord;
        const deltaRow = [-1, 0, 1, 0];
        const deltaCol = [0, 1, 0, -1];
        // The tuple represents a coordinate pair, where the first number is the row and the second number is the column.
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

    // O(m * n)
    function getSize(start: [number, number]): number {
        const queue: [number, number][] = [start];
        const [startRow, startCol] = start;
        grid[startRow][startCol] = 0;
        let size = 0;
        while (queue.length > 0) {
            // The exclamation mark (!) in queue.shift()! is the non-null assertion operator in TypeScript. 
            // It tells the TypeScript compiler that you are certain that queue.shift() will not return null or undefined.
            const [row, col] = queue.shift()!;
            size++;
            for (const neighbour of getNeighbours([row, col])) {
                const [r, c] = neighbour;
                if (grid[r][c] === 0) continue;
                queue.push(neighbour);
                grid[r][c] = 0;
            }
        }
        return size;
    }

    // O(m * n)
    /*
    Stack Space for DFS: For each DFS call, memory is allocated on the call stack to store the function call and 
    local variables. Since we perform DFS on each cell, the maximum depth of the call stack can be equal to 
    the number of cells in the largest ship. In the worst case, the largest ship can cover the entire grid, 
    so the maximum stack depth is O(N * M).
    Auxiliary Space: Apart from the call stack, additional space is used to store the grid representation. However, 
    this space is negligible compared to the stack space and can be considered constant.
    */
   
    function getSizeWithDfs(coord: [number, number]): number {
        const [row, col] = coord;
        if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] === 0) {
            return 0;
        }
        grid[row][col] = 0; // Mark visited
        let size = 1;
        for (const neighbour of getNeighbours([row, col])) {
            size += getSizeWithDfs(neighbour);
        }
        return size;
    }

    for (let i = 0; i < numRows; i++) {
        for (let j = 0; j < numCols; j++) {
            if (grid[i][j] === 0) continue;
            const size = getSize([i, j]);
            if (size <= 3) {
                res[size - 1] = (res[size - 1] || 0) + 1;
            }
        }
    }

    return res;
}

// Test input
let board: string[] = ['.##.#', '#.#..', '#...#', '#.##.'];
console.log(countNumberOfShips(board)); // Output: [2, 1, 2]
