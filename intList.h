/* Seth Crawford
 * sacrawfo@ucsc.edu
 * 1304569
 * intList.h
 * (what is the purpose of this file?)
 * It's a header for intlist.c
 * It lays out the functions for intList.c
 */

#ifndef C101IntList
#define C101IntList

/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;

/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 * (what are the preconditions?)
 * oldL needs to exist. It cannot be NULL
 */

/** first
 */
int intFirst(IntList oldL);

/** rest
 */
IntList intRest(IntList oldL);

/* Constructors
 * (what are the preconditions and postconditions?)
 *newE and oldL need to exist
 * the returned IntList has the properties if you call intFirst, you get newE
 * if you call intRest you get oldL
 */

/** cons
 */
IntList intCons(int newE, IntList oldL);

#endif

