/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucinguy <lucinguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:31:52 by lucinguy          #+#    #+#             */
/*   Updated: 2026/11/02 23:42:17 by lucinguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int i = 1; argv[i] ; i++)
		{
			for(int j = 0; argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
		}
		std::cout  << std::endl;
	}

	return 0;
}
