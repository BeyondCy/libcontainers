#ifndef _LIBCONTAINERS_COLLISIONS_H_
#define _LIBCONTAINERS_COLLISIONS_H_

#include <stddef.h>

enum libcontainers_status
{
	LIBCONTAINERS_OK = 0,
	LIBCONTAINERS_MEM_ERROR,
	LIBCONTAINERS_KEY
};


#ifdef __cplusplus
#define LIBCONTAINERS_EXTERN_C extern "C" {
#define LIBCONTAINERS_EXTERN_C_END }
#else
#define LIBCONTAINERS_EXTERN_C
#define LIBCONTAINERS_EXTERN_C_END
#endif

#ifndef LIBCONTAINERS_NO_COLLISIONS

/* vector API */
#define vector libcontainers_vector

#define vector_new(...) libcontainers_vector_new(__VA_ARGS__)
#define vector_delete(...) libcontainers_vector_delete(__VA_ARGS__)

#define vector_size(...) libcontainers_vector_size(__VA_ARGS__)
#define vector_empty(...) libcontainers_vector_empty(__VA_ARGS__)

#define vector_resize(...) libcontainers_vector_resize(__VA_ARGS__)

#define vector_push_back(...) libcontainers_vector_push_back(__VA_ARGS__)
#define vector_pop_back(...) libcontainers_vector_pop_back(__VA_ARGS__)

#define vector_back(...) libcontainers_vector_back(__VA_ARGS__)
#define vector_at(...) libcontainers_vector_at(__VA_ARGS__)

#endif


#endif
