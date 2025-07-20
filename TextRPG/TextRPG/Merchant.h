#pragma once
#include "Struct.h"
#include "Player.h"
#include "Inventory.h"

void InitMerchant(Merchant* merchant, StoreTable* storeTable);
void InitStoreTable(StoreTable* storeTable);
void SelectProduct(const Merchant* merchant, Player* player);