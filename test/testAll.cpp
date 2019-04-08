//
// Created by cosimo on 04/04/19.
//
#include <gtest/gtest.h>
#include "../Mappa.h"

TEST(MappaTest, Map1DimentionTest) {
    Mappa* map0 = Mappa::Instance(0);
    ASSERT_EQ(map0->getHeight(),20) << "Mappa piccola reading problem: height not calculated correctly.";
    ASSERT_EQ(map0->getWidth(),20) << "Mappa piccola reading problem: width not calculated correctly.";
    delete map0;
}

TEST(MappaTest, Map2DimentionTest) {
    Mappa* map1 = Mappa::Instance(1);
    ASSERT_EQ(map1->getHeight(),25) << "Mappa grande reading problem: height not calculated correctly.";
    ASSERT_EQ(map1->getWidth(),25) << "Mappa grande reading problem: width not calculated correctly.";
    delete map1;
}

/*TEST(MapTest, MapGenericTest) {
    Map* map3 = Map::Istance(250);
    ASSERT_EQ(map3->getHeight(),15) << "Map 3 reading problem: height not calculated correctly.";
    ASSERT_EQ(map3->getWidth(),20) << "Map 3 reading problem: width not calculated correctly.";
    delete map3;
}*/
