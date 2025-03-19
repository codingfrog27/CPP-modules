/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/14 17:23:05 by mde-cloe      #+#    #+#                 */
/*   Updated: 2025/03/17 13:57:52 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

//stack is actually a deqeue container with restrictions to enforce last in first out
// nature of a stack, BUT it has a protected member called c that you can use to still acess
// the original deqeue methods, like begin and end ;)

//the extra container template means we can mutantstack any container, not just deque :)
// debatable if mandatory, simpler implementation below
template <typename T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(/* args */) = default;
		~MutantStack() = default;
		MutantStack(const MutantStack& rhs) = default;
		MutantStack& operator=(const MutantStack& rhs) = default;

		// using <name> == making a typedef with c++ using
		// typename needed cause it concerns a template and we wanna 
		using iterator = typename Container::iterator;
		//haha get it cause reverse iterator
		using rotareti = typename Container::reverse_iterator;

		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}

		rotareti rbegin()
		{
			return this->c.rbegin();
		}

		rotareti rend()
		{
			return this->c.rend();
		}
};









//old non changeable mstack
// template <typename T>
// class MutantStack : public std::stack<T>
// {
// 	private:
// 		// <T>::iterator it;
// 	public:
// 		MutantStack(/* args */) = default;
// 		~MutantStack() = default;
// 		MutantStack(const MutantStack& rhs) = default;
// 		MutantStack& operator=(const MutantStack& rhs) = default;

// 	using iterator = typename std::deque<T>::iterator;

// 	iterator begin();
// 	iterator end();
// 	iterator rbegin();
// 	iterator rend();
// };

// template<typename T>
// typename MutantStack<T>::iterator MutantStack<T>::begin() {
// 	return this->c.begin();
// }

// template<typename T>
// typename MutantStack<T>::iterator MutantStack<T>::end() {
// 	return this->c.end();
// }

// template<typename T>
// typename MutantStack<T>::iterator MutantStack<T>::rbegin() {
// 	return this->c.rbegin();
// }

// template<typename T>
// typename MutantStack<T>::iterator MutantStack<T>::rend() {
// 	return this->c.rend();
// }