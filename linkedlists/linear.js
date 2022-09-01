class Node {
    data;
    next;
}

class LinkedLists {
    head;
    last;

    constructor() {
        this.head = null;
    }

    insertToLast(data) {
        let t = new TsNode();
        t.data = data;
        t.next = null;

        if (!this.head) {
            this.head = t;
            this.last = this.head;
        } else {
            this.last.next = t;
            this.last = t;
        }
    }

    display() {
        let p = this.head;
        while (p) {
            process.stdout.write(`${p.data} `);
            p = p.next;
        }
        console.log();
    }
}

let l = new LinkedLists();
l.insertToLast(10);
l.insertToLast(20);
l.insertToLast(30);
l.insertToLast(40);
l.insertToLast(50);
l.display();