# include <iostream>
# include <vector>
# include <llvm/Value.h>

class Codegenration;

class Statement;

class Expression;

class VariableDec;

typedef std::vector<Statement*> Liststatement;

typedef std:: vector <VariableDec*> ListVariable;

typedef std ::vector <Expression*> ListExpression;


	class Node { 
public: 

virtual ~Node () {}

virtual llvm:: Value* codeGen (Codegeneration& context) 

{}
};

class Interger : public Expression {

public:
 long value;
Integer (long value): value (value) {}

virtual llvm::Value* codeGen(Codegeneration& context);

};

class Expression : public Node { };

class Statement : public Node { };


class Double : public Expression
{
public:
 double value;
 Double (double value) : vlaue (value) { }

virtual llvm::Value* codeGen (Codegeneration& context);

};

class Identifier : public Expression {
public:
 std:: stirng name;
 Identifier (const std:: string& name) : name (name) {}
 virual llvm::Value* codeGen (Codegeneration& context);

};

class BinaryOperation : public Expression 
{
public:
 int operation;
 Expression& lhs;
 Expression& rhs;
BinaryOperator (Expression& lhs, int operation, Expression& rhs) :
lsh (lsh), rhs (rhs) , operation (operation) { }
virtual llvm:: Value* codeGen (Codegeneration& context);
};

class CallingMethod : Public Expression { 
public:
   const Identifier& Id;
ListExpression arguments;

CallingMethod (const Identifier& Id, ListExpression& arguments)

Id(Id), arguments (arguments) { }

virtual llvm::Value* codeGen(Codegeneration& context);

};

class Block : public Expression {
public :
 Liststatement statements;
 Block () {}
virtual llvm:: Value* codeGen (Codegeneration& context);
};

class Assingnment: public Expression {
public:
Identifier& lhs;
Expression& rhs;
Assingnment (Identifier& lhs, Expression& rhs):
lhs(lhs) , rhs (rhs) { }

virtual llvm::Value* codeGen ( Codegeneration& context);

};

class ExpressionStatement : public Statement {
public:
Expression& expression;
ExpressionStatement (Expression& expression) :
expression (expression) {}
virtual llvm:: Value* codeGen (Codegeneration& context);
};

class FunctionDec : public Statement {

public :
constant Identifer& type;
const Identifier& Id;
ListVariable arguments;
Block& block;
FunctionDec (const Identifier& type, const Identifier& Id,
const ListVariable& arguments, Block& block):
type (type), Id (Id) , arguments (arguments), block (block) {}
virtual llvm::Value* codeGen (Codegeneration& context);
};

class VarDec : public Statement 
{
public :
const Identifier& Id;
Expression *assingnemntExpr;
VarDec (const Identifier& type, Identifier& Id):
type (type) , Id(Id) {}
VarDec (const Identifier& type , Identifier& Id, Expression *assignmetExpr) :
type (type), Id (Id), assignmentExpr(assignmentExpr) {}
virtual llvm:: Value* codeGen (Codegeneration& context);

};



