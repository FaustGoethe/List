#pragma once
#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

namespace SLL
{
	
	class List
	{	
	public:
		struct content
		{
			int key;
			size_t index;

			friend std::ostream& operator<<(std::ostream& os, const content& value) {
				os << value.key << std::endl;
			}
			inline content& operator=(const int value){
				key = value;
				return *this;
		}
		};
	    struct list{
			content value;
			list* next;
		};
	private:
		// ��������� �� ������
		list* begin; 

		// ���������� ������� �������� ������ �������
		void Indexation();

		// ������������� ������ � ���� �������
		content* Array(); 
	public:
		List();
		List(const List&);
		//������������� ��������
		List(const int*, int);
		List(int, int);
		~List();

		List& push(const int); // ������� �������� n �������� � ������
		List& remove(const int); // �������� �������� �� ������ �� ��������
		
		int remove_at_index(size_t); // �������� �������� �� ������ �� ������� 
		
		List& push_back(const int); // ������� �������� � ����� ������
		List& push_front(const int); // ������� �������� � ������ ������
		
		size_t size() const; // ����������� ������

		double averege()const; // ������� ������������� �������� ������
		int max()const; // ������������ �������� ������
		int min()const; // ����������� �������� ������

		void fout(const std::string&) const;
		size_t find(const int); // ����� �� ��������

		// ������� ������
		inline list* _begin() const{ 
			return begin;
		}
		// ������� �����
		list* _end() const {
			if (begin == NULL) {
				return NULL;
			}
			list* end = begin;

			while (end) {
				if (end->next == NULL) {
					return end;
				}
				end = end->next;
			}
		}

		// ���������� ��������� �� ��������
		void ksort() {
			if (begin == NULL) {
				return;
			}
			for (int i(1); i <= size(); i++) {
				for (int j(1); j <= i; j++) {
					if ((*this)[i].key < (*this)[j].key) {
						std::swap((*this)[i].key, (*this)[j].key);
					}
				}
			}
		}
		List& key_sort_reverse_bubble(); // �������� ���������� ��������� �� ��������
		List& index_sort_bubble(); // ���������� ��������� �� �������
		List& index_sort_reverse_bubble(); // �������� ���������� ��������� �� �������

		friend std::ostream& operator<<(std::ostream&, const List&);
		friend std::istream& operator>>(std::istream&, List&);

		List& fin(const std::string&);
		
		content& operator[](size_t);
		content& operator[](size_t) const;
	};
}
#endif

using namespace SLL;