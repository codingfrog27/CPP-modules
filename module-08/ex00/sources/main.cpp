/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:05:44 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/02/12 17:06:41 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>


//from chatgpt tbf
int main() {
    try {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::list<int> lst = {10, 20, 30, 40, 50};

        // Test with vector
        auto vecIt = easyfind(vec, 3);
        std::cout << "Found in vector: " << *vecIt << std::endl;

        // Test with list
        auto listIt = easyfind(lst, 40);
        std::cout << "Found in list: " << *listIt << std::endl;

        // Test for a value that doesn't exist
        easyfind(vec, 99);  // This will throw an exception

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}