#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//announce the size of the alphabets is 26
#define ALPHABET_SIZE 26
// this is struct trie
typedef struct Trie
{
// struct trie for letter
    struct Trie *letter[ALPHABET_SIZE];
// int for count
    int count;
//trie return
} Trie;
// this get the node
Trie *getNode()
{
  //trie malloc size
    Trie *node = (Trie *)malloc(sizeof(Trie));
  // node to count is 0
    node->count = 0;
  // for int i is 0, i is less than alphabet size, i plus 1
    for (int i = 0; i < ALPHABET_SIZE; i++)
      //node to letter is NULL
        node->letter[i] = NULL;
  // returns the node 
    return node;
}
// this is void the trie and char word
void insert(Trie **ppTrie, char *word)
{
  //Trie to ppTrie
    Trie *trie = *ppTrie;
  // if trie is NULL
    if (trie == NULL)
      // trie to getNode
        trie = getNode();
  //Trie current to trie
    Trie *curr = trie;
  //for int i is 0, i less than strlen word, i plus 1
    for (int i = 0; i < strlen(word); i++)
    {
      // int index to word [i] minus a
        int index = word[i] - 'a';
      //current to letter is NULL
        if (curr->letter[index] == NULL)
         // current to letter is getNode
            curr->letter[index] = getNode();
      //current is current to lettre
        curr = curr->letter[index];
    }
  //current to count plus 1
    curr->count++;
  //ppTrie to trie
    *ppTrie = trie;
}
//the number os Occurances
int numberOfOccurances(Trie *pTrie, char *word)
{
  //Trie current to pTrie
    Trie *curr = pTrie;
  // for i is 0, i is less than strlen word, i plus 1
    for (int i = 0; i < strlen(word); i++)
    {
      //int index to word minus a
        int index = word[i] - 'a';
      // if current is to letter is NULL
        if (curr->letter[index] == NULL)
          //returns 0
            return 0;
      //current is current to letter
        curr = curr->letter[index];
    }
  //return current to count
    return curr->count;
}
//trie deallocate trie
Trie *deallocateTrie(Trie *pTrie)
{
  // if pTrie is NULL
    if (pTrie == NULL)
      //return the NULL
        return NULL;
  // for i is 0, i is less than ALPHABET_SIZE, i plus 1
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
      //pTrie to Letter is not NULL
        if (pTrie->letter[i] != NULL)
          //this deallocate 
            deallocateTrie(pTrie->letter[i]);
    }
  //this freepTrie
    free(pTrie);
  //this returns NULL
    return NULL;
}
// this is for int main
int main(void)
{
    // read the number of the words in the dictionary
    // parse line by line, and insert each word to the trie data structure
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
//Trie to NULL
    Trie *trie = NULL;
// for int i is 0, i is less than 5, i plus 1
    for (int i = 0; i < 5; i++)
      //inserts the &trie and pWords
        insert(&trie, pWords[i]);
// for int to 0, i less than 5, i plus 1
    for (int i = 0; i < 5; i++)
    {
      //prints out the words and occurances
        printf("\t%s : %d\n", pWords[i], numberOfOccurances(trie, pWords[i]));
    }
  // trie t0 deallocate 
    trie = deallocateTrie(trie);
  // if trie is not equal to NULL
    if (trie != NULL)
//prints There is an error in this program
        printf("There is an error in this program\n");
  //this returns 0
    return 0;
}
