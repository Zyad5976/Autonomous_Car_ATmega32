/*
 * STD_TYPES.h
 *
 * Created: 9/18/2026 4:03:28 PM
 *  Author: Eltawel
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* UNSIGNED */
typedef unsigned char			u8;
typedef unsigned int			u16;
typedef unsigned long			u32;
typedef unsigned long long		u64;

/* SIGNED */
typedef signed char				s8;
typedef signed int				s16;
typedef signed long				s32;
typedef signed long long		s64;

/* FLOAT & DOUBLE */
typedef float					f32;
typedef double					f64;

/* TEXT BUFFER */
#define nul						'\0'

/* NULL PTR */
#define null					((void*)0)

/* RETURN TYPE */
typedef u8						Std_RET;

/* ERR Status */
#define E_OK					0
#define E_NOK					1

#endif /* STD_TYPES_H_ */