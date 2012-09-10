/*****************************************************************************

FileName: <yuv422packedto420planar.cpp>

Module Description:
	Modules to convert YUV422packed to YUV420planar format
	List of Functions:

	uyvy_prog_packed_to_yuv420_prog_planar
	uyvy_int_packed_to_yuv420_prog_planar
	yuyv_prog_packed_to_yuv420_prog_planar
	yuyv_int_packed_to_yuv420_prog_planar
	yvyu_int_packed_to_yuv420_prog_planar
	yvyu_int_packed_to_yuv420_prog_planar

*****************************************************************************/

#include "yuvconverter.h"

/*****************************************************************************
  Routine:  void uyvy_prog_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts uyvy prog to yuv420 prog format 
*****************************************************************************/

void  uyvy_prog_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define UYVY_PACKED_PROG
#define SRC
#include "yuv422offsets.h"
#undef SRC
#undef UYVY_PACKED_PROG

#define YUV_420_PLANAR_PROG
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_PROG

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{
			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty2++) = (*ptrsrcy2);
			(*ptrdesty3++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty2++) = (*ptrsrcy2);
			(*ptrdesty3++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 4;
			ptrsrccb3 += 4;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 4;
			ptrsrccr3 += 4;

		}


		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb3 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr3 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

}//uyvy_prog_packed_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void uyvy_int_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts uyvy int to yuv420 prog format 
*****************************************************************************/

void  uyvy_int_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define UYVY_PACKED_INT
#define SRC
#include "yuv422offsets.h"
#undef SRC
#undef UYVY_PACKED_INT

#define YUV_420_PLANAR_PROG
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_PROG

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{
			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty3++) = (*ptrsrcy2);
			(*ptrdesty2++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty3++) = (*ptrsrcy2);
			(*ptrdesty2++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 4;
			ptrsrccb3 += 4;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 4;
			ptrsrccr3 += 4;

		}


		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb3 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr3 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

}//uyvy_int_packed_to_yuv420_prog_planar.end




/*****************************************************************************
  Routine:  void yuyv_prog_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuyv prog to yuv420 prog format 
*****************************************************************************/

void  yuyv_prog_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUYV_PACKED_PROG
#define SRC
#include "yuv422offsets.h"
#undef SRC
#undef YUYV_PACKED_PROG

#define YUV_420_PLANAR_PROG
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_PROG

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{
			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty2++) = (*ptrsrcy2);
			(*ptrdesty3++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty2++) = (*ptrsrcy2);
			(*ptrdesty3++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 4;
			ptrsrccb3 += 4;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 4;
			ptrsrccr3 += 4;

		}


		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb3 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr3 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

}//yuyv_prog_packed_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void yuyv_int_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuyv int to yuv420 prog format 
*****************************************************************************/

void  yuyv_int_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUYV_PACKED_INT
#define SRC
#include "yuv422offsets.h"
#undef SRC
#undef YUYV_PACKED_INT

#define YUV_420_PLANAR_PROG
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_PROG

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{
			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty3++) = (*ptrsrcy2);
			(*ptrdesty2++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty3++) = (*ptrsrcy2);
			(*ptrdesty2++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 4;
			ptrsrccb3 += 4;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 4;
			ptrsrccr3 += 4;

		}


		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb3 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr3 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

}//yuyv_int_packed_to_yuv420_prog_planar.end




/*****************************************************************************
  Routine:  void yvyu_prog_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yvyu prog to yuv420 prog format 
*****************************************************************************/

void  yvyu_prog_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YVYU_PACKED_PROG
#define SRC
#include "yuv422offsets.h"
#undef SRC
#undef YVYU_PACKED_PROG

#define YUV_420_PLANAR_PROG
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_PROG

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{
			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty2++) = (*ptrsrcy2);
			(*ptrdesty3++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty2++) = (*ptrsrcy2);
			(*ptrdesty3++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 4;
			ptrsrccb3 += 4;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 4;
			ptrsrccr3 += 4;

		}


		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb3 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr3 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

}//yvyu_prog_packed_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void yvyu_int_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yvyu int to yuv420 prog format 
*****************************************************************************/

void  yvyu_int_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YVYU_PACKED_INT
#define SRC
#include "yuv422offsets.h"
#undef SRC
#undef YVYU_PACKED_INT

#define YUV_420_PLANAR_PROG
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_PROG

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{
			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty3++) = (*ptrsrcy2);
			(*ptrdesty2++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty3++) = (*ptrsrcy2);
			(*ptrdesty2++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 2;
			ptrsrcy2 += 2;
			ptrsrcy3 += 2;
			ptrsrcy4 += 2;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 4;
			ptrsrccb3 += 4;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 4;
			ptrsrccr3 += 4;

		}


		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb3 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr3 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

}//yvyu_int_packed_to_yuv420_prog_planar.end


