#pragma once
#include <iostream>
#include "general_set_up.h"
#include "my_pair.h"

template<class s, class p>
class my_multimap {
	struct multimap_element {
		multimap_element* next;
		s first;
		p second;
		multimap_element(multimap_element* pointer, s str, p x) :next(pointer), second(x), first(str) {}
		multimap_element(void){}
	};
	multimap_element* head;
	int general_key;
	void selection_sort_multimap(void) {
		multimap_element* p_tmp = head;
		multimap_element** array_pointer = new multimap_element * [general_key];
		for (int i = 0; i < general_key; i++) {
			array_pointer[i] = p_tmp;
			p_tmp = p_tmp->next;
		}
		for (int i = 0; i < general_key; i++) {
			for (int j = i; j < general_key; j++) {
				int tmp_for_string_check;
				tmp_for_string_check = (array_pointer[i]->first).compare(array_pointer[j]->first);
				if (tmp_for_string_check > 0) {
					multimap_element* tmp_change = array_pointer[j];
					array_pointer[j] = array_pointer[i];
					array_pointer[i] = tmp_change;
				}
				else if (tmp_for_string_check == 0) {
					if (array_pointer[j]->second[0] < array_pointer[i]->second[0]) {
						multimap_element* tmp_change = array_pointer[j];
						array_pointer[j] = array_pointer[i];
						array_pointer[i] = tmp_change;
					}
				}
			}
		}
		int counter_i = 0;
		head = array_pointer[counter_i];
		for (; counter_i < general_key; counter_i++) {
			if (counter_i < (general_key - 1)) {
				array_pointer[counter_i]->next = array_pointer[counter_i + 1];
			}
			else {
				array_pointer[counter_i]->next = nullptr;
			}
		}
	}
public:
	class iterator {
		multimap_element* field;
	public:
		iterator(multimap_element* field) :field(field) {}
		iterator(void) :field(nullptr){}
		void operator++() {
			field = field->next;
		}
		multimap_element* operator->() {
			return field;
		}
		bool operator!=(iterator i) {
			return field != i.field;
		}

		bool operator==(iterator i) {
			return field == i.field;
		}

	};
	void insert(my_pair<s,p> input_pair) {
		head = new multimap_element(head, input_pair.first, input_pair.second);
		general_key++;
		selection_sort_multimap();
	}
	my_multimap(void) {
		head = nullptr;
		general_key = 0;
	}
	iterator begin(void) {
		return head;
	}
	iterator end(void) {
		return nullptr;
	}
};

