`SELECT p1.day
FROM prices p1
WHERE p1.price > (SELECT price FROM prices WHERE day = p1.day - 1)
  AND p1.price > (SELECT price FROM prices WHERE day = p1.day + 1)
  AND p1.day != 1
  AND p1.day != (SELECT MAX(day) FROM prices);`;

  `
  In this query:
  
  p1 represents the current day's data.
  p2 represents the previous day's data.
  p3 represents the next day's data.
  We join the prices table three times: once to represent the current day, once to represent the previous day (p2), and once to represent the next day (p3). Then, we compare the prices of the current day with the prices of the previous and next days using the join conditions. Finally, we add additional conditions to exclude the first day and the last day from the result set.
  
  This approach eliminates the need for subqueries and may improve the query's performance, especially on large datasets.
  `;
  
  
  `SELECT p1.day
  FROM prices p1
  JOIN prices p2 ON p1.day = p2.day - 1
  JOIN prices p3 ON p1.day = p3.day + 1
  WHERE p1.price > p2.price
    AND p1.price > p3.price
    AND p1.day != 1
    AND p1.day != (SELECT MAX(day) FROM prices);
`;
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


/*
Depth-First Search (DFS) and Breadth-First Search (BFS) are both algorithms used for traversing or 
searching graphs or trees, but they have different strategies and characteristics:

Strategy:
DFS explores as far as possible along each branch before backtracking. It goes deep into the graph or tree, 
exploring as far as possible along each branch before backtracking.
BFS explores all the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.
Traversal Order:
DFS traverses depth-wise, meaning it explores nodes at the same level before moving to the next level.
BFS traverses breadth-wise, meaning it explores all nodes at the current level before moving to the nodes at the next level.
Data Structures Used:
DFS is usually implemented using recursion or a stack data structure (implicitly through the call stack).
BFS is implemented using a queue data structure.
Space Complexity:
DFS typically uses less memory because it doesn't need to store all nodes at the current level like BFS does. 
It only needs to store the nodes along the current branch.
BFS may use more memory, especially for large, wide graphs, because it needs to maintain a queue to store nodes 
at the current level.
Applications:
DFS is often used for topological sorting, cycle detection, pathfinding, and solving puzzles like maze traversal.
BFS is commonly used for shortest path finding, finding connected components, and traversing level-by-level.
Completeness and Optimality:
DFS may not find the shortest path between two nodes, especially if the graph has cycles.
BFS always finds the shortest path between two nodes in an unweighted graph.
*/
