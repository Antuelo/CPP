/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:10:32 by antuel            #+#    #+#             */
/*   Updated: 2026/08/03 11:30:42 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRT.hpp"
#include <unistd.h>

int main()
{
	for(int i = 0; i < 10; i++)
	{
		Base* Test = generate();
		
		identify(Test);		
		identify(*Test);
		
		sleep(1.5);
		delete Test;

		std::cout << "----------------------------" << std::endl;
	}
	return 0;
}