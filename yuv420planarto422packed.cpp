/*****************************************************************************

FileName: <yuv420planarto422packed.cpp>

Module Description:
	Module to convert YUV420planar to YUV422packed format
	List of Functions:

	yuv420_prog_planar_to_uyvy_prog_packed
	yuv420_prog_planar_to_uyvy_int_packed
	yuv420_prog_planar_to_yuyv_prog_packed
	yuv420_prog_planar_to_yuyv_int_packed
	yuv420_prog_planar_to_yvyu_prog_packed
	yuv420_prog_planar_to_yvyu_int_packed

*****************************************************************************/

#include "yuvconverter.h"

/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_uyvy_prog_packed(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to uyvy progressive format 
*****************************************************************************/

void  yuv420_prog_planar_to_uyvy_prog_packed(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef YUV_420_PLANAR_PROG

#define UYVY_PACKED_PROG
#define DEST
#include "yuv422offsets.h"
#undef DEST
#undef UYVY_PACKED_PROG

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty2) = (*ptrsrcy2++);
			(*ptrdesty3) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty2) = (*ptrsrcy2++);
			(*ptrdesty3) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdestcb1) = (*ptrsrccb1);
			(*ptrdestcb2) = (*ptrsrccb1++);
			(*ptrdestcb3) = (*ptrsrccb2);
			(*ptrdestcb4) = (*ptrsrccb2++);

			ptrdestcb1 += 4;
			ptrdestcb2 += 4;
			ptrdestcb3 += 4;
			ptrdestcb4 += 4;
			
			(*ptrdestcr1) = (*ptrsrccr1);
			(*ptrdestcr2) = (*ptrsrccr1++);
			(*ptrdestcr3) = (*ptrsrccr2);
			(*ptrdestcr4) = (*ptrsrccr2++);

			ptrdestcr1 += 4;
			ptrdestcr2 += 4;
			ptrdestcr3 += 4;
			ptrdestcr4 += 4;
			
		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;
		ptrdestcb3 += destccstride;
		ptrdestcb4 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;
		ptrdestcr3 += destccstride;
		ptrdestcr4 += destccstride;

	}

} // yuv420_prog_planar_to_uyvy_prog_packed.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_uyvy_int_packed(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to uyvy interlaced format 
*****************************************************************************/

void  yuv420_prog_planar_to_uyvy_int_packed(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef YUV_420_PLANAR_PROG

#define UYVY_PACKED_INT
#define DEST
#include "yuv422offsets.h"
#undef DEST
#undef UYVY_PACKED_INT

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty3) = (*ptrsrcy2++);
			(*ptrdesty2) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty3) = (*ptrsrcy2++);
			(*ptrdesty2) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdestcb1) = (*ptrsrccb1);
			(*ptrdestcb2) = (*ptrsrccb1++);
			(*ptrdestcb3) = (*ptrsrccb2);
			(*ptrdestcb4) = (*ptrsrccb2++);

			ptrdestcb1 += 4;
			ptrdestcb2 += 4;
			ptrdestcb3 += 4;
			ptrdestcb4 += 4;
			
			(*ptrdestcr1) = (*ptrsrccr1);
			(*ptrdestcr2) = (*ptrsrccr1++);
			(*ptrdestcr3) = (*ptrsrccr2);
			(*ptrdestcr4) = (*ptrsrccr2++);

			ptrdestcr1 += 4;
			ptrdestcr2 += 4;
			ptrdestcr3 += 4;
			ptrdestcr4 += 4;
			
		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;
		ptrdestcb3 += destccstride;
		ptrdestcb4 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;
		ptrdestcr3 += destccstride;
		ptrdestcr4 += destccstride;

	}

} // yuv420_prog_planar_to_uyvy_int_packed.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yuyv_prog_packed(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yuyv progressive format 
*****************************************************************************/

void  yuv420_prog_planar_to_yuyv_prog_packed(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef YUV_420_PLANAR_PROG

#define YUYV_PACKED_PROG
#define DEST
#include "yuv422offsets.h"
#undef DEST
#undef YUYV_PACKED_PROG

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty2) = (*ptrsrcy2++);
			(*ptrdesty3) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty2) = (*ptrsrcy2++);
			(*ptrdesty3) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdestcb1) = (*ptrsrccb1);
			(*ptrdestcb2) = (*ptrsrccb1++);
			(*ptrdestcb3) = (*ptrsrccb2);
			(*ptrdestcb4) = (*ptrsrccb2++);

			ptrdestcb1 += 4;
			ptrdestcb2 += 4;
			ptrdestcb3 += 4;
			ptrdestcb4 += 4;
			
			(*ptrdestcr1) = (*ptrsrccr1);
			(*ptrdestcr2) = (*ptrsrccr1++);
			(*ptrdestcr3) = (*ptrsrccr2);
			(*ptrdestcr4) = (*ptrsrccr2++);

			ptrdestcr1 += 4;
			ptrdestcr2 += 4;
			ptrdestcr3 += 4;
			ptrdestcr4 += 4;
			
		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;
		ptrdestcb3 += destccstride;
		ptrdestcb4 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;
		ptrdestcr3 += destccstride;
		ptrdestcr4 += destccstride;

	}

} // yuv420_prog_planar_to_yuyv_prog_packed.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yuyv_int_packed(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yuyv interlaced format 
*****************************************************************************/

