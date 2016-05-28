#include "../linkedlist/linkedlist.h"
#include <iostream>
#include <math.h>

LinkedList::Node* sumLists(LinkedList::Node* list1, LinkedList::Node* list2) {
  LinkedList::Node* sumList = nullptr;
  LinkedList::Node* currDigit = nullptr;
  int carry = 0;

  while (list1 || list2 || carry > 0) {
    /* Deal with the case where one list is longer */
    int a = (list1? list1->data : 0);
    int b = (list2? list2->data : 0);

    /* Compute the sum of the current digits */
    int dSum = a + b + carry;
    LinkedList::Node* digitNode = new LinkedList::Node(dSum % 10);
    
    if (sumList) {
      currDigit->next = digitNode;
      currDigit = digitNode;
    } else {
      sumList = currDigit = digitNode;
    }
    carry = dSum / 10;
    
    if (list1) list1 = list1->next;
    if (list2) list2 = list2->next;
  }

  return sumList;
}

/* For the follow up, in order to add forward lists we need
   to pad the shorter list with 0s. To add digit by digit,
   we need to add from tail to head which can be done with
   recursion. We need some struct to allow us to return the 
   carry from each recursive call. Let's make one. */

struct CarrySum {
  LinkedList::Node* sum = nullptr;
  int carry = 0;
  CarrySum(LinkedList::Node* sum, int carry) :
    sum(sum), carry(carry) {};
};

CarrySum partialSum(LinkedList::Node* list1, LinkedList::Node* list2) {
  if (!list1 || !list2) return CarrySum(nullptr, 0);
  CarrySum cs = partialSum(list1->next, list2->next);
  int sum = list1->data + list2->data + cs.carry;
  LinkedList::Node* digit = new LinkedList::Node(sum % 10);
  digit->next = cs.sum;
  cs.sum = digit;
  cs.carry = sum / 10;
  return cs;
}

LinkedList::Node* forwardSumLists(LinkedList::Node* list1, LinkedList::Node* list2) {
  int length1 = LinkedList::length(list1);
  int length2 = LinkedList::length(list2);
  int diff = std::abs(length1 - length2);
  while (diff-- > 0) {
    LinkedList::Node* n = new LinkedList::Node(0);
    if (length1 < length2) {
      n->next = list1;
      list1 = n;
    } else {
      n->next = list2;
      list2 = n;
    }
  }
  
  CarrySum cs = partialSum(list1, list2);
  LinkedList::Node* sum = cs.sum;
  int carry = cs.carry;
  while (carry) {
    LinkedList::Node* n = new LinkedList::Node(carry % 10);
    n->next = sum;
    sum = n;
    carry /= 10;
  }

  return sum;
}

int main() {
  std::cout << "Enter list 1:" << std::endl;
  LinkedList::Node* list1 = LinkedList::read(std::cin);
  std::cout << "Enter list 2:" << std::endl;
  LinkedList::Node* list2 = LinkedList::read(std::cin);
  std::cout << "Backward sum:" << std::endl;
  LinkedList::Node* sumList = sumLists(list1, list2);
  LinkedList::print(sumList);
  LinkedList::destroy(sumList);
  std::cout << "Forward sum:" << std::endl;
  sumList = forwardSumLists(list1, list2);
  LinkedList::print(sumList);
  LinkedList::destroy(sumList);
  LinkedList::destroy(list1);
  LinkedList::destroy(list2);
  return 0;
}
