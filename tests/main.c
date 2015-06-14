#include <stdio.h>
#include <vector.h>


void vector_tests(void)
{
    int i;
    vector nums = vector_new(sizeof(int));

    for (i = 0; i < 1000; ++i)
        vector_push_back(nums, &i, sizeof(i));

    printf("%zu\n", vector_size(nums));


    for (i = 0; i < 1000; ++i)
    {
        printf("%d\n", *(int*)vector_at(nums, i));
    }

    vector_delete(nums);
}

int main()
{
    vector_tests();
    return 0;
}
