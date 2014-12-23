/*****************************************************************************

Module Name: <yuv420offsets.h>

Module Description:
	This file contains the offset definitions for different yuv420 formats.
	This will can be included in different files with proper macros defined
	to replace huge codes in different source files.

*****************************************************************************/



#ifdef YUV_420_PLANAR_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
   	unsigned char *ptrsrccb1, *ptrsrccb2;
   	unsigned char *ptrsrccr1, *ptrsrccr2;
	int srcystride, srcccstride;

	ptrsrcy1 = bufsrc;
	ptrsrcy2 = bufsrc + width;
	ptrsrcy3 = bufsrc + width*2;
	ptrsrcy4 = bufsrc + width*3;
	
	ptrsrccb1 = bufsrc + width*height;	
	ptrsrccb2 = bufsrc + width*height + (width>>1);	
	
	ptrsrccr1 = bufsrc + width*height + ((width*height) >> 2);	
	ptrsrccr2 = bufsrc + width*height + ((width*height) >> 2) + (width>>1);	

	srcystride  = (width)*3;
	srcccstride = (width>>1);
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
   	unsigned char *ptrdestcb1, *ptrdestcb2;
   	unsigned char *ptrdestcr1, *ptrdestcr2;
	int destystride, destccstride;

	ptrdesty1 = bufdest;
	ptrdesty2 = bufdest + width;
	ptrdesty3 = bufdest + width*2;
	ptrdesty4 = bufdest + width*3;
	
	ptrdestcb1 = bufdest + width*height;	
	ptrdestcb2 = bufdest + width*height + (width>>1);	
	
	ptrdestcr1 = bufdest + width*height + ((width*height) >> 2);	
	ptrdestcr2 = bufdest + width*height + ((width*height) >> 2) + (width>>1);	

	destystride  = (width)*3;
	destccstride = (width>>1);
#endif
#endif


#ifdef YUV_420_PLANAR_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;			
	ptrsrcy2  = bufsrc + width;
	ptrsrccb1 = bufsrc + ((width*height)>>1);
	ptrsrccr1 = bufsrc + ((width*height)>>1) + ((width*height)>>3);

	ptrsrcy3  = bufsrc + ((width*height)>>1) + ((width*height)>>2);
	ptrsrcy4  = bufsrc + ((width*height)>>1) + ((width*height)>>2) + width;
	ptrsrccb2 = bufsrc + (width*height) + ((width*height)>>2);
	ptrsrccr2 = bufsrc + (width*height) + ((width*height)>>2) + ((width*height)>>3);

	srcystride  = width;
	srcccstride = 0; 
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	int destystride, destccstride;

	ptrdesty1  = bufdest;			
	ptrdesty2  = bufdest + width;
	ptrdestcb1 = bufdest + ((width*height)>>1);
	ptrdestcr1 = bufdest + ((width*height)>>1) + ((width*height)>>3);

	ptrdesty3  = bufdest + ((width*height)>>1) + ((width*height)>>2);
	ptrdesty4  = bufdest + ((width*height)>>1) + ((width*height)>>2) + width;
	ptrdestcb2 = bufdest + (width*height) + ((width*height)>>2);
	ptrdestcr2 = bufdest + (width*height) + ((width*height)>>2) + ((width*height)>>3);

	destystride  = width;
	destccstride = 0; 
#endif
#endif



#ifdef YVU_420_PLANAR_PROG
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
   	unsigned char *ptrsrccb1, *ptrsrccb2;
   	unsigned char *ptrsrccr1, *ptrsrccr2;
	int srcystride, srcccstride;

	ptrsrcy1 = bufsrc;
	ptrsrcy2 = bufsrc + width;
	ptrsrcy3 = bufsrc + width*2;
	ptrsrcy4 = bufsrc + width*3;
	
	ptrsrccr1 = bufsrc + width*height;	
	ptrsrccr2 = bufsrc + width*height + (width>>1);	
	
	ptrsrccb1 = bufsrc + width*height + ((width*height) >> 2);	
	ptrsrccb2 = bufsrc + width*height + ((width*height) >> 2) + (width>>1);	

	srcystride  = (width)*3;
	srcccstride = (width>>1);
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
   	unsigned char *ptrdestcb1, *ptrdestcb2;
   	unsigned char *ptrdestcr1, *ptrdestcr2;
	int destystride, destccstride;

	ptrdesty1 = bufdest;
	ptrdesty2 = bufdest + width;
	ptrdesty3 = bufdest + width*2;
	ptrdesty4 = bufdest + width*3;
	
	ptrdestcr1 = bufdest + width*height;	
	ptrdestcr2 = bufdest + width*height + (width>>1);	
	
	ptrdestcb1 = bufdest + width*height + ((width*height) >> 2);	
	ptrdestcb2 = bufdest + width*height + ((width*height) >> 2) + (width>>1);	

	destystride  = (width)*3;
	destccstride = (width>>1); 
