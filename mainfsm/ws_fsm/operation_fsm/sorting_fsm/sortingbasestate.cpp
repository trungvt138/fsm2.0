/*
 * sortingbasestate.cpp
 *
 *  Created on: 25.06.2024
 *      Author: infwur761
 */

#include "sortingbasestate.h"
#include <iostream>

#include "Check_WS_Data.h"

void SortingBaseState::enterViaPseudoStart() {
	std::cout << "Sorting Initial Transition taken" << std::endl;
	entry();
	new(this) Check_WS_Data;
	enterByDefaultEntryPoint();
}

void SortingBaseState::enterViaDeepHistory() {
	enterByDeepHistoryEntryPoint();
}

