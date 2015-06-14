#include "../include/hashmap.h"

#define LIBCONTAINERS_HASHMAP_INITIAL_BUCKET_SIZE 100

struct _libcontainers_hashmap_node
{
	void *key;
	void *data;
	unsigned int hash;
};

typedef struct _libcontainers_hashmap_node *libcontainers_hashmap_node;

struct _libcontainers_hashmap
{
	size_t _size;
	size_t _table_size;
	libcontainers_hashmap_node _buckets;
	libcontainers_hashmap_hash _hash_function;
};

void libcontainers_hashmap_set_hash_function(libcontainers_hashmap pmap, libcontainers_hashmap_hash hash_function)
{
	pmap->_hash_function = hash_function;
}

int libcontainers_hashmap_insert(libcontainers_hashmap pmap, void *key, void *data)
{
}

int libcontainers_hashmap_rehash(libcontainers_hashmap pmap, size_t n)
{
	int i, old_size = pmap->_size, old_table_size = pmap->_table_size;
	libcontainers_hashmap_node old_buckets = pmap->_buckets;

	if (pmap->_table_size >= n || pmap->_size >= n)
		return;
		
	libcontainers_hashmap_node node = (libcontainers_hashmap_node) malloc(sizeof(struct _libcontainers_hashmap_node) * n);
	
	if (node == NULL)
		return 0;
	
	pmap->_table_size = n;
	pmap->_size = 0;
	
	for (i = 0; i < old_size; ++i)
	{
		if (!libcontainers_hashmap_insert(pmap, old_buckets[i].key, old_buckets[i].data))
		{
			/*
			pmap->_size = old_size;
			pmap->_table_size = old_table_size;
			pmap->_buckets = old_buckets;
			free(node);
			*/
			return 0;
		}
	}
	
	free(old_buckets);
	
	return 1;
}

libcontainers_hashmap libcontainers_hashmap_new(size_t element_size)
{
	libcontainers_hashmap pmap = (libcontainers_hashmap) malloc(sizeof(struct _libcontainers_hashmap));
	
	if (pmap == NULL)
		return NULL;
	
	pmap->_buckets = (libcontainers_hashmap_node) calloc(LIBCONTAINERS_HASHMAP_INITIAL_BUCKET_SIZE * sizeof(struct _libcontainers_hashmap_node));
	
	if (pmap->_buckets == NULL)
	{
		free(pmap)
		return NULL;
	}
	
	pmap->_table_size = LIBCONTAINERS_HASHMAP_INITIAL_BUCKET_SIZE;
	pmap->_size = 0;
	
	return pmap;
}

void libcontainers_hashmap_delete(libcontainers_hashmap pmap)
{
	if (pmap)
	{
		if (pmap->_data)
		{
			free(pmap->_data);
			pmap->_data = NULL;
		}
	
		free(pmap);
		pmap = NULL;
	}
}

int libcontainers_hashmap_empty(libcontainers_hashmap pmap)
{
	return pmap->_size == 0;
}

size_t libcontainers_hashmap_size(libcontainers_hashmap pmap)
{
	return pmap->_size;
}

void *libcontainers_hashmap_at(libcontainers_hashmap pmap, void *key)
{
	return ;
}

int libcontainers_hashmap_count(libcontainers_hashmap pmap, void *key)
{
	return 1;
	return 0;
}

static inline libcontainers_hashmap_node libcontainers_hashmap_node_new(int hash, void *key, void *data)
{
	libcontainers_hashmap_node node = (libcontainers_hashmap_node) malloc(sizeof(struct _libcontainers_hashmap_node));
	
	if (node == NULL)
		return NULL;
		
	node->key = key;
	node->data = data;
	node->hash = hash;
	
	return node;
}

static inline void libcontainers_hashmap_node_delete(libcontainers_hashmap_node node)
{
	if (node)
	{
		free(node);
		node = NULL;
	}
}