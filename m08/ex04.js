// Array
const fruits = ['apple', 'banana', 'cherry'];
console.log(fruits[1]); // Output: banana

// Object
const person = {
    name: 'Alice',
    age: 25,
    isStudent: true
};
console.log(person.name); // Output: Alice

// Set
const uniqueNumbers = new Set([1, 2, 3, 3, 4]);
console.log(uniqueNumbers.has(3)); // Output: true

// Map
const userRoles = new Map();
userRoles.set('Alice', 'Admin');
userRoles.set('Bob', 'User');
console.log(userRoles.get('Alice')); // Output: Admin

// Stack (using an array)
class Stack {
    constructor() {
        this.items = [];
    }
    push(element) {
        this.items.push(element);
    }
    pop() {
        return this.items.pop();
    }
    peek() {
        return this.items[this.items.length - 1];
    }
}
const stack = new Stack();
stack.push(10);
stack.push(20);
console.log(stack.pop()); // Output: 20

// Queue (using an array)
class Queue {
    constructor() {
        this.items = [];
    }
    enqueue(element) {
        this.items.push(element);
    }
    dequeue() {
        return this.items.shift();
    }
}
const queue = new Queue();
queue.enqueue('A');
queue.enqueue('B');
console.log(queue.dequeue()); // Output: A