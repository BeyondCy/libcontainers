#include <malloc.h>
#include <string.h>
#include "../include/vector.h"

struct _libcontainers_vector
{
    unsigned char *_mem;        /* buffer for data items */
    size_t _element_size;       /* sizeof(element) */
    size_t _size;               /* count of elements */
    size_t _max_size;           /* container capacity */
    unsigned long _reserve;
};

libcontainers_vector libcontainers_vector_new(size_t element_size)
{
    libcontainers_vector pvec = (libcontainers_vector) malloc(sizeof(struct _libcontainers_vector));

    if (pvec == NULL)
        return NULL;

    pvec->_reserve = 10;
    pvec->_max_size = pvec->_reserve;
    pvec->_size = 0;
    pvec->_element_size = element_size;
    pvec->_mem = (unsigned char *) malloc(pvec->_element_size * pvec->_max_size);

    if (pvec->_mem == NULL)
    {
        free(pvec);
        return NULL;
    }

    return pvec;
}

void libcontainers_vector_delete(libcontainers_vector pvec)
{
    free(pvec->_mem);
    free(pvec);
}

int libcontainers_vector_push_back(libcontainers_vector pvec, void *data, size_t element_size)
{
    if (pvec->_element_size != element_size)
        return 0;

    if (pvec->_size == pvec->_max_size)
    {
        size_t new_size = (size_t)(((float)pvec->_size) * 1.5f);

        if (!libcontainers_vector_resize(pvec, new_size))
            return 0;
    }

    memcpy((void *)(pvec->_mem + (pvec->_size * pvec->_element_size)), data, pvec->_element_size);

    ++pvec->_size;

    return 1;
}

size_t libcontainers_vector_size(libcontainers_vector pvec)
{
    return pvec->_size;
}

int libcontainers_vector_empty(libcontainers_vector pvec)
{
    return pvec->_size == 0;
}

int libcontainers_vector_resize(libcontainers_vector pvec, size_t n)
{
    /* consider realloc() instead */
    const size_t new_size = pvec->_element_size * n;
    unsigned char *mem = (unsigned char*) malloc(new_size);

    if (mem == NULL)
        return 0;


    memcpy(mem, pvec->_mem, new_size);
    free(pvec->_mem);

    pvec->_mem = mem;

    pvec->_max_size = n;

    if (pvec->_size > n)
        pvec->_size = n;

    return 1;
}

void *libcontainers_vector_at(libcontainers_vector pvec, size_t index)
{
    if (index >= pvec->_size)
        return NULL;

    return (void*)(pvec->_mem + (index * pvec->_element_size));
}

void *libcontainers_vector_back(libcontainers_vector pvec)
{
    if (pvec->_size == 0)
        return NULL;

    return (void*)(pvec->_mem + ((pvec->_size - 1) * pvec->_element_size));
}

void libcontainers_vector_pop_back(libcontainers_vector pvec)
{
    if (pvec->_size == 0)
        return;

    --pvec->_size;

    /* not necessary to zero memory */
}


