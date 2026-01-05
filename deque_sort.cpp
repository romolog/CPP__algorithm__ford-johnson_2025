/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_sort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:01:03 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/03 19:47:45 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	pmm::PmergeMe::sort_deque_make_pairs( \
	std::deque<std::deque<int> >& pairs, \
	int& last, \
	unsigned len, \
	std::deque<int>& unsorted)
{
	int lim = len - (len % 2) - 1;
	int i = 0;
	for (; i < lim; i += 2)
	{
		std::deque<int> v;
		if (unsorted[i] < unsorted[i + 1])
		{
			v.push_back(unsorted[i + 1]);
			v.push_back(unsorted[i]);
		}
		else
		{
			v.push_back(unsorted[i]);
			v.push_back(unsorted[i + 1]);
		}

		pairs.push_back(v);		
	}
	
	if (len % 2)
		last = unsorted[i];

}

void	pmm::PmergeMe::sort_deque_make_pairs( \
	std::deque<std::deque<int> >& pairs, \
	std::deque<int>& last, \
	unsigned len, \
	std::deque<std::deque<int> >& unsorted)
{
	int lim = len - (len % 2) - 1;
	int i = 0;
	for (; i < lim; i += 2)
	{
		std::deque<int> v;
		if (unsorted[i][0] < unsorted[i + 1][0])
		{
			v.insert(v.begin(), unsorted[i + 1].begin(), unsorted[i + 1].end());
			v.insert(v.begin() + v.size(), unsorted[i].begin(), unsorted[i].end());	
		}
		else
		{
			v.insert(v.begin(), unsorted[i].begin(), unsorted[i].end());
			v.insert(v.begin() + v.size(), unsorted[i + 1].begin(), unsorted[i + 1].end());
		}

		pairs.push_back(v);
		
	}
	

	if (len % 2)
		last = unsorted[i];

}

void	pmm::PmergeMe::sort_deque_binary_insert(int next, std::deque<int>& main_line, unsigned upper)
{
	unsigned lower = 0;
	unsigned middle = (lower + upper) / 2;

	int not_inserted = 1;
	while (not_inserted)
	{
		if (next < main_line[middle])
			upper = middle;
		else
			lower = middle + 1;

		if (upper == lower)
		{
			main_line.insert(main_line.begin() + lower, next);
			not_inserted = 0;
		}
		else 	
			middle = (lower + upper) / 2;
	}
}

void	pmm::PmergeMe::sort_deque_binary_insert(std::deque<int>& next, std::deque<std::deque<int> >& main_line, unsigned upper)
{
	unsigned lower = 0;
	unsigned middle = (lower + upper) / 2;

	int not_inserted = 1;
	while (not_inserted)
	{
		if (next[0] < main_line[middle][0])
			upper = middle;
		else
			lower = middle + 1;

		if (upper == lower)
		{
			main_line.insert(main_line.begin() + lower, next);
			not_inserted = 0;
		}
		else 	
			middle = (lower + upper) / 2;
			
	}
}

void	pmm::PmergeMe::sort_deque_main_line(std::deque<int>& main_line, std::deque<std::deque<int> >& pairs, int& last)
{
	//	insert b0 to Main_line

	main_line.push_back(pairs[0][1]);

	//	insert a0-ai to Main_line : i = pairs.size()
	unsigned plen = pairs.size();
	for(unsigned i = 0; i < plen; ++i)
		main_line.push_back(pairs[i][0]);

	//	binary insert b1-bi and 'last' to Main_line : i = pairs.size()
	unsigned jsn = 1;
	unsigned jsn_next = 3;
	unsigned idx = 2;
	unsigned idx_prev = 0;
	unsigned count = 2;
	do
	{
		unsigned tmp_idx = idx_prev + (jsn_next - jsn);
		idx = tmp_idx;

		unsigned upper = main_line.size();

		if (idx >= plen)
		{
			if (last != -1)
				sort_deque_binary_insert(last, main_line, upper);
			else
				--upper;						
			
			idx = plen - 1;
		}
		else
			--upper;

		for(; idx_prev < idx; --idx)
			sort_deque_binary_insert(pairs[idx][1], main_line, upper);
		
		idx_prev = tmp_idx;
		idx = tmp_idx;
		
		jsn = jsn_next;
		++count;
		jsn_next = jsn * 2 + 1 - 2 * (count % 2);
		
	} while (idx < plen);
}

