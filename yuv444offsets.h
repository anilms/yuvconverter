/*****************************************************************************

Module Name: <yuv444offsets.h>

Module Description:
	This file contains the offset definitions for different yuv444 formats.
	This will can be included in different files with proper macros defined
	to replace huge codes in different source files.

*****************************************************************************/



#ifdef YUV_444_PLANAR_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;
	ptrsrcy2  = bufsrc + width;
	ptrsrcy3  = bufsrc + width*2;
	ptrsrcy4  = bufsrc + width*3;

	ptrsrccb1 = bufsrc + width*height;
	ptrsrccb2 = bufsrc + width*height + width;
	ptrsrccb3 = bufsrc + width*height + width*2;
	ptrsrccb4 = bufsrc + width*height + width*3;
	
	ptrsrccr1 = bufsrc + ((width*height)<<1);	
	ptrsrccr2 = bufsrc + ((width*height)<<1) + width;
	ptrsrccr3 = bufsrc + ((width*height)<<1) + width*2;
	ptrsrccr4 = bufsrc + ((width*height)<<1) + width*3;

	srcystride  = width*3;
	srcccstride = width*3; 
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest;
	ptrdesty2  = bufdest + width;
	ptrdesty3  = bufdest + width*2;
	ptrdesty4  = bufdest + width*3;

	ptrdestcb1 = bufdest + width*height;
	ptrdestcb2 = bufdest + width*height + width;
	ptrdestcb3 = bufdest + width*height + width*2;
	ptrdestcb4 = bufdest + width*height + width*3;
	
	ptrdestcr1 = bufdest + ((width*height)<<1);	
	ptrdestcr2 = bufdest + ((width*height)<<1) + width;
	ptrdestcr3 = bufdest + ((width*height)<<1) + width*2;
	ptrdestcr4 = bufdest + ((width*height)<<1) + width*3;

	destystride  = width*3;
	destccstride = width*3; 
#endif
#endif


#ifdef YUV_444_PLANAR_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;			
	ptrsrcy2  = bufsrc + width;
	ptrsrccb1 = bufsrc + (width*height>>1);
	ptrsrccb2 = bufsrc + (width*height>>1) + width;
	ptrsrccr1 = bufsrc + (width*height) ;
	ptrsrccr2 = bufsrc + (width*height) + width;

	ptrsrcy3  = bufsrc + (width*height) + ((width*height)>>1);
	ptrsrcy4  = bufsrc + (width*height) + ((width*height)>>1) + width;
	ptrsrccb3 = bufsrc + ((width*height)<<1);
	ptrsrccb4 = bufsrc + ((width*height)<<1) + width;
	ptrsrccr3 = bufsrc + ((width*height)<<1) + ((width*height)>>1);
	ptrsrccr4 = bufsrc + ((width*height)<<1) + ((width*height)>>1) + width;

	srcystride  = width;
	srcccstride = width; 
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest;			
	ptrdesty2  = bufdest + width;
	ptrdestcb1 = bufdest + (width*height>>1);
	ptrdestcb2 = bufdest + (width*height>>1) + width;
	ptrdestcr1 = bufdest + (width*height) ;
	ptrdestcr2 = bufdest + (width*height) + width;

	ptrdesty3  = bufdest + (width*height) + ((width*height)>>1);
	ptrdesty4  = bufdest + (width*height) + ((width*height)>>1) + width;
	ptrdestcb3 = bufdest + ((width*height)<<1);
	ptrdestcb4 = bufdest + ((width*height)<<1) + width;
	ptrdestcr3 = bufdest + ((width*height)<<1) + ((width*height)>>1);
	ptrdestcr4 = bufdest + ((width*height)<<1) + ((width*height)>>1) + width;

	destystride  = width;
	destccstride = width; 
#endif
#endif


