/*****************************************************************************

FileName: <yuv444packedto420planar.cpp>

Module Description:
	Modules to convert YUV444packed to YUV420planar format
	List of Functions:

	yuv444_prog_packed_to_yuv420_prog_planar
	yuv444_int_packed_to_yuv420_prog_planar
	yvu444_prog_packed_to_yuv420_prog_planar
	yvu444_int_packed_to_yuv420_prog_planar
	uyv444_prog_packed_to_yuv420_prog_planar
	uyv444_int_packed_to_yuv420_prog_planar

*****************************************************************************/

#include "yuvconverter.h"

/*****************************************************************************
  Routine:  void yuv444_prog_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv444 prog to yuv420 prog format 
*****************************************************************************/

void  yuv444_prog_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_444_PACKED_PROG
#define SRC
#include "yuv444offsets.h"
#undef SRC
#undef YUV_444_PACKED_PROG


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

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty2++) = (*ptrsrcy2);
			(*ptrdesty3++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 6;
			ptrsrccb3 += 6;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 6;
			ptrsrccr3 += 6;

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

}//yuv444_prog_packed_to_yuv420_prog_planar.end


/*****************************************************************************
  Routine:  void yuv444_int_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv444 int to yuv420 prog format 
*****************************************************************************/

void  yuv444_int_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_444_PACKED_INT
#define SRC
#include "yuv444offsets.h"
#undef SRC
#undef YUV_444_PACKED_INT


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

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty3++) = (*ptrsrcy2);
			(*ptrdesty2++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 6;
			ptrsrccb3 += 6;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 6;
			ptrsrccr3 += 6;

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

}//yuv444_int_packed_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void yvu444_prog_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yvu444 prog to yuv420 prog format 
*****************************************************************************/

void  yvu444_prog_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YVU_444_PACKED_PROG
#define SRC
#include "yuv444offsets.h"
#undef SRC
#undef YVU_444_PACKED_PROG


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

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty2++) = (*ptrsrcy2);
			(*ptrdesty3++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 6;
			ptrsrccb3 += 6;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 6;
			ptrsrccr3 += 6;
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

}//yvu444_prog_packed_to_yuv420_prog_planar.end


/*****************************************************************************
  Routine:  void yvu444_int_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yvu444 int to yuv420 prog format 
*****************************************************************************/

void  yvu444_int_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YVU_444_PACKED_INT
#define SRC
#include "yuv444offsets.h"
#undef SRC
#undef YVU_444_PACKED_INT


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

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty3++) = (*ptrsrcy2);
			(*ptrdesty2++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 6;
			ptrsrccb3 += 6;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 6;
			ptrsrccr3 += 6;
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

}//yvu444_int_packed_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void uyv444_prog_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts uyv444 prog to yuv420 prog format 
*****************************************************************************/

void  uyv444_prog_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define UYV_444_PACKED_PROG
#define SRC
#include "yuv444offsets.h"
#undef SRC
#undef UYV_444_PACKED_PROG


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

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty2++) = (*ptrsrcy2);
			(*ptrdesty3++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 6;
			ptrsrccb3 += 6;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 6;
			ptrsrccr3 += 6;

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

}//uyv444_prog_packed_to_yuv420_prog_planar.end


/*****************************************************************************
  Routine:  void uyv444_int_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts uyv444 int to yuv420 prog format 
*****************************************************************************/

void  uyv444_int_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define UYV_444_PACKED_INT
#define SRC
#include "yuv444offsets.h"
#undef SRC
#undef UYV_444_PACKED_INT


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

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdesty1++) = (*ptrsrcy1);
			(*ptrdesty3++) = (*ptrsrcy2);
			(*ptrdesty2++) = (*ptrsrcy3);
			(*ptrdesty4++) = (*ptrsrcy4);

			ptrsrcy1 += 3;
			ptrsrcy2 += 3;
			ptrsrcy3 += 3;
			ptrsrcy4 += 3;

			(*ptrdestcb1++) = (*ptrsrccb1);
			(*ptrdestcb2++) = (*ptrsrccb3);

			ptrsrccb1 += 6;
			ptrsrccb3 += 6;

			(*ptrdestcr1++) = (*ptrsrccr1);
			(*ptrdestcr2++) = (*ptrsrccr3);

			ptrsrccr1 += 6;
			ptrsrccr3 += 6;
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

}//uyv444_int_packed_to_yuv420_prog_planar.end

