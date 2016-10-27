/*

Forward lists are sequence containers that allow constant time insert and erase
operations anywhere within the sequence.

Forward lists are implemented as singly-linked lists; Singly linked lists can
store each of the elements they contain in different and unrelated storage
locations. The ordering is kept by the association to each element of a link to
the next element in the sequence.

The main design difference between a forward_list container and a list container
is that the first keeps internally only a link to the next element, while the
latter keeps two links per element: one pointing to the next element and one to
the preceding one, allowing efficient iteration in both directions, but
consuming additional storage per element and with a slight higher time overhead
inserting and removing elements. forward_list objects are thus more efficient
than list objects, although they can only be iterated forwards.

Compared to other base standard sequence containers (array, vector and deque),
forward_list perform generally better in inserting, extracting and moving
elements in any position within the container, and therefore also in algorithms
that make intensive use of these, like sorting algorithms.

The main drawback of forward_lists and lists compared to these other sequence
containers is that they lack direct access to the elements by their position;
For example, to access the sixth element in a forward_list one has to iterate
from the beginning to that position, which takes linear time in the distance
between these. They also consume some extra memory to keep the linking
information associated to each element (which may be an important factor for
large lists of small-sized elements).

The forward_list class template has been designed with efficiency in mind: By
design, it is as efficient as a simple handwritten C-style singly-linked list,
and in fact is the only standard container to deliberately lack a size member
function for efficiency considerations: due to its nature as a linked list,
having a size member that takes constant time would require it to keep an
internal counter for its size (as list does). This would consume some extra
storage and make insertion and removal operations slightly less efficient. To
obtain the size of a forward_list object, you can use the distance algorithm
with its begin and end, which is an operation that takes linear time.

Source: http://www.cplusplus.com/reference/forward_list/forward_list/
*/

#include <forward_list>
#include <iostream>

int main(int argc, char const *argv[]) {
  std::forward_list<int> llist;
  llist.push_front(1);
  llist.push_front(2);
  for (const auto &p : llist) {
    std::cout << p << std::endl;
  }
  return 0;
}