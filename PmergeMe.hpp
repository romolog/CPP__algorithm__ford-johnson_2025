/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:02:31 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/03 19:59:17 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>

#define PMM_ALREADY_SORTED "PmergeMe: Already sorted"
#define PMM_FAIL "PmergeMe: Error (exception thrown): Sorted sequence is not equal to std::sort()"
#define PMM_NOT_INITIALIZED "PmergeMe: Error (exception thrown): Not yet initialized by an int sequence"
#define PMM_NOT_SORTED "PmergeMe: Warning: Not yet sorted"

namespace pmm
{
	class PmergeMe
	{
		public:
			PmergeMe();
			PmergeMe(const PmergeMe& rhs);
			PmergeMe& operator=(const PmergeMe& rhs);
			~PmergeMe();
		public:
			class PmmException : public std::runtime_error
			{
				public:
					explicit PmmException(const std::string& what_arg);
			};

					
		private:			
			int						status_;
			unsigned long long		time_deque_;
			unsigned long long		time_vector_;
		private:
			std::deque<int>			start_sequence_deque_;
			std::deque<int>			result_sequence_deque_;
		private:			
			std::vector<int>		start_sequence_vector_;
			std::vector<int>		result_sequence_vector_;

		public:
			void					check(void);		
			void					print_result(void);
			void					print_sort_time(void);						
			void					print_start(void);
			void					push_back(int num);
			void					sort(void);			

//		DEQUE:
		private:
			void					sort_deque(void);

		private:
			void					sort_deque_fj(std::deque<int>& unsorted);
			void					sort_deque_fj(std::deque<std::deque<int> >& unsorted);

			void					sort_deque_make_pairs(std::deque<std::deque<int> >& unsorted_pairs, int& last, unsigned len, std::deque<int>& unsorted);
			void					sort_deque_make_pairs(std::deque<std::deque<int> >& unsorted_pairs, std::deque<int>& last, unsigned len, std::deque<std::deque<int> >& unsorted);

			void					sort_deque_main_line(std::deque<int>& main_line, std::deque<std::deque<int> >& pairs, int& last);
			void					sort_deque_main_line(std::deque<std::deque<int> >& main_line, std::deque<std::deque<int> >& pairs, std::deque<int>& last);

			void					sort_deque_binary_insert(int next, std::deque<int>& main_line, unsigned upper);
			void					sort_deque_binary_insert(std::deque<int>& next, std::deque<std::deque<int> >& main_line, unsigned upper);



//		VECTOR:
		private:
			void					sort_vector(void);

		private:
			void					sort_vector_fj(std::vector<int>& unsorted);
			void					sort_vector_fj(std::vector<std::vector<int> >& unsorted);

			void					sort_vector_2(std::vector<int>& unsorted);
			void					sort_vector_2(std::vector<std::vector<int> >& unsorted);

			void					sort_vector_3(std::vector<int>& unsorted);
			void					sort_vector_3(std::vector<std::vector<int> >& unsorted);

			void					sort_vector_make_pairs(std::vector<std::vector<int> >& unsorted_pairs, int& last, unsigned len, std::vector<int>& unsorted);
			void					sort_vector_make_pairs(std::vector<std::vector<int> >& unsorted_pairs, std::vector<int>& last, unsigned len, std::vector<std::vector<int> >& unsorted);

			void					sort_vector_main_line(std::vector<int>& main_line, std::vector<std::vector<int> >& pairs, int& last);
			void					sort_vector_main_line(std::vector<std::vector<int> >& main_line, std::vector<std::vector<int> >& pairs, std::vector<int>& last);

			void					sort_vector_binary_insert(int next, std::vector<int>& main_line, unsigned upper);
			void					sort_vector_binary_insert(std::vector<int>& next, std::vector<std::vector<int> >& main_line, unsigned upper);
	};	
} 
// namespace pmm
