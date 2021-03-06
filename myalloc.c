// Ryan Earl

#include "myalloc.h"

struct block *head = NULL;  // Head of the list, empty

void *myalloc(int temp) {

    struct block *cur, *prev;

	if (head == NULL) { 
    	head = sbrk(1024);
    	head->next = NULL;
    	head->size = 1024 - PADDED_SIZE(sizeof(struct block));
    	head->in_use = 0;

        
	}

    cur = head;

    while (((cur->in_use) == 1) && (((cur->next) != NULL) || ((cur->size) < temp))) {
        
        prev = cur;
        cur = cur->next;
    }

    if (temp <= (cur->size)) {
        cur->in_use = 1;
    }

    else { return NULL; }
    
    unsigned long padded_struct_block_size = PADDED_SIZE(sizeof(struct block));

    return PTR_OFFSET(cur, padded_struct_block_size);
}

void print_data(void) {
    struct block *b = head;

    if (b == NULL) {
        printf("[empty]\n");
        return;
    }

    while (b != NULL) {
        // Uncomment the following line if you want to see the pointer values
        //printf("[%p:%d,%s]", b, b->size, b->in_use? "used": "free");
        printf("[%d,%s]", b->size, b->in_use? "used": "free");
        if (b->next != NULL) {
            printf(" -> ");
        }

        b = b->next;
    }

    printf("\n");
}

int main(void) {
	void *p;
    print_data();
    p = myalloc(16);
    print_data();
    p = myalloc(16);
    printf("%p\n", p);
}
