#include <math.h>
#include "openvml_kernel.h"
#include "simd_lns_avx.h"

void KERNEL_NAME(VMLLONG n, VML_FLOAT * a, VML_FLOAT * b, VML_FLOAT * y, VML_FLOAT * z, VML_FLOAT * other_params) {
    unsigned int m = n >> 3;
    unsigned int k = n & 7, j;
    unsigned int l = n & (~7);

    for (j = 0; j < m; j++) {
        v8sf src = _mm256_loadu_ps(a + 8 * j);
        v8sf tem = simd_ln8f(src);
        _mm256_storeu_ps(y + 8 * j, tem);
    }

    for (j = 0; j < k; j++) {
        y[j + l] = logf(a[j + l]);
    }
}
