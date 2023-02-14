#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    if (head == NULL) {
        return 0;
    } else if (head->next == NULL) {
        return 0;
    }
    node *fast = head;
    node *slow = head;
    do {
        fast = fast->next;
        slow = slow->next;
        if (fast->next) {
            fast = fast->next;
        }
        if (fast == slow) {
            return 1;
        }
    } while (fast->next); 
    return 0;
}