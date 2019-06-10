#ifndef LINKEDLISTDICT_H_INCLUDED
#define LINKEDLISTDICT_H_INCLUDED

#include "PreDict.h"

// An implementation of a dictionary ADT as an unsorted linked list.
// This will be very slow.
//
class LinkedListDict : public PredDict
  {
  public:
    LinkedListDict();
    ~LinkedListDict();
    bool find(PuzzleState *key, PuzzleState *&pred);
    void add(PuzzleState *key, PuzzleState *pred);

  private:
    struct node {
      PuzzleState *key;
      PuzzleState *data;
      node *next;
    };

    node *root;

    bool find_helper(node *r, PuzzleState *key, PuzzleState *&pred);
  };


#endif // LINKEDLISTDICT_H_INCLUDED
