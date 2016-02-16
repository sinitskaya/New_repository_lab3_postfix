#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack)
{
	Stack<int> *stack;
	ASSERT_NO_THROW(stack = new Stack<int>);
}

TEST(Stack, can_create_stack_of_copying_another)
{
	Stack<int> *S1 = new Stack<int>;
	ASSERT_NO_THROW(Stack<int> *S2 = new Stack<int>(*S1));
}

TEST(Stack, can_copy_stack_correct)
{
	Stack<int> *S1 = new Stack<int>;
	S1->Push(1);
	Stack<int> *S2 = new Stack<int>(*S1);
	EXPECT_EQ(*S1, *S2);
}

TEST(Stack, empty_stack_IsEmpty_1)
{
	Stack<int> *S = new Stack<int>;
	EXPECT_EQ(1, S->IsEmpty());
}

TEST(Stack, isnt_empty_stack_IsEmpty_0)
{
	Stack<int> *S = new Stack<int>;
	S->Push(1);
	EXPECT_EQ(0, S->IsEmpty());
}

TEST(Stack, isnt_full_stack_IsFull_0)
{
	Stack<int> *S = new Stack<int>;
	S->Push(1);
	EXPECT_EQ(0, S->IsFull());
}

TEST(Stack, can_push)
{
	Stack<int> *S = new Stack<int>;
	ASSERT_NO_THROW(S->Push(3));
}

TEST(Stack, can_push_correct)
{
	Stack<int> *S1 = new Stack<int>;
	S1->Push(1);
	S1->Push(2);
	S1->Push(3);
	Stack<int> *S2 = new Stack<int>;
	S2->Push(1);
	S2->Push(2);
	S2->Push(3);
	EXPECT_EQ(*S1, *S2);
}

TEST(Stack, can_pop)
{
	Stack<int> *S = new Stack<int>;
	S->Push(1);
	S->Push(2);
	ASSERT_NO_THROW(S->Pop());
}

TEST(Stack, can_pop_correct)
{
	Stack<int> *S1 = new Stack<int>;
	S1->Push(1);
	Stack<int> *S2 = new Stack<int>;
	S2->Push(1);
	S2->Push(2);
	S2->Pop();
	EXPECT_EQ(*S1, *S2);
}

TEST(Stack, throw_when_stack_is_empty_for_Pop)
{
	Stack<int> *S1 = new Stack<int>;
	ASSERT_ANY_THROW(S1->Pop());
}

TEST(Stack, can_GetValue)
{
	Stack<int> *S1 = new Stack<int>;
	S1->Push(1);
	ASSERT_NO_THROW(S1->GetValue());
}

TEST(Stack, throw_when_stack_is_empty_for_GetValue)
{
	Stack<int> *S1 = new Stack<int>;
	ASSERT_ANY_THROW(S1->GetValue());
}

TEST(Stack, GetValue_without_delete_key)
{
	Stack<int> *S1 = new Stack<int>;
	S1->Push(2);
	S1->Push(1);
	Stack<int> *S2 = new Stack<int>;
	S2->Push(2);
	S2->Push(1);
	S2->GetValue();
	EXPECT_EQ(*S1, *S2);
}

TEST(Stack, GetValue_correct)
{
	Stack<int> *S = new Stack<int>;
	S->Push(2);
	S->Push(5);
	EXPECT_EQ(5, S->GetValue());
}

TEST(Stack, compare_equal_stacks_return_true)
{
	Stack<int> *S1 = new Stack<int>;
	S1->Push(1);
	Stack<int> *S2 = new Stack<int>;
	S2->Push(1);
	EXPECT_TRUE(*S1 == *S2);
}

TEST(Stack, compare_not_equal_stacks_return_false)
{
	Stack<int> *S1 = new Stack<int>;
	S1->Push(2);
	Stack<int> *S2 = new Stack<int>;
	S2->Push(1);
	EXPECT_FALSE(*S1 == *S2);
}

TEST(Stack, compare_inequality_not_equal_stacks_return_true)
{
	Stack<int> *S1 = new Stack<int>;
	S1->Push(1);
	Stack<int> *S2 = new Stack<int>;
	S2->Push(2);
	EXPECT_TRUE(*S1 != *S2);
}

TEST(Stack, compare_inequality_equal_stacks_return_false)
{
	Stack<int> *S1 = new Stack<int>;
	S1->Push(1);
	Stack<int> *S2 = new Stack<int>;
	S2->Push(1);
	EXPECT_FALSE(*S1 != *S2);
}