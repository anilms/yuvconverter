/*****************************************************************************

File Name: 	<yuvconverter.h>

File Description:
Header File for yuvconverter.cpp

*****************************************************************************/
#define NUMARGS 	(5+1)			//actual no. of ARGs+1

/*****************************************************************************

  Extern Variables

 *****************************************************************************/

//Look Up Tables
extern long int crv_tab[];
extern long int cbu_tab[];
extern long int cgu_tab[];
extern long int cgv_tab[];
extern long int tab_76309[];

extern long int yr_tab[];
extern long int yg_tab[];
extern long int yb_tab[];
extern long int ur_tab[];
extern long int ug_tab[];
extern long int ub_tab[];
extern long int vr_tab[];
extern long int vg_tab[];
extern long int vb_tab[];

extern unsigned char clp[];


/*****************************************************************************

  Function Prototypes

 *****************************************************************************/

/* Initialization Routines */
void InitConvt(int width, int height);


/* Functions to convert from YUV420 */

/* yuv420 converters */ 
void  yuv420_prog_planar_to_yuv400_prog_planar(unsigned char *,unsigned char *, int , int );		//110100

void  yuv420_prog_planar_to_yuv420_int_planar(unsigned char *,unsigned char *, int , int );			//110111
void  yuv420_prog_planar_to_yvu420_prog_planar(unsigned char *,unsigned char *, int , int );		//110120
void  yuv420_prog_planar_to_yvu420_int_planar(unsigned char *,unsigned char *, int , int );			//110121
void  yuv420_prog_planar_to_ycbcr_planar(unsigned char *,unsigned char *, int , int );				//110130

void  yuv420_prog_planar_to_yuv422_prog_planar(unsigned char *,unsigned char *, int , int );		//110210
void  yuv420_prog_planar_to_yuv422_int_planar(unsigned char *,unsigned char *, int , int );			//110211
void  yuv420_prog_planar_to_yvu422_prog_planar(unsigned char *,unsigned char *, int , int );		//110220
void  yuv420_prog_planar_to_yvu422_int_planar(unsigned char *,unsigned char *, int , int );			//110221
void  yuv420_prog_planar_to_uyvy_prog_packed(unsigned char *,unsigned char *, int , int );			//110230
void  yuv420_prog_planar_to_uyvy_int_packed(unsigned char *,unsigned char *, int , int );			//110231
void  yuv420_prog_planar_to_yuyv_prog_packed(unsigned char *,unsigned char *, int , int );			//110240
void  yuv420_prog_planar_to_yuyv_int_packed(unsigned char *,unsigned char *, int , int );			//110241
void  yuv420_prog_planar_to_yvyu_prog_packed(unsigned char *,unsigned char *, int , int );			//110250
void  yuv420_prog_planar_to_yvyu_int_packed(unsigned char *,unsigned char *, int , int );			//110251

void  yuv420_prog_planar_to_yuv444_prog_planar(unsigned char *,unsigned char *, int , int );		//110310
void  yuv420_prog_planar_to_yuv444_int_planar(unsigned char *,unsigned char *, int , int );			//110311
void  yuv420_prog_planar_to_yvu444_prog_planar(unsigned char *,unsigned char *, int , int );		//110320
void  yuv420_prog_planar_to_yvu444_int_planar(unsigned char *,unsigned char *, int , int );			//110321
void  yuv420_prog_planar_to_uyv444_prog_planar(unsigned char *,unsigned char *, int , int );		//110330
void  yuv420_prog_planar_to_uyv444_int_planar(unsigned char *,unsigned char *, int , int );			//110331
void  yuv420_prog_planar_to_yuv444_prog_packed(unsigned char *,unsigned char *, int , int );		//110340
void  yuv420_prog_planar_to_yuv444_int_packed(unsigned char *,unsigned char *, int , int );			//110341
void  yuv420_prog_planar_to_yvu444_prog_packed(unsigned char *,unsigned char *, int , int );		//110350
void  yuv420_prog_planar_to_yvu444_int_packed(unsigned char *,unsigned char *, int , int );			//110351
void  yuv420_prog_planar_to_uyv444_prog_packed(unsigned char *,unsigned char *, int , int );		//110360
void  yuv420_prog_planar_to_uyv444_int_packed(unsigned char *,unsigned char *, int , int );			//110361

void  yuv420_prog_planar_to_rgb_planar(unsigned char *,unsigned char *, int , int );				//110410
void  yuv420_prog_planar_to_bgr_planar(unsigned char *,unsigned char *, int , int );				//110420
void  yuv420_prog_planar_to_rgb_packed(unsigned char *,unsigned char *, int , int );				//110430
void  yuv420_prog_planar_to_bgr_packed(unsigned char *,unsigned char *, int , int );				//110440





/* Functions to convert to YUV420 */

/* yuv420 converters */ 
void  yuv400_prog_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );		//100110

void  yuv420_int_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//111110
void  yvu420_prog_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );		//120110
void  yvu420_int_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//121110
void  ycbcr_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );				//130110

void  yuv422_prog_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );		//210110
void  yuv422_int_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//211110
void  yvu422_prog_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );		//220110
void  yvu422_int_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//221110
void  uyvy_prog_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//230110
void  uyvy_int_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//231110
void  yuyv_prog_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//240110
void  yuyv_int_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//241110
void  yvyu_prog_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//250110
void  yvyu_int_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//251110

void  yuv444_prog_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );		//310110
void  yuv444_int_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//311110
void  yvu444_prog_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );		//320110
void  yvu444_int_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//321110
void  uyv444_prog_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );		//330110
void  uyv444_int_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//331110
void  yuv444_prog_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );		//340110
void  yuv444_int_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//341110
void  yvu444_prog_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );		//350110
void  yvu444_int_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//351110
void  uyv444_prog_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );		//360110
void  uyv444_int_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );			//361110

void  rgb_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );				//410110
void  bgr_planar_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );				//420110
void  rgb_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );				//430110
void  bgr_packed_to_yuv420_prog_planar(unsigned char *,unsigned char *, int , int );				//440110



