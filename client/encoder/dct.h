////////////////////////////////////////////////////////////////////////////
//
//
//    Project     : VideoNet version 1.1.
//    Description : Peer to Peer Video Conferencing over the LAN.
//	  Author      :	Nagareshwar Y Talekar ( nsry2002@yahoo.co.in)
//    Date        : 15-6-2004.
//
//    I have converted origional fast h.263 encoder library from C to C++ 
//	  so that it can be integrated into any windows application easily.
//	  I have removed some of unnecessary codes/files from the
//	  fast h263 library.Also moved definitions and declarations
//	  in their proper .h and .cpp files.
//
//    File description : 
//    Name    : dct.h
//
//
/////////////////////////////////////////////////////////////////////////////


#if !defined _DCT_H
#define _DCT_H

#include "Global.h"


/* dct.c prototypes */
int Dct( int *block, int *coeff);
int idct(int *coeff,int *block);



#endif
