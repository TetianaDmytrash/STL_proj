#pragma once

//#define with_stl
#define general_gebug_stl
#define const_pair

#ifdef general_gebug_stl
	#define cout_results for_each(mp_in.begin(), mp_in.end(), output_start);
#else
	#define cout_results
#endif

