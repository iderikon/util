/*
Copyright (c) 2014 Artem Sokolov <derikon@yandex.ru>
Copyright (c) 2011-2014 Other contributors as noted in the AUTHORS file.

This file is part of Kora.

Kora is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

Kora is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KORA_UTILITY_INTEGER_SEQUENCE_HPP
#define KORA_UTILITY_INTEGER_SEQUENCE_HPP

#include "kora/utility/noexcept.hpp"
#include "kora/utility/constexpr.hpp"

#include <type_traits>

// n3658
namespace kora {

template<typename T, T... Ints>
struct integer_sequence;

namespace detail {

template<typename T, bool, T... Ints>
struct integer_sequence_impl;

template<typename T, T... Ints>
struct integer_sequence_impl<T, true, Ints...> {
	typedef T value_type;

	static
	KORA_CONSTEXPR
	std::size_t
	size() KORA_NOEXCEPT {
		return sizeof...(Ints);
	}
};

template<typename T, T... Ints>
struct integer_sequence : integer_sequence_impl<T, std::is_integral<T>::value, Ints...>
{ };


template<typename T, bool, T N, T... Ints>
struct make_integer_sequence_impl : make_integer_sequence_impl<T, N - 1 == 0, N - 1, N - 1, Ints...>
{ };

template<typename T, T N, T... Ints>
struct make_integer_sequence_impl<T, true, N, Ints...> : integer_sequence<T, Ints...>
{ };

template<typename T, T N>
struct make_integer_sequence : make_integer_sequence_impl<T, N == 0, N>
{ };

} // namespace detail

template<typename T, T... Ints>
struct integer_sequence : detail::integer_sequence<T, Ints...>
{ };

template<size_t... I>
struct index_sequence : integer_sequence<size_t, I...>
{ };

template<typename T, T N>
struct make_integer_sequence : detail::make_integer_sequence<T, N>
{ };

template<std::size_t N>
struct make_index_sequence : make_integer_sequence<std::size_t, N>
{ };

template<typename... T>
struct index_sequence_for : make_index_sequence<sizeof...(T)>
{ };

} // namespace kora

#endif


