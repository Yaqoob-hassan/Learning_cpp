#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
};

struct Hashtable {
  int Tablenum;
  Node *table[100];
};

void init(Hashtable &ht, int b) {
  if (b > 100) {
    b = 100; // Cap to avoid buffer overflow
  }
  ht.Tablenum = b;
  for (int i = 0; i < ht.Tablenum; i++) {
    ht.table[i] = nullptr;
  }
}

int hashFunction(int key, int Tablenum) { return key % Tablenum; }

void insert(Hashtable &ht, int key) {
  int index = hashFunction(key, ht.Tablenum);

  Node *newNode = new Node;
  newNode->key = key;
  newNode->next = nullptr;

  if (ht.table[index] == nullptr) {
    ht.table[index] = newNode;
  } else {
    Node *temp = ht.table[index];
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

bool search(Hashtable &ht, int key) {
  int index = hashFunction(key, ht.Tablenum);

  Node *temp = ht.table[index];
  while (temp != nullptr) {
    if (temp->key == key) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

void displayHash(Hashtable &ht) {
  for (int i = 0; i < ht.Tablenum; i++) {
    cout << "Table " << i << ": ";
    Node *temp = ht.table[i];
    while (temp != nullptr) {
      cout << temp->key << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
}

int main() {
  Hashtable ht;
  init(ht, 7);

  insert(ht, 10);
  insert(ht, 20);
  insert(ht, 15);
  insert(ht, 7);
  insert(ht, 31);

  displayHash(ht);

  return 0;
}