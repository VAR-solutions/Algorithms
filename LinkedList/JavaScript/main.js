const LinkedList = require("./LinkedList");

//name of methods and properties are self explaining of there role

let obj = new LinkedList();

obj.addLast(600);
obj.addLast(3);
obj.addFirst(90);
obj.addFirst(88);
obj.addFirst(45);

obj.print();

console.log(obj.indexOf(90));
console.log(obj.contains(600));
console.log(obj.size);

obj.removeFirst();

obj.print();

console.log(obj.removeLast());

obj.print();

obj.addLast(0);

obj.addFirst(45);

obj.print();

console.log(obj.remove(4));

obj.print();

console.log(obj.size);
console.log(obj.toArray());
console.log(obj.isEmpty());
obj.reverse();

obj.print();

console.log(obj.kthNodeFromEnd(2));//not index
obj.middleNode();
obj.hasLoop();