void	pmm::PmergeMe::sort_deque_main_line(std::deque<std::deque<int> >& main_line, std::deque<std::deque<int> >& pairs, std::deque<int>& last)
{
	//	insert b0 to Main_line
	std::deque<int>& p0 = pairs[0];
	
	unsigned ml_len = p0.size() / 2;	
	
	std::deque<int> ml0;
	ml0.insert(ml0.begin(), p0.begin() + ml_len, p0.end());
	main_line.push_back(ml0);

	//	insert a0-ai to Main_line : i = pairs.size()
	unsigned plen = pairs.size();
	for(unsigned i = 0; i < plen; ++i)
	{
		std::deque<int> mli;
		std::deque<int>& pi = pairs[i];
		mli.insert(mli.begin(), pi.begin(), pi.begin() + ml_len);
		main_line.push_back(mli);
	}

	//	binary insert b1-bi and 'last' to Main_line : i = pairs.size()	
	unsigned jsn = 1;
	unsigned jsn_next = 3;
	unsigned idx = 2;
	unsigned idx_prev = 0;
	unsigned count = 2;
	do
	{
		unsigned tmp_idx = idx_prev + (jsn_next - jsn);
		idx = tmp_idx;

		unsigned upper = main_line.size();

		if (idx >= plen)
		{
			if (last[0] != -1)
				sort_deque_binary_insert(last, main_line, upper);			
			else
				--upper;
				
			idx = plen - 1;
		}
		else
			--upper;

		for(; idx_prev < idx; --idx)
		{
			std::deque<int>& p = pairs[idx];						
			std::deque<int> next;
			next.insert(next.begin(), p.begin() + ml_len, p.end());
			sort_deque_binary_insert(next, main_line, upper);
		}
		
		idx_prev = tmp_idx;
		idx = tmp_idx;

		jsn = jsn_next;
		++count;
		jsn_next = jsn * 2 + 1 - 2 * (count % 2);
		
	} while (idx < plen);

}


void	pmm::PmergeMe::sort_deque_fj(std::deque<int>& unsorted)
{
	unsigned len = unsorted.size();

	if (len < 2)
		return ;
	
	std::deque<std::deque<int> > pairs;
	int last = -1;
	sort_deque_make_pairs(pairs, last, len, unsorted);

	sort_deque_fj(pairs);

	std::deque<int> main_line;
	sort_deque_main_line(main_line, pairs, last);

	unsorted.swap(main_line);
}

void	pmm::PmergeMe::sort_deque_fj(std::deque<std::deque<int> >& unsorted)
{
	unsigned len = unsorted.size();

	if (len < 2)
		return ;
	
	std::deque<std::deque<int> > pairs;
	std::deque<int> last(1, -1);
	sort_deque_make_pairs(pairs, last, len, unsorted);

	sort_deque_fj(pairs);

	std::deque<std::deque<int> > main_line;
	sort_deque_main_line(main_line, pairs, last);

	unsorted.swap(main_line);
}


void	pmm::PmergeMe::sort_deque(void)
{

	timespec start;
	clock_gettime(CLOCK_REALTIME, &start);

	unsigned len = start_sequence_vector_.size();
	if (len < 2)
	{

		timespec end;
		clock_gettime(CLOCK_REALTIME, &end);
		time_deque_ = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec);

		return ;
	}
		
	result_sequence_deque_ = start_sequence_deque_;
	sort_deque_fj(result_sequence_deque_);

	timespec end;
	clock_gettime(CLOCK_REALTIME, &end);
	time_deque_ = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec);	

}