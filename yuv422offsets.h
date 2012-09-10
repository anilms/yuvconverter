/*****************************************************************************

Module Name: <yuv422offsets.h>

Module Description:
	This file contains the offset definitions for different yuv422 formats.
	This will can be included in different files with proper macros defined
	to replace huge codes in different source files.

*****************************************************************************/






#ifdef YUV_422_PLANAR_PROG
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
	ptrsrccb2 = bufsrc + width*height + (width>>1);
	ptrsrccb3 = bufsrc + width*height + (width>>1)*2;
	ptrsrccb4 = bufsrc + width*height + (width>>1)*3;
	
	ptrsrccr1 = bufsrc + width*height + ((width*height) >> 1);
	ptrsrccr2 = bufsrc + width*height + ((width*height) >> 1) + (width>>1);
	ptrsrccr3 = bufsrc + width*height + ((width*height) >> 1) + (width>>1)*2;
	ptrsrccr4 = bufsrc + width*height + ((width*height) >> 1) + (width>>1)*3;

	srcystride  = width*3;
	srcccstride = (width>>1)*3; 
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
	ptrdestcb2 = bufdest + width*height + (width>>1);
	ptrdestcb3 = bufdest + width*height + (width>>1)*2;
	ptrdestcb4 = bufdest + width*height + (width>>1)*3;
	
	ptrdestcr1 = bufdest + width*height + ((width*height) >> 1);
	ptrdestcr2 = bufdest + width*height + ((width*height) >> 1) + (width>>1);
	ptrdestcr3 = bufdest + width*height + ((width*height) >> 1) + (width>>1)*2;
	ptrdestcr4 = bufdest + width*height + ((width*height) >> 1) + (width>>1)*3;

	destystride  = width*3;
	destccstride = (width>>1)*3; 
#endif
#endif


#ifdef YUV_422_PLANAR_INT
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
	ptrsrccb2 = bufsrc + (width*height>>1) + (width>>1);
	ptrsrccr1 = bufsrc + (width*height>>1) + ((width*height)>>2);
	ptrsrccr2 = bufsrc + (width*height>>1) + ((width*height)>>2) + (width>>1);

	ptrsrcy3  = bufsrc + width*height;
	ptrsrcy4  = bufsrc + width*height + width;
	ptrsrccb3 = bufsrc + width*height + ((width*height)>>1);
	ptrsrccb4 = bufsrc + width*height + ((width*height)>>1) + (width>>1);
	ptrsrccr3 = bufsrc + width*height + ((width*height)>>1) + ((width*height)>>2);
	ptrsrccr4 = bufsrc + width*height + ((width*height)>>1) + ((width*height)>>2) + (width>>1);

	srcystride  = width;
	srcccstride = (width>>1); 
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
	ptrdestcb2 = bufdest + (width*height>>1) + (width>>1);
	ptrdestcr1 = bufdest + (width*height>>1) + ((width*height)>>2);
	ptrdestcr2 = bufdest + (width*height>>1) + ((width*height)>>2) + (width>>1);

	ptrdesty3  = bufdest + width*height;
	ptrdesty4  = bufdest + width*height + width;
	ptrdestcb3 = bufdest + width*height + ((width*height)>>1);
	ptrdestcb4 = bufdest + width*height + ((width*height)>>1) + (width>>1);
	ptrdestcr3 = bufdest + width*height + ((width*height)>>1) + ((width*height)>>2);
	ptrdestcr4 = bufdest + width*height + ((width*height)>>1) + ((width*height)>>2) + (width>>1);

	destystride  = width;
	destccstride = (width>>1); 
#endif
#endif


#ifdef YVU_422_PLANAR_PROG
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
	ptrsrccr2 = bufsrc + width*height + (width>>1);
	ptrsrccr3 = bufsrc + width*height + (width>>1)*2;
	ptrsrccr4 = bufsrc + width*height + (width>>1)*3;
	
	ptrsrccb1 = bufsrc + width*height + ((width*height) >> 1);
	ptrsrccb2 = bufsrc + width*height + ((width*height) >> 1) + (width>>1);
	ptrsrccb3 = bufsrc + width*height + ((width*height) >> 1) + (width>>1)*2;
	ptrsrccb4 = bufsrc + width*height + ((width*height) >> 1) + (width>>1)*3;

	srcystride  = width*3;
	srcccstride = (width>>1)*3; 
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
	ptrdestcr2 = bufdest + width*height + (width>>1);
	ptrdestcr3 = bufdest + width*height + (width>>1)*2;
	ptrdestcr4 = bufdest + width*height + (width>>1)*3;
	
	ptrdestcb1 = bufdest + width*height + ((width*height) >> 1);
	ptrdestcb2 = bufdest + width*height + ((width*height) >> 1) + (width>>1);
	ptrdestcb3 = bufdest + width*height + ((width*height) >> 1) + (width>>1)*2;
	ptrdestcb4 = bufdest + width*height + ((width*height) >> 1) + (width>>1)*3;

	destystride  = width*3;
	destccstride = (width>>1)*3; 
