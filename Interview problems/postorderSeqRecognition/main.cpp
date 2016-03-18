#include <cstdio>
#include <cstdlib>

// This example checks whether a given binary search tree traversal is a post-order traversal or not. The traversal is input is represented as an array.
// The BST is assumed to store simple integers.


bool checkPostorder(int seq[], int first , int last);


int main(int argc, char const *argv[])
{
    // examples
    
    // int seq[] = {20, 40, 35, 30, 60, 80, 70, 50}; // OK
    // int seq[] = {20, 40, 55, 60, 60, 80, 70, 10}; // OK
    int seq[] = {20, 40, 55, 60, 60, 80, 70, 110}; // OK
    // int seq[] = {20, 40, 55, 30, 60, 80, 70, 50}; // NOT OK


    printf("%s\n",checkPostorder(seq, 0, 8-1)? "OK" : "NOT OK");

    return 0;
}


bool checkPostorder(int seq[], int first , int last)
{
    // trivial 
    if (first == last)
    {
        return true;
    }

    int root = seq[last];

    // verify right subtree
    int breakingPoint = -1;
    for (int i = last-1; i >= first; --i)
    {
        if (seq[i] < root)
        {
            breakingPoint = i;
            break; 
        }
    }

    // this means no left subtree, only right subtree
    if (breakingPoint < 0) return true;

    for (int i = breakingPoint; i >= first; --i)
    {
        if (seq[i] > root)
        {
            // if a bigger element is found in the left subtree, then its not a valid BST
            printf("%d > %d\n", seq[i], root);
            return false;
        }
    }


    if (checkPostorder(seq, first, breakingPoint))
    {
        return checkPostorder(seq, breakingPoint+1, last-1);
    }
    else
    {
        return false;
    }



}