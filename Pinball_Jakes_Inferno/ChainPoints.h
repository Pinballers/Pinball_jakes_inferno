

int elements = 3;

// Pivot -25, -34
int background_points[238] = {
	15, 1024,
	15, 886,
	49, 854,
	49, 795,
	42, 786,
	45, 783,
	49, 788,
	51, 783,
	36, 765,
	30, 766,
	33, 770,
	30, 773,
	22, 762,
	22, 648,
	24, 633,
	30, 616,
	38, 598,
	48, 581,
	56, 572,
	66, 562,
	78, 552,
	90, 544,
	99, 540,
	104, 534,
	104, 526,
	100, 521,
	24, 490,
	19, 485,
	16, 478,
	16, 383,
	40, 358,
	40, 296,
	33, 281,
	37, 278,
	39, 285,
	43, 279,
	34, 258,
	28, 256,
	30, 262,
	25, 264,
	21, 251,
	22, 159,
	27, 133,
	36, 110,
	47, 92,
	59, 78,
	75, 63,
	89, 52,
	106, 43,
	122, 37,
	137, 33,
	153, 31,
	174, 31,
	193, 33,
	209, 38,
	226, 45,
	244, 55,
	259, 67,
	274, 82,
	288, 101,
	299, 124,
	305, 146,
	308, 165,
	308, 252,
	300, 263,
	296, 262,
	299, 257,
	292, 258,
	280, 277,
	283, 282,
	288, 274,
	290, 278,
	278, 294,
	278, 360,
	301, 382,
	301, 477,
	297, 485,
	292, 489,
	218, 519,
	213, 525,
	212, 533,
	216, 538,
	223, 541,
	238, 547,
	255, 557,
	271, 568,
	289, 586,
	306, 610,
	317, 634,
	322, 654,
	325, 677,
	326, 686,
	326, 1023,
	312, 1023,
	312, 769,
	310, 764,
	305, 767,
	300, 773,
	296, 770,
	300, 766,
	293, 764,
	278, 780,
	279, 788,
	285, 782,
	288, 785,
	277, 798,
	277, 857,
	303, 884,
	303, 1023,
	282, 1023,
	282, 997,
	276, 992,
	207, 1023,
	107, 1023,
	43, 993,
	38, 993,
	34, 997,
	34, 1023,
	15, 1023
};

// Pivot 0, 0
int ball[16] = {
	0, 2,
	6, 0,
	11, 1,
	13, 6,
	11, 11,
	4, 12,
	0, 8,
	0, 2
};

// Pivot 0, 0
int circle_points[22] = {
	3, 4,
	8, 0,
	19, 0,
	24, 4,
	27, 11,
	26, 21,
	19, 27,
	9, 27,
	1, 22,
	-1, 12,
	0, 7,
};

// Pivot 0, 0
int close_piece[14] = {
	1, 15,
	14, 1,
	19, 0,
	19, 5,
	7, 19,
	1, 20,
	1, 15
};

// Pivot 0, 0
int close_piece2[14] = {
	19, 20,
	12, 19,
	1, 6,
	1, 0,
	7, 1,
	18, 14,
	19, 20
};

// Pivot 0, 0
int empty_hole[20] = {
	1, 4,
	7, 0,
	14, 0,
	20, 4,
	22, 11,
	19, 19,
	11, 22,
	3, 19,
	0, 10,
	1, 4
};

// Pivot 0, 0
int Eyes_dragon_on[10] = {
	0, 19,
	0, 0,
	66, 0,
	66, 20,
	0, 19
};


// Pivot 0, 0
int left_flipper_points[14] = {
	4, 15,
	1, 9,
	4, 2,
	11, 1,
	50, 25,
	53, 28,
	49, 29,
};

// Pivot 0, 0
int right_flipper_points[14] = {
	40, 2,
	47, 1,
	53, 9,
	48, 16,
	6, 28,
	1, 28,
	7, 23,
};



// Pivot 0, 0
int left_piece1_points[18] = {
	0, 58,
	0, 1,
	3, -1,
	5, 2,
	5, 55,
	63, 82,
	64, 86,
	60, 87,
	4, 61,
};


// Pivot 0, 0
int left_piece2_points[18] = {
	1, 48,
	1, 5,
	4, 0,
	8, 0,
	13, 4,
	42, 53,
	43, 60,
	38, 63,
	31, 61,
};

// Pivot 0, 0
int left_wheel_piece_points[52] = {
	7, 131,
	15, 154,
	41, 141,
	34, 119,
	52, 104,
	54, 96,
	53, 59,
	56, 43,
	61, 28,
	69, 16,
	77, 8,
	77, 2,
	72, 0,
	65, 4,
	45, 19,
	33, 32,
	26, 40,
	22, 36,
	17, 40,
	21, 46,
	15, 58,
	7, 74,
	2, 92,
	0, 108,
	0, 127,
	3, 130,
};


// Pivot 0, 0
int piece3_points[16] = {
	5, 31,
	0, 27,
	0, 2,
	4, -1,
	11, -1,
	14, 3,
	14, 26,
	11, 31,
};

// Pivot 0, 0
int right_piece1_points[16] = {
	2, 82,
	59, 54,
	59, 2,
	62, 0,
	65, 2,
	65, 60,
	6, 86,
	1, 86,
};

// Pivot 0, 0
int right_piece2_points[18] = {
	11, 62,
	4, 63,
	0, 58,
	2, 52,
	31, 4,
	35, 0,
	40, 0,
	43, 4,
	43, 48,
};


// Pivot 0, 0
int right_wheel_piece_points[54] = {
	1, 7,
	11, 19,
	20, 34,
	25, 53,
	25, 70,
	25, 97,
	26, 104,
	45, 119,
	37, 141,
	64, 156,
	72, 131,
	77, 130,
	79, 127,
	78, 102,
	74, 82,
	67, 64,
	60, 51,
	57, 45,
	62, 41,
	56, 35,
	52, 39,
	40, 25,
	31, 16,
	19, 7,
	10, 1,
	5, 0,
	1, 3,
};



