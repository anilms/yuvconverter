/*****************************************************************************

Module Name: <yuv400offsets.h>

Module Description:
	This file contains the offset definitions for different yuv420 formats.
	This will can be included in different files with proper macros defined
	to replace huge codes in different source files.

*****************************************************************************/



#ifdef YUV_400_PLANAR_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	int srcystride;

	ptrsrcy1 = bufsrc;
	ptrsrcy2 = bufsrc + width;
	ptrsrcy3 = bufsrc + width*2;
	ptrsrcy4 = bufsrc + width*3;
	
	srcystride  = (width)*3;
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	int destystride;

	ptrdesty1 = bufdest;
	ptrdesty2 = bufdest + width;
	ptrdesty3 = bufdest + width*2;
	ptrdesty4 = bufdest + width*3;
	
	destystride  = (width)*3;
#endif
#endif

