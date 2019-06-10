#ifndef PUZZLE2_H_INCLUDED
#define PUZZLE2_H_INCLUDED

#include <iostream>
#include<sstream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

// 221 STUDENTS: You'll need to include any .hpp files of classes that
// you create and use here
#include "PuzzleState.h"
#include "WolfGoatCabbage.h"
#include "BagOfPuzzleStates.h"
#include "PreDict.h"
#include "ArrayStack.h"
#include "LinkedListDict.h"
#include "WolfGoatCabbage.cpp"
#include "LinkedListDict.cpp"
using namespace std;



void solvePuzzle(PuzzleState *start, BagOfPuzzleStates &active, PredDict &seen, vector<PuzzleState*> &solution) {
  PuzzleState *state;
  PuzzleState *temp;

  active.put_in(start); // Must explore the successors of the start state.
  seen.add(start,NULL); // We've seen this state.  It has no predecessor.

  while (!active.is_empty()) {
    // Loop Invariants:
    // 'seen' contains the set of puzzle states that we know how to reach.
    // 'active' contains the set of puzzle states that we know how to reach,
    //    and whose successors we might not have explored yet.

    state = active.take_out();
    // Note:  Do not delete this, as this PuzzleState is also in 'seen'

    // The following two lines are handy for debugging, or seeing what
    // the algorithm is doing.
    // 221 STUDENTS:  Comment these out when you want the program to
    // run at full speed!
    //cout << "Exploring State: \n";
    //state->print(cout);
    //usleep(10000);	// Pause for some microseconds, to let human read output

    if (state->isSolution()) {
      // Found a solution!
      cout << "Found solution! \n";
      state->print(cout);

      // Follow predecessors to construct path to solution.
      temp = state;
      while (temp!=NULL) {
	solution.push_back(temp);
	// Guaranteed to succeed, because these states must have been
	// added to dictionary already.
        seen.find(temp,temp);
      }
      return;
    }

    vector<PuzzleState*> nextMoves = state->getSuccessors();
    for (unsigned int i=0; i < nextMoves.size(); i++) {
      if (!seen.find(nextMoves[i], temp)) {
        // Never seen this state before.  Add it to 'seen' and 'active'
        active.put_in(nextMoves[i]);
        seen.add(nextMoves[i], state);
      } else {
	delete nextMoves[i];
      }
    }
  }

  // Ran out of states to explore.  No solution!
  solution.clear();
  return;
}
void puzzle2()
{
     PuzzleState *startState;
     startState = new WolfGoatCabbage();
       ArrayStack activeStates;
       LinkedListDict seenStates;

  vector<PuzzleState*> solution;

  solvePuzzle(startState, activeStates, seenStates, solution);

  // Print out solution
  for (int i=(int)solution.size()-1; i >= 0; i--) {
    cout << "STEP " << solution.size()-i << ":\n";
    solution[i]->print(cout);
    cout << endl;
  }

  delete startState;
}

#endif // PUZZLE2_H_INCLUDED
