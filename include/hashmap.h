#include "common.h"

struct _libcontainers_hashmap;
typedef struct _libcontainers_hashmap *libcontainers_hashmap;

typedef int (*libcontainers_hashmap_compare)(void *a, void *b);
typedef unsigned int (*libcontainers_hashmap_hash)(void *key);

LIBCONTAINERS_EXTERN_C

extern libcontainers_hashmap libcontainers_hashmap_new(size_t element_size);
extern void libcontainers_hashmap_delete(libcontainers_hashmap pmap);

extern int libcontainers_hashmap_empty(libcontainers_hashmap pmap);
extern size_t libcontainers_hashmap_size(libcontainers_hashmap pmap);
extern int libcontainers_hashmap_count(libcontainers_hashmap pmap, void *key);

extern int libcontainers_hashmap_insert(libcontainers_hashmap pmap, void *key, void *data);
extern void *libcontainers_hashmap_at(libcontainers_hashmap pmap, void *key);

extern int libcontainers_hashmap_rehash(libcontainers_hashmap pmap, size_t n);
extern void libcontainers_hashmap_set_hash_function(libcontainers_hashmap pmap, libcontainers_hashmap_hash hash_function);

#ifndef LIBCONTAINERS_HASHMAP_NAMESPACE

typedef libcontainers_hashmap hashmap;

static inline hashmap_new(size_t element_size) { return libcontainers_hashmap_new(element_size); }
static inline void hashmap_delete(hashmap pmap) { return libcontainers_hashmap_delete(pmap); }

static inline int hashmap_empty(hashmap pmap) { return libcontainers_hashmap_empty(pmap); }
static inline size_t hashmap_size(hashmap pmap) { return libcontainers_hashmap_size(pmap); }
static inline int hashmap_count(hashmap pmap, void *key) { return libcontainers_hashmap_count(pmap, key); }

static inline int hashmap_insert(hashmap pmap, void *key, void *data) { return libcontainers_hashmap_insert(pmap, key, data); }
static inline void *hashmap_at(hashmap pmap, void *key) { return libcontainers_hashmap_at(pmap, key); }

static inline int hashmap_rehash(hashmap pmap, size_t n) { return libcontainers_hashmap_rehash(pmap, n); }
static inline void hashmap_set_hash_function(hashmap pmap, hashmap_hash hash_function) { return libcontainers_hashmap_set_hash_function(pmap, hash_function); }

#endif

LIBCONTAINERS_EXTERN_C_END