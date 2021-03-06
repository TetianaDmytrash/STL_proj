#pragma once
#include <iostream>
#include "my_pair.h"

template<class s, class p>
class my_map {
public:
	struct map_element {
		map_element* next;
		s first;
		p second;
		double array_for_data[3];
		map_element(map_element* pointer, s str, p y) {
			next = pointer;
			first = str;
			for (int i = 0; i < 3; i++) {
				array_for_data[i] = y[i];
			}
			second = array_for_data;
		}
		map_element(void){}
	};
	map_element* head;
	int general_key;
	void selection_sort_map(void) {
		map_element* p_tmp = head;
		map_element** array_pointer = new map_element * [general_key];
		for (int i = 0; i < general_key; i++) {
			array_pointer[i] = p_tmp;
			p_tmp = p_tmp->next;
		}
		for (int i = 0; i < general_key; i++) {
			for (int j = i; j < general_key; j++) {
				int tmp_for_string_check;
				tmp_for_string_check = (array_pointer[i]->first).compare(array_pointer[j]->first);
				if (tmp_for_string_check > 0) {
					map_element* tmp_change = array_pointer[j];
					array_pointer[j] = array_pointer[i];
					array_pointer[i] = tmp_change;
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

	class iterator {
	public:
		map_element* field;
		iterator(map_element* field) :field(field) {}
		iterator(void):field(nullptr){}
		void operator++() {
			field = field->next;
		}
		map_element* operator->() {
			return field;
		}
		bool operator!=(iterator i) {
			return field != i.field;
		}
	};
	my_map(void) {
		general_key = 0;
		head = nullptr;
	}
	void insert(my_pair<s, p> output_data) {
		head = new map_element(head, output_data.first, output_data.second);
		general_key++;
		selection_sort_map();
	}
	iterator begin(void) {
		return head;
	}
	iterator end(void) {
		return nullptr;
	}
};

