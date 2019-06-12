#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <threads.h>

enum R_Type;
union R_Value;
struct R_Object;
struct R_Struct;
struct R_Union;
struct R_Enum;

typedef enum R_Type {
    R_TYPE_B,
    R_TYPE_I8,
    R_TYPE_U8,
    R_TYPE_I16,
    R_TYPE_U16,
    R_TYPE_I32,
    R_TYPE_U32,
    R_TYPE_I64,
    R_TYPE_U64,
    R_TYPE_F32,
    R_TYPE_F64,
    R_TYPE_C,
    R_TYPE_P,
    R_TYPE_STRUCT
} R_Type;

typedef union R_Value {
    bool b;
    int8_t i8;
    uint8_t u8;
    int16_t i16;
    uint16_t u16;
    int32_t i32;
    uint32_t u32;
    int64_t i64;
    uint64_t u64;
    float f32;
    double f64;
    char *c;
    void *p;
} R_Value;

typedef struct R_Object {
    uint64_t rc;
    R_Type type;
    R_Value value;
    // Own, Borrow, Mut Borrow
} R_Object;

typedef struct R_Struct {
    // char *name;
    // char **attrs;
    // int *sizes;

} R_Struct;

typedef struct R_Union {

} R_Union;

typedef struct R_Enum {

} R_Enum;

/*
 * RResult
 */
typedef enum R_ResultType {
    R_RESULT_TYPE_OK,
    R_RESULT_TYPE_ERR
} R_ResultType;

typedef struct R_Result {
    R_ResultType type;
    R_Object value;
} R_Result;

/*
 * _RArray
 */
/*typedef struct _R_Array {
    uint64_t cap;
    uint64_t len;
    uint64_t item_size;
    char * data;
} _R_Array;*/

/*
 * _R_Array
 */
/*_R_Result _R_Array_new(uint64_t cap, uint64_t len, uint64_t item_size);
_R_Result _R_Array_free(_R_Array * self);
_R_Result _R_Array_append(_R_Array * self, void * item);
_R_Result _R_Array_prepend(_R_Array * self, void * item);
_R_Result _R_Array_remove(_R_Array * self, void * item);
_R_Result _R_Array_insert(_R_Array * self, uint64_t index, void * item);
_R_Result _R_Array_find(_R_Array * self, void * item);
_R_Result _R_Array_getitem(_R_Array * self, uint64_t index);
_R_Result _R_Array_setitem(_R_Array * self, uint64_t index, void * item);
_R_Result _R_Array_delitem(_R_Array * self, uint64_t index);

_R_Result _R_Array_new(uint64_t cap, uint64_t len, uint64_t item_size) {
    _R_Result res;

    _R_Array * self = (_R_Array *)malloc(sizeof(_R_Array));
    self->cap = cap;
    self->len = len;
    self->item_size = item_size;
    self->data = (char*)malloc(self->cap * self->item_size);
    
    res = (_R_Result){.type = _R_OK, .value = {.ok = (void *)self}};
    return res;
}

_R_Result _R_Array_free(_R_Array * self) {
    _R_Result res;

    free(self->data);
    free(self);
    
    res = (_R_Result){.type = _R_OK, .value = {.ok = (void*)self}};
    return res;
}

_R_Result _R_Array_append(_R_Array * self, void * item) {
    _R_Result res;
    char * reallocated_data = NULL;

    if (self->len == self->cap) {
        reallocated_data = (char *)realloc(self->data, self->cap * self->item_size * 2);

        if (reallocated_data == NULL) {
            res = (_R_Result){.type = _R_ERR, .value = {.err = "realloc failed"}};
            return res;
        }

        self->cap *= 2;
        self->data = reallocated_data;
    }

    // self->data
    self->len++;

    res = (_R_Result){.type = _R_OK, .value = {.ok = (void*)self}};
    return res;
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
        default:
            printf("error[%d]: _R_try supports only _R_OK and _R_ERR\n", __LINE__);
    }

    return v;
}*/

void test_i8(void) {
    R_Object i8_0 = {
        .type = R_TYPE_I8,
        .value = {.i8 = 10}
    };

    R_Object i8_1 = {
        .type = R_TYPE_I8,
        .value = {.i8 = 20}
    };

    R_Object i8_2 = {
        .type = R_TYPE_I8,
        .value = {.i8 = i8_0.value.i8 + i8_1.value.i8}
    };

    printf("i8_2=%d\n", i8_2.value.i8);
}

int main(int argc, char * argv[]) {
    /*
     * r0
     */
    /*_R_Result r0 = _R_Array_new(8, 0, sizeof(int));
    _R_Array * a0 = NULL;

    switch (r0.type) {
        case _R_OK:
            printf("value[%d]: %p\n", __LINE__, r0.value.ok);
            a0 = r0.value.ok;
            break;
        case _R_ERR:
            printf("error[%d]: %s\n", __LINE__, r0.value.err);
            break;
        default:
            printf("error[%d]: supports only _R_OK and _R_ERR\n", __LINE__);
    }

    _R_Array_free(a0);*/

    /*
     * r1
     */
    /*_R_Array * a1 = _R_try(_R_Array_new(8, 0, sizeof(int)));
    _R_Array_free(a1);*/

    test_i8();

    R_Object i8_0 = {
        .type = R_TYPE_I8,
        .value = {.i8 = 10}
    };

    R_Object i8_1 = {
        .type = R_TYPE_I8,
        .value = {.i8 = 20}
    };

    R_Object _arr_0[2] = {i8_0, i8_1};

    R_Object arr_0 = {
        .type = R_TYPE_I8,
        .value = {.p = &_arr_0}
    };

    R_Object struct_0 = {
        .type = R_TYPE_STRUCT,
        .value = {.c = "i8,i8"}
    };

    /**/
    R_Object r_array_struct = {
        .type = R_TYPE_STRUCT,
        .value = {.c =
            "len u64;"
            "cap u64;"
            "data p;"
        }
    };

    /*
    R_Object r_array_0 = {
        .type: R_TYPE_STRUCT_INST,
        .value = {.p = R_Object_new(
            r_array_struct,
            (R_Object){.type = R_TYPE_U64, .value = {.u64 = 0}},
            (R_Object){.type = R_TYPE_U64, .value = {.u64 = 8}},
            (R_Object){.type = R_TYPE_P, .value = {.p = malloc(8 * sizeof(R_Object))}},
        )}
    };
    */

    return 0;
}
