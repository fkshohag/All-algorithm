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
console.log(countNumberOfShips(board)); // Output: [2, 1, 0]