#ifdef YVU_444_PLANAR_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;
	ptrsrcy2  = bufsrc + width;
	ptrsrcy3  = bufsrc + width*2;
	ptrsrcy4  = bufsrc + width*3;

	ptrsrccr1 = bufsrc + width*height;
	ptrsrccr2 = bufsrc + width*height + width;
	ptrsrccr3 = bufsrc + width*height + width*2;
	ptrsrccr4 = bufsrc + width*height + width*3;
	
	ptrsrccb1 = bufsrc + ((width*height)<<1);	
	ptrsrccb2 = bufsrc + ((width*height)<<1) + width;
	ptrsrccb3 = bufsrc + ((width*height)<<1) + width*2;
	ptrsrccb4 = bufsrc + ((width*height)<<1) + width*3;

	srcystride  = width*3;
	srcccstride = width*3;
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest;
	ptrdesty2  = bufdest + width;
	ptrdesty3  = bufdest + width*2;
	ptrdesty4  = bufdest + width*3;

	ptrdestcr1 = bufdest + width*height;
	ptrdestcr2 = bufdest + width*height + width;
	ptrdestcr3 = bufdest + width*height + width*2;
	ptrdestcr4 = bufdest + width*height + width*3;
	
	ptrdestcb1 = bufdest + ((width*height)<<1);	
	ptrdestcb2 = bufdest + ((width*height)<<1) + width;
	ptrdestcb3 = bufdest + ((width*height)<<1) + width*2;
	ptrdestcb4 = bufdest + ((width*height)<<1) + width*3;

	destystride  = width*3;
	destccstride = width*3;
#endif
#endif


#ifdef YVU_444_PLANAR_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;			
	ptrsrcy2  = bufsrc + width;
	ptrsrccr1 = bufsrc + (width*height>>1);
	ptrsrccr2 = bufsrc + (width*height>>1) + width;
	ptrsrccb1 = bufsrc + (width*height) ;
	ptrsrccb2 = bufsrc + (width*height) + width;

	ptrsrcy3  = bufsrc + (width*height) + ((width*height)>>1);
	ptrsrcy4  = bufsrc + (width*height) + ((width*height)>>1) + width;
	ptrsrccr3 = bufsrc + ((width*height)<<1);
	ptrsrccr4 = bufsrc + ((width*height)<<1) + width;
	ptrsrccb3 = bufsrc + ((width*height)<<1) + ((width*height)>>1);
	ptrsrccb4 = bufsrc + ((width*height)<<1) + ((width*height)>>1) + width;

	srcystride  = width;
	srcccstride = width; 
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest;			
	ptrdesty2  = bufdest + width;
	ptrdestcr1 = bufdest + (width*height>>1);
	ptrdestcr2 = bufdest + (width*height>>1) + width;
	ptrdestcb1 = bufdest + (width*height) ;
	ptrdestcb2 = bufdest + (width*height) + width;

	ptrdesty3  = bufdest + (width*height) + ((width*height)>>1);
	ptrdesty4  = bufdest + (width*height) + ((width*height)>>1) + width;
	ptrdestcr3 = bufdest + ((width*height)<<1);
	ptrdestcr4 = bufdest + ((width*height)<<1) + width;
	ptrdestcb3 = bufdest + ((width*height)<<1) + ((width*height)>>1);
	ptrdestcb4 = bufdest + ((width*height)<<1) + ((width*height)>>1) + width;

	destystride  = width;
	destccstride = width; 
#endif
#endif





#ifdef UYV_444_PLANAR_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrccb1  = bufsrc;
	ptrsrccb2  = bufsrc + width;
	ptrsrccb3  = bufsrc + width*2;
	ptrsrccb4  = bufsrc + width*3;

	ptrsrcy1 = bufsrc + width*height;
	ptrsrcy2 = bufsrc + width*height + width;
	ptrsrcy3 = bufsrc + width*height + width*2;
	ptrsrcy4 = bufsrc + width*height + width*3;
	
	ptrsrccr1 = bufsrc + ((width*height)<<1);
	ptrsrccr2 = bufsrc + ((width*height)<<1) + width;
	ptrsrccr3 = bufsrc + ((width*height)<<1) + width*2;
	ptrsrccr4 = bufsrc + ((width*height)<<1) + width*3;

	srcystride  = width*3;
	srcccstride = width*3;
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdestcb1  = bufdest;
	ptrdestcb2  = bufdest + width;
	ptrdestcb3  = bufdest + width*2;
	ptrdestcb4  = bufdest + width*3;

	ptrdesty1 = bufdest + width*height;
	ptrdesty2 = bufdest + width*height + width;
	ptrdesty3 = bufdest + width*height + width*2;
	ptrdesty4 = bufdest + width*height + width*3;
	
	ptrdestcr1 = bufdest + ((width*height)<<1);
	ptrdestcr2 = bufdest + ((width*height)<<1) + width;
	ptrdestcr3 = bufdest + ((width*height)<<1) + width*2;
	ptrdestcr4 = bufdest + ((width*height)<<1) + width*3;

	destystride  = width*3;
	destccstride = width*3;
