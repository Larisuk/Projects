#include <iostream>
#include <climits>

using namespace std;

class Nod {
    int info;
    Nod *next;
public:
    Nod() {
        info = 0;
        next = NULL;
    }

    Nod(int x, Nod *p) {
        info = x;
        next = p;
    }

    void setInfo(int x) {
        info = x;
    }

    int getInfo() {
        return info;
    }

    void setNext(Nod *p) {
        next = p;
    }

    Nod *getNext() {
        return next;
    }
};

class Lista {
    Nod *start;
    Nod *endd;
    unsigned int sized;
public:
    Lista() {
        sized = 0;
        start = endd = NULL;

    }

    Lista(int x);

    Lista(int x, int y);

    Lista(const Lista &l);

    void insertie(int x);

    void insertAt(int x, int i);

    int get(int i);

    int length();

    void removed(int i);

    void f(int x);

    Lista reversed() {
        Nod *p = start;
        Lista lb;
        lb.insertie(p->getInfo());
        p = p->getNext();
        for (int i = 1; i < length(); i++) {
            lb.insertAt(p->getInfo(), 0);
            p = p->getNext();
        }

        return lb;

    }

    void removeFirst();

    void removeLast();

    bool hasDuplicates();

    bool has(int x);

    bool isEmpty();

    ~Lista() {
        Nod *p = start;
        while (p != NULL) {
            Nod *q = p;
            p = p->getNext();
            delete q;
        }
        start = endd = NULL;
        sized = 0;
    }

};

Lista::Lista(int x) {
    start->setNext(new Nod(x, NULL));
    endd = start;
    endd = endd->getNext();
    sized = 1;
}

void Lista::insertie(int x) {
    if (sized == 0) {
        start = endd = new Nod(x, NULL);
        sized = 1;
    } else {
        endd->setNext(new Nod(x, NULL));
        endd = endd->getNext();
        sized++;
    }

}

Lista::Lista(int x, int y) {
    sized = 0;
    start = endd = NULL;
    for (int i = 0; i < x; i++) {
        insertie(y);
    }
}

Lista::Lista(const Lista &l) {
    Nod *p = l.start;
    start = new Nod(p->getInfo(), NULL);
    sized = 1;
    Nod *q = start;
    p = p->getNext();

    while (p->getNext() != NULL) {
        Nod *aux = new Nod(p->getInfo(), NULL);
        q->setNext(aux);
        q = q->getNext();
        sized++;
        p = p->getNext();
    }
    endd = new Nod(p->getInfo(), NULL);
    q->setNext(endd);
    sized++;

}

void Lista::insertAt(int x, int i) {
    if (i > sized) {
        insertie(x);
    } else if (i <= 0) {
        Nod *p = new Nod(x, start);
        start = p;
        sized += 1;
    } else {
        Nod *p = start;
        for (int j = 0; j < i; j++) {
            p = p->getNext();
        }
        Nod *q = new Nod(x, p);
        Nod *aux = start;
        for (int j = 0; j < i - 1; ++j) aux = aux->getNext();
        aux->setNext(q);
        sized += 1;


    }
}

int Lista::get(int i) {
    if (i < 0 or i >= sized)
        return INT_MAX;
    else {
        Nod *p = start;
        for (int j = 0; j < i; j++) {
            p = p->getNext();
        }
        return p->getInfo();
    }
}

int Lista::length() {
    if (start == NULL)
        return 0;
    else {
        int lungime = 0;
        Nod *p = start;
        while (p != NULL) {
            p = p->getNext();
            lungime++;
        }
        if (lungime != 0)
            return lungime;
        else return 0;
    }
}

void Lista::removed(int i) {
    if (i == 0) {
        Nod *p = start;
        start = start->getNext();
        sized--;
        delete p;
    } else if (i == sized - 1) {
        Nod *aux = start;
        for (int j = 0; j < i - 1; j++)
            aux = aux->getNext();
        endd = aux;
        aux = aux->getNext();
        delete aux;
        endd->setNext(NULL);

        sized--;
    } else {
        Nod *p = start;
        for (int j = 0; j < i; j++) {
            p = p->getNext();
        }
        Nod *aux = start;
        for (int j = 0; j < i - 1; j++)aux = aux->getNext();
        aux->setNext(p->getNext());
        sized--;
        delete p;

    }
}

void Lista::f(int x) {
    insertie(x);
    Nod *p = start;

    while (p != NULL) {
        cout << p->getInfo() << " ";
        p = p->getNext();
    }

}

void Lista::removeFirst() {
    removed(0);
}

void Lista::removeLast() {
    if (length() > 0)
        removed(length() - 1);
}

bool Lista::hasDuplicates() {
    if (length() == 0 or length() == 1)
        return false;
    else {
        for (int j = 0; j < length(); j++) {
            for (int i = 0; i < length(); i++)
                if (get(j) == get(i))
                    return true;
        }

    }
    return false;

}

bool Lista::has(int x) {
    if (length() != 0) {
        for (int i = 0; i < length(); i++) {
            if (get(i) == x)
                return true;
        }
    }
    return false;
}

bool Lista::isEmpty() {
    return length() == 0;

}

int main() {
    Lista M(3, 10);
    M.insertAt(203,20);       //Cand pozitia este mai mare ca numarul de elemente; (i>=size => insereaza pe ultima pozitie)
    M.insertAt(123, 1);
    M.f(5);
    Lista X(M.reversed());
    cout << '\n';
    X.f(5);
    return 0;
}
