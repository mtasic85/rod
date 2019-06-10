#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <threads.h>

/*
 * _RResult
 */
typedef enum _RResultType {
    _R_OK,
    _R_ERR
} _RResultType;

typedef union _RResultHolder {
    void * ok;
    char * err;
} _RResultHolder;

typedef struct _RResult {
    _RResultType type;
    _RResultHolder value;
} _RResult;

/*
 * _ROption
 */
typedef enum _ROptionType {
    _R_SOME,
    _R_NONE
} _ROptionType;

typedef struct _ROption {
    _ROptionType type;
    void * value;
} _ROption;

/*
 * _RArray
 */
typedef struct _RArray {
    uint64_t cap;
    uint64_t len;
    uint64_t item_size;
    char * data;
} _RArray;

/*
 * _RArray
 */
_RResult * _RArray_new(uint64_t cap, uint64_t len, uint64_t item_size);
void _RArray_free(_RArray * self);
void _RArray_append(_RArray * self, void * item);
void _RArray_prepend(_RArray * self, void * item);
void _RArray_remove(_RArray * self, void * item);
void _RArray_insert(_RArray * self, uint64_t index, void * item);
uint64_t _RArray_find(_RArray * self, void * item);
void * _RArray_getitem(_RArray * self, uint64_t index);
void _RArray_setitem(_RArray * self, uint64_t index, void * item);
void _RArray_delitem(_RArray * self, uint64_t index);

_RResult _RArray_new(uint64_t cap, uint64_t len, uint64_t item_size) {
    _RArray * self = (_RArray *)malloc(sizeof(_RArray));
    self->cap = cap;
    self->len = len;
    self->item_size = item_size;
    self->data = (char*)malloc(self->cap * self->item_size);

    _RResult res = {.type: _R_SOME, .value: {.ok: (void *)self }};
    return res;
}

void _RArray_free(_RArray * self) {
    free(self->data);
    free(self);
}

void _RArray_append(_RArray * self, void * item) {
    char * reallocated_data = NULL;

    if (self->len == self->cap) {
        self->cap *= 2;
        reallocated_data = (char *)realloc(self->data, self->cap * self->item_size * 2);

        if (reallocated_data != NULL) {

        }
    }
}

int main(int argc, char * argv[]) {
    _RResult r0 = _RArray_new(8, 0, sizeof(int));
    _RArray * a0 = r0.v
    _RArray_free(a0);
    return 0;
}