#endif
#endif


#ifdef UYV_444_PLANAR_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrccb1  = bufsrc;			
	ptrsrccb2  = bufsrc + width;
	ptrsrcy1 = bufsrc + (width*height>>1);
	ptrsrcy2 = bufsrc + (width*height>>1) + width;
	ptrsrccr1 = bufsrc + (width*height) ;
	ptrsrccr2 = bufsrc + (width*height) + width;

	ptrsrccb3  = bufsrc + (width*height) + ((width*height)>>1);
	ptrsrccb4  = bufsrc + (width*height) + ((width*height)>>1) + width;
	ptrsrcy3 = bufsrc + ((width*height)<<1);
	ptrsrcy4 = bufsrc + ((width*height)<<1) + width;
	ptrsrccr3 = bufsrc + ((width*height)<<1) + ((width*height)>>1);
	ptrsrccr4 = bufsrc + ((width*height)<<1) + ((width*height)>>1) + width;

	srcystride  = width;
	srcccstride = width; 
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdestcb1  = bufdest;			
	ptrdestcb2  = bufdest + width;
	ptrdesty1 = bufdest + (width*height>>1);
	ptrdesty2 = bufdest + (width*height>>1) + width;
	ptrdestcr1 = bufdest + (width*height) ;
	ptrdestcr2 = bufdest + (width*height) + width;

	ptrdestcb3  = bufdest + (width*height) + ((width*height)>>1);
	ptrdestcb4  = bufdest + (width*height) + ((width*height)>>1) + width;
	ptrdesty3 = bufdest + ((width*height)<<1);
	ptrdesty4 = bufdest + ((width*height)<<1) + width;
	ptrdestcr3 = bufdest + ((width*height)<<1) + ((width*height)>>1);
	ptrdestcr4 = bufdest + ((width*height)<<1) + ((width*height)>>1) + width;

	destystride  = width;
	destccstride = width; 
#endif
#endif



#ifdef YUV_444_PACKED_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;
	ptrsrcy2  = bufsrc + width*3;
	ptrsrcy3  = bufsrc + width*3*2;
	ptrsrcy4  = bufsrc + width*3*3;

	ptrsrccb1 = bufsrc + 1;
	ptrsrccb2 = bufsrc + width*3 + 1;
	ptrsrccb3 = bufsrc + width*3*2 + 1;
	ptrsrccb4 = bufsrc + width*3*3 + 1;
	
	ptrsrccr1 = bufsrc + 2;
	ptrsrccr2 = bufsrc + width*3 + 2;
	ptrsrccr3 = bufsrc + width*3*2 + 2;
	ptrsrccr4 = bufsrc + width*3*3 + 2;
	
	srcystride  = width*3*3;
	srcccstride = width*3*3;
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest;
	ptrdesty2  = bufdest + width*3;
	ptrdesty3  = bufdest + width*3*2;
	ptrdesty4  = bufdest + width*3*3;

	ptrdestcb1 = bufdest + 1;
	ptrdestcb2 = bufdest + width*3 + 1;
	ptrdestcb3 = bufdest + width*3*2 + 1;
	ptrdestcb4 = bufdest + width*3*3 + 1;
	
	ptrdestcr1 = bufdest + 2;
	ptrdestcr2 = bufdest + width*3 + 2;
	ptrdestcr3 = bufdest + width*3*2 + 2;
	ptrdestcr4 = bufdest + width*3*3 + 2;
	
	destystride  = width*3*3;
	destccstride = width*3*3;
#endif
#endif


