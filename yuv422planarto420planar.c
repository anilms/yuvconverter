/*****************************************************************************

FileName: <yuv422planarto420planar.cpp>

Module Description:
	Modules to convert YUV422planar to YUV420planar format
	List of Functions:

	yuv422_prog_planar_to_yuv420_prog_planar
	yuv422_int_planar_to_yuv420_prog_planar
	yvu422_prog_planar_to_yuv420_prog_planar
	yvu422_int_planar_to_yuv420_prog_planar

*****************************************************************************/

#include "yuvconverter.h"

/*****************************************************************************
  Routine:  void yuv422_prog_planar_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv422 prog to yuv420 prog format 
*****************************************************************************/

void  yuv422_prog_planar_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_422_PLANAR_PROG
#define SRC
#include "yuv422offsets.h"
#undef SRC
#undef YUV_422_PLANAR_PROG


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
			(*ptrdestcb2++) = (*ptrsrccb3++);

			(*ptrdestcr1++) = (*ptrsrccr1++);
			(*ptrdestcr2++) = (*ptrsrccr3++);

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

}//yuv422_prog_planar_to_yuv420_prog_planar.end


/*****************************************************************************
  Routine:  void yuv422_int_planar_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv422 int to yuv420 prog format 
*****************************************************************************/

void  yuv422_int_planar_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YUV_422_PLANAR_INT
#define SRC
#include "yuv422offsets.h"
#undef SRC
#undef YUV_422_PLANAR_INT


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
			(*ptrdestcb2++) = (*ptrsrccb3++);

			(*ptrdestcr1++) = (*ptrsrccr1++);
			(*ptrdestcr2++) = (*ptrsrccr3++);

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

}//yuv422_int_planar_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void yvu422_prog_planar_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yvu422 prog to yuv420 prog format 
*****************************************************************************/

void  yvu422_prog_planar_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YVU_422_PLANAR_PROG
#define SRC
#include "yuv422offsets.h"
#undef SRC
#undef YVU_422_PLANAR_PROG


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
			(*ptrdestcb2++) = (*ptrsrccb3++);

			(*ptrdestcr1++) = (*ptrsrccr1++);
			(*ptrdestcr2++) = (*ptrsrccr3++);

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

}//yvu422_prog_planar_to_yuv420_prog_planar.end




/*****************************************************************************
  Routine:  void yvu422_int_planar_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yvu422 int to yuv420 prog format 
*****************************************************************************/

void  yvu422_int_planar_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define YVU_422_PLANAR_INT
#define SRC
#include "yuv422offsets.h"
#undef SRC
#undef YVU_422_PLANAR_INT


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
			(*ptrdestcb2++) = (*ptrsrccb3++);

			(*ptrdestcr1++) = (*ptrsrccr1++);
			(*ptrdestcr2++) = (*ptrsrccr3++);

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

}//yvu422_int_planar_to_yuv420_prog_planar.end



