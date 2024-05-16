/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 10 May 2024             	*****************/
/******* Version   : 0.1                        *****************/
/******* File Name : BIT_MATH.h                 *****************/
/****************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG, BIT_NO) REG |= (1 << BIT_NO)
#define CLR_BIT(REG, BIT_NO) REG &= ~(1 << BIT_NO)
#define TOG_BIT(REG, BIT_NO) REG ^= (1 << BIT_NO)
#define GET_BIT(REG, BIT_NO) (1 & (REG >> BIT_NO))

#endif /* BIT_MATH_H */