#endif
#endif


#ifdef YVU_422_PLANAR_INT
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
	ptrsrccr2 = bufsrc + (width*height>>1) + (width>>1);
	ptrsrccb1 = bufsrc + (width*height>>1) + ((width*height)>>2);
	ptrsrccb2 = bufsrc + (width*height>>1) + ((width*height)>>2) + (width>>1);

	ptrsrcy3  = bufsrc + width*height;
	ptrsrcy4  = bufsrc + width*height + width;
	ptrsrccr3 = bufsrc + width*height + ((width*height)>>1);
	ptrsrccr4 = bufsrc + width*height + ((width*height)>>1) + (width>>1);
	ptrsrccb3 = bufsrc + width*height + ((width*height)>>1) + ((width*height)>>2);
	ptrsrccb4 = bufsrc + width*height + ((width*height)>>1) + ((width*height)>>2) + (width>>1);

	srcystride  = width;
	srcccstride = (width>>1); 
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
	ptrdestcr2 = bufdest + (width*height>>1) + (width>>1);
	ptrdestcb1 = bufdest + (width*height>>1) + ((width*height)>>2);
	ptrdestcb2 = bufdest + (width*height>>1) + ((width*height)>>2) + (width>>1);

	ptrdesty3  = bufdest + width*height;
	ptrdesty4  = bufdest + width*height + width;
	ptrdestcr3 = bufdest + width*height + ((width*height)>>1);
	ptrdestcr4 = bufdest + width*height + ((width*height)>>1) + (width>>1);
	ptrdestcb3 = bufdest + width*height + ((width*height)>>1) + ((width*height)>>2);
	ptrdestcb4 = bufdest + width*height + ((width*height)>>1) + ((width*height)>>2) + (width>>1);

	destystride  = width;
	destccstride = (width>>1); 
#endif
#endif



#ifdef UYVY_PACKED_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc + 1;
	ptrsrcy2  = bufsrc + (width<<1) + 1;
	ptrsrcy3  = bufsrc + (width<<1)*2 + 1;
	ptrsrcy4  = bufsrc + (width<<1)*3 + 1;

	ptrsrccb1 = bufsrc;
	ptrsrccb2 = bufsrc + (width<<1);
	ptrsrccb3 = bufsrc + (width<<1)*2;
	ptrsrccb4 = bufsrc + (width<<1)*3;

	ptrsrccr1 = bufsrc + 2;
	ptrsrccr2 = bufsrc + (width<<1) + 2;
	ptrsrccr3 = bufsrc + (width<<1)*2 + 2;
	ptrsrccr4 = bufsrc + (width<<1)*3 + 2;

	srcystride  = (width<<1)*3;
	srcccstride = (width<<1)*3; 
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest + 1;
	ptrdesty2  = bufdest + (width<<1) + 1;
	ptrdesty3  = bufdest + (width<<1)*2 + 1;
	ptrdesty4  = bufdest + (width<<1)*3 + 1;

	ptrdestcb1 = bufdest;
	ptrdestcb2 = bufdest + (width<<1);
	ptrdestcb3 = bufdest + (width<<1)*2;
	ptrdestcb4 = bufdest + (width<<1)*3;

	ptrdestcr1 = bufdest + 2;
	ptrdestcr2 = bufdest + (width<<1) + 2;
	ptrdestcr3 = bufdest + (width<<1)*2 + 2;
	ptrdestcr4 = bufdest + (width<<1)*3 + 2;

	destystride  = (width<<1)*3;
	destccstride = (width<<1)*3; 
#endif
#endif



