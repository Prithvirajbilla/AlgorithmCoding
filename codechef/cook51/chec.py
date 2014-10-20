def partitions(n):
    if n == 0:
        yield []
    else:
        for partial_partition in partitions(n-1):
            for i in range(len(partial_partition)):
                copy_partition = partial_partition[:]
                copy_partition[i] += (n,)
                yield copy_partition
            yield partial_partition + [(n,)]

print partitions(5)