#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <threads.h>

/*
 * _RResult
 */
typedef enum _R_ResultType {
    _R_OK,
    _R_ERR
} _R_ResultType;

typedef union _R_ResultHolder {
    void * ok;
    char * err;
} _R_ResultHolder;

typedef struct _R_Result {
    _R_ResultType type;
    _R_ResultHolder value;
} _R_Result;

/*
 * _ROption
 */
typedef enum _R_OptionType {
    _R_SOME,
    _R_NONE
} _R_OptionType;

typedef struct _R_Option {
    _R_OptionType type;
    void * value;
} _R_Option;

/*
 * _RArray
 */
typedef struct _R_Array {
    uint64_t cap;
    uint64_t len;
    uint64_t item_size;
    char * data;
} _R_Array;

/*
 * _R_Array
 */
_R_Result _R_Array_new(uint64_t cap, uint64_t len, uint64_t item_size);
void _R_Array_free(_R_Array * self);
void _R_Array_append(_R_Array * self, void * item);
void _R_Array_prepend(_R_Array * self, void * item);
void _R_Array_remove(_R_Array * self, void * item);
void _R_Array_insert(_R_Array * self, uint64_t index, void * item);
uint64_t _R_Array_find(_R_Array * self, void * item);
void * _R_Array_getitem(_R_Array * self, uint64_t index);
void _R_Array_setitem(_R_Array * self, uint64_t index, void * item);
void _R_Array_delitem(_R_Array * self, uint64_t index);

_R_Result _R_Array_new(uint64_t cap, uint64_t len, uint64_t item_size) {
    _R_Array * self = (_R_Array *)malloc(sizeof(_R_Array));
    self->cap = cap;
    self->len = len;
    self->item_size = item_size;
    self->data = (char*)malloc(self->cap * self->item_size);

    _R_Result res = {
        .type = _R_OK,
        .value = {
            .ok = (void *)self
        }
    };

    // _RResult res = _RRESULT_OK()

    return res;
}

void _R_Array_free(_R_Array * self) {
    free(self->data);
    free(self);
}

void _R_Array_append(_R_Array * self, void * item) {
    char * reallocated_data = NULL;

    if (self->len == self->cap) {
        self->cap *= 2;
        reallocated_data = (char *)realloc(self->data, self->cap * self->item_size * 2);

        if (reallocated_data != NULL) {

        }
    }
}

void * _R_try(_R_Result r) {
    void * v = NULL;

    switch (r.type) {
        case _R_OK:
            v = r.value.ok;
            printf("value[%d]: %p\n", __LINE__, r.value.ok);
            break;
        case _R_ERR:
            printf("error[%d]: %s\n", __LINE__, r.value.err);
            exit(1);
            break;
    }

    return v;
}

int main(int argc, char * argv[]) {
    _R_Result r0 = _R_Array_new(8, 0, sizeof(int));
    _R_Array * a0 = NULL;

    switch (r0.type) {
        case _R_OK:
            printf("value[%d]: %p\n", __LINE__, r0.value.ok);
            a0 = r0.value.ok;
            break;
        case _R_ERR:
            printf("error[%d]: %s\n", __LINE__, r0.value.err);
            break;
    }

    _R_Array * a1 = _R_try(_R_Array_new(8, 0, sizeof(int)));

    _R_Array_free(a0);
    _R_Array_free(a1);
    return 0;
}
