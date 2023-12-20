//guard
#ifndef std_types
#define std_types


//boolean data type
typedef unsigned char               boolean;

#ifndef         True
#define         True                (1u)
#endif

#ifndef         False
#define         False               (0u)
#endif

//define HIGH and LOW signals
#define         LOGIC_HIGH          (1u)
#define         LOGIC_LOW           (0u)

//define null pointer
#define         Null_ptr            ((void* )0)


//define data types
typedef         unsigned char           uint8;   // 255<<<<<<<<0
typedef         signed char             sint8;   // 127<<<<<<<<<-128
typedef         unsigned short   int    uint16;  // 2 byte 0 <<<<<<65535
typedef         signed short  int       sint16;  // 2 bytes -32,768<<<<<<<<32,767
typedef         unsigned long int       uint32;  // 4 byte 0<<<<<<<<<<<4294967295
typedef         signed long int         sint32;  // 4 byte -2147483648<<<<<<2147483647
typedef         unsigned long long      uint64;  //8 bytes
typedef         signed long long        sint64;  //8 bytes
typedef         float                   float32;  //4 bytes
typedef         double                  double64;  //8 bytes

//define pointer
typedef      unsigned char*           pu8;
typedef      unsigned short*          pu16;
typedef      unsigned long*           pu32;
typedef      unsigned long long*      pu64;

#define CONC(B7,B6,B5,B4,B3,B2,B1,B0)         CONCHelper(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONCHelper(B7,B6,B5,B4,B3,B2,B1,B0)     0b##B7##B6##B5##B4##B3##B2##B1##B0

//end if std_types
#endif
