/*****************************************************************************

FileName:     <yuvconverter.cpp>

File Description:
Convert any YUV format to another

*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "yuvconverter.h"


/*****************************************************************************

Module Name: <main>

Module Description:
Wrapper main to convert any YUV format to another

*****************************************************************************/
int main(int argc, char **argv)
{

    FILE *infile;
    FILE *outfile;

    char *infile_name, *outfile_name;
    int width, height, inframesize, outframesize; 
    unsigned char *ptrbufinframe, *ptrbufoutframe;
    int conv_code;
    void (*yuvconvert) (unsigned char*, unsigned char *, int, int);

    if (argc < NUMARGS){

        printf("\n");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |  Usage: <infile> <outfile> <width> <height> <conv_code>    |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |      Input Format      |    Output Format       | ConvCode |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   YUV420 Prog Planar   |   YUV400 Prog Planar   |  110100  |");
        printf("\n  |   YUV420 Prog Planar   |   YUV420 Int Planar    |  110111  |");
        printf("\n  |   YUV420 Prog Planar   |   YVU420 Prog Planar   |  110120  |");
        printf("\n  |   YUV420 Prog Planar   |   YVU420 Int Planar    |  110121  |");
        printf("\n  |   YUV420 Prog Planar   |   YCbCr Prog Planar    |  110130  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   YUV420 Prog Planar   |   YUV422 Prog Planar   |  110210  |");
        printf("\n  |   YUV420 Prog Planar   |   YUV422 Int Planar    |  110211  |");
        printf("\n  |   YUV420 Prog Planar   |   YVU422 Prog Planar   |  110220  |");
        printf("\n  |   YUV420 Prog Planar   |   YVU422 Int Planar    |  110221  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   YUV420 Prog Planar   |   UYVY Prog            |  110230  |");
        printf("\n  |   YUV420 Prog Planar   |   UYVY Int             |  110231  |");
        printf("\n  |   YUV420 Prog Planar   |   YUYV Prog            |  110240  |");
        printf("\n  |   YUV420 Prog Planar   |   YUYV Int             |  110241  |");
        printf("\n  |   YUV420 Prog Planar   |   YVYU Prog            |  110250  |");
        printf("\n  |   YUV420 Prog Planar   |   YVYU Int             |  110251  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   YUV420 Prog Planar   |   YUV444 Prog Planar   |  110310  |");
        printf("\n  |   YUV420 Prog Planar   |   YUV444 Int Planar    |  110311  |");
        printf("\n  |   YUV420 Prog Planar   |   YVU444 Prog Planar   |  110320  |");
        printf("\n  |   YUV420 Prog Planar   |   YVU444 Int Planar    |  110321  |");
        printf("\n  |   YUV420 Prog Planar   |   UYV444 Prog Planar   |  110330  |");
        printf("\n  |   YUV420 Prog Planar   |   UYV444 Int Planar    |  110331  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   YUV420 Prog Planar   |   YUV444 Prog Packed   |  110340  |");
        printf("\n  |   YUV420 Prog Planar   |   YUV444 Int Packed    |  110341  |");
        printf("\n  |   YUV420 Prog Planar   |   YVU444 Prog Packed   |  110350  |");
        printf("\n  |   YUV420 Prog Planar   |   YVU444 Int Packed    |  110351  |");
        printf("\n  |   YUV420 Prog Planar   |   UYV444 Prog Packed   |  110360  |");
        printf("\n  |   YUV420 Prog Planar   |   UYV444 Int Packed    |  110361  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   YUV420 Prog Planar   |   RGB Prog Planar      |  110410  |");
        printf("\n  |   YUV420 Prog Planar   |   BGR Prog Planar      |  110420  |");
        printf("\n  |   YUV420 Prog Planar   |   RGB Prog Packed      |  110430  |");
        printf("\n  |   YUV420 Prog Planar   |   BGR Prog Packed      |  110440  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |                                                            |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   YUV400 Prog Planar   |   YUV420 Prog Planar   |  100110  |");
        printf("\n  |   YUV420 Int Planar    |   YUV420 Prog Planar   |  111110  |");
        printf("\n  |   YVU420 Prog Planar   |   YUV420 Prog Planar   |  120110  |");
        printf("\n  |   YVU420 Int Planar    |   YUV420 Prog Planar   |  121110  |");
        printf("\n  |   YCbCr Prog Planar    |   YUV420 Prog Planar   |  130110  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   YUV422 Prog Planar   |   YUV420 Prog Planar   |  210110  |");
        printf("\n  |   YUV422 Int Planar    |   YUV420 Prog Planar   |  211110  |");
        printf("\n  |   YVU422 Prog Planar   |   YUV420 Prog Planar   |  220110  |");
        printf("\n  |   YVU422 Int Planar    |   YUV420 Prog Planar   |  221110  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   UYVY Prog            |   YUV420 Prog Planar   |  230110  |");
        printf("\n  |   UYVY Int             |   YUV420 Prog Planar   |  231110  |");
        printf("\n  |   YUYV Prog            |   YUV420 Prog Planar   |  240110  |");
        printf("\n  |   YUYV Int             |   YUV420 Prog Planar   |  241110  |");
        printf("\n  |   YVYU Prog            |   YUV420 Prog Planar   |  250110  |");
        printf("\n  |   YVYU Int             |   YUV420 Prog Planar   |  251110  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   YUV444 Prog Planar   |   YUV420 Prog Planar   |  310110  |");
        printf("\n  |   YUV444 Int Planar    |   YUV420 Prog Planar   |  311110  |");
        printf("\n  |   YVU444 Prog Planar   |   YUV420 Prog Planar   |  320110  |");
        printf("\n  |   YVU444 Int Planar    |   YUV420 Prog Planar   |  321110  |");
        printf("\n  |   UYV444 Prog Planar   |   YUV420 Prog Planar   |  330110  |");
        printf("\n  |   UYV444 Int Planar    |   YUV420 Prog Planar   |  331110  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   YUV444 Prog Packed   |   YUV420 Prog Planar   |  340110  |");
        printf("\n  |   YUV444 Int Packed    |   YUV420 Prog Planar   |  341110  |");
        printf("\n  |   YVU444 Prog Packed   |   YUV420 Prog Planar   |  350110  |");
        printf("\n  |   YVU444 Int Packed    |   YUV420 Prog Planar   |  351110  |");
        printf("\n  |   UYV444 Prog Packed   |   YUV420 Prog Planar   |  360110  |");
        printf("\n  |   UYV444 Int Packed    |   YUV420 Prog Planar   |  361110  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n  |   RGB Prog Planar      |   YUV420 Prog Planar   |  410110  |");
        printf("\n  |   BGR Prog Planar      |   YUV420 Prog Planar   |  420110  |");
        printf("\n  |   RGB Prog Packed      |   YUV420 Prog Planar   |  430110  |");
        printf("\n  |   BGR Prog Packed      |   YUV420 Prog Planar   |  440110  |");
        printf("\n  +------------------------------------------------------------+");
        printf("\n");

        exit (-1);
    }


    infile_name     = argv[1];
    outfile_name     = argv[2];
    width             = atoi(argv[3]);
    height             = atoi(argv[4]);
    conv_code         = atoi(argv[5]);


    infile  = fopen(infile_name, "rb");
    outfile = fopen(outfile_name, "wb");
    if(infile == NULL) 
    {
        printf("\nCannot open file %s",infile_name); 
        printf("\n\n");
        fclose(infile);
        return 2;
    }
    if(outfile == NULL) 
    {
        printf("\nCannot open file %s",outfile_name); 
        printf("\n\n");
        fclose(infile);
        fclose(outfile);
        return 2;
    }


    
    switch(conv_code)
    {

            /* YUV420 Output */
            case 110100:
                    yuvconvert = yuv420_prog_planar_to_yuv400_prog_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height);
                    break;


            case 110111:
                    yuvconvert = yuv420_prog_planar_to_yuv420_int_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3)>>1;
                    break;


            case 110120:
                    yuvconvert = yuv420_prog_planar_to_yvu420_prog_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3)>>1;
                    break;


            case 110121:
                    yuvconvert = yuv420_prog_planar_to_yvu420_int_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3)>>1;
                    break;

            case 110130:
                    yuvconvert = yuv420_prog_planar_to_ycbcr_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3)>>1;
                    break;

            /* 420 rev */        
            case 100110:
                    yuvconvert = yuv400_prog_planar_to_yuv420_prog_planar;
                    inframesize = (width * height);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 111110:
                    yuvconvert = yuv420_int_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3)>>1;
                    break;


            case 120110:
                    yuvconvert = yvu420_prog_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3)>>1;
                    break;


            case 121110:
                    yuvconvert = yvu420_int_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3)>>1;
                    break;


            case 130110:
                    yuvconvert = ycbcr_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3)>>1;
                    break;

            /* 422 rev */
            case 210110:
                    yuvconvert = yuv422_prog_planar_to_yuv420_prog_planar;
                    inframesize  = ((width * height) << 1);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 211110:
                    yuvconvert = yuv422_int_planar_to_yuv420_prog_planar;
                    inframesize = ((width * height) << 1);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 220110:
                    yuvconvert = yvu422_prog_planar_to_yuv420_prog_planar;
                    inframesize = ((width * height) << 1);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 221110:
                    yuvconvert = yvu422_int_planar_to_yuv420_prog_planar;
                    inframesize =  ((width * height) << 1);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 230110:
                    yuvconvert = uyvy_prog_packed_to_yuv420_prog_planar;
                    inframesize = ((width * height) << 1);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 231110:
                    yuvconvert = uyvy_int_packed_to_yuv420_prog_planar;
                    inframesize = ((width * height) << 1);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 240110:
                    yuvconvert = yuyv_prog_packed_to_yuv420_prog_planar;
                    inframesize = ((width * height) << 1);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 241110:
                    yuvconvert = yuyv_int_packed_to_yuv420_prog_planar;
                    inframesize = ((width * height) << 1);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 250110:
                    yuvconvert = yvyu_prog_packed_to_yuv420_prog_planar;
                    inframesize = ((width * height) << 1);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 251110:
                    yuvconvert = yvyu_int_packed_to_yuv420_prog_planar;
                    inframesize = ((width * height) << 1);
                    outframesize = (width * height * 3)>>1;
                    break;


            /* 444 rev */
            case 310110:
                    yuvconvert = yuv444_prog_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 311110:
                    yuvconvert = yuv444_int_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 320110:
                    yuvconvert = yvu444_prog_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 321110:
                    yuvconvert = yvu444_int_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 330110:
                    yuvconvert = uyv444_prog_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 331110:
                    yuvconvert = uyv444_int_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 340110:
                    yuvconvert = yuv444_prog_packed_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 341110:
                    yuvconvert = yuv444_int_packed_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 350110:
                    yuvconvert = yvu444_prog_packed_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 351110:
                    yuvconvert = yvu444_int_packed_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 360110:
                    yuvconvert = uyv444_prog_packed_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 361110:
                    yuvconvert = uyv444_int_packed_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            /* rgb rev */
            case 410110:
                    InitConvt(width, height);
                    yuvconvert = rgb_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 420110:
                    InitConvt(width, height);
                    yuvconvert = bgr_planar_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;

    
            case 430110:
                    InitConvt(width, height);
                    yuvconvert = rgb_packed_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;


            case 440110:
                    InitConvt(width, height);
                    yuvconvert = bgr_packed_to_yuv420_prog_planar;
                    inframesize = (width * height * 3);
                    outframesize = (width * height * 3)>>1;
                    break;



            /* YUV422 Output */
            case 110210:
                    yuvconvert = yuv420_prog_planar_to_yuv422_prog_planar;
                    inframesize  = (width * height * 3)>>1;
                    outframesize = ((width * height) << 1) ;
                    break;


            case 110211:
                    yuvconvert = yuv420_prog_planar_to_yuv422_int_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = ((width * height) << 1) ;
                    break;


            case 110220:
                    yuvconvert = yuv420_prog_planar_to_yvu422_prog_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = ((width * height) << 1) ;
                    break;


            case 110221:
                    yuvconvert = yuv420_prog_planar_to_yvu422_int_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = ((width * height) << 1) ;
                    break;


            case 110230:
                    yuvconvert = yuv420_prog_planar_to_uyvy_prog_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = ((width * height) << 1) ;
                    break;


            case 110231:
                    yuvconvert = yuv420_prog_planar_to_uyvy_int_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = ((width * height) << 1) ;
                    break;


            case 110240:
                    yuvconvert = yuv420_prog_planar_to_yuyv_prog_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = ((width * height) << 1) ;
                    break;


            case 110241:
                    yuvconvert = yuv420_prog_planar_to_yuyv_int_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = ((width * height) << 1) ;
                    break;


            case 110250:
                    yuvconvert = yuv420_prog_planar_to_yvyu_prog_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = ((width * height) << 1) ;
                    break;


            case 110251:
                    yuvconvert = yuv420_prog_planar_to_yvyu_int_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = ((width * height) << 1) ;
                    break;




            /* YUV444 Output */        
            case 110310:
                    yuvconvert = yuv420_prog_planar_to_yuv444_prog_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110311:
                    yuvconvert = yuv420_prog_planar_to_yuv444_int_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110320:
                    yuvconvert = yuv420_prog_planar_to_yvu444_prog_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110321:
                    yuvconvert = yuv420_prog_planar_to_yvu444_int_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110330:
                    yuvconvert = yuv420_prog_planar_to_uyv444_prog_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110331:
                    yuvconvert = yuv420_prog_planar_to_uyv444_int_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110340:
                    yuvconvert = yuv420_prog_planar_to_yuv444_prog_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110341:
                    yuvconvert = yuv420_prog_planar_to_yuv444_int_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110350:
                    yuvconvert = yuv420_prog_planar_to_yvu444_prog_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110351:
                    yuvconvert = yuv420_prog_planar_to_yvu444_int_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110360:
                    yuvconvert = yuv420_prog_planar_to_uyv444_prog_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110361:
                    yuvconvert = yuv420_prog_planar_to_uyv444_int_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;



            /* RGB Output */        
            case 110410:
                    InitConvt(width, height);
                    yuvconvert = yuv420_prog_planar_to_rgb_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110420:
                    InitConvt(width, height);
                    yuvconvert = yuv420_prog_planar_to_bgr_planar;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;

    
            case 110430:
                    InitConvt(width, height);
                    yuvconvert = yuv420_prog_planar_to_rgb_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;


            case 110440:
                    InitConvt(width, height);
                    yuvconvert = yuv420_prog_planar_to_bgr_packed;
                    inframesize = (width * height * 3)>>1;
                    outframesize = (width * height * 3);
                    break;

    
        
            default:
                    printf("\n\nUnknown Mode of Conversion!!! Exiting!");
                    fclose(infile);
                    fclose(outfile);
                    exit(-1);
    }




    ptrbufinframe = (unsigned char *) malloc(inframesize);
    ptrbufoutframe = (unsigned char *) malloc(outframesize);
    fread(ptrbufinframe, 1, inframesize, infile);
        
    while (!feof(infile))
    {
        yuvconvert(ptrbufinframe, ptrbufoutframe,width, height);
        fwrite(ptrbufoutframe, 1, outframesize, outfile);
        fread(ptrbufinframe, 1, inframesize, infile);
    }
  
    
    free(ptrbufinframe);
    free(ptrbufoutframe);
    fclose(infile);
    fclose(outfile);
    return 0;

}




