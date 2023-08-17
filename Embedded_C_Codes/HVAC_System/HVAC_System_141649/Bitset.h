#ifndef BITSET_H
#define BITSET_H

#define SET_BIT(PORT,BIT) PORT|= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&= ~(1<<BIT)
#define READ_BIT(PORT,BIT) PORT &= (1<<BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^=(1<<BIT)

#endif // BITSET_H
