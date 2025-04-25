#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

/* Define fixed-point type and fraction bits. */
typedef int fixed_t;
#define FP_SHIFT_AMOUNT 14 /* Number of fractional bits */

/* Convert between int and fixed-point */
#define FP_CONST(n) ((fixed_t)(n << FP_SHIFT_AMOUNT))
#define FP_INT_PART(x) (x >> FP_SHIFT_AMOUNT)
#define FP_ROUND(x) ((x >= 0) ? ((x + (1 << (FP_SHIFT_AMOUNT - 1))) >> FP_SHIFT_AMOUNT) \
                              : ((x - (1 << (FP_SHIFT_AMOUNT - 1))) >> FP_SHIFT_AMOUNT))

/* Fixed-point arithmetic */
#define FP_ADD(x, y) (x + y)
#define FP_SUB(x, y) (x - y)
#define FP_ADD_MIX(x, n) (x + FP_CONST(n))
#define FP_SUB_MIX(x, n) (x - FP_CONST(n))
#define FP_MULT(x, y) ((fixed_t)(((int64_t) x) * y >> FP_SHIFT_AMOUNT))
#define FP_DIV(x, y) ((fixed_t)((((int64_t) x) << FP_SHIFT_AMOUNT) / y))
#define FP_MULT_MIX(x, n) (x * n)
#define FP_DIV_MIX(x, n) (x / n)

#endif /* threads/fixed_point.h */