#ifdef UYVY_PACKED_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc + 1;
	ptrsrcy2  = bufsrc + (width<<1) + 1;
	ptrsrcy3  = bufsrc + (width*height) + 1;
	ptrsrcy4  = bufsrc + (width*height) + (width<<1) + 1;

	ptrsrccb1 = bufsrc;
	ptrsrccb2 = bufsrc + (width<<1);
	ptrsrccb3 = bufsrc + (width*height);
	ptrsrccb4 = bufsrc + (width*height) + (width<<1);

	ptrsrccr1 = bufsrc + 2;
	ptrsrccr2 = bufsrc + (width<<1) + 2;
	ptrsrccr3 = bufsrc + (width*height) + 2;
	ptrsrccr4 = bufsrc + (width*height) + (width<<1) + 2;

	srcystride  = (width<<1);
	srcccstride = (width<<1); 
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest + 1;
	ptrdesty2  = bufdest + (width<<1) + 1;
	ptrdesty3  = bufdest + (width*height) + 1;
	ptrdesty4  = bufdest + (width*height) + (width<<1) + 1;

	ptrdestcb1 = bufdest;
	ptrdestcb2 = bufdest + (width<<1);
	ptrdestcb3 = bufdest + (width*height);
	ptrdestcb4 = bufdest + (width*height) + (width<<1);

	ptrdestcr1 = bufdest + 2;
	ptrdestcr2 = bufdest + (width<<1) + 2;
	ptrdestcr3 = bufdest + (width*height) + 2;
	ptrdestcr4 = bufdest + (width*height) + (width<<1) + 2;

	destystride  = (width<<1);
	destccstride = (width<<1); 
#endif
#endif



#ifdef YUYV_PACKED_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc ;
	ptrsrcy2  = bufsrc + (width<<1) ;
	ptrsrcy3  = bufsrc + (width<<1)*2 ;
	ptrsrcy4  = bufsrc + (width<<1)*3 ;

	ptrsrccb1 = bufsrc + 1;
	ptrsrccb2 = bufsrc + (width<<1) + 1;
	ptrsrccb3 = bufsrc + (width<<1)*2 + 1;
	ptrsrccb4 = bufsrc + (width<<1)*3 + 1;

	ptrsrccr1 = bufsrc + 3;
	ptrsrccr2 = bufsrc + (width<<1) + 3;
	ptrsrccr3 = bufsrc + (width<<1)*2 + 3;
	ptrsrccr4 = bufsrc + (width<<1)*3 + 3;

	srcystride  = (width<<1)*3;
	srcccstride = (width<<1)*3; 
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest ;
	ptrdesty2  = bufdest + (width<<1) ;
	ptrdesty3  = bufdest + (width<<1)*2 ;
	ptrdesty4  = bufdest + (width<<1)*3 ;

	ptrdestcb1 = bufdest + 1;
	ptrdestcb2 = bufdest + (width<<1) + 1;
	ptrdestcb3 = bufdest + (width<<1)*2 + 1;
	ptrdestcb4 = bufdest + (width<<1)*3 + 1;

	ptrdestcr1 = bufdest + 3;
	ptrdestcr2 = bufdest + (width<<1) + 3;
	ptrdestcr3 = bufdest + (width<<1)*2 + 3;
	ptrdestcr4 = bufdest + (width<<1)*3 + 3;

	destystride  = (width<<1)*3;
	destccstride = (width<<1)*3; 
#endif
#endif



#ifdef YUYV_PACKED_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;
	ptrsrcy2  = bufsrc + (width<<1);
	ptrsrcy3  = bufsrc + (width*height);
	ptrsrcy4  = bufsrc + (width*height) + (width<<1);

	ptrsrccb1 = bufsrc + 1;
	ptrsrccb2 = bufsrc + (width<<1) + 1;
	ptrsrccb3 = bufsrc + (width*height) + 1;
	ptrsrccb4 = bufsrc + (width*height) + (width<<1) + 1;

	ptrsrccr1 = bufsrc + 3;
	ptrsrccr2 = bufsrc + (width<<1) + 3;
	ptrsrccr3 = bufsrc + (width*height) + 3;
	ptrsrccr4 = bufsrc + (width*height) + (width<<1) + 3;

	srcystride  = (width<<1);
	srcccstride = (width<<1); 
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
	ptrdesty2  = bufdest + (width<<1);
	ptrdesty3  = bufdest + (width*height);
	ptrdesty4  = bufdest + (width*height) + (width<<1);

	ptrdestcb1 = bufdest + 1;
	ptrdestcb2 = bufdest + (width<<1) + 1;
	ptrdestcb3 = bufdest + (width*height) + 1;
	ptrdestcb4 = bufdest + (width*height) + (width<<1) + 1;

	ptrdestcr1 = bufdest + 3;
	ptrdestcr2 = bufdest + (width<<1) + 3;
	ptrdestcr3 = bufdest + (width*height) + 3;
	ptrdestcr4 = bufdest + (width*height) + (width<<1) + 3;

	destystride  = (width<<1);
	destccstride = (width<<1); 
