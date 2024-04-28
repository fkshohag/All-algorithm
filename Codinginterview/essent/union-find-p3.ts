class UnionFind {
    parent: number[];
    rank: number[];

    constructor(size: number) {
        this.parent = Array.from({ length: size }, (_, i) => i);
        this.rank = Array(size).fill(0);
    }

    find(x: number): number {
        if (this.parent[x] !== x) {
            this.parent[x] = this.find(this.parent[x]);
        }
        return this.parent[x];
    }

    union(x: number, y: number): void {
        let rootX = this.find(x);
        let rootY = this.find(y);
        if (rootX === rootY) return;

        if (this.rank[rootX] < this.rank[rootY]) {
            [rootX, rootY] = [rootY, rootX];
        }
        this.parent[rootY] = rootX;
        if (this.rank[rootX] === this.rank[rootY]) {
            this.rank[rootX]++;
        }
    }
}

function countNumberOfShips(b: number[][]): number[] {
    const numRows = b.length;
    const numCols = b[0].length;
    const uf = new UnionFind(numRows * numCols);
    const res: number[] = [];
    for (let i = 0; i < 3; i++) {
        res.push(0);
    }

    for (let i = 0; i < numRows; i++) {
        for (let j = 0; j < numCols; j++) {
            if (b[i][j] === 0) continue;
            
            const index = i * numCols + j;
            if (i > 0 && b[i - 1][j] === 1) uf.union(index, index - numCols); // Union with cell above
            if (j > 0 && b[i][j - 1] === 1) uf.union(index, index - 1); // Union with cell on the left
        }
    }

    const shipCounts: { [key: number]: number } = {};
    for (let i = 0; i < numRows; i++) {
        for (let j = 0; j < numCols; j++) {
            if (b[i][j] === 1) {
                const root = uf.find(i * numCols + j);
                shipCounts[root] = (shipCounts[root] || 0) + 1;
            }
        }
    }

    for (let count of Object.values(shipCounts)) {
        if (count <= 3) {
            res[count - 1] = (res[count - 1] || 0) + 1;
        }
    }

    return res;
}

// Test input
let b: string[] = ['.##.#', '#.#..', '#...#', '#.##.'];
b = b.map(row => row.replace(/\./g, '0').replace(/#/g, '1').split('').map(Number));
console.log(countNumberOfShips(b)); // Output: [2, 1, 0]
