/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:02:55 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/05 21:30:24 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//	EXCEPTION ------------------------------------------------------------------
pmm::PmergeMe::PmmException::PmmException(const std::string& what_arg) :
		std::runtime_error::runtime_error(what_arg)
{}

//	CTOR DEFAULT ------------------------------------------------------------------
pmm::PmergeMe::PmergeMe()
{
	status_	= -1;
	time_deque_ = 0;
	time_vector_ = 0;
}

//	COPY CTOR ------------------------------------------------------------------
pmm::PmergeMe::PmergeMe(const PmergeMe& rhs) :
		status_(rhs.status_),
		time_deque_(rhs.time_deque_),
		time_vector_(rhs.time_vector_),
		start_sequence_deque_(rhs.start_sequence_deque_),	
		result_sequence_deque_(rhs.result_sequence_deque_),
		start_sequence_vector_(rhs.start_sequence_vector_), 
		result_sequence_vector_(rhs.result_sequence_vector_)
{}

//	COPY ASSIGNMENT OPERATOR ------------------------------------------------------------------
pmm::PmergeMe& pmm::PmergeMe::operator=(const pmm::PmergeMe& rhs)
{
	if (this == &rhs)
		return (*this);

	status_ = rhs.status_;
	time_deque_ = rhs.time_deque_;
	time_vector_ = rhs.time_vector_;
	start_sequence_deque_ = rhs.start_sequence_deque_;
	result_sequence_deque_ = rhs.result_sequence_deque_;
	start_sequence_vector_ = rhs.start_sequence_vector_; 
	result_sequence_vector_ = rhs.result_sequence_vector_;		

	return (*this);
}

//	DTOR ------------------------------------------------------------------
pmm::PmergeMe::~PmergeMe()
{}

//	FUNCTIONS ------------------------------------------------------------------
void	pmm::PmergeMe::push_back(int num)
{
	start_sequence_deque_.push_back(num);
	start_sequence_vector_.push_back(num);
	if (status_ == 1)
	{
		time_deque_ = 0;
		time_vector_ = 0;	
	}
	status_ = 0;
}

void	pmm::PmergeMe::print_start(void)
{
	std::vector<int>::iterator it = start_sequence_vector_.begin();
	std::vector<int>::iterator it_end = start_sequence_vector_.end();	
	std::cout << "\n\tBefore:\t\t";
	for (; it != it_end; ++it)
		std::cout << *it << ' ';
	std::cout << "\n\n";
}

void	pmm::PmergeMe::print_result(void)
{
	std::vector<int>::iterator it = result_sequence_vector_.begin();
	std::vector<int>::iterator it_end = result_sequence_vector_.end();	
	std::cout << "\tAfter:\t\t";
	for (; it != it_end; ++it)
		std::cout << *it << ' ';
	std::cout << "\n\n";
}

void	pmm::PmergeMe::print_sort_time(void)
{
	if (status_ == -1)
		throw PmmException(PMM_NOT_INITIALIZED);
	else if (status_ == 0)
		std::cerr << PMM_NOT_SORTED << '\n';
	else
	{
		std::cout << "\tTime using deque:\t" << time_deque_ << "\tnanosec\n";
		std::cout << "\tTime using vector:\t" << time_vector_ << "\tnanosec\n";
		if (time_vector_ < time_deque_)
		{
			std::cout << "\tVector is faster by:\t"	<< 	(time_deque_ - time_vector_) / 1000 << "\tmilisec\n";
			std::cout << "\tVector is faster by:\t"	<< 	static_cast<double>(time_deque_ * 10 / time_vector_) / 10  << "\ttimes\n"; 
		}
		else if (time_vector_ > time_deque_)
		{
			std::cout << "\tVector is slower by:\t"	<< 	(time_vector_ - time_deque_) / 1000 << "\tmilisec\n";
			std::cout << "\tVector is slower by:\t"	<< 	static_cast<double>(time_vector_ * 10 / time_deque_) / 10  << "\ttimes\n"; 
		}
		else
			std::cout << "\tVector and Deque are equally fast\n"; 
	}
}



void	pmm::PmergeMe::check(void)
{
	std::vector<int> v(start_sequence_vector_);
	std::sort(v.begin(), v.end());
	unsigned lim = start_sequence_vector_.size();
	for (unsigned i = 0; i < lim; ++i)
	{
		if (v[i] != result_sequence_vector_[i] || v[i] != result_sequence_deque_[i])
			throw PmmException(PMM_FAIL);
	}
	std::cout << "\tSUCCESS:\tSorted result equals to std::sort()\n";
}

void	pmm::PmergeMe::sort(void)
{
	if (status_ == -1)
		throw PmmException(PMM_NOT_INITIALIZED);
	else if (status_ == 1)
		std::cout << PMM_ALREADY_SORTED << '\n';
	else
	{
		sort_vector();
		sort_deque();
		check();
		status_ = 1;
	}
}
