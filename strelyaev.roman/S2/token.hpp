#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <string>
namespace strelyaev
{
  enum class TokenType
  {
    OPERAND = 0,
    OPERATION = 1,
    BRACKET = 2,
    NONE = 3
  };

  class ExpressionUnit;

  union Token
  {
    friend struct ExpressionUnit;
    public:
      Token();
      explicit Token(long long);
      explicit Token(char);
      ~Token() = default;
    private:
      long long operand_;
      char operation_;
  };

  struct ExpressionUnit
  {
    public:
      ExpressionUnit() = default;
      ExpressionUnit(const Token&, TokenType);
      long long getOperand() const;
      char getOperation() const;
      TokenType getType() const;
    private:
      Token token_;
      TokenType type_;
  };
  bool isOperation(const std::string&);
  bool isBracket(const std::string&);
  bool operator<(const strelyaev::ExpressionUnit& a, const strelyaev::ExpressionUnit& b);
}

#endif



