/*****************************************************************************

FileName: <yuv420planarto444planar.cpp>

Module Description:
	Module to convert YUV420planar to YUV444planar format
	List of Functions:

	yuv420_prog_planar_to_yuv444_prog_planar
	yuv420_prog_planar_to_yuv444_int_planar
	yuv420_prog_planar_to_yvu444_prog_planar
	yuv420_prog_planar_to_yvu444_int_planar
	yuv420_prog_planar_to_uyv444_prog_planar
	yuv420_prog_planar_to_uyv444_int_planar

*****************************************************************************/

#include "yuvconverter.h"

/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yuv444_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yuv444 prog format 
*****************************************************************************/

void  yuv420_prog_planar_to_yuv444_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef  YUV_420_PLANAR_PROG


#define YUV_444_PLANAR_PROG
#define DEST
#include "yuv444offsets.h"
#undef DEST
#undef  YUV_444_PLANAR_PROG

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
			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1++);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2++);
					
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1++);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2++);

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


} // yuv420_prog_planar_to_yuv444_prog_planar.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yuv444_int_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yuv444 int format 
*****************************************************************************/

void  yuv420_prog_planar_to_yuv444_int_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef  YUV_420_PLANAR_PROG


#define YUV_444_PLANAR_INT
#define DEST
#include "yuv444offsets.h"
#undef DEST
#undef  YUV_444_PLANAR_INT

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

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1++);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2++);
					
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1++);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2++);

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

} // yuv420_prog_planar_to_yuv444_int_planar.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yvu444_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yvu444 prog format 
*****************************************************************************/

void  yuv420_prog_planar_to_yvu444_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef  YUV_420_PLANAR_PROG


#define YVU_444_PLANAR_PROG
#define DEST
#include "yuv444offsets.h"
#undef DEST
#undef  YVU_444_PLANAR_PROG

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
			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1++);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2++);
					
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1++);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2++);

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


} // yuv420_prog_planar_to_yvu444_prog_planar.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_yvu444_int_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to yvu444 int format 
*****************************************************************************/

void  yuv420_prog_planar_to_yvu444_int_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef  YUV_420_PLANAR_PROG


#define YVU_444_PLANAR_INT
#define DEST
#include "yuv444offsets.h"
#undef DEST
#undef  YVU_444_PLANAR_INT

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

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1++);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2++);
					
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1++);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2++);

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

} // yuv420_prog_planar_to_yvu444_int_planar.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_uyv444_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to uyv444 prog format 
*****************************************************************************/

void  yuv420_prog_planar_to_uyv444_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef  YUV_420_PLANAR_PROG


#define UYV_444_PLANAR_PROG
#define DEST
#include "yuv444offsets.h"
#undef DEST
#undef  UYV_444_PLANAR_PROG

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
			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1++);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2++);
					
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1++);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2++);

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


} // yuv420_prog_planar_to_uyv444_prog_planar.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_uyv444_int_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to uyv444 int format 
*****************************************************************************/

void  yuv420_prog_planar_to_uyv444_int_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_420_PLANAR_PROG
#define SRC
#include "yuv420offsets.h"
#undef SRC
#undef  YUV_420_PLANAR_PROG


#define UYV_444_PLANAR_INT
#define DEST
#include "yuv444offsets.h"
#undef DEST
#undef  UYV_444_PLANAR_INT

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

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb1++);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb3++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2);
			(*ptrdestcb4++) = (*ptrsrccb2++);
					
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr1++);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr3++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2);
			(*ptrdestcr4++) = (*ptrsrccr2++);

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

} // yuv420_prog_planar_to_uyv444_int_planar.end



