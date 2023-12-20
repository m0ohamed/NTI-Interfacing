
// guard
#ifndef common_macros
#define common_macros

//set_bit
#define SET_BIT(REG,BIT)      (REG = REG | (1<<BIT))

//clear bit
#define CLEAR_BIT(REG,BIT)    (REG = REG & (~(1<<BIT)))
//Get Bit
#define GET_BIT(REG,BIT_NUM) ( ( REG & (1<<BIT_NUM) ) >> BIT_NUM )
//shift register left
#define LSHIFT_REG(REG,NO)   ( REG << NO)

//shift register right
#define RSHIFT_REG(REG,NO)   ( REG >> NO)

//toggle bit
#define TOGGLE_BIT(REG,BIT)   (REG = REG ^ (1<<BIT))

#define TGLWithOUTASSIGN(REG,NUM)           (REG^(1<<NUM))
//check if bit is set
#define BIT_IS_SET(REG,BIT)   (REG & (1<<BIT))

//check if bit is clear
#define BIT_IS_CLEAR(REG,BIT) (!(REG & (1<<BIT)))

// circular to left
#define CRSHIFT_REG(REG,NUM)          (REG = (REG<<NUM) | (REG>>((sizeof(REG)*8)-NUM)))

// circuler to right
#define CLSHIFT_REG(REG,NUM)          (REG = (REG>>num) | (REG<<((sizeof(REG)*8)-NUM)))

//assign value to register
#define ASSIGN_REG(REG,VALUE)          (REG = (REG & 0) | (VALUE))

//set register
#define SET_REG(REG)          (REG = ~(REG & 0))

//clear register
#define CLR_REG(REG)          (REG = (REG & 0))

//toggle bit
#define TGL_BIT(REG,BIT)   (REG = REG ^ (1<<BIT))

//toggle REG
#define TGL_REG(REG)   (REG = ~(REG))

//set high nibble
#define SET_H_NIB(REG)  (REG |= (((~0)<<(sizeof(REG)*4))))


//set low nibble
#define SET_L_NIB(REG)  (REG |= (((~0)>>(sizeof(REG)*4))))

//clear high nibble
#define CLR_H_NIB(REG)  (REG &= (((~0)>>(sizeof(REG)*4))))

//clear low nibble
#define CLR_L_NIB(REG)  (REG &= (((~0)<<(sizeof(REG)*4))))

//get high niblle
#define GET_H_NIB(REG)     ( ( ( (~0)<<(sizeof(REG)*4) ) & REG)>>(sizeof(REG)*4) )

//get low niblle
#define GET_L_NIB(REG)     ( ( ( (~0)>>(sizeof(REG)*4) ) & REG) )

//ASSIGN high nibble
#define ASSIGN_H_NIB(REG,VALUE)  (REG |= (((~0)<<(sizeof(REG)*4)) & VALUE))

//ASSIGN low nibble
#define ASSIGN_L_NIB(REG,VALUE)  (REG |= (((~0)>>(sizeof(REG)*4)) & VALUE))

//toggle high nibble
#define TGL_H_NIB(REG)  (REG ^= ((~0)<<(sizeof(REG)*4)))

//toggle low nibble
#define TGL_L_NIB(REG)  (REG ^= ((~0)>>(sizeof(REG)*4)))

//SWAP nibble
#define SWAP_NIB(REG)  ( REG = (REG >> (sizeof(REG)*4)) |  (REG << (sizeof(REG)*4))  )

#endif
