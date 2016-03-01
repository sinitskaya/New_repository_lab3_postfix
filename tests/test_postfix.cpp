#include "postfix.h"
#include <gtest.h>

TEST(Postfix, Postfix_Form_correct)
{
	Postfix <char> postfix;
	string str = "(1+2)*8=";
	string str_correct = "12+8*=";
	string str_result_postfix = postfix.PostfixForm(str);
	EXPECT_EQ (str_correct, str_result_postfix);
}

TEST(Postfix, Postfix_Form_without_extra_brackets)
{
	Postfix <char> postfix;
	string str = "(1+2)*8=";
	ASSERT_NO_THROW(string str_result_postfix = postfix.PostfixForm(str));
}

TEST(Postfix, throw_when_exist_extra_left_braskets)
{
	Postfix <char> postfix;
	string str = "((1+2)*8=";
	ASSERT_ANY_THROW(string str_result_postfix = postfix.PostfixForm(str));
}

TEST(Postfix, throw_when_exist_right_extra_braskets)
{
	Postfix <char> postfix;
	string str = "(1+2))*8=";
	ASSERT_ANY_THROW(string str_result_postfix = postfix.PostfixForm(str));
}

TEST(Postfix, Calcul_correct)
{
	Postfix <char> postfix;

	string str_result_postfix = "ab+c*=";
	
	RT res = postfix.Calcul(str_result_postfix);
	
	RT resTrue;
	cout << "For 'ab+c*=' or '(a+b)*c=' input true result: ";
	cin >> resTrue;
	EXPECT_EQ(resTrue,res);
}