#ifdef YUV_444_PACKED_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;
	ptrsrcy2  = bufsrc + width*3;
	ptrsrcy3  = bufsrc + ((width*height*3)>>1);
	ptrsrcy4  = bufsrc + ((width*height*3)>>1) + width*3;

	ptrsrccb1 = bufsrc + 1;
	ptrsrccb2 = bufsrc + width*3 + 1;
	ptrsrccb3 = bufsrc + ((width*height*3)>>1) + 1;
	ptrsrccb4 = bufsrc + ((width*height*3)>>1) + width*3 + 1;
	
	ptrsrccr1 = bufsrc + 2;
	ptrsrccr2 = bufsrc + width*3 + 2;
	ptrsrccr3 = bufsrc + ((width*height*3)>>1) + 2;
	ptrsrccr4 = bufsrc + ((width*height*3)>>1) + width*3 + 2;
	
	srcystride  = width*3;
	srcccstride = width*3;
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest;
	ptrdesty2  = bufdest + width*3;
	ptrdesty3  = bufdest + ((width*height*3)>>1);
	ptrdesty4  = bufdest + ((width*height*3)>>1) + width*3;

	ptrdestcb1 = bufdest + 1;
	ptrdestcb2 = bufdest + width*3 + 1;
	ptrdestcb3 = bufdest + ((width*height*3)>>1) + 1;
	ptrdestcb4 = bufdest + ((width*height*3)>>1) + width*3 + 1;
	
	ptrdestcr1 = bufdest + 2;
	ptrdestcr2 = bufdest + width*3 + 2;
	ptrdestcr3 = bufdest + ((width*height*3)>>1) + 2;
	ptrdestcr4 = bufdest + ((width*height*3)>>1) + width*3 + 2;
	
	destystride  = width*3;
	destccstride = width*3;
#endif
#endif


#ifdef YVU_444_PACKED_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;
	ptrsrcy2  = bufsrc + width*3;
	ptrsrcy3  = bufsrc + width*3*2;
	ptrsrcy4  = bufsrc + width*3*3;

	ptrsrccr1 = bufsrc + 1;
	ptrsrccr2 = bufsrc + width*3 + 1;
	ptrsrccr3 = bufsrc + width*3*2 + 1;
	ptrsrccr4 = bufsrc + width*3*3 + 1;
	
	ptrsrccb1 = bufsrc + 2;
	ptrsrccb2 = bufsrc + width*3 + 2;
	ptrsrccb3 = bufsrc + width*3*2 + 2;
	ptrsrccb4 = bufsrc + width*3*3 + 2;
	
	srcystride  = width*3*3;
	srcccstride = width*3*3;
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest;
	ptrdesty2  = bufdest + width*3;
	ptrdesty3  = bufdest + width*3*2;
	ptrdesty4  = bufdest + width*3*3;

	ptrdestcr1 = bufdest + 1;
	ptrdestcr2 = bufdest + width*3 + 1;
	ptrdestcr3 = bufdest + width*3*2 + 1;
	ptrdestcr4 = bufdest + width*3*3 + 1;
	
	ptrdestcb1 = bufdest + 2;
	ptrdestcb2 = bufdest + width*3 + 2;
	ptrdestcb3 = bufdest + width*3*2 + 2;
	ptrdestcb4 = bufdest + width*3*3 + 2;
	
	destystride  = width*3*3;
	destccstride = width*3*3;
#endif
#endif


#ifdef YVU_444_PACKED_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;
	ptrsrcy2  = bufsrc + width*3;
	ptrsrcy3  = bufsrc + ((width*height*3)>>1);
	ptrsrcy4  = bufsrc + ((width*height*3)>>1) + width*3;

	ptrsrccr1 = bufsrc + 1;
	ptrsrccr2 = bufsrc + width*3 + 1;
	ptrsrccr3 = bufsrc + ((width*height*3)>>1) + 1;
	ptrsrccr4 = bufsrc + ((width*height*3)>>1) + width*3 + 1;
	
	ptrsrccb1 = bufsrc + 2;
	ptrsrccb2 = bufsrc + width*3 + 2;
	ptrsrccb3 = bufsrc + ((width*height*3)>>1) + 2;
	ptrsrccb4 = bufsrc + ((width*height*3)>>1) + width*3 + 2;
	
	srcystride  = width*3;
	srcccstride = width*3;
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest;
	ptrdesty2  = bufdest + width*3;
	ptrdesty3  = bufdest + ((width*height*3)>>1);
	ptrdesty4  = bufdest + ((width*height*3)>>1) + width*3;

	ptrdestcr1 = bufdest + 1;
	ptrdestcr2 = bufdest + width*3 + 1;
	ptrdestcr3 = bufdest + ((width*height*3)>>1) + 1;
	ptrdestcr4 = bufdest + ((width*height*3)>>1) + width*3 + 1;
	
	ptrdestcb1 = bufdest + 2;
	ptrdestcb2 = bufdest + width*3 + 2;
	ptrdestcb3 = bufdest + ((width*height*3)>>1) + 2;
	ptrdestcb4 = bufdest + ((width*height*3)>>1) + width*3 + 2;
	
	destystride  = width*3;
	destccstride = width*3;
