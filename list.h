// list/list.h
// 
// Interface definition for linked list.
//
// <Author>

#include <stdbool.h>

typedef struct block {
    int pid;   // Process ID
    int start; // Start address of the block
    int end;   // End address of the block
} block_t;

/* Defines the node structure. Each node contains a block (blk) and points to the
 * next node in the list. The last element in the list has NULL as its next pointer. */
typedef struct node {
    block_t *blk;      // Pointer to the block
    struct node *next; // Pointer to the next node
} node_t;

/* Defines the list structure, which points to the first node in the list. */
typedef struct list {
    node_t *head; // Pointer to the head of the list
} list_t;

/* Functions for allocating and freeing lists. By using only these functions,
 * the user can allocate and free all the memory required for this linked list library. */
list_t *list_alloc();
node_t *node_alloc(block_t *blk);

void list_free(list_t *l);

/* Prints the list in some format. */
void list_print(list_t *l);

/* Returns the length of the list. */
int list_length(list_t *l);

/* Methods for adding to the list. */
void list_add_to_back(list_t *l, block_t *blk);
void list_add_to_front(list_t *l, block_t *blk);
void list_add_at_index(list_t *l, block_t *blk, int index);
void list_add_ascending_by_address(list_t *l, block_t *blk);
void list_add_ascending_by_blocksize(list_t *l, block_t *blk);
void list_add_descending_by_blocksize(list_t *l, block_t *blk);

/* Methods for removing from the list. Returns the removed block. */
block_t* list_remove_from_back(list_t *l);
block_t* list_remove_from_front(list_t *l);
block_t* list_remove_at_index(list_t *l, int index);

/* Methods for checking blocks in the list. */
bool list_is_in(list_t *l, block_t *blk); // Checks if a block is in the list
bool list_is_in_by_size(list_t *l, int Size); // Checks if a block of given size or greater exists
bool list_is_in_by_pid(list_t *l, int pid); // Checks if a block with a specific PID exists

/* Methods for retrieving elements or indexes. */
block_t* list_get_elem_at(list_t *l, int index); // Returns the block at a specific index
block_t* list_get_from_front(list_t *l); // Returns the block at the front of the list
int list_get_index_of(list_t *l, block_t *blk); // Returns the index of a specific block
int list_get_index_of_by_Size(list_t *l, int Size); // Returns the index of a block with the given size or greater
int list_get_index_of_by_Pid(list_t *l, int pid); // Returns the index of a block with a specific PID

/* Utility functions. */
bool compareBlks(block_t* a, block_t *b); // Compares if two blocks are equal
void list_coalese_nodes(list_t *l); // Joins adjacent nodes whose blocks are physically contiguous

