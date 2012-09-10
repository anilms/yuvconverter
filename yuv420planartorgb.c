/*****************************************************************************

FileName: <yuv420planartorgb.cpp>

File Description:
	Modules to convert YUV420planar to rgb format
	List of Functions:

	yuv420_prog_planar_to_rgb_planar
	yuv420_prog_planar_to_bgr_planar
	yuv420_prog_planar_to_rgb_packed
	yuv420_prog_planar_to_bgr_packed

*****************************************************************************/

#include "yuvconverter.h"

/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_rgb_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to rgb planar format 
*****************************************************************************/

void  yuv420_prog_planar_to_rgb_planar(
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

#define RGB_PLANAR
#define DEST
#include "rgboffsets.h"
#undef DEST
#undef RGB_PLANAR

	int crv, cgu, cgv, cbu;
	int y, u, v;

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			/* First and Second Lines */	
			u = (*ptrsrccb1++);
			v = (*ptrsrccr1++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1++) = clp[384+((y + cbu)>>16)];

			/* Top Right */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1++) = clp[384+((y + cbu)>>16)];

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2++) = clp[384+((y + cbu)>>16)];

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2++) = clp[384+((y + cbu)>>16)];



			/* Third and Fourth Lines */
			u = (*ptrsrccb2++);
			v = (*ptrsrccr2++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3++) = clp[384+((y + cbu)>>16)];

			/* Top Right */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3++) = clp[384+((y + cbu)>>16)];

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4++) = clp[384+((y + cbu)>>16)];

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4++) = clp[384+((y + cbu)>>16)];

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
		ptrdestr1 += destrgbstride;
		ptrdestr2 += destrgbstride;
		ptrdestr3 += destrgbstride;
		ptrdestr4 += destrgbstride;

		ptrdestg1 += destrgbstride;
		ptrdestg2 += destrgbstride;
		ptrdestg3 += destrgbstride;
		ptrdestg4 += destrgbstride;

		ptrdestb1 += destrgbstride;
		ptrdestb2 += destrgbstride;
		ptrdestb3 += destrgbstride;
		ptrdestb4 += destrgbstride;

	}

} // yuv420_prog_planar_to_rgb_planar.end





/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_bgr_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to bgr planar format 
*****************************************************************************/

void  yuv420_prog_planar_to_bgr_planar(
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

#define BGR_PLANAR
#define DEST
#include "rgboffsets.h"
#undef DEST
#undef BGR_PLANAR

	int crv, cgu, cgv, cbu;
	int y, u, v;

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			/* First and Second Lines */	
			u = (*ptrsrccb1++);
			v = (*ptrsrccr1++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1++) = clp[384+((y + cbu)>>16)];

			/* Top Right */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1++) = clp[384+((y + cbu)>>16)];

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2++) = clp[384+((y + cbu)>>16)];

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2++) = clp[384+((y + cbu)>>16)];



			/* Third and Fourth Lines */
			u = (*ptrsrccb2++);
			v = (*ptrsrccr2++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3++) = clp[384+((y + cbu)>>16)];

			/* Top Right */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3++) = clp[384+((y + cbu)>>16)];

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4++) = clp[384+((y + cbu)>>16)];

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4++) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4++) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4++) = clp[384+((y + cbu)>>16)];

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
		ptrdestr1 += destbgrstride;
		ptrdestr2 += destbgrstride;
		ptrdestr3 += destbgrstride;
		ptrdestr4 += destbgrstride;

		ptrdestg1 += destbgrstride;
		ptrdestg2 += destbgrstride;
		ptrdestg3 += destbgrstride;
		ptrdestg4 += destbgrstride;

		ptrdestb1 += destbgrstride;
		ptrdestb2 += destbgrstride;
		ptrdestb3 += destbgrstride;
		ptrdestb4 += destbgrstride;

	}


} // yuv420_prog_planar_to_bgr_planar.end



/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_rgb_packed(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to rgb packed format 
*****************************************************************************/

void  yuv420_prog_planar_to_rgb_packed(
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

#define RGB_PACKED
#define DEST
#include "rgboffsets.h"
#undef DEST
#undef RGB_PACKED

	int crv, cgu, cgv, cbu;
	int y, u, v;

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			/* First and Second Lines */	
			u = (*ptrsrccb1++);
			v = (*ptrsrccr1++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];

			ptrdestr1 += 3;
			ptrdestg1 += 3;
			ptrdestb1 += 3;

			/* Top Right */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];

			ptrdestr1 += 3;
			ptrdestg1 += 3;
			ptrdestb1 += 3;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];

			ptrdestr2 += 3;
			ptrdestg2 += 3;
			ptrdestb2 += 3;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];

			ptrdestr2 += 3;
			ptrdestg2 += 3;
			ptrdestb2 += 3;


			/* Third and Fourth Lines */
			u = (*ptrsrccb2++);
			v = (*ptrsrccr2++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];

			ptrdestr3 += 3;
			ptrdestg3 += 3;
			ptrdestb3 += 3;

			/* Top Right */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];

			ptrdestr3 += 3;
			ptrdestg3 += 3;
			ptrdestb3 += 3;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];

			ptrdestr4 += 3;
			ptrdestg4 += 3;
			ptrdestb4 += 3;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];

			ptrdestr4 += 3;
			ptrdestg4 += 3;
			ptrdestb4 += 3;

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
		ptrdestr1 += destrgbstride;
		ptrdestr2 += destrgbstride;
		ptrdestr3 += destrgbstride;
		ptrdestr4 += destrgbstride;

		ptrdestg1 += destrgbstride;
		ptrdestg2 += destrgbstride;
		ptrdestg3 += destrgbstride;
		ptrdestg4 += destrgbstride;

		ptrdestb1 += destrgbstride;
		ptrdestb2 += destrgbstride;
		ptrdestb3 += destrgbstride;
		ptrdestb4 += destrgbstride;

	}


} // yuv420_prog_planar_to_rgb_packed.end




/*****************************************************************************
  Routine:  void yuv420_prog_planar_to_bgr_packed(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts yuv420 prog to bgr packed format 
*****************************************************************************/

void  yuv420_prog_planar_to_bgr_packed(
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

#define BGR_PACKED
#define DEST
#include "rgboffsets.h"
#undef DEST
#undef BGR_PACKED

	int crv, cgu, cgv, cbu;
	int y, u, v;

	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

			/* First and Second Lines */	
			u = (*ptrsrccb1++);
			v = (*ptrsrccr1++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];

			ptrdestr1 += 3;
			ptrdestg1 += 3;
			ptrdestb1 += 3;

			/* Top Right */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];

			ptrdestr1 += 3;
			ptrdestg1 += 3;
			ptrdestb1 += 3;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];

			ptrdestr2 += 3;
			ptrdestg2 += 3;
			ptrdestb2 += 3;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];

			ptrdestr2 += 3;
			ptrdestg2 += 3;
			ptrdestb2 += 3;


			/* Third and Fourth Lines */
			u = (*ptrsrccb2++);
			v = (*ptrsrccr2++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];

			ptrdestr3 += 3;
			ptrdestg3 += 3;
			ptrdestb3 += 3;

			/* Top Right */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];

			ptrdestr3 += 3;
			ptrdestg3 += 3;
			ptrdestb3 += 3;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];

			ptrdestr4 += 3;
			ptrdestg4 += 3;
			ptrdestb4 += 3;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];

			ptrdestr4 += 3;
			ptrdestg4 += 3;
			ptrdestb4 += 3;

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
		ptrdestr1 += destbgrstride;
		ptrdestr2 += destbgrstride;
		ptrdestr3 += destbgrstride;
		ptrdestr4 += destbgrstride;

		ptrdestg1 += destbgrstride;
		ptrdestg2 += destbgrstride;
		ptrdestg3 += destbgrstride;
		ptrdestg4 += destbgrstride;

		ptrdestb1 += destbgrstride;
		ptrdestb2 += destbgrstride;
		ptrdestb3 += destbgrstride;
		ptrdestb4 += destbgrstride;

	}

} // yuv420_prog_planar_to_bgr_packed.end



