#include <iostream>
#include <string>

class Animal {
public:
    Animal(std::string n, bool dog);
    std::string getName();
    bool isADog();

private:
    std::string name;
    bool isDog;
};

Animal::Animal(std::string n, bool dog) : name(n), isDog(dog) {}
std::string Animal::getName() { return name; }
bool Animal::isADog() { return isDog; }

class AnimalQueue {
public:
    AnimalQueue();
    Animal dequeueAny();
    Animal dequeueCat();
    Animal dequeueDog();
    void enqueue(Animal item);
    bool isEmpty();

private:
    
    class AnimalQueueNode {
        public:
            AnimalQueueNode(Animal an);
            Animal animal;
            AnimalQueueNode *next;
    };

    AnimalQueueNode *first;
    AnimalQueueNode *last;
};

AnimalQueue::AnimalQueueNode::AnimalQueueNode(Animal an) : animal(an) {}

AnimalQueue::AnimalQueue() : first(nullptr), last(nullptr) {}

Animal AnimalQueue::dequeueAny() {
    if (isEmpty()) {
        throw "Is empty"; 
    }
    else {
        Animal ret_animal = first->animal;
        AnimalQueueNode *tmp = first;
        if (first == last) {
            first = nullptr;
            last = nullptr;
        }
        else {
            first = first->next;
        }
        delete tmp;
        return ret_animal;
    }
}

Animal AnimalQueue::dequeueDog() {
    if (isEmpty()) {
        throw "Is empty"; 
    }
    if (first->animal.isADog()) {
        Animal dog = first->animal;
        AnimalQueueNode *tmp = first;
        if (first == last) {
            last = nullptr;
        }
        else {
            first = first->next;
        }
        delete tmp;
        return dog;
    }
    else {
        AnimalQueueNode *curr = first;
        while (curr->next != nullptr) {
            if (curr->next->animal.isADog()) {
                Animal dog = curr->next->animal;
                AnimalQueueNode *tmp = curr->next;
                if (tmp == last) {
                    last = curr;
                }
                curr->next = curr->next->next;
                delete tmp;
                return dog;
            }
            curr = curr->next;
        }
        throw "no dogs available";
    }
}


Animal AnimalQueue::dequeueCat() {
    if (isEmpty()) {
        throw "Is empty"; 
    }
    if (!first->animal.isADog()) {
        Animal cat = first->animal;
        AnimalQueueNode *tmp = first;
        if (first == last) {
            last = nullptr;
        }
        else {
            first = first->next;
        }
        delete tmp;
        return cat;
    }
    else {
        AnimalQueueNode *curr = first;
        while (curr->next != nullptr) {
            if (!curr->next->animal.isADog()) {
                Animal cat = curr->next->animal;
                AnimalQueueNode *tmp = curr->next;
                if (tmp == last) {
                    last = curr;
                }
                curr->next = curr->next->next;
                delete tmp;
                return cat;
            }
            curr = curr->next;
        }
        throw "no cats available";
    }
}

void AnimalQueue::enqueue(Animal item) {
    if (first == nullptr) {
        first = new AnimalQueueNode(item);
        last = first;
    }
    else {
        last->next = new AnimalQueueNode(item);
        last = last->next;
    }

}

bool AnimalQueue::isEmpty() {
    if (first == nullptr)
        return true;
    return false;
}




int main(int argc, char *argv[]) {

    Animal d1 = Animal("Gracie",true);
    Animal d2 = Animal("Dani",true);

    Animal c1 = Animal("Pixel",false);

    AnimalQueue q = AnimalQueue();
    q.enqueue(d1);
    q.enqueue(d2);
    q.enqueue(c1);

    Animal curr = q.dequeueCat();
    curr = q.dequeueDog();
    curr = q.dequeueDog();


    return 0;
}