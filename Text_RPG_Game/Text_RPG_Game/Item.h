//해당 헤더는 임시로 작성한 아이템 클래스입니다.

#pragma once
#ifndef Item_H
#define Item_H

#include <iostream>
using namespace std;

struct Item{
    string name;
	int price;
};
const int Test_Item_List = 4;

const Item Test_Item[Test_Item_List] = {
    {"HP포션", 50}, {"MP포션", 70}, {"대미지포션", 100}, {"강화포션", 120}
};

#endif