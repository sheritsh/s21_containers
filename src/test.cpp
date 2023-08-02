#include <gtest/gtest.h>
#include <set>
#include <map>
#include <algorithm>
#include "Set.h"
#include "Map.h"

class MapTest {
public:
    s21::map<int, int> empty_map;
    s21::map<int, int> map_int{{1, 2}, {2, 3}, {3, 4}, {4, 5},
                               {5, 6}, {6, 7}, {7, 8}, {8, 9}};
    s21::map<std::string, std::string> map_string{
            {"baka", "mitai"}, {"obon", "katsurage"}, {"kokoro", "desu"}};
    s21::map<double, double> map_double{
            {1.2, 3.4}, {5.2, 1.1}, {-10.2, 1.123}, {0.02, 12.33}};

    std::map<int, int> empty_map_orig;
    std::map<int, int> map_int_orig{{1, 2}, {2, 3}, {3, 4}, {4, 5},
                                    {5, 6}, {6, 7}, {7, 8}, {8, 9}};
    std::map<std::string, std::string> map_string_orig{
            {"baka", "mitai"}, {"obon", "katsurage"}, {"kokoro", "desu"}};
    std::map<double, double> map_double_orig{
            {1.2, 3.4}, {5.2, 1.1}, {-10.2, 1.123}, {0.02, 12.33}};

    s21::map<int, int> swapped{{100, 0}, {101, 1}, {102, 2}};
    std::map<int, int> swapped_orig{{100, 0}, {101, 1}, {102, 2}};

    s21::map<int, int> merged{{1, 1}, {50, 2}, {60, 3}};
    std::map<int, int> merged_orig{{1, 1}, {50, 2}, {60, 3}};
};

TEST(map, Constructor) {
    MapTest tmp;
    EXPECT_EQ(*(tmp.empty_map.begin()) == *(tmp.empty_map_orig.begin()), true);
    EXPECT_EQ(*(tmp.empty_map.end()) == *(tmp.empty_map_orig.end()), true);
}

TEST(map, ConstructorList) {
    MapTest tmp;
    for (int i = 0; static_cast<size_t>(i) < tmp.map_int_orig.size(); ++i) {
        EXPECT_NEAR(tmp.map_int_orig[i], tmp.map_int[i], 0.001);
    }
}

TEST(map, ConstructorCopy) {
    MapTest tmp;
    s21::map<double, double> two{tmp.map_double};
    std::map<double, double> two_orig{tmp.map_double_orig};
    for (int i = 0; static_cast<size_t>(i) < two_orig.size(); ++i) {
        EXPECT_NEAR(two[i], tmp.map_double_orig[i], 0.001);
    }
    tmp.map_double.clear();
    EXPECT_TRUE(tmp.map_double.empty());
    EXPECT_TRUE(!two.empty());
}

TEST(map, ConstructorMove) {
    MapTest tmp;
    s21::map<double, double> two{std::move(tmp.map_double)};
    int size = static_cast<int>(two.size());
    for (int i = 0; i < size; ++i) {
        EXPECT_NEAR(two[i], tmp.map_double_orig[i], 0.001);
    }
    EXPECT_TRUE(tmp.map_double.empty());
    EXPECT_TRUE(!two.empty());
}

TEST(map, EmptyTest) {
    MapTest tmp;
    EXPECT_TRUE(tmp.map_int.empty() == tmp.map_int_orig.empty());
    EXPECT_TRUE(tmp.empty_map.empty() == tmp.empty_map_orig.empty());
    EXPECT_TRUE(tmp.map_string.empty() == tmp.map_string_orig.empty());
    EXPECT_TRUE(tmp.map_double.empty() == tmp.map_double.empty());
}

TEST(map, SizeTest) {
    MapTest tmp;
    EXPECT_TRUE(tmp.map_int.size() == tmp.map_int.size());
    EXPECT_TRUE(tmp.empty_map.size() == tmp.empty_map.size());
    EXPECT_TRUE(tmp.map_string.size() == tmp.map_string.size());
    EXPECT_TRUE(tmp.map_double.size() == tmp.map_double_orig.size());
}

//TEST(map, MaxSizeTest) {
//    MapTest tmp;
//    EXPECT_TRUE(tmp.map_int.max_size() == tmp.map_int.max_size());
//    EXPECT_TRUE(tmp.empty_map.max_size() == tmp.empty_map_orig.max_size());
//}

TEST(map, ClearTest) {
    MapTest tmp;
    tmp.map_int.clear();
    tmp.map_int_orig.clear();
    EXPECT_TRUE(tmp.map_int.empty() == tmp.map_int_orig.empty());
}

