/*
 * BIT_MATH.h
 *
 * Created: 9/18/2026 4:03:42 PM
 *  Author: Eltawel
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define BIT_MASK					1

#define SET_BIT(REG,BIT)			((REG) |= (BIT_MASK << (BIT)))
#define CLEAR_BIT(REG,BIT)			((REG) &= ~(BIT_MASK << (BIT)))
#define TOGGLE_BIT(REG,BIT)			((REG) ^= (BIT_MASK << (BIT)))
#define GET_BIT(REG,BIT)			(((REG) >> (BIT)) & BIT_MASK)

#endif /* BIT_MATH_H_ */