#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue {
    long long *a;
    long long head;
    long long tail;
    int size;
    int maxSize;
};

struct set {
    long long *a;
    int size;
    int maxSize;
};

void queue_resize(struct queue *q) {
    q->a = (long long *)realloc(q->a, 2 * q->maxSize * sizeof(long long));
    q->maxSize *= 2;
}
void set_resize(struct set *s) {
    s->a = (long long *)realloc(s->a, 2 * s->maxSize * sizeof(long long));
    s->maxSize *= 2;
}

void queue_push(struct queue *q, long long num) {
    if (q->size >= q->maxSize) {
        queue_resize(q);
    }
    q->a[q->tail] = num;
    q->tail++;
    q->size++;
}

long long queue_pop(struct queue *q) {
    long long num = q->a[q->head];
    q->head++;
    q->size--;
    return num;
}

bool queue_empty(struct queue *q) {
    return q->size == 0;
}

void set_insert(struct set *s, long long num) {
    int l = 0;
    int r = s->size - 1;
    while (l <= r) {
        int mid = l + (r - 1) / 2;

        if (s->a[mid] == num) {
            return;
        }
        if (s->a[mid] < num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (s->size >= s->maxSize) {
        set_resize(s);
    }
    s->a[s->size] = num;
    s->size++;
}

long long set_count(struct set *s, long long num) {
    int l = 0;
    int r = s->size - 1;
    while (l <= r) {
        int mid = l + (r - 1) / 2;

        if (s->a[mid] == num) {
            return 1;
        }
        if (s->a[mid] < num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return 0;
}

struct queue* new_queue() {
    struct queue *q = malloc(sizeof(struct queue));
    q->a = malloc(400 * sizeof(long long));
    q->maxSize = 400;
    q->size = 0;
    q->head = 0;
    q->tail = 0;
    return q;
}

struct set* new_set() {
    struct set *s = malloc(sizeof(struct set));
    s->a = malloc(400 * sizeof(long long));
    s->maxSize = 400;
    s->size = 0;
}

int main() {
    long long l, r;
    scanf("%lld %lld", &l, &r);

    struct queue *q = new_queue();
    struct set *visited = new_set();
    int count = 0;

    queue_push(q, 1);
    while (!queue_empty(q)) {
        printf("looping...\n");
        long long curr = queue_pop(q);
        printf("%lld\n", curr);
        if (curr <= r && set_count(visited, curr) != 1) {
            if (curr >= l) {
                count++;
            }
            queue_push(q, curr * 2);
            queue_push(q, curr * 3);
            set_insert(visited, curr);
        }
    }
    printf("%lld\n", count);
    free(q->a);
    free(visited->a);
    free(q);
    free(visited);
    return 0;
}