TEST(map, EraseTest) {
    MapTest tmp;
    tmp.map_int.erase(tmp.map_int.begin());
    tmp.map_int_orig.erase(tmp.map_int_orig.begin());
    EXPECT_TRUE(tmp.empty_map.size() == tmp.empty_map_orig.size());
    EXPECT_THROW(tmp.map_int.at(1), std::out_of_range);
    EXPECT_THROW(tmp.map_int.at(1), std::out_of_range);
}

TEST(map, InsertTest) {
    MapTest tmp;
    auto s21_pair = tmp.empty_map.insert({1, 2});
    auto std_pair = tmp.empty_map_orig.insert({1, 2});
    EXPECT_TRUE(tmp.empty_map[1] == tmp.empty_map_orig[1]);
    EXPECT_TRUE(s21_pair.second == std_pair.second);
    s21_pair = tmp.empty_map.insert(5, 3);
    EXPECT_TRUE(tmp.empty_map[5] == 3);
    EXPECT_TRUE(s21_pair.second);
    s21_pair = tmp.empty_map.insert_or_assign(5, 10);
    EXPECT_TRUE(tmp.empty_map[5] == 10);
    EXPECT_FALSE(s21_pair.second);
}

TEST(map, SwapTest) {
    MapTest tmp;
    tmp.map_int.swap(tmp.swapped);
    tmp.map_int_orig.swap(tmp.swapped_orig);
    EXPECT_TRUE(tmp.map_int.size() == tmp.map_int_orig.size());
    auto it_orig = tmp.map_int_orig.begin();
    for (auto it = tmp.map_int.begin(); it != tmp.map_int.end(); ++it) {
        EXPECT_TRUE(*it == *(it_orig++));
    }
}

TEST(map, ContainsTest) {
    MapTest tmp;
    for (auto it : tmp.map_int_orig) {
        EXPECT_TRUE(tmp.map_int.contains(it.first));
        EXPECT_FALSE(tmp.map_int.contains(it.first + 10));
    }
}

TEST(map, MergeTest) {
    MapTest tmp;
    tmp.map_int.merge(tmp.merged);
    tmp.map_int_orig.merge(tmp.merged_orig);
    EXPECT_EQ(tmp.map_int.size(), tmp.map_int_orig.size());
    EXPECT_EQ(tmp.merged.size(), tmp.merged_orig.size());
    auto it_orig = tmp.map_int_orig.begin();
    for (auto it = tmp.map_int.begin(); it != tmp.map_int.end(); ++it) {
        EXPECT_TRUE(*it == *(it_orig++));
    }
}

class SetTest {
public:
    s21::set<int> empty_set;
    s21::set<int> set_int{3, 5, 7, 2, 1, 1, 4, 6};
    s21::set<std::string> set_string{"baka", "obon", "kokoro"};
    s21::set<double> set_double{1.2, 2.0, 3.345, -1.233};

    std::set<int> empty_set_orig;
    std::set<int> set_int_orig{3, 5, 7, 2, 1, 1, 4, 6};
    std::set<std::string> set_string_orig{"baka", "obon", "kokoro"};
    std::set<double> set_double_orig{1.2, 2.0, 3.345, -1.233};

    s21::set<int> swapped{100, 101, 102};
    std::set<int> swapped_orig{100, 101, 102};

    s21::set<int> merged{1, 50, 60};
    std::set<int> merged_orig{1, 50, 60};
};

TEST(set, Constructor) {
    SetTest tmp;
    EXPECT_EQ(*(tmp.empty_set.begin()) == *(tmp.empty_set_orig.begin()), true);
    EXPECT_EQ(*(tmp.empty_set.end()) == *(tmp.empty_set_orig.end()), true);
}

TEST(set, ConstructorList) {
    SetTest tmp;
    int eq[7]{1, 2, 3, 4, 5, 6, 7};
    int* pos = eq;
    for (auto it : tmp.set_int) {
        EXPECT_EQ(it == *(pos++), true);
    }
}

TEST(set, ConstructorCopy) {
    SetTest tmp;
    s21::set<double> two{tmp.set_double};
    double eq[4]{-1.233, 1.2, 2.0, 3.345};
    double* pos = eq;
    for (auto it : two) {
        EXPECT_EQ(it == *(pos++), true);
    }
    tmp.set_double.clear();
    EXPECT_TRUE(tmp.set_double.empty());
    EXPECT_TRUE(!two.empty());
}

TEST(set, ConstructorMove) {
    SetTest tmp;
    s21::set<double> two{std::move(tmp.set_double)};
    double eq[4]{-1.233, 1.2, 2.0, 3.345};
    double* pos = eq;
    for (auto it : two) {
        EXPECT_EQ(it == *(pos++), true);
    }
    EXPECT_TRUE(tmp.set_double.empty());
    EXPECT_TRUE(!two.empty());
}

