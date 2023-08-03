#include <set>

#include "tests_entry.h"

TEST(set, ConstructorDefaultSet) {
    s21::set<char> my_empty_set;
    std::set<char> orig_empty_set;
    EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
}

TEST(set, ConstructorInitializerSet) {
    s21::set<char> my_set = {'x', 'b', 'z', 'y'};
    std::set<char> orig_set = {'x', 'b', 'z', 'y'};
    EXPECT_EQ(my_set.size(), orig_set.size());
    auto my_it = my_set.begin();
    auto orig_it = orig_set.begin();
    for (;my_it != my_set.end(); ++my_it, ++orig_it ) {
        EXPECT_TRUE(*orig_it == *my_it);
    }
}

TEST(set, ConstructorInitializer2Set) {
    s21::set<char> my_set = {};
    std::set<char> orig_set = {};
    EXPECT_EQ(my_set.size(), orig_set.size());
    auto my_it = my_set.begin();
    auto orig_it = orig_set.begin();
    for (;my_it != my_set.end(); ++my_it, ++orig_it ) {
        EXPECT_TRUE(*orig_it == *my_it);
    }
}

TEST(set, ConstructorCopySet) {
    s21::set<int> my_set = {1,2,3,4,5};
    std::set<int> orig_set = {1,2,3,4,5};
    s21::set<int> my_set_copy = my_set;
    std::set<int> orig_set_copy = orig_set;
    EXPECT_EQ(my_set_copy.size(), orig_set_copy.size());
    auto my_it = my_set_copy.begin();
    auto orig_it = orig_set_copy.begin();
    for (;my_it != my_set_copy.end(); ++my_it, ++orig_it ) {
        EXPECT_TRUE(*orig_it == *my_it);
    }
}

TEST(set, ConstructorMoveSet) {
    s21::set<int> my_set = {1,2,3,4,5};
    std::set<int> orig_set = {1,2,3,4,5};
    s21::set<int> my_set_copy = std::move(my_set);
    std::set<int> orig_set_copy = std::move(orig_set);
    EXPECT_EQ(my_set.size(), orig_set.size());
    EXPECT_EQ(my_set_copy.size(), orig_set_copy.size());
    auto my_it = my_set_copy.begin();
    auto orig_it = orig_set_copy.begin();
    for (;my_it != my_set_copy.end(); ++my_it, ++orig_it ) {
        EXPECT_TRUE(*orig_it == *my_it);
    }
}

TEST(set, SetIteratorsSet) {
    s21::set<std::string> my_set = {"This", "is", "my", "set"};
    std::set<std::string> orig_set = {"This", "is", "my", "set"};
    auto my_it = my_set.begin();
    auto orig_it = orig_set.begin();
    EXPECT_TRUE(*orig_it == *my_it);
    my_it = my_set.end();
    orig_it = orig_set.end();
    --my_it;
    --orig_it;
    EXPECT_TRUE(*orig_it == *my_it);
}

TEST(set, CapacitySet) {
    s21::set<char> my_empty_set;
    std::set<char> orig_empty_set;
    EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
    EXPECT_EQ(my_empty_set.size(), orig_empty_set.size());
    my_empty_set.insert('b');
    orig_empty_set.insert('c');
    EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
    EXPECT_EQ(my_empty_set.size(), orig_empty_set.size());
}

TEST(set, ClearSet) {
    s21::set<char> my_empty_set;
    std::set<char> orig_empty_set;
    my_empty_set.clear();
    orig_empty_set.clear();
    EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
    EXPECT_EQ(my_empty_set.size(), orig_empty_set.size());
    my_empty_set.insert('a');
    orig_empty_set.insert('b');
    EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
    EXPECT_EQ(my_empty_set.size(), orig_empty_set.size());
    my_empty_set.clear();
    orig_empty_set.clear();
    EXPECT_EQ(my_empty_set.empty(), orig_empty_set.empty());
    EXPECT_EQ(my_empty_set.size(), orig_empty_set.size());
}

TEST(set, InsertSet) {
    s21::set<std::string> my_set = {"This", "is", "my", "set"};
    std::set<std::string> orig_set = {"This", "is", "my", "set"};
    auto my_pr = my_set.insert("best");
    auto orig_pr = orig_set.insert("best");
    EXPECT_TRUE(my_pr.second == orig_pr.second);
    EXPECT_TRUE(*my_pr.first == *orig_pr.first);
    my_pr = my_set.insert("is");
    orig_pr = orig_set.insert("is");
    EXPECT_TRUE(my_pr.second == orig_pr.second);
    EXPECT_TRUE(*my_pr.first == *orig_pr.first);
}

TEST(set, EraseSet) {
    s21::set<int> my_set = {5,4,3,2,7,8,9};
    std::set<int> orig_set = {5,4,3,2,7,8,9};
    auto size = my_set.size();
    my_set.erase(my_set.end());
    auto new_size = my_set.size();
    EXPECT_EQ(size, new_size);
    my_set.erase(my_set.begin());
    orig_set.erase(orig_set.begin());
    auto my_it = my_set.begin();
    auto orig_it = orig_set.begin();
    for (;my_it != my_set.end(); ++my_it, ++orig_it ) {
        EXPECT_TRUE(*orig_it == *my_it);
    }
}

TEST(set, SwapSet) {
    s21::set<int> my_set = {1};
    s21::set<int> my_swap_set = {3,4,5};

    my_set.swap(my_swap_set);
    EXPECT_EQ(my_set.size(), 3);
    EXPECT_EQ(my_swap_set.size(), 1);
    EXPECT_EQ(*my_set.begin(), 3);
    EXPECT_EQ(*my_swap_set.begin(), 1);
}

TEST(set, MergeSet) {
    s21::set<int> my_set = {1};
    s21::set<int> my_merge_set = {3,4,5};
    my_set.merge(my_merge_set);

    std::set<int> orig_set = {1};
    std::set<int> orig_merge_set = {3,4,5};
    orig_set.merge(orig_merge_set);
    auto my_it = my_set.begin();
    auto orig_it = orig_set.begin();
    for (;my_it != my_set.end(); ++my_it, ++orig_it ) {
        EXPECT_TRUE(*orig_it == *my_it);
    }
    EXPECT_EQ(orig_set.size(), my_set.size());
    EXPECT_EQ(my_merge_set.size(), orig_merge_set.size());
}

TEST(set, FindSet) {
    s21::set<double> my_set = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
    s21::set<double> orig_set = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
    auto my_it = my_set.find(2.4);
    auto orig_it = orig_set.find(2.4);
    EXPECT_TRUE(*orig_it == *my_it);
}

TEST(set, ContainsSet) {
    s21::set<double> my_set = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
    s21::set<double> orig_set = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
    EXPECT_EQ(my_set.contains(2), orig_set.contains(2));
    EXPECT_EQ(my_set.contains(2.1), orig_set.contains(2.1));
}