void  yuv420_prog_planar_to_yuyv_int_packed(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef YUV_420_PLANAR_PROG

#define YUYV_PACKED_INT
#define DEST
#include "yuv422offsets.h"
#undef DEST
#undef YUYV_PACKED_INT

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty3) = (*ptrsrcy2++);
			(*ptrdesty2) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty3) = (*ptrsrcy2++);
			(*ptrdesty2) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdestcb1) = (*ptrsrccb1);
			(*ptrdestcb2) = (*ptrsrccb1++);
			(*ptrdestcb3) = (*ptrsrccb2);
			(*ptrdestcb4) = (*ptrsrccb2++);

			ptrdestcb1 += 4;
			ptrdestcb2 += 4;
			ptrdestcb3 += 4;
			ptrdestcb4 += 4;
			
			(*ptrdestcr1) = (*ptrsrccr1);
			(*ptrdestcr2) = (*ptrsrccr1++);
			(*ptrdestcr3) = (*ptrsrccr2);
			(*ptrdestcr4) = (*ptrsrccr2++);

			ptrdestcr1 += 4;
			ptrdestcr2 += 4;
			ptrdestcr3 += 4;
			ptrdestcr4 += 4;
			
		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;
		ptrdestcb3 += destccstride;
		ptrdestcb4 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;
		ptrdestcr3 += destccstride;
		ptrdestcr4 += destccstride;

	}

} // yuv420_prog_planar_to_yuyv_int_packed.end




/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yvyu_prog_packed(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yvyu progressive format 
*****************************************************************************/

void  yuv420_prog_planar_to_yvyu_prog_packed(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef YUV_420_PLANAR_PROG

#define YVYU_PACKED_PROG
#define DEST
#include "yuv422offsets.h"
#undef DEST
#undef YVYU_PACKED_PROG

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty2) = (*ptrsrcy2++);
			(*ptrdesty3) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty2) = (*ptrsrcy2++);
			(*ptrdesty3) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdestcb1) = (*ptrsrccb1);
			(*ptrdestcb2) = (*ptrsrccb1++);
			(*ptrdestcb3) = (*ptrsrccb2);
			(*ptrdestcb4) = (*ptrsrccb2++);

			ptrdestcb1 += 4;
			ptrdestcb2 += 4;
			ptrdestcb3 += 4;
			ptrdestcb4 += 4;
			
			(*ptrdestcr1) = (*ptrsrccr1);
			(*ptrdestcr2) = (*ptrsrccr1++);
			(*ptrdestcr3) = (*ptrsrccr2);
			(*ptrdestcr4) = (*ptrsrccr2++);

			ptrdestcr1 += 4;
			ptrdestcr2 += 4;
			ptrdestcr3 += 4;
			ptrdestcr4 += 4;
			
		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;
		ptrdestcb3 += destccstride;
		ptrdestcb4 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;
		ptrdestcr3 += destccstride;
		ptrdestcr4 += destccstride;

	}

} // yuv420_prog_planar_to_yvyu_prog_packed.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yvyu_int_packed(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yvyu interlaced format 
*****************************************************************************/

void  yuv420_prog_planar_to_yvyu_int_packed(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef YUV_420_PLANAR_PROG

#define YVYU_PACKED_INT
#define DEST
#include "yuv422offsets.h"
#undef DEST
#undef YVYU_PACKED_INT

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty3) = (*ptrsrcy2++);
			(*ptrdesty2) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdesty1) = (*ptrsrcy1++);	
			(*ptrdesty3) = (*ptrsrcy2++);
			(*ptrdesty2) = (*ptrsrcy3++);
			(*ptrdesty4) = (*ptrsrcy4++);

			ptrdesty1 += 2;
			ptrdesty2 += 2;
			ptrdesty3 += 2;
			ptrdesty4 += 2;

			(*ptrdestcb1) = (*ptrsrccb1);
			(*ptrdestcb2) = (*ptrsrccb1++);
			(*ptrdestcb3) = (*ptrsrccb2);
			(*ptrdestcb4) = (*ptrsrccb2++);

			ptrdestcb1 += 4;
			ptrdestcb2 += 4;
			ptrdestcb3 += 4;
			ptrdestcb4 += 4;
			
			(*ptrdestcr1) = (*ptrsrccr1);
			(*ptrdestcr2) = (*ptrsrccr1++);
			(*ptrdestcr3) = (*ptrsrccr2);
			(*ptrdestcr4) = (*ptrsrccr2++);

			ptrdestcr1 += 4;
			ptrdestcr2 += 4;
			ptrdestcr3 += 4;
			ptrdestcr4 += 4;
			
		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;

		
		/* Update dest pointers */
		ptrdesty1 += destystride;
		ptrdesty2 += destystride;
		ptrdesty3 += destystride;
		ptrdesty4 += destystride;

		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;
		ptrdestcb3 += destccstride;
		ptrdestcb4 += destccstride;

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;
		ptrdestcr3 += destccstride;
		ptrdestcr4 += destccstride;

	}

} // yuv420_prog_planar_to_yvyu_int_packed.end



