/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:02:51 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/03 16:47:31 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <sstream>
#include <vector>
#include <deque>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "\tford_johnson: Error: Requires args: Sequence of positive intigers, one int per arg\n";
		return (1);
	}

	pmm::PmergeMe sorter;

	std::string str;
	std::stringstream init_stream(str);
	std::string num_str;
	long long num;

	std::string radix = "0123456789";

	for (int i = 1; i < argc; ++i)
	{
		init_stream << argv[i] << '\n';
		init_stream >> num_str;
		if (num_str.find_first_not_of(radix) != std::string::npos || \
			num_str.length() > 10)
		{
			std::cerr << "\tford_johnson: Error: Invalid input format\n";
			return (1);
		}
		init_stream << num_str << '\n';
		init_stream >> num;
		init_stream.ignore(1);
		if (num < 0 || num > __INT_MAX__)
		{
			std::cerr << "\tford_johnson: Error: Invalid int: <0 or >INT_MAX\n";
			return (1);
		}
		
		sorter.push_back(num);
	}

	try
	{
		sorter.print_start();
		sorter.sort();
		sorter.print_result();
		sorter.print_sort_time();

	}
	catch(const std::runtime_error& rte)
	{
		std::cerr << rte.what() << '\n';
	}
	
	return (0);
}