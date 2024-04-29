// Note: please restart the page if syntax highlighting works bad.
let el = document.querySelector('#header')

const sum = (a: number, b: number): number => a + b;
const concate = (a: string, b: string): string => `${a}${b}`;

const destruction = (a:[number, number]): number => {
  const [x, y] = a;
  console.log(x, y);
  return 2;
}


console.log(sum(1, 2), concate('i love', ' bangladesh'), destruction([2, 4]));


class X {
  protected name: string;
  protected age: number | null;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }

  setName(name: string) {
    this.name = name;
  }

  getName() {
    return this.name;
  }

  setAge(age: number) {
    this.age = age;
  }
  
  getAge() {
    return this.age;
  }
}

class Y extends X {
  constructor(name: string, age: number) {
    super(name, age);
  }
}

const yy : Y = new Y('shohag', 34);
const employeeName: string = yy.getName();

console.log(employeeName);


