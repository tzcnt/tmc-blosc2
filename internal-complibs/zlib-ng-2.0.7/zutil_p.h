/* zutil_p.h -- Private inline functions used internally in zlib-ng
 *
 */

#ifndef ZUTIL_P_H
#define ZUTIL_P_H

#if defined(HAVE_POSIX_MEMALIGN) && !defined(_POSIX_C_SOURCE)
#  define _POSIX_C_SOURCE 200112L  /* For posix_memalign(). */
#endif

#if defined(__APPLE__) || defined(HAVE_POSIX_MEMALIGN) || defined(HAVE_ALIGNED_ALLOC)
#  include <stdlib.h>
#elif defined(__FreeBSD__)
#  include <stdlib.h>
#  include <malloc_np.h>
#else
#  include <malloc.h>
#endif

/* Function to allocate 16 or 64-byte aligned memory */
static inline void *zng_alloc(size_t size) {
#ifdef HAVE_POSIX_MEMALIGN
    void *ptr;
    return posix_memalign(&ptr, 64, size) ? NULL : ptr;
#elif defined(_WIN32)
    return (void *)_aligned_malloc(size, 64);
#elif defined(__APPLE__)
    return (void *)malloc(size);     /* MacOS always aligns to 16 bytes */
#elif defined(HAVE_ALIGNED_ALLOC)
    return (void *)aligned_alloc(64, size);
#else
    return (void *)memalign(64, size);
#endif
}

/* Function that can free aligned memory */
static inline void zng_free(void *ptr) {
#if defined(_WIN32)
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}

#endif