#endif
#endif



#ifdef YVYU_PACKED_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc ;
	ptrsrcy2  = bufsrc + (width<<1) ;
	ptrsrcy3  = bufsrc + (width<<1)*2 ;
	ptrsrcy4  = bufsrc + (width<<1)*3 ;

	ptrsrccb1 = bufsrc + 3;
	ptrsrccb2 = bufsrc + (width<<1) + 3;
	ptrsrccb3 = bufsrc + (width<<1)*2 + 3;
	ptrsrccb4 = bufsrc + (width<<1)*3 + 3;

	ptrsrccr1 = bufsrc + 1;
	ptrsrccr2 = bufsrc + (width<<1) + 1;
	ptrsrccr3 = bufsrc + (width<<1)*2 + 1;
	ptrsrccr4 = bufsrc + (width<<1)*3 + 1;

	srcystride  = (width<<1)*3;
	srcccstride = (width<<1)*3; 
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcb3, *ptrdestcb4;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	unsigned char *ptrdestcr3, *ptrdestcr4;
	int destystride, destccstride;

	ptrdesty1  = bufdest ;
	ptrdesty2  = bufdest + (width<<1) ;
	ptrdesty3  = bufdest + (width<<1)*2 ;
	ptrdesty4  = bufdest + (width<<1)*3 ;

	ptrdestcb1 = bufdest + 3;
	ptrdestcb2 = bufdest + (width<<1) + 3;
	ptrdestcb3 = bufdest + (width<<1)*2 + 3;
	ptrdestcb4 = bufdest + (width<<1)*3 + 3;

	ptrdestcr1 = bufdest + 1;
	ptrdestcr2 = bufdest + (width<<1) + 1;
	ptrdestcr3 = bufdest + (width<<1)*2 + 1;
	ptrdestcr4 = bufdest + (width<<1)*3 + 1;

	destystride  = (width<<1)*3;
	destccstride = (width<<1)*3; 
#endif
#endif



#ifdef YVYU_PACKED_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccb3, *ptrsrccb4;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	unsigned char *ptrsrccr3, *ptrsrccr4;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;
	ptrsrcy2  = bufsrc + (width<<1);
	ptrsrcy3  = bufsrc + (width*height);
	ptrsrcy4  = bufsrc + (width*height) + (width<<1);

	ptrsrccb1 = bufsrc + 3;
	ptrsrccb2 = bufsrc + (width<<1) + 3;
	ptrsrccb3 = bufsrc + (width*height) + 3;
	ptrsrccb4 = bufsrc + (width*height) + (width<<1) + 3;

	ptrsrccr1 = bufsrc + 1;
	ptrsrccr2 = bufsrc + (width<<1) + 1;
	ptrsrccr3 = bufsrc + (width*height) + 1;
	ptrsrccr4 = bufsrc + (width*height) + (width<<1) + 1;

	srcystride  = (width<<1);
	srcccstride = (width<<1); 	
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
	ptrdesty2  = bufdest + (width<<1);
	ptrdesty3  = bufdest + (width*height);
	ptrdesty4  = bufdest + (width*height) + (width<<1);

	ptrdestcb1 = bufdest + 3;
	ptrdestcb2 = bufdest + (width<<1) + 3;
	ptrdestcb3 = bufdest + (width*height) + 3;
	ptrdestcb4 = bufdest + (width*height) + (width<<1) + 3;

	ptrdestcr1 = bufdest + 1;
	ptrdestcr2 = bufdest + (width<<1) + 1;
	ptrdestcr3 = bufdest + (width*height) + 1;
	ptrdestcr4 = bufdest + (width*height) + (width<<1) + 1;

	destystride  = (width<<1);
	destccstride = (width<<1); 	
#endif
#endif

