#include <stdio.h>

/* Basic constants and macros */
#define WSIZE 4             /* Word and header/footer size (bytes) */
#define DSIZE 8             /* Double word size (bytes) */
#define CHUNKSIZE (1<<12)   /* Extend heap by this amount (bytes) */

#define MAX(x, y) ((x) > (y)? (x) : (y))

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc) ((size) | (alloc))

/* Read and write a word at address p */
#define GET(p) (*(unsigned int *)(p)) /* 读取和返回参数p引用的字。 这里强制类型转换是至关重要的。参数p典型地是一个(void*)指针，不可以直接进行间接引用 */
#define PUT(p, val) (*(unsigned int *)(p) = (val))

/* Read and write a word at address p */
#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

/* 块指针指向第一个有效载荷字节 */
/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp) ((char*)(bp) - WSIZE) /* brk往高位增长,所以头在低位，所以需要块指针减去一个字(4字节6) */
#define FTRP(bp) ((char*)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)

/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp) ((char*)(bp) + GET_SIZE(((char*)(bp) - WSIZE)))
#define PREV_BLKP(bp) ((char*)(bp) - GET_SIZE(((char*)(bp) - DSIZE)))

static void *coalesce(void *bp);
static void *extend_heap(size_t words);
static void *find_fit(size_t asize); /* 首次适配搜索 */
static void place(void *bp, size_t asize); /* 应该将请求块放置在空闲块的起始位置, 只有当剩余部分的大小等于或超出最小块时，才进行分割 */

static char *heap_listp; /* 总是指向序言块 */

int mm_init(void) {
    /* Creat the initial empty heap */
    if ((heap_listp = mem_sbrk(4*WSIZE)) == (void*)-1)
        return -1;
    PUT(heap_listp, 0);                          /* Alignment padding */
    PUT(heap_listp + (1*WSIZE), PACK(DSIZE, 1)); /* Prologue header */
    PUT(heap_listp + (2*WSIZE), PACK(DSIZE, 1)); /* Prologue footer */
    PUT(heap_listp + (3*WSIZE), PACK(0, 1));     /* Epilogue header */
    heap_listp += (2*WSIZE);

    /* Extend the empty heap with a free block of CHUNKSIZE bytes */
    if (extend_heap(CHUNKSIZE/WSIZE) == NULL)
        return -1;
    return 0;
}

static void *extend_heap(size_t words) {
    char* bp;
    size_t size;

    /* Allocate an even number of words to maintain alignment */
    size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;
    if ((long)(bp = mem_sbrk(size)) == -1) 
        return NULL;
    
    /* Initialize free block header/footer and epilogue header */
    PUT(HDRP(bp), PACK(size, 0));         /* Free block header(第一个头是占用空间为Epilogue header) */ 
    PUT(FTRP(bp), PACK(size, 0));         /* Free block footer */
    PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1)); /* New epilogue header*/

    /* Coalesce if previous block was free */
    return coalesce(bp);
}

void mm_free(void *bp) {
    size_t size = GET_SIZE(HDRP(bp));

    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    coalesce(bp);
}

static void *coalesce(void *bp) {
    size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
    size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
    size_t size = GET_SIZE(HDRP(bp));

    if (prev_alloc && next_alloc) {
        return bp;
    }

    else if (prev_alloc && !next_alloc) {
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        PUT(HDRP(bp), PACK(size, 0));
        PUT(FTRP(bp), PACK(size, 0));
    }

    else if (!prev_alloc && next_alloc) {
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        PUT(FTRP(bp), PACK(size, 0));
        PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
        bp = PREV_BLKP(bp);
    }

    else {
        size += GET_SIZE(HDRP(PREV_BLKP(bp))) + 
        GET_SIZE(FTRP(NEXT_BLKP(bp)));
        PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
        PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
        bp = PREV_BLKP(bp);
    }
    return bp;
}

void *mm_malloc(size_t size) {
    size_t asize;      /* Adjusted block size */
    size_t extendsize; /* Amount to extend if not fit */
    char *bp;

    /* Ignore spurious request */
    if (size == 0)
        return NULL;
    
    /* Adjust block size to include overhead and alignment reqs */
    if (size <= DSIZE)
        asize = 2*DSIZE;
    else
        asize = DSIZE * ((size + (DSIZE) + (DSIZE - 1)) / DSIZE);

    /* search the free list for a fit */
    if (bp = find_fit(asize) != NULL) {
        place(bp, asize);
        return bp;
    }

    /* No fit found. Get More memory and place the block */
    extendsize = MAX(asize, CHUNKSIZE);
    if ((bp = extend_heap(extendsize/WSIZE)) == NULL)
        return NULL;
    place(bp, asize);
    return bp;
}   

/* 首次适配搜索 */
static void *find_fit(size_t asize) {
    // 标准答案
    /* First-fit search */
    void *bp;

    for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) {
        if (!GET_ALLOC(HDRP(bp)) && (GET_SIZE(HDRP(bp) >= asize))) {
            return bp;
        }
    }

    return NULL;

    // 1 拿到开始指针 
    // char *bp = heap_listp; /* 指向开始指针 */
    // 自己做的
    // while (1) {
    //     // 1 如果这个指针的尾部 + WSIZE(4字节) 的 size==0 && alloacted == 1 则到尾部，那么返回null
    //     if ((GET_SIZE(FTRP(bp) + WSIZE) == 0) &&  (GET_ALLOC((FTRP(bp) + WSIZE) == 1)))
    //         return NULL; 

    //     // 2 找到合适的位置退出
    //     if ((GET_SIZE(HDRP(bp)) >= asize) && !(GET_ALLOC(HDRP(bp)))) {
    //         break;
    //     }

    //     // 3 找不到合适的则继续往下
    //     NEXT_BLKP(bp);
    // }

    // // 2 成功返回bp指针
    // return (void*)bp;
}

static void place(void *bp, size_t asize) {
    // 1 获取当前空闲块大小
    size_t csize = GET_SIZE(HDRP(bp));

    // 2 如果空闲块大于最小块(16)，则对空闲块切割 
    if ((csize - asize) >= 16) {
        // 需要切割
        // 设置头
        PUT(HDRP(bp), PACK(asize, 1));

        // 设置尾 (头中的size变了,则尾也变了)
        PUT(FTRP(bp), PACK(asize, 1));

        // 设置切割块头
        PUT(HDRP(NEXT_BLKP(bp)), PACK(csize - asize, 0));

        // 设置切割块尾
        PUT(FTRP(NEXT_BLKP(bp)), PACK(csize - asize, 0));
    }

    // 3 不切割则直接将b的size全给掉
    // 设置头
    PUT(HDRP(bp), PACK(csize, 1));
    
    // 设置尾
    PUT(FTRP(bp), PACK(csize, 1)); 
}

int main() {
    printf(" 7/8 = %d\n", 7/8);
}