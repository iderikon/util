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

#ifndef KORA_UTILITY_CONSTEXPR_HPP
#define KORA_UTILITY_CONSTEXPR_HPP

#include "kora/utility/platform.hpp"

#ifdef KORA_NOT_BAD
    #define KORA_CONSTEXPR constexpr
#else
    #define KORA_CONSTEXPR
#endif

#endif

