#ifndef _COMPLEX_TYPE_DECLARE_T_
struct COMPLEX 
{
    float real;
    float imaginary;
};
typedef struct COMPLEX complex_type;
#define _COMPLEX_TYPE_DECLARE_T_
#endif

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

extern complex_type complex(float r, float i);
extern void print_complex(complex_type B);
extern complex_type add_complex(complex_type A, complex_type B);
extern complex_type sub_complex(complex_type A, complex_type B);
extern complex_type mul_complex(complex_type A, complex_type B);
extern complex_type complex_conjugate(complex_type A);
extern float absolute(complex_type A);
extern complex_type div_complex(complex_type A, complex_type B);
extern complex_type sqrt_complex(complex_type A);

#endif