#endif
#endif




#ifdef YVU_420_PLANAR_INT
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	unsigned char *ptrsrccb1, *ptrsrccb2;
	unsigned char *ptrsrccr1, *ptrsrccr2;
	int srcystride, srcccstride;

	ptrsrcy1  = bufsrc;			
	ptrsrcy2  = bufsrc + width;
	ptrsrccr1 = bufsrc + ((width*height)>>1);
	ptrsrccb1 = bufsrc + ((width*height)>>1) + ((width*height)>>3);

	ptrsrcy3  = bufsrc + ((width*height)>>1) + ((width*height)>>2);
	ptrsrcy4  = bufsrc + ((width*height)>>1) + ((width*height)>>2) + width;
	ptrsrccr2 = bufsrc + (width*height) + ((width*height)>>2);
	ptrsrccb2 = bufsrc + (width*height) + ((width*height)>>2) + ((width*height)>>3);

	srcystride  = width;
	srcccstride = 0; 
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
	unsigned char *ptrdestcb1, *ptrdestcb2;
	unsigned char *ptrdestcr1, *ptrdestcr2;
	int destystride, destccstride;

	ptrdesty1  = bufdest;			
	ptrdesty2  = bufdest + width;
	ptrdestcr1 = bufdest + ((width*height)>>1);
	ptrdestcb1 = bufdest + ((width*height)>>1) + ((width*height)>>3);

	ptrdesty3  = bufdest + ((width*height)>>1) + ((width*height)>>2);
	ptrdesty4  = bufdest + ((width*height)>>1) + ((width*height)>>2) + width;
	ptrdestcr2 = bufdest + (width*height) + ((width*height)>>2);
	ptrdestcb2 = bufdest + (width*height) + ((width*height)>>2) + ((width*height)>>3);

	destystride  = width;
	destccstride = 0; 
#endif
#endif




#ifdef YUV_420_PLANAR_YCBCR
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
   	unsigned char *ptrsrccb1, *ptrsrccb2;
   	unsigned char *ptrsrccr1, *ptrsrccr2;
	int srcystride, srcccstride;

	ptrsrcy1 = bufsrc;
	ptrsrcy2 = bufsrc + width;
	ptrsrcy3 = bufsrc + width*2;
	ptrsrcy4 = bufsrc + width*3;
	
	ptrsrccb1 = bufsrc + width*height;	
	ptrsrccb2 = bufsrc + width*height + width;	
	
	ptrsrccr1 = bufsrc + width*height + 1;	
	ptrsrccr2 = bufsrc + width*height + 1 + width;	

	srcystride  = (width)*3;
	srcccstride = (width);
#endif

#ifdef DEST
	unsigned char *ptrdesty1, *ptrdesty2;
	unsigned char *ptrdesty3, *ptrdesty4;
   	unsigned char *ptrdestcb1, *ptrdestcb2;
   	unsigned char *ptrdestcr1, *ptrdestcr2;
	int destystride, destccstride;

	ptrdesty1 = bufdest;
	ptrdesty2 = bufdest + width;
	ptrdesty3 = bufdest + width*2;
	ptrdesty4 = bufdest + width*3;
	
	ptrdestcb1 = bufdest + width*height;	
	ptrdestcb2 = bufdest + width*height + width;	
	
	ptrdestcr1 = bufdest + width*height + 1;	
	ptrdestcr2 = bufdest + width*height + width + 1;	

	destystride  = (width)*3;
	destccstride = (width);
#endif
#endif