TEST(set, OperatorsPlusTest) {
    SetTest tmp;
    s21::set<int>::iterator it(tmp.set_int.begin());
    EXPECT_TRUE(*(it++) == 1);
    EXPECT_TRUE(*(it) == 2);
    EXPECT_TRUE(*(++it) == 3);
}

TEST(set, OperatorsMinusTest) {
    SetTest tmp;
    s21::set<int>::iterator it(tmp.set_int.find(7));
    EXPECT_TRUE(*(it--) == 7);
    EXPECT_TRUE(*(it) == 6);
    EXPECT_TRUE(*(--it) == 5);
}

TEST(set, EmptyTest) {
    SetTest tmp;
    EXPECT_TRUE(tmp.set_int.empty() == tmp.set_int_orig.empty());
    EXPECT_TRUE(tmp.empty_set.empty() == tmp.empty_set_orig.empty());
    EXPECT_TRUE(tmp.set_string.empty() == tmp.set_string_orig.empty());
    EXPECT_TRUE(tmp.set_double.empty() == tmp.set_double_orig.empty());
}

TEST(set, SizeTest) {
    SetTest tmp;
    EXPECT_TRUE(tmp.set_int.size() == tmp.set_int_orig.size());
    EXPECT_TRUE(tmp.empty_set.size() == tmp.empty_set_orig.size());
    EXPECT_TRUE(tmp.set_string.size() == tmp.set_string_orig.size());
    EXPECT_TRUE(tmp.set_double.size() == tmp.set_double_orig.size());
}

//TEST(set, MaxSizeTest) {
//    SetTest tmp;
//    EXPECT_TRUE(tmp.set_int.max_size() == tmp.set_int_orig.max_size());
//    EXPECT_TRUE(tmp.empty_set.max_size() == tmp.empty_set_orig.max_size());
//}

TEST(set, ClearTest) {
    SetTest tmp;
    tmp.set_int.clear();
    tmp.set_int_orig.clear();
    EXPECT_TRUE(tmp.set_int.empty() == tmp.set_int_orig.empty());
}

TEST(set, InsertTest) {
    SetTest tmp;
    tmp.empty_set.insert(1);
    tmp.empty_set.insert(1);
    EXPECT_TRUE(tmp.set_int.empty() == tmp.set_int_orig.empty());
    EXPECT_TRUE(*(tmp.set_int.find(1)) == *(tmp.set_int_orig.find(1)));
    EXPECT_EQ(tmp.set_int.find(2) == tmp.set_int.end(),
              tmp.set_int_orig.find(2) == tmp.set_int_orig.end());
}

TEST(set, EraseTest) {
    SetTest tmp;
    tmp.set_int.erase(tmp.set_int.find(5));
    tmp.set_int_orig.erase(5);
    EXPECT_TRUE(tmp.set_int.size() == tmp.set_int_orig.size());
    EXPECT_EQ(tmp.set_int.find(5) == tmp.set_int.end(),
              tmp.set_int_orig.find(5) == tmp.set_int_orig.end());
}

TEST(set, SwapTest) {
    SetTest tmp;
    tmp.set_int.swap(tmp.swapped);
    tmp.set_int_orig.swap(tmp.swapped_orig);
    EXPECT_TRUE(tmp.set_int.size() == tmp.set_int_orig.size());
    auto it_orig = tmp.set_int_orig.begin();
    for (auto it = tmp.set_int.begin(); it != tmp.set_int.end(); ++it) {
        EXPECT_TRUE(*it == *(it_orig++));
    }
}

TEST(set, FindTest) {
    SetTest tmp;
    for (int i = 1; i < 8; ++i) {
        EXPECT_TRUE(tmp.set_int.find(i) != tmp.set_int.end());
        EXPECT_TRUE(tmp.set_int.find(i + 10) == tmp.set_int.end());
    }
}

TEST(set, ContainsTest) {
    SetTest tmp;
    for (int i = 1; i < 8; ++i) {
        EXPECT_TRUE(tmp.set_int.contains(i));
        EXPECT_FALSE(tmp.set_int.contains(i + 10));
    }
}

TEST(set, MergeTest) {
    SetTest tmp;
    tmp.set_int.merge(tmp.merged);
    tmp.set_int_orig.merge(tmp.merged_orig);
    EXPECT_TRUE(tmp.set_int.size() == tmp.set_int_orig.size());
    EXPECT_TRUE(tmp.merged.size() == tmp.merged_orig.size());
    auto it_orig = tmp.set_int_orig.begin();
    for (auto it = tmp.set_int.begin(); it != tmp.set_int.end(); ++it) {
        EXPECT_TRUE(*it == *(it_orig++));
    }
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}