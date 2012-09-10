/*****************************************************************************

FileName: <rgbto420planar.cpp>

File Description:
	Modules to convert rgb to yuv420planar format
	List of Functions:

	rgb_planar_to_yuv420_prog_planar
	bgr_planar_to_yuv420_prog_planar
	rgb_packed_to_yuv420_prog_planar
	bgr_packed_to_yuv420_prog_planar

*****************************************************************************/

#include "yuvconverter.h"
#include "inittab.h"

/*****************************************************************************
  Routine:  void rgb_planar_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts rgb planar to yuv420 prog format 
*****************************************************************************/

void  rgb_planar_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define RGB_PLANAR
#define SRC
#include "rgboffsets.h"
#undef SRC
#undef RGB_PLANAR 

#define YUV_420_PLANAR_PROG 
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_PROG

    int yr, yg, yb;
    int ur, ug, ub;
    int vr, vg, vb;
    int r, g, b;
    
	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

            /* First and Second Line */
            /* Top Left */
			r = (*ptrsrcr1++);
			g = (*ptrsrcg1++);
			b = (*ptrsrcb1++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
			ur = ur_tab[r];
			ug = ug_tab[g];
			ub = ub_tab[b];
			vr = vr_tab[r];
			vg = vg_tab[g];
			vb = vb_tab[b];
            (*ptrdestcb1++) = clp[384+((ur + ug + ub)>>16)+SHIFTCC];  
            (*ptrdestcr1++) = clp[384+((vr + vg + vb)>>16)+SHIFTCC];  
            (*ptrdesty1++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  

            /* Top Right */
			r = (*ptrsrcr1++);
			g = (*ptrsrcg1++);
			b = (*ptrsrcb1++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty1++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            
            /* Bottom Left */
			r = (*ptrsrcr2++);
			g = (*ptrsrcg2++);
			b = (*ptrsrcb2++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty2++) = clp[384+((yr + yg + yb)>>16)+SHIFTY]; 

            /* Bottom Right */
			r = (*ptrsrcr2++);
			g = (*ptrsrcg2++);
			b = (*ptrsrcb2++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty2++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];


            /* Third and Fourth Line */
            /* Top Left */
			r = (*ptrsrcr3++);
			g = (*ptrsrcg3++);
			b = (*ptrsrcb3++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
			ur = ur_tab[r];
			ug = ug_tab[g];
			ub = ub_tab[b];
			vr = vr_tab[r];
			vg = vg_tab[g];
			vb = vb_tab[b];
            (*ptrdestcb2++) = clp[384+((ur + ug + ub)>>16)+SHIFTCC];  
            (*ptrdestcr2++) = clp[384+((vr + vg + vb)>>16)+SHIFTCC];  
            (*ptrdesty3++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  

            /* Top Right */
			r = (*ptrsrcr3++);
			g = (*ptrsrcg3++);
			b = (*ptrsrcb3++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty3++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            
            /* Bottom Left */
			r = (*ptrsrcr4++);
			g = (*ptrsrcg4++);
			b = (*ptrsrcb4++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty4++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];

            /* Bottom Right */
			r = (*ptrsrcr4++);
			g = (*ptrsrcg4++);
			b = (*ptrsrcb4++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty4++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  

            
		}

		
		/* Update src pointers */
		ptrsrcr1 += srcrgbstride;
		ptrsrcr2 += srcrgbstride;
		ptrsrcr3 += srcrgbstride;
		ptrsrcr4 += srcrgbstride;

		ptrsrcg1 += srcrgbstride;
		ptrsrcg2 += srcrgbstride;
		ptrsrcg3 += srcrgbstride;
		ptrsrcg4 += srcrgbstride;

		ptrsrcb1 += srcrgbstride;
		ptrsrcb2 += srcrgbstride;
		ptrsrcb3 += srcrgbstride;
		ptrsrcb4 += srcrgbstride;


        /* Update dest pointers */
		ptrdesty1  += destystride;
		ptrdesty2  += destystride;
		ptrdesty3  += destystride;
		ptrdesty4  += destystride;
		
		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;
	
		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // rgb_planar_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void bgr_planar_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts bgr planar to yuv420 prog format 
*****************************************************************************/

void  bgr_planar_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define BGR_PLANAR
#define SRC
#include "rgboffsets.h"
#undef SRC
#undef BGR_PLANAR 

#define YUV_420_PLANAR_PROG 
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_PROG

    int yr, yg, yb;
    int ur, ug, ub;
    int vr, vg, vb;
    int r, g, b;
    
	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

            /* First and Second Line */
            /* Top Left */
			r = (*ptrsrcr1++);
			g = (*ptrsrcg1++);
			b = (*ptrsrcb1++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
			ur = ur_tab[r];
			ug = ug_tab[g];
			ub = ub_tab[b];
			vr = vr_tab[r];
			vg = vg_tab[g];
			vb = vb_tab[b];
            (*ptrdestcb1++) = clp[384+((ur + ug + ub)>>16)+SHIFTCC];  
            (*ptrdestcr1++) = clp[384+((vr + vg + vb)>>16)+SHIFTCC];  
            (*ptrdesty1++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  

            /* Top Right */
			r = (*ptrsrcr1++);
			g = (*ptrsrcg1++);
			b = (*ptrsrcb1++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty1++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            
            /* Bottom Left */
			r = (*ptrsrcr2++);
			g = (*ptrsrcg2++);
			b = (*ptrsrcb2++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty2++) = clp[384+((yr + yg + yb)>>16)+SHIFTY]; 

            /* Bottom Right */
			r = (*ptrsrcr2++);
			g = (*ptrsrcg2++);
			b = (*ptrsrcb2++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty2++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];


            /* Third and Fourth Line */
            /* Top Left */
			r = (*ptrsrcr3++);
			g = (*ptrsrcg3++);
			b = (*ptrsrcb3++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
			ur = ur_tab[r];
			ug = ug_tab[g];
			ub = ub_tab[b];
			vr = vr_tab[r];
			vg = vg_tab[g];
			vb = vb_tab[b];
            (*ptrdestcb2++) = clp[384+((ur + ug + ub)>>16)+SHIFTCC];  
            (*ptrdestcr2++) = clp[384+((vr + vg + vb)>>16)+SHIFTCC];  
            (*ptrdesty3++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  

            /* Top Right */
			r = (*ptrsrcr3++);
			g = (*ptrsrcg3++);
			b = (*ptrsrcb3++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty3++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            
            /* Bottom Left */
			r = (*ptrsrcr4++);
			g = (*ptrsrcg4++);
			b = (*ptrsrcb4++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty4++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];

            /* Bottom Right */
			r = (*ptrsrcr4++);
			g = (*ptrsrcg4++);
			b = (*ptrsrcb4++);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty4++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  

            
		}

		
		/* Update src pointers */
		ptrsrcr1 += srcbgrstride;
		ptrsrcr2 += srcbgrstride;
		ptrsrcr3 += srcbgrstride;
		ptrsrcr4 += srcbgrstride;

		ptrsrcg1 += srcbgrstride;
		ptrsrcg2 += srcbgrstride;
		ptrsrcg3 += srcbgrstride;
		ptrsrcg4 += srcbgrstride;

		ptrsrcb1 += srcbgrstride;
		ptrsrcb2 += srcbgrstride;
		ptrsrcb3 += srcbgrstride;
		ptrsrcb4 += srcbgrstride;


        /* Update dest pointers */
		ptrdesty1  += destystride;
		ptrdesty2  += destystride;
		ptrdesty3  += destystride;
		ptrdesty4  += destystride;
		
		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;
	
		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // bgr_planar_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void rgb_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts rgb packed to yuv420 prog format 
*****************************************************************************/

void  rgb_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define RGB_PACKED
#define SRC
#include "rgboffsets.h"
#undef SRC
#undef RGB_PACKED

#define YUV_420_PLANAR_PROG 
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_PROG

    int yr, yg, yb;
    int ur, ug, ub;
    int vr, vg, vb;
    int r, g, b;
    
	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

            /* First and Second Line */
            /* Top Left */
			r = (*ptrsrcr1);
			g = (*ptrsrcg1);
			b = (*ptrsrcb1);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
			ur = ur_tab[r];
			ug = ug_tab[g];
			ub = ub_tab[b];
			vr = vr_tab[r];
			vg = vg_tab[g];
			vb = vb_tab[b];
            (*ptrdestcb1++) = clp[384+((ur + ug + ub)>>16)+SHIFTCC];  
            (*ptrdestcr1++) = clp[384+((vr + vg + vb)>>16)+SHIFTCC];  
            (*ptrdesty1++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            ptrsrcr1 += 3; 
            ptrsrcg1 += 3;            
            ptrsrcb1 += 3;
            
            /* Top Right */
			r = (*ptrsrcr1);
			g = (*ptrsrcg1);
			b = (*ptrsrcb1);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty1++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            ptrsrcr1 += 3; 
            ptrsrcg1 += 3;            
            ptrsrcb1 += 3;
            
            /* Bottom Left */
			r = (*ptrsrcr2);
			g = (*ptrsrcg2);
			b = (*ptrsrcb2);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty2++) = clp[384+((yr + yg + yb)>>16)+SHIFTY]; 
            ptrsrcr2 += 3; 
            ptrsrcg2 += 3;            
            ptrsrcb2 += 3;

            /* Bottom Right */
			r = (*ptrsrcr2);
			g = (*ptrsrcg2);
			b = (*ptrsrcb2);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty2++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            ptrsrcr2 += 3; 
            ptrsrcg2 += 3;            
            ptrsrcb2 += 3;


            /* Third and Fourth Line */
            /* Top Left */
			r = (*ptrsrcr3);
			g = (*ptrsrcg3);
			b = (*ptrsrcb3);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
			ur = ur_tab[r];
			ug = ug_tab[g];
			ub = ub_tab[b];
			vr = vr_tab[r];
			vg = vg_tab[g];
			vb = vb_tab[b];
            (*ptrdestcb2++) = clp[384+((ur + ug + ub)>>16)+SHIFTCC];  
            (*ptrdestcr2++) = clp[384+((vr + vg + vb)>>16)+SHIFTCC];  
            (*ptrdesty3++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  
            ptrsrcr3 += 3; 
            ptrsrcg3 += 3;            
            ptrsrcb3 += 3;

            /* Top Right */
			r = (*ptrsrcr3);
			g = (*ptrsrcg3);
			b = (*ptrsrcb3);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty3++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            ptrsrcr3 += 3; 
            ptrsrcg3 += 3;            
            ptrsrcb3 += 3;
            
            /* Bottom Left */
			r = (*ptrsrcr4);
			g = (*ptrsrcg4);
			b = (*ptrsrcb4);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty4++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            ptrsrcr4 += 3; 
            ptrsrcg4 += 3;            
            ptrsrcb4 += 3;

            /* Bottom Right */
			r = (*ptrsrcr4);
			g = (*ptrsrcg4);
			b = (*ptrsrcb4);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty4++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  
            ptrsrcr4 += 3; 
            ptrsrcg4 += 3;            
            ptrsrcb4 += 3;

            
		}

		
		/* Update src pointers */
		ptrsrcr1 += srcrgbstride;
		ptrsrcr2 += srcrgbstride;
		ptrsrcr3 += srcrgbstride;
		ptrsrcr4 += srcrgbstride;

		ptrsrcg1 += srcrgbstride;
		ptrsrcg2 += srcrgbstride;
		ptrsrcg3 += srcrgbstride;
		ptrsrcg4 += srcrgbstride;

		ptrsrcb1 += srcrgbstride;
		ptrsrcb2 += srcrgbstride;
		ptrsrcb3 += srcrgbstride;
		ptrsrcb4 += srcrgbstride;


        /* Update dest pointers */
		ptrdesty1  += destystride;
		ptrdesty2  += destystride;
		ptrdesty3  += destystride;
		ptrdesty4  += destystride;
		
		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;
	
		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // rgb_packed_to_yuv420_prog_planar.end



/*****************************************************************************
  Routine:  void bgr_packed_to_yuv420_prog_planar(
  								unsigned char *bufsrc, 
								unsigned char *bufdest, 
  								int width, int height, 
								)

        returns        	: void
        bufsrc         	: input buffer
        bufdest        	: output buffer
		width			: frame width
		height			: frame height
  Description          	: Converts bgr packed to yuv420 prog format 
*****************************************************************************/

void  bgr_packed_to_yuv420_prog_planar(
							unsigned char *bufsrc, 
							unsigned char *bufdest, 
							int width, int height
							)
{

#define BGR_PACKED
#define SRC
#include "rgboffsets.h"
#undef SRC
#undef BGR_PACKED

#define YUV_420_PLANAR_PROG 
#define DEST
#include "yuv420offsets.h"
#undef DEST
#undef YUV_420_PLANAR_PROG

    int yr, yg, yb;
    int ur, ug, ub;
    int vr, vg, vb;
    int r, g, b;
    
	int i, j;

	for(j=0; j<(height/4); j++)
	{
		for(i=0;i<(width/2);i++)
		{

            /* First and Second Line */
            /* Top Left */
			r = (*ptrsrcr1);
			g = (*ptrsrcg1);
			b = (*ptrsrcb1);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
			ur = ur_tab[r];
			ug = ug_tab[g];
			ub = ub_tab[b];
			vr = vr_tab[r];
			vg = vg_tab[g];
			vb = vb_tab[b];
            (*ptrdestcb1++) = clp[384+((ur + ug + ub)>>16)+SHIFTCC];  
            (*ptrdestcr1++) = clp[384+((vr + vg + vb)>>16)+SHIFTCC];  
            (*ptrdesty1++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  
            ptrsrcr1 += 3; 
            ptrsrcg1 += 3;
            ptrsrcb1 += 3;

            /* Top Right */
			r = (*ptrsrcr1);
			g = (*ptrsrcg1);
			b = (*ptrsrcb1);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty1++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            ptrsrcr1 += 3; 
            ptrsrcg1 += 3;
            ptrsrcb1 += 3;
            
            /* Bottom Left */
			r = (*ptrsrcr2);
			g = (*ptrsrcg2);
			b = (*ptrsrcb2);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty2++) = clp[384+((yr + yg + yb)>>16)+SHIFTY]; 
            ptrsrcr2 += 3; 
            ptrsrcg2 += 3;
            ptrsrcb2 += 3;
            

            /* Bottom Right */
			r = (*ptrsrcr2);
			g = (*ptrsrcg2);
			b = (*ptrsrcb2);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty2++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            ptrsrcr2 += 3; 
            ptrsrcg2 += 3;
            ptrsrcb2 += 3;
            


            /* Third and Fourth Line */
            /* Top Left */
			r = (*ptrsrcr3);
			g = (*ptrsrcg3);
			b = (*ptrsrcb3);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
			ur = ur_tab[r];
			ug = ug_tab[g];
			ub = ub_tab[b];
			vr = vr_tab[r];
			vg = vg_tab[g];
			vb = vb_tab[b];
            (*ptrdestcb2++) = clp[384+((ur + ug + ub)>>16)+SHIFTCC];  
            (*ptrdestcr2++) = clp[384+((vr + vg + vb)>>16)+SHIFTCC];  
            (*ptrdesty3++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  
            ptrsrcr3 += 3; 
            ptrsrcg3 += 3;
            ptrsrcb3 += 3;
            

            /* Top Right */
			r = (*ptrsrcr3);
			g = (*ptrsrcg3);
			b = (*ptrsrcb3);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty3++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            ptrsrcr3 += 3; 
            ptrsrcg3 += 3;
            ptrsrcb3 += 3;
            
            /* Bottom Left */
			r = (*ptrsrcr4);
			g = (*ptrsrcg4);
			b = (*ptrsrcb4);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty4++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];
            ptrsrcr4 += 3; 
            ptrsrcg4 += 3;
            ptrsrcb4 += 3;

            /* Bottom Right */
			r = (*ptrsrcr4);
			g = (*ptrsrcg4);
			b = (*ptrsrcb4);
			yr = yr_tab[r];
			yg = yg_tab[g];
			yb = yb_tab[b];
            (*ptrdesty4++) = clp[384+((yr + yg + yb)>>16)+SHIFTY];  
            ptrsrcr4 += 3; 
            ptrsrcg4 += 3;
            ptrsrcb4 += 3;
            
		}

		
		/* Update src pointers */
		ptrsrcr1 += srcbgrstride;
		ptrsrcr2 += srcbgrstride;
		ptrsrcr3 += srcbgrstride;
		ptrsrcr4 += srcbgrstride;

		ptrsrcg1 += srcbgrstride;
		ptrsrcg2 += srcbgrstride;
		ptrsrcg3 += srcbgrstride;
		ptrsrcg4 += srcbgrstride;

		ptrsrcb1 += srcbgrstride;
		ptrsrcb2 += srcbgrstride;
		ptrsrcb3 += srcbgrstride;
		ptrsrcb4 += srcbgrstride;


        /* Update dest pointers */
		ptrdesty1  += destystride;
		ptrdesty2  += destystride;
		ptrdesty3  += destystride;
		ptrdesty4  += destystride;
		
		ptrdestcb1 += destccstride;
		ptrdestcb2 += destccstride;
	
		ptrdestcr1 += destccstride;
		ptrdestcr2 += destccstride;

	}

} // bgr_packed_to_yuv420_prog_planar.end


