/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sort.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:11:19 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/05 21:27:56 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	pmm::PmergeMe::sort_vector_2(std::vector<int>& unsorted)
{

	std::vector<int> sorted;
	if (unsorted[1] < unsorted[0])
	{
		sorted.push_back(unsorted[1]);
		sorted.push_back(unsorted[0]);

		unsorted.swap(sorted);
	}	
}

void	pmm::PmergeMe::sort_vector_2(std::vector<std::vector<int> >& unsorted)
{

	std::vector<std::vector<int> > sorted;
	if (unsorted[1][0] < unsorted[0][0])
	{
		sorted.push_back(unsorted[1]);
		sorted.push_back(unsorted[0]);

		unsorted.swap(sorted);
	}	
}

void	pmm::PmergeMe::sort_vector_3(std::vector<int>& unsorted)
{
	std::vector<int> sorted;
	if (unsorted[1] < unsorted[0])
	{
		if (unsorted[2] < unsorted[1])
		{
			sorted.push_back(unsorted[2]);
			sorted.push_back(unsorted[1]);
			sorted.push_back(unsorted[0]);
			unsorted.swap(sorted);
		}
		else if (unsorted[2] < unsorted[0])
		{
			sorted.push_back(unsorted[1]);
			sorted.push_back(unsorted[2]);
			sorted.push_back(unsorted[0]);
			unsorted.swap(sorted);
		}
		else
		{
			sorted.push_back(unsorted[1]);
			sorted.push_back(unsorted[0]);
			sorted.push_back(unsorted[2]);
			unsorted.swap(sorted);				
		}
	}
	else
	{
		if (unsorted[2] < unsorted[0])
		{
			sorted.push_back(unsorted[2]);
			sorted.push_back(unsorted[0]);
			sorted.push_back(unsorted[1]);
			unsorted.swap(sorted);
		}
		else if (unsorted[2] < unsorted[1]) 
		{				
			sorted.push_back(unsorted[0]);
			sorted.push_back(unsorted[2]);
			sorted.push_back(unsorted[1]);
			unsorted.swap(sorted);
		}
	}
}

void	pmm::PmergeMe::sort_vector_3(std::vector<std::vector<int> >& unsorted)
{
	std::vector<std::vector<int> > sorted;
	if (unsorted[1][0] < unsorted[0][0])
	{
		if (unsorted[2][0] < unsorted[1][0])
		{
			sorted.push_back(unsorted[2]);
			sorted.push_back(unsorted[1]);
			sorted.push_back(unsorted[0]);
			unsorted.swap(sorted);
		}
		else if (unsorted[2][0] < unsorted[0][0])
		{
			sorted.push_back(unsorted[1]);
			sorted.push_back(unsorted[2]);
			sorted.push_back(unsorted[0]);
			unsorted.swap(sorted);
		}
		else
		{
			sorted.push_back(unsorted[1]);
			sorted.push_back(unsorted[0]);
			sorted.push_back(unsorted[2]);
			unsorted.swap(sorted);				
		}
	}
	else
	{
		if (unsorted[2][0] < unsorted[0][0])
		{
			sorted.push_back(unsorted[2]);
			sorted.push_back(unsorted[0]);
			sorted.push_back(unsorted[1]);
			unsorted.swap(sorted);
		}
		else if (unsorted[2][0] < unsorted[1][0]) 
		{				
			sorted.push_back(unsorted[0]);
			sorted.push_back(unsorted[2]);
			sorted.push_back(unsorted[1]);
			unsorted.swap(sorted);
		}
	}
}

