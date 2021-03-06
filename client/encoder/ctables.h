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
//    Name    : ctables.h
//
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTABLES_H__9AA44A65_691B_11D6_889A_000B2B0F84B6__INCLUDED_)
#define AFX_CTABLES_H__9AA44A65_691B_11D6_889A_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/* tables.h */
/* TMN Huffman tables */

/* Motion vectors */
int vlc_mv_coeff[] = {
32,13,5,
33,13,7,
34,12,5,
35,12,7,
36,12,9,
37,12,11,
38,12,13,
39,12,15,
40,11,9,
41,11,11,
42,11,13,
43,11,15,
44,11,17,
45,11,19,
46,11,21,
47,11,23,
48,11,25,
49,11,27,
50,11,29,
51,11,31,
52,11,33,
53,11,35,
54,10,19,
55,10,21,
56,10,23,
57,8,7,
58,8,9,
59,8,11,
60,7,7,
61,5,3,
62,4,3,
63,3,3,
 0,1,1,
 1,3,2,
 2,4,2,
 3,5,2,
 4,7,6,
 5,8,10,
 6,8,8,
 7,8,6,
 8,10,22,
 9,10,20,
10,10,18,
11,11,34,
12,11,32,
13,11,30,
14,11,28,
15,11,26,
16,11,24,
17,11,22,
18,11,20,
19,11,18,
20,11,16,
21,11,14,
22,11,12,
23,11,10,
24,11,8,
25,12,14,
26,12,12,
27,12,10,
28,12,8,
29,12,6,
30,12,4,
31,13,6,
-1,-1
};

/* CBPCM (MCBPC) */
int vlc_cbpcm_intra_coeff[] = {
3,1,1,
19,3,1,
35,3,2,
51,3,3,
4,4,1,
20,6,1,
36,6,2,
52,6,3,
255,9,1,
-1,-1
};

int vlc_cbpcm_coeff[] = {
0,1,1,
16,4,3,
32,4,2,
48,6,5,
1,3,3,
17,7,7,
33,7,6,
49,9,5,
2,3,2,
18,7,5,
34,7,4,
50,8,5,
3,5,3,
19,8,4,
35,8,3,
51,7,3,
4,6,4,
20,9,4,
36,9,3,
52,9,2,
255,9,1,
-1,-1
};


/* CBPY */
int vlc_cbpy_coeff[] = {
0,  2,3,
8,  4,11,
4,  4,10,
12, 4,9,
2,  4,8,
10, 4,7,
6,  6,3,
14, 5,5,
1,  4,6,
9,  6,2,
5,  4,5,
13, 5,4,
3,  4,4,
11, 5,3,
7,  5,2,
15, 4,3,
-1,-1
};

/* 3D VLC */
int vlc_3d_coeff[] = {
1,2,2,
2,4,15,
3,6,21,
4,7,23,
5,8,31,
6,9,37,
7,9,36,
8,10,33,
9,10,32,
10,11,7,
11,11,6,
12,11,32,
17,3,6,
18,6,20,
19,8,30,
20,10,15,
21,11,33,
22,12,80,
33,4,14,
34,8,29,
35,10,14,
36,12,81,
49,5,13,
50,9,35,
51,10,13,
65,5,12,
66,9,34,
67,12,82,
81,5,11,
82,10,12,
83,12,83,
97,6,19,
98,10,11,
99,12,84,
113,6,18,
114,10,10,
129,6,17,
130,10,9,
145,6,16,
146,10,8,
161,7,22,
162,12,85,
177,7,21,
193,7,20,
209,8,28,
225,8,27,
241,9,33,
257,9,32,
273,9,31,
289,9,30,
305,9,29,
321,9,28,
337,9,27,
353,9,26,
369,11,34,
385,11,35,
401,12,86,
417,12,87,

4097,4,7,                          /* Table for last coeff */
4098,9,25,
4099,11,5,
4113,6,15,
4114,11,4,
4129,6,14,
4145,6,13,
4161,6,12,
4177,7,19,
4193,7,18,
4209,7,17,
4225,7,16,
4241,8,26,
4257,8,25,
4273,8,24,
4289,8,23,
4305,8,22,
4321,8,21,
4337,8,20,
4353,8,19,
4369,9,24,
4385,9,23,
4401,9,22,
4417,9,21,
4433,9,20,
4449,9,19,
4465,9,18,
4481,9,17,
4497,10,7,
4513,10,6,
4529,10,5,
4545,10,4,
4561,11,36,
4577,11,37,
4593,11,38,
4609,11,39,
4625,12,88,
4641,12,89,
4657,12,90,
4673,12,91,
4689,12,92,
4705,12,93,
4721,12,94,
4737,12,95,
7167,7,3,               /* escape */
-1,-1
};


#endif // !defined(AFX_CTABLES_H__9AA44A65_691B_11D6_889A_000B2B0F84B6__INCLUDED_)
