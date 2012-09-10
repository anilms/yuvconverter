/*****************************************************************************

FileName: 	<inittab.cpp>

File Description:
Contains Modules to initialize the LUTs

*****************************************************************************/

#include "inittab.h"

/* LUTs for YUV to RGB conversion */
long int crv_tab[256];
long int cbu_tab[256];
long int cgu_tab[256];
long int cgv_tab[256];
long int tab_76309[256];

long int yr_tab[256];
long int yg_tab[256];
long int yb_tab[256];
long int ur_tab[256];
long int ug_tab[256];
long int ub_tab[256];
long int vr_tab[256];
long int vg_tab[256];
long int vb_tab[256];

unsigned char clp[1024];



/*****************************************************************************
  Routine:  void InitConvt(int width, int height)

        returns        	: void
		width			: frame width
		height			: frame height
  Description          	: Initializes the LUTs for yuvtorgb conversion
*****************************************************************************/

void InitConvt(int width, int height) {
   long int crv,cbu,cgu,cgv;
   int i,ind;   
     
   crv = SCALECrv; cbu = SCALECbu;
   cgu = SCALECgu; cgv = SCALECgv;
  
   for (i = 0; i < 256; i++) {
        crv_tab[i] = (i-SHIFTCrv) * crv;
        cbu_tab[i] = (i-SHIFTCbu) * cbu;
        cgu_tab[i] = (i-SHIFTCgu) * cgu;
        cgv_tab[i] = (i-SHIFTCgv) * cgv;
        tab_76309[i] = SCALEY*(i-SHIFTY);

        yr_tab[i] = i*SCALEYR;
        yg_tab[i] = i*SCALEYG;
        yb_tab[i] = i*SCALEYB;
        
        ur_tab[i] = i*SCALEUR;
        ug_tab[i] = i*SCALEUG;
        ub_tab[i] = i*SCALEUB;
        
        vr_tab[i] = i*SCALEVR;
        vg_tab[i] = i*SCALEVG;
        vb_tab[i] = i*SCALEVB;
      
   }
	 
   for (i=0; i<384; i++)
	  clp[i] =0;
   ind=384;
   for (i=0;i<256; i++)
	   clp[ind++]=i;
   ind=640;
   for (i=0;i<384;i++)
	   clp[ind++]=255;
}



