/* Copyright 2014 Jonas Platte
 *
 * This file is part of Cyvasse Online.
 *
 * Cyvasse Online is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Affero General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * Cyvasse Online is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include "hexagon_test.hpp"

// for std::sort
#include <algorithm>

void HexagonTest::setUp()
{
	h6Coord1 = hexagon<6>::Coordinate::create(3, 5);
	h6Coord2 = hexagon<6>::Coordinate::create(9, 2);
}

void HexagonTest::tearDown()
{
	h6Coord1.reset();
	h6Coord2.reset();
}

void HexagonTest::testCoordValidity()
{
	CPPUNIT_ASSERT(h6Coord1);
	CPPUNIT_ASSERT(h6Coord2);

	CPPUNIT_ASSERT(hexagon<6>::Coordinate::create( 0, 11) == nullptr); // outside – top
	CPPUNIT_ASSERT(hexagon<6>::Coordinate::create( 8,  9) == nullptr); // outside – top right
	CPPUNIT_ASSERT(hexagon<6>::Coordinate::create(11,  2) == nullptr); // outside – bottom right
	CPPUNIT_ASSERT(hexagon<6>::Coordinate::create(10, -2) == nullptr); // outside – bottom
	CPPUNIT_ASSERT(hexagon<6>::Coordinate::create( 1,  3) == nullptr); // outside – bottom left
	CPPUNIT_ASSERT(hexagon<6>::Coordinate::create(-2,  7) == nullptr); // outside – top left
}

void HexagonTest::testCoordEquality()
{
	CPPUNIT_ASSERT(*h6Coord1 == *h6Coord1);
	CPPUNIT_ASSERT(*h6Coord2 == *h6Coord2);

	CPPUNIT_ASSERT(*h6Coord1 != *h6Coord2);
}

void HexagonTest::testCoordCompleteness()
{
	CPPUNIT_ASSERT(hexagon<2>::getAllCoordinates().size() == 7);
	CPPUNIT_ASSERT(hexagon<3>::getAllCoordinates().size() == 19);
	CPPUNIT_ASSERT(hexagon<4>::getAllCoordinates().size() == 37);

	std::vector<hexagon<2>::Coordinate> coords = hexagon<2>::getAllCoordinates();
	std::sort(coords.begin(), coords.end());

	CPPUNIT_ASSERT(coords.at(0) == *hexagon<2>::Coordinate::create(0, 1));
	CPPUNIT_ASSERT(coords.at(1) == *hexagon<2>::Coordinate::create(0, 2));
	CPPUNIT_ASSERT(coords.at(2) == *hexagon<2>::Coordinate::create(1, 0));
	CPPUNIT_ASSERT(coords.at(3) == *hexagon<2>::Coordinate::create(1, 1));
	CPPUNIT_ASSERT(coords.at(4) == *hexagon<2>::Coordinate::create(1, 2));
	CPPUNIT_ASSERT(coords.at(5) == *hexagon<2>::Coordinate::create(2, 0));
	CPPUNIT_ASSERT(coords.at(6) == *hexagon<2>::Coordinate::create(2, 1));
}