#endif
#endif


#ifdef UYV_444_PACKED_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrccb1  = bufsrc;
	ptrsrccb2  = bufsrc + width*3;
	ptrsrccb3  = bufsrc + width*3*2;
	ptrsrccb4  = bufsrc + width*3*3;

	ptrsrcy1 = bufsrc + 1;
	ptrsrcy2 = bufsrc + width*3 + 1;
	ptrsrcy3 = bufsrc + width*3*2 + 1;
	ptrsrcy4 = bufsrc + width*3*3 + 1;
	
	ptrsrccr1 = bufsrc + 2;
	ptrsrccr2 = bufsrc + width*3 + 2;
	ptrsrccr3 = bufsrc + width*3*2 + 2;
	ptrsrccr4 = bufsrc + width*3*3 + 2;
	
	srcystride  = width*3*3;
	srcccstride = width*3*3;
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdestcb1  = bufdest;
	ptrdestcb2  = bufdest + width*3;
	ptrdestcb3  = bufdest + width*3*2;
	ptrdestcb4  = bufdest + width*3*3;

	ptrdesty1 = bufdest + 1;
	ptrdesty2 = bufdest + width*3 + 1;
	ptrdesty3 = bufdest + width*3*2 + 1;
	ptrdesty4 = bufdest + width*3*3 + 1;
	
	ptrdestcr1 = bufdest + 2;
	ptrdestcr2 = bufdest + width*3 + 2;
	ptrdestcr3 = bufdest + width*3*2 + 2;
	ptrdestcr4 = bufdest + width*3*3 + 2;
	
	destystride  = width*3*3;
	destccstride = width*3*3;
#endif
#endif


#ifdef UYV_444_PACKED_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrccb1  = bufsrc;
	ptrsrccb2  = bufsrc + width*3;
	ptrsrccb3  = bufsrc + ((width*height*3)>>1);
	ptrsrccb4  = bufsrc + ((width*height*3)>>1) + width*3;

	ptrsrcy1 = bufsrc + 1;
	ptrsrcy2 = bufsrc + width*3 + 1;
	ptrsrcy3 = bufsrc + ((width*height*3)>>1) + 1;
	ptrsrcy4 = bufsrc + ((width*height*3)>>1) + width*3 + 1;
	
	ptrsrccr1 = bufsrc + 2;
	ptrsrccr2 = bufsrc + width*3 + 2;
	ptrsrccr3 = bufsrc + ((width*height*3)>>1) + 2;
	ptrsrccr4 = bufsrc + ((width*height*3)>>1) + width*3 + 2;
	
	srcystride  = width*3;
	srcccstride = width*3;
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdestcb1  = bufdest;
	ptrdestcb2  = bufdest + width*3;
	ptrdestcb3  = bufdest + ((width*height*3)>>1);
	ptrdestcb4  = bufdest + ((width*height*3)>>1) + width*3;

	ptrdesty1 = bufdest + 1;
	ptrdesty2 = bufdest + width*3 + 1;
	ptrdesty3 = bufdest + ((width*height*3)>>1) + 1;
	ptrdesty4 = bufdest + ((width*height*3)>>1) + width*3 + 1;
	
	ptrdestcr1 = bufdest + 2;
	ptrdestcr2 = bufdest + width*3 + 2;
	ptrdestcr3 = bufdest + ((width*height*3)>>1) + 2;
	ptrdestcr4 = bufdest + ((width*height*3)>>1) + width*3 + 2;
	
	destystride  = width*3;
	destccstride = width*3;
#endif
#endif