void	pmm::PmergeMe::sort_vector_make_pairs( \
	std::vector<std::vector<int> >& pairs, \
	int& last, \
	unsigned len, \
	std::vector<int>& unsorted)
{
	int lim = len - (len % 2) - 1;
	int i = 0;
	for (; i < lim; i += 2)
	{
		std::vector<int> v;
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

void	pmm::PmergeMe::sort_vector_make_pairs( \
	std::vector<std::vector<int> >& pairs, \
	std::vector<int>& last, \
	unsigned len, \
	std::vector<std::vector<int> >& unsorted)
{
	int lim = len - (len % 2) - 1;
	int i = 0;
	for (; i < lim; i += 2)
	{
		std::vector<int> v;
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

void	pmm::PmergeMe::sort_vector_binary_insert(int next, std::vector<int>& main_line, unsigned upper)
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

void	pmm::PmergeMe::sort_vector_binary_insert(std::vector<int>& next, std::vector<std::vector<int> >& main_line, unsigned upper)
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

void	pmm::PmergeMe::sort_vector_main_line(std::vector<int>& main_line, std::vector<std::vector<int> >& pairs, int& last)
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
	unsigned idx;
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
				sort_vector_binary_insert(last, main_line, upper);
			else
				--upper;
			
			idx = plen - 1;
		}
		else
			--upper;
		
		for(; idx_prev < idx; --idx)
			sort_vector_binary_insert(pairs[idx][1], main_line, upper);
		
		idx_prev = tmp_idx;
		idx = tmp_idx;

		jsn = jsn_next;
		++count;
		jsn_next = jsn * 2 + 1 - 2 * (count % 2);

	} while (idx < plen);
}

void	pmm::PmergeMe::sort_vector_main_line(std::vector<std::vector<int> >& main_line, std::vector<std::vector<int> >& pairs, std::vector<int>& last)
{
	//	insert b0 to Main_line
	std::vector<int>& p0 = pairs[0];
	
	unsigned ml_len = p0.size() / 2;	
	
	std::vector<int> ml0;
	ml0.insert(ml0.begin(), p0.begin() + ml_len, p0.end());
	main_line.push_back(ml0);

	//	insert a0-ai to Main_line : i = pairs.size()
	unsigned plen = pairs.size();
	for(unsigned i = 0; i < plen; ++i)
	{
		std::vector<int> mli;
		std::vector<int>& pi = pairs[i];
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
				sort_vector_binary_insert(last, main_line, upper);
			else
				--upper;		
			
			idx = plen - 1;
		}
		else
			--upper;

		for(; idx_prev < idx; --idx)
		{
			std::vector<int>& p = pairs[idx];						
			std::vector<int> next;
			next.insert(next.begin(), p.begin() + ml_len, p.end());
			sort_vector_binary_insert(next, main_line, upper);
		}
		
		idx_prev = tmp_idx;
		idx = tmp_idx;

		jsn = jsn_next;
		++count;
		jsn_next = jsn * 2 + 1 - 2 * (count % 2);
		
	} while (idx < plen);

}


void	pmm::PmergeMe::sort_vector_fj(std::vector<int>& unsorted)
{
	unsigned len = unsorted.size();

	if (len < 2)
		return ;
	
	switch (len)
	{
		case 2:
			sort_vector_2(unsorted);
			return ;

		case 3:
			sort_vector_3(unsorted);
			return ;
		
		default:

			std::vector<std::vector<int> > pairs;
			int last = -1;
			sort_vector_make_pairs(pairs, last, len, unsorted);

			sort_vector_fj(pairs);

			std::vector<int> main_line;
			sort_vector_main_line(main_line, pairs, last);

			unsorted.swap(main_line);
	}
}

void	pmm::PmergeMe::sort_vector_fj(std::vector<std::vector<int> >& unsorted)
{
	unsigned len = unsorted.size();

	if (len < 2)
		return ;
	
	switch (len)
	{
		case 2:
			sort_vector_2(unsorted);
			return ;

		case 3:
			sort_vector_3(unsorted);
			return ;
		
		default:

			std::vector<std::vector<int> > pairs;
			std::vector<int> last(1, -1);
			sort_vector_make_pairs(pairs, last, len, unsorted);

			sort_vector_fj(pairs);

			std::vector<std::vector<int> > main_line;
			sort_vector_main_line(main_line, pairs, last);

			unsorted.swap(main_line);
	}
}


void	pmm::PmergeMe::sort_vector(void)
{	

	timespec start;
	clock_gettime(CLOCK_REALTIME, &start);

	unsigned len = start_sequence_vector_.size();
	if (len < 2)
	{
		result_sequence_deque_ = start_sequence_deque_;
		result_sequence_vector_ = start_sequence_vector_;
		timespec end;
		clock_gettime(CLOCK_REALTIME, &end);
		time_vector_ = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec);

		return ;
	}
		


	result_sequence_vector_ = start_sequence_vector_;
	sort_vector_fj(result_sequence_vector_);

	timespec end;
	clock_gettime(CLOCK_REALTIME, &end);
	time_vector_ = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec);
}
