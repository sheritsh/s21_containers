//
// Created by Oznak Banshee on 8/1/23.
//

#include "Map.h"
#include "Set.h"
#include <map>

int main() {
    s21::map<int, int> m = {{1,1}, {2,2}};
    auto it = m.begin();
    s21::map<int, int> const m_const(m);
    auto it_const = m_const.cbegin();
}


