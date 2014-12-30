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

#include <gtest/gtest.h>

#include "kora/utility/integer_sequence.hpp"

namespace {

} // namespace

TEST(IntegerSequence, Simple) {
	{
		typedef kora::integer_sequence<int, 0, 1, 2, 3> seq_t;
		EXPECT_EQ(seq_t::size(), 4);
		EXPECT_EQ((std::is_same<int, seq_t::value_type>::value), true);
	}

	{
		typedef kora::integer_sequence<unsigned> seq_t;
		EXPECT_EQ(seq_t::size(), 0);
	}
}

TEST(IntegerSequence, IndexSequence) {
	{
		typedef kora::index_sequence<0, 1, 2, 3, 4> seq_t;
		EXPECT_EQ(seq_t::size(), 5);
		EXPECT_EQ((std::is_same<std::size_t, seq_t::value_type>::value), true);
	}

	{
		typedef kora::index_sequence<> seq_t;
		EXPECT_EQ(seq_t::size(), 0);
	}
}

TEST(IntegerSequence, MakeIntegerSequence) {
	{
		typedef kora::make_integer_sequence<int, 5> seq_t;
		EXPECT_EQ(seq_t::size(), 5);
	}

	{
		typedef kora::make_integer_sequence<int, 0> seq_t;
		EXPECT_EQ(seq_t::size(), 0);
	}
}

TEST(IntegerSequence, MakeIndexSequence) {
	{
		typedef kora::make_index_sequence<5> seq_t;
		EXPECT_EQ(seq_t::size(), 5);
	}

	{
		typedef kora::make_index_sequence<0> seq_t;
		EXPECT_EQ(seq_t::size(), 0);
	}
}

TEST(IntegerSequence, IndexSequenceFor) {
	{
		typedef kora::index_sequence_for<int, short, double> seq_t;

		EXPECT_EQ(seq_t::size(), 3);
		EXPECT_EQ((std::is_same<seq_t::value_type, size_t>::value), true);
	}
}

