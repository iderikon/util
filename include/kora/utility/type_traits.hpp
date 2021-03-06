/*
Copyright (c) 2013 Andrey Goryachev <andrey.goryachev@gmail.com>
Copyright (c) 2011-2013 Other contributors as noted in the AUTHORS file.

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

#ifndef KORA_UTILITY_TYPE_TRAITS_HPP
#define KORA_UTILITY_TYPE_TRAITS_HPP

#include <type_traits>

namespace kora {

/*! Remove references and cv-qualifiers.
 *
 * It's like \p std::decay, but doesn't convert arrays to pointers.
 */
template<class T>
struct pristine {
    typedef typename std::remove_cv<
        typename std::remove_reference<T>::type
    >::type type;
};

} // namespace kora

#endif
