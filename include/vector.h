#ifndef _LIBCONTAINERS_VECTOR_H_
#define _LIBCONTAINERS_VECTOR_H_

#include "common.h"

struct _libcontainers_vector;
typedef struct _libcontainers_vector *libcontainers_vector;

LIBCONTAINERS_EXTERN_C

libcontainers_vector libcontainers_vector_new(size_t element_size);
void libcontainers_vector_delete(libcontainers_vector pvec);

size_t libcontainers_vector_size(libcontainers_vector pvec);
int libcontainers_vector_empty(libcontainers_vector pvec);

int libcontainers_vector_resize(libcontainers_vector pvec, size_t n);

int libcontainers_vector_push_back(libcontainers_vector pvec, void *data, size_t element_size);
void libcontainers_vector_pop_back(libcontainers_vector pvec);

void *libcontainers_vector_back(libcontainers_vector pvec);
void *libcontainers_vector_at(libcontainers_vector pvec, size_t index);

LIBCONTAINERS_EXTERN_C_END

#endif
