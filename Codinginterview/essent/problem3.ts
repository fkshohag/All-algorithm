// O(m*n )

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

    function getSize(start: [number, number]): number {
        const queue: [number, number][] = [start];
        const [startRow, startCol] = start;
        b[startRow][startCol] = 0;
        let size = 0;
        while (queue.length > 0) {
            const [row, col] = queue.shift()!;
            size++;
            for (const neighbour of getNeighbours([row, col])) {
                const [r, c] = neighbour;
                if (b[r][c] === 0) continue;
                queue.push(neighbour);
                b[r][c] = 0;
            }
        }
        return size;
    }

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

// A string is a primitive value, it's immutable. we can change value inside a string that is the reason for changing this value

b = b.map(row => row.replace(/\./g, '0').replace(/#/g, '1').split('').map(Number));
console.log(countNumberOfShips(b)); // Output: [2, 1, 2]

/*
'.##.#',
'#.#..',
'#...#',
'#.##.'
*/




