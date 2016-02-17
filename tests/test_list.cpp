#include "list.h"
#include <gtest.h>

TEST(List, can_create_list)
{
	List<int> *list;
	ASSERT_NO_THROW(list = new List<int>);
}

TEST(List, can_create_list_of_copying_another)
{
	List<int> *list1 = new List<int>;
	ASSERT_NO_THROW(List<int> *list2 = new List<int>(*list1));
}

TEST(List, create_list_of_copying_another_correct)
{
	List<int> *list1 = new List<int>;
	list1->PushStart(1);
	list1->PushEnd(2);
	List<int> *list2 = new List<int> (*list1);
	EXPECT_EQ(*list1, *list2);
}

TEST(List, can_push_start)
{
	List<int> *list = new List<int>;
	ASSERT_NO_THROW(list->PushStart(1));
}

TEST(List, push_start_correct)
{
	List<int> *L1 = new List<int>;
	L1->PushEnd(1);
	List<int> *L2 = new List<int>;
	L2->PushStart(1);
	EXPECT_EQ(*L1, *L2);
}

TEST(List, can_push_before_key)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	list->PushEnd(3);
	ASSERT_NO_THROW(list->PushBefore(3,2));
}

TEST(List, push_before_key_correct)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	list->PushEnd(2);
	list->PushEnd(3);
	List<int> *L2 = new List<int>;
	L2->PushStart(1);
	L2->PushEnd(3);
	L2->PushBefore(3,2);
	EXPECT_EQ(*list, *L2);
}

TEST(List, can_push_after_key)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	list->PushEnd(2);
	ASSERT_NO_THROW(list->PushAfter(2,3));
}

TEST(List, push_after_key_correct)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	list->PushEnd(2);
	list->PushEnd(3);
	List<int> *L2 = new List<int>;
	L2->PushStart(1);
	L2->PushEnd(2);
	L2->PushAfter(2,3);
	EXPECT_EQ(*list, *L2);
}

TEST(List, can_push_end)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	ASSERT_NO_THROW(list->PushEnd(2));
}

TEST(List, push_end_correct)
{
	List<int> *list = new List<int>;
	list->PushStart(3);
	list->PushStart(2);
	list->PushStart(1);
	List<int> *L2 = new List<int>;
	L2->PushStart(2);
	L2->PushStart(1);
	L2->PushEnd(3);
	EXPECT_EQ(*list, *L2);
}

TEST(List, can_find_key)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	list->PushEnd(2);
	ASSERT_NO_THROW(list->Find(2));
}

TEST(List, throw_if_list_doesnt_exist_in_search_of_key)
{
	List<int> *list = new List<int>;
	ASSERT_ANY_THROW(list->Find(2));
}

TEST(List, throw_if_findKey_doesnt_exist)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	ASSERT_ANY_THROW(list->Find(2));
}

TEST(List, can_get_first)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	list->PushEnd(2);
	ASSERT_NO_THROW(list->GetFirst());
}

TEST(List, get_first_is_correct)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	list->PushEnd(2);
	EXPECT_EQ(1, list->GetFirst()->key);//==
}
TEST(List, can_remove_with_key)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	list->PushEnd(2);
	ASSERT_NO_THROW(list->Remove(1));
}

TEST(List, remove_with_key_correct)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	list->PushEnd(2);
	list->Remove(2);
	List<int> *L2 = new List<int>;
	L2->PushStart(1);
	EXPECT_EQ(*L2, *list);//должно.получается
}

TEST(List, remove_First_key_correct)
{
	List<int> *list = new List<int>;
	list->PushStart(2);
	List<int> *L2 = new List<int>;
	L2->PushStart(1);
	L2->PushEnd(2);
	L2->Remove(1);
	EXPECT_EQ(*list, *L2);//должно.получается
}

TEST(List, remove_End_key_correct)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	List<int> *L2 = new List<int>;
	L2->PushStart(1);
	L2->PushEnd(2);
	L2->Remove(2);
	EXPECT_EQ(*list, *L2);//должно.получается
}

TEST(List, dont_remove_if_first_is_NULL)
{
	List<int> *list = new List<int>;
	ASSERT_ANY_THROW(list->Remove(2));
}

TEST(List, dont_remove_if_key_doesnt_exist)
{
	List<int> *list = new List<int>;
	list->PushStart(1);
	ASSERT_ANY_THROW(list->Remove(2));
}

TEST(List, compare_equal_lists_return_true)
{
	List<int> *L1 = new List<int>;
	L1->PushStart(1);
	List<int> *L2 = new List<int>;
	L2->PushStart(1);
	EXPECT_TRUE(*L1 == *L2);
}

TEST(List, compare_not_equal_lists_return_false)
{
	List<int> *L1 = new List<int>;
	L1->PushStart(2);
	List<int> *L2 = new List<int>;
	L2->PushStart(1);
	EXPECT_FALSE(*L1 == *L2);
}

TEST(List, compare_inequality_not_equal_lists_return_true)
{
	List<int> *L1 = new List<int>;
	L1->PushStart(1);
	List<int> *L2 = new List<int>;
	L2->PushStart(2);
	EXPECT_TRUE(*L1 != *L2);
}

TEST(List, compare_inequality_equal_lists_return_false)
{
	List<int> *L1 = new List<int>;
	L1->PushStart(1);
	List<int> *L2 = new List<int>;
	L2->PushStart(1);
	EXPECT_FALSE(*L1 != *L2);
}