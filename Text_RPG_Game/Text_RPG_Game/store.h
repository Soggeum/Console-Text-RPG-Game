#pragma once
#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "Item.h"
using namespace std;

class Store {
public:
    void enterStore();              // 상점 입장 메시지
    void exitStore();               // 상점 이용하지 않음 메시지
	void showItems();				// 아이템 목록 출력
	void buyItem(int choice, int gold);       // 아이템 구매 메시지
	void goldCheck(int gold);       // 소지 금액 확인
};

#endif
//test