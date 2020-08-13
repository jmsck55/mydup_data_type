
#ifndef __COMMON_H__
#define __COMMON_H__


//#define BIT64

#ifndef __INT_T__
#define __INT_T__

#ifdef BIT64
typedef long long int_t;
#else
typedef int int_t;
#endif

#endif // __INT_T__



#endif // __COMMON_H__
