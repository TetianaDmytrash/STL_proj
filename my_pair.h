#pragma once
#include "general_set_up.h"
#include <iostream>

template<class s, class p>
class my_pair {
public:
	s first;
	p second;
	my_pair(s str, p x):first(str),second(x) {}
	my_pair(void) {}
};

