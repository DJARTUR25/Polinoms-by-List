#include "../TList_modify/TList.h"
#include "gtest.h"

TEST(TList, can_made_empty_list_by_designer) {
	ASSERT_NO_THROW(TList<int> a);
};

TEST(TList, can_create_empty_list_by_copying_empty_list) {
	TList<int> a;
	TList<int> b(a);
}

