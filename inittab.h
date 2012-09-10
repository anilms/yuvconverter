/*****************************************************************************

File Name: 	<inittab.h>

File Description:
Contains YUV conversion defines

*****************************************************************************/

#define TAB_76309
#ifdef TAB_76309

//YUV to RGB conversion
//
//    |R|     | 1.1644    0       1.596   |   |Y-16 |
//    |G|  =  | 1.1644    -0.392  -0.813  |   |U-128|
//    |B|     | 1.1644    2.02    0       |   |V-128|
//

#define SCALEY     76309
#define SCALECrv   104597
#define SCALECbu   132201
#define SCALECgu   25675
#define SCALECgv   53279

#define SHIFTY     16
#define SHIFTCC    128
#define SHIFTCrv   128
#define SHIFTCbu   128
#define SHIFTCgu   128
#define SHIFTCgv   128


//RGB to YUV conversion
//
//    |Y|     |  0.2568    0.5042    0.0978| |R| + |16 |
//    |U|  =  | -0.1480   -0.2906    0.4387| |G| + |128|
//    |V|     |  0.4392   -0.3678   -0.0714| |B| + |128|
//

#define SCALEYR     16831
#define SCALEYG     33040
#define SCALEYB     6412
#define SCALEUR    -9702
#define SCALEUG    -19046
#define SCALEUB     28748
#define SCALEVR     28783
#define SCALEVG    -24105 
#define SCALEVB    -4678

#endif
