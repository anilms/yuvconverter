/*****************************************************************************

FileName: <yuv420planarto420planar.cpp>

Module Description:
	Modules to convert YUV420planar to YUV420planar format
	List of Functions:

	yuv420_prog_planar_to_yuv420_int_planar
	yuv420_prog_planar_to_yvu420_prog_planar
	yuv420_prog_planar_to_yvu420_int_planar

	yuv420_int_planar_to_yuv420_prog_planar
	yvu420_prog_planar_to_yuv420_prog_planar
	yvu420_int_planar_to_yuv420_prog_planar

*****************************************************************************/

#include "yuvconverter.h"

/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yuv420_int_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yuv420 int format 
*****************************************************************************/

void  yuv420_prog_planar_to_yuv420_int_planar(
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

#define YUV_420_PLANAR_INT
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_INT

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty3++) = (*ptrsrcy2++);
			(*ptrdesty2++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);
			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty3++) = (*ptrsrcy2++);
			(*ptrdesty2++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);

			(*ptrdestcb1++) = (*ptrsrccb1++);
			(*ptrdestcr1++) = (*ptrsrccr1++);
			(*ptrdestcb2++) = (*ptrsrccb2++);
			(*ptrdestcr2++) = (*ptrsrccr2++);

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

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // yuv420_prog_planar_to_yuv420_int_planar.end




/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yvu420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yvu420 prog format 
*****************************************************************************/

void  yuv420_prog_planar_to_yvu420_prog_planar(
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

#define YVU_420_PLANAR_PROG
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YVU_420_PLANAR_PROG

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty2++) = (*ptrsrcy2++);
			(*ptrdesty3++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);
			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty2++) = (*ptrsrcy2++);
			(*ptrdesty3++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);

			(*ptrdestcb1++) = (*ptrsrccb1++);
			(*ptrdestcr1++) = (*ptrsrccr1++);
			(*ptrdestcb2++) = (*ptrsrccb2++);
			(*ptrdestcr2++) = (*ptrsrccr2++);

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

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // yuv420_prog_planar_to_yvu420_prog_planar.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yvu420_int_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yvu420 int format 
*****************************************************************************/

void  yuv420_prog_planar_to_yvu420_int_planar(
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

#define YVU_420_PLANAR_INT
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YVU_420_PLANAR_INT

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty3++) = (*ptrsrcy2++);
			(*ptrdesty2++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);
			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty3++) = (*ptrsrcy2++);
			(*ptrdesty2++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);

			(*ptrdestcb1++) = (*ptrsrccb1++);
			(*ptrdestcr1++) = (*ptrsrccr1++);
			(*ptrdestcb2++) = (*ptrsrccb2++);
			(*ptrdestcr2++) = (*ptrsrccr2++);
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

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // yuv420_prog_planar_to_yvu420_int_planar.end


/*****************************************************************************
  Routine:  void yuv420_int_planar_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 int to yuv420 prog format 
*****************************************************************************/


void  yuv420_int_planar_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_INT
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef YUV_420_PLANAR_INT

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

			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty3++) = (*ptrsrcy2++);
			(*ptrdesty2++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);
			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty3++) = (*ptrsrcy2++);
			(*ptrdesty2++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);

			(*ptrdestcb1++) = (*ptrsrccb1++);
			(*ptrdestcr1++) = (*ptrsrccr1++);
			(*ptrdestcb2++) = (*ptrsrccb2++);
			(*ptrdestcr2++) = (*ptrsrccr2++);

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

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // yuv420_int_planar_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_ycbcr_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yCbCr prog format 
*****************************************************************************/

void  yuv420_prog_planar_to_ycbcr_planar(
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

#define YUV_420_PLANAR_YCBCR
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_YCBCR

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty2++) = (*ptrsrcy2++);
			(*ptrdesty3++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);
			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty2++) = (*ptrsrcy2++);
			(*ptrdesty3++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);

			(*ptrdestcb1) = (*ptrsrccb1++);
			(*ptrdestcr1) = (*ptrsrccr1++);
			(*ptrdestcb2) = (*ptrsrccb2++);
			(*ptrdestcr2) = (*ptrsrccr2++);

			ptrdestcb1 += 2;
			ptrdestcb2 += 2;
			ptrdestcr1 += 2;
			ptrdestcr2 += 2;
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

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // yuv420_prog_planar_to_ycbcr_planar.end



/*****************************************************************************
  Routine:  void yvu420_prog_planar_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yvu420 prog to yuv420 prog format 
*****************************************************************************/

void  yvu420_prog_planar_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YVU_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef YVU_420_PLANAR_PROG

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

			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty2++) = (*ptrsrcy2++);
			(*ptrdesty3++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);
			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty2++) = (*ptrsrcy2++);
			(*ptrdesty3++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);

			(*ptrdestcb1++) = (*ptrsrccb1++);
			(*ptrdestcr1++) = (*ptrsrccr1++);
			(*ptrdestcb2++) = (*ptrsrccb2++);
			(*ptrdestcr2++) = (*ptrsrccr2++);

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

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // yvu420_prog_planar_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void yvu420_int_planar_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yvu420 int to yuv420 prog format 
*****************************************************************************/

void  yvu420_int_planar_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YVU_420_PLANAR_INT
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef YVU_420_PLANAR_INT

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

			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty3++) = (*ptrsrcy2++);
			(*ptrdesty2++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);
			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty3++) = (*ptrsrcy2++);
			(*ptrdesty2++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);

			(*ptrdestcb1++) = (*ptrsrccb1++);
			(*ptrdestcr1++) = (*ptrsrccr1++);
			(*ptrdestcb2++) = (*ptrsrccb2++);
			(*ptrdestcr2++) = (*ptrsrccr2++);

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

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // yvu420_int_planar_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void ycbcr_planar_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yCbCr int to yuv420 prog format 
*****************************************************************************/

void  ycbcr_planar_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_YCBCR
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef YUV_420_PLANAR_YCBCR

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

			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty2++) = (*ptrsrcy2++);
			(*ptrdesty3++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);
			(*ptrdesty1++) = (*ptrsrcy1++);
			(*ptrdesty2++) = (*ptrsrcy2++);
			(*ptrdesty3++) = (*ptrsrcy3++);
			(*ptrdesty4++) = (*ptrsrcy4++);

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcb2++) = (*ptrsrccb2);
			(*ptrdestcr2++) = (*ptrsrccr2);

			ptrsrccb1 += 2;
			ptrsrccr1 += 2;
			ptrsrccb2 += 2;
			ptrsrccr2 += 2;

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

		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // ycbcr_planar_to_yuv420_prog_planar